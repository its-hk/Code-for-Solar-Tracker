// Variable Declaration
#include "math.h"
Servo yservo;
Servo xservo;
int X1Y1LDR;
int X1Y2LDR;
int X2Y1LDR;
int X2Y2LDR;
int voltage;
int current;
int divisor;
int spd;
int sensitivity;
//X1 = left 
//X2 = RIGHT
//Y1 = UP
//Y2 = DOWN




void setup () {
  yservo.attach(9); // attaches the servo on pin 9 to the servo object
  xservo.attach(10); // attaches the servo on pin 10 to the servo object
  divisor = 10; // this controls the speed of the servo. lower number = higher speed
  sensitivity = 5; // this controls the sensitivity of the tracker. lower number = higher sensitivity. if your tracker is constantly jittering back and forth increase the number
  Serial.begin(19200); // open serial com
  Serial.print("Solar Tracker ready!");
}

void loop () {

x1y1sense = analogRead(TOPLEFT); // read the light sensors
X2y1 = analogRead(TOPRIGHT);
x1y2 = analogRead(BOTLEFT); // read the light sensors
X2y2 = analogRead(BOTRIGHT);
//bsense = bsense * 1.05; // I had to adjust the value of this sensor to make it more accurate. you might have to do the same but start by leaving it alone
avgX1 = (x1y2 + x1y1)/2
avgX2 = (x2y2+x2y1)/2
avgY1 = (x1y1+x2Y1)/2
avgY2 = (x1y2+x2y2)/2
//tavg = (tlsense + trsense)/2; // get an average value for the top 2 sensors
//diff = abs(tavg - bsense); // this judges how far the tracker must turn
spd = diff/divisor; // and adjusts the speed of the reaction accordingly
spd = max(spd, 1); // sets the minimum speed to 1
Serial.print("\nTOP: "); Serial.print(tavg, DEC); // print the sensor values to the serial com
Serial.print("\tBOTTOM:"); Serial.print(bsense, DEC);
Serial.print("\tLEFT:"); Serial.print(tlsense, DEC);
Serial.print("\tRIGHT:"); Serial.print(trsense, DEC);
}


