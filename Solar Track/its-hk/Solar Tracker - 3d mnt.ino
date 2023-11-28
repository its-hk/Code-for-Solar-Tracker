// Library Import
#include "math.h"
#include "Solar Track/Servo/src/Servo.h"

//Servo Dec

Servo horizontalServo;
Servo verticalServo;
Servo tiltServo;

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
int l2;
int l1;
int l3;
int l4;
int l5;
int l6;