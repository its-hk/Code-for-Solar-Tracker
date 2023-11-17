// Library Import
#include "math.h"
#include "Solar Track/Servo/src/Servo.h"

//Servo Dec

Servo yservo;
Servo xservo;

// Const Dec
#define X1Y1LDR;
#define X1Y2LDR;
#define X2Y1LDR;
#define X2Y2LDR;

// Var Dec
int divisor;
int spd;
int sensitivity;
int potPinX = 0;  // analog pin used to connect the potentiometer; CHANGE ACCORDINGLY
int potPinY = 1;
int valX;    // variable to read the value from the analog pin
int valY;
int x1y1;
int x1y2;
int x2y1;
int x2y2;
int avgX1;
int avgX2;
int avgY1;
int avgY2;
int threshold_value=10; 

void setup () {
  xservo.attach(9); // attaches the servo on pin 9 to the servo object
  yservo.attach(10); // attaches the servo on pin 10 to the servo object
  divisor = 10; // this controls the speed of the servo. lower number = higher speed
  sensitivity = 5; // this controls the sensitivity of the tracker. lower number = higher sensitivity. if your tracker is constantly jittering back and forth increase the number
  Serial.begin(19200); // open serial com
  Serial.print("Solar Tracker ready!");
  pinMode(X1Y1LDR, INPUT); //Did we not want a pin number for the pin mode?
  pinMode(X1Y2LDR, INPUT);
  pinMode(X2Y1LDR, INPUT);
  pinMode(X2Y2LDR, INPUT);
}

void loop () {

  x1y1 = analogRead(X1Y1LDR); // read the light sensors Left Bottom
  x1y2 = analogRead(X1Y2LDR); // read the light sensors Left Top
  x2y1 = analogRead(X2Y1LDR); // read the light sensors Right Bottom
  x2y2 = analogRead(X2Y2LDR); // read the light sensors Right Top

  // Average Calculations
  avgX1 = (x1y2+x1y1)/2;
  avgX2 = (x2y2+x2y1)/2;
  avgY1 = (x1y1+x2Y1)/2;
  avgY2 = (x1y2+x2y2)/2;

  // Power Calc from Solar Panel
  char  Mode;
  float volt = analogRead(A5) * 5.0 / 1023; // CHANGE PIN
  float voltage = 2 * volt;
  float current = voltage / 20;
  float power  = voltage * current;



  // While loops
  if (avgX1 != avgX2 && avgY1 != avgY2) {

    do {

      if (avgX1 < avgX2){

        if (avgY1 < avgY2) {
          /* code */ 
        } //Allows perfect diagonal movement to BOTTOM-LEFT

        else if (avgY1 > avgY2) {
        /* code */  
        } //Allows perfect diagonal movement to TOP-LEFT

      }

      else if (avgX1 > avgX2) {

        if (avgY1 < avgY2) {
          /* code */ 
        } //Allows perfect diagonal movement to TOP-LEFT

        else if (avgY1 > avgY2) {
          /* code */ 
        } //Allows perfect diagonal movement to TOP-RIGHT

      }

    } while (avgX1 != avgX2 || avgY1 != avgY2);

  }

  else if (avgX1 != avgX2) {

    if (avgY1 < avgY2) {

      do {
        /*code*/
      } while (avgY1 != avgY2);

    }

    else {

     do {
        /*code*/
      } while (avgY1 != avgY2);

    }

  }

  else if (avgY1 != avgY2) {

    if (avgY1 < avgY2) {

      do {
        /*code*/
      } while (avgY1 != avgY2);

    }

    else {

     do {
        /*code*/
      } while (avgY1 != avgY2);

    }
    
  }


//tavg = (tlsense + trsense)/2; // get an average value for the top 2 sensors
//diff = abs(tavg - bsense); // this judges how far the tracker must turn
spd = diff/divisor; // and adjusts the speed of the reaction accordingly
spd = max(spd, 1); // sets the minimum speed to 1
Serial.print("\nTOP: "); Serial.print(tavg, DEC); // print the sensor values to the serial com
Serial.print("\tBOTTOM:"); Serial.print(bsense, DEC);
Serial.print("\tLEFT:"); Serial.print(tlsense, DEC);
Serial.print("\tRIGHT:"); Serial.print(trsense, DEC);
}


