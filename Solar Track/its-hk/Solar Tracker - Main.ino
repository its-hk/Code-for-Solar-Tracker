// Variable Declaration
#include "math.h"
#include "Solar Track/Servo/src/Servo.h"
Servo yservo;
Servo xservo;
#define X1Y1LDR;
#define X1Y2LDR;
#define X2Y1LDR;
#define X2Y2LDR;
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
  pinMode(X1Y1LDR, INPUT);
  pinMode(X1Y2LDR, INPUT);
  pinMode(X2Y1LDR, INPUT);
  pinMode(X2Y2LDR, INPUT);
}

void loop () {

x1y1 = analogRead(X1Y1LDR); // read the light sensors
x1y2 = analogRead(X1Y2LDR);
x2y1 = analogRead(X2Y1LDR); // read the light sensors
x2y2 = analogRead(X2Y2LDR);
//bsense = bsense * 1.05; // I had to adjust the value of this sensor to make it more accurate. you might have to do the same but start by leaving it alone
x1 = (x1y2 + x1y1)/2
x2 = (x2y2+x2y1)/2
y1 = (x1y1+x2Y1)/2
y2 = (x1y2+x2y2)/2
// While loops
do {
  
} while (x1 != x2)
//tavg = (tlsense + trsense)/2; // get an average value for the top 2 sensors
//diff = abs(tavg - bsense); // this judges how far the tracker must turn
spd = diff/divisor; // and adjusts the speed of the reaction accordingly
spd = max(spd, 1); // sets the minimum speed to 1
Serial.print("\nTOP: "); Serial.print(tavg, DEC); // print the sensor values to the serial com
Serial.print("\tBOTTOM:"); Serial.print(bsense, DEC);
Serial.print("\tLEFT:"); Serial.print(tlsense, DEC);
Serial.print("\tRIGHT:"); Serial.print(trsense, DEC);
}


