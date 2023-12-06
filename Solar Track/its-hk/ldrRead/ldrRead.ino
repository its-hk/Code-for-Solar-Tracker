// Library Import
#include "math.h"
#include "Servo.h"

//Servo Dec
Servo yservo;
Servo xservo;
Servo tservo;

int pos = 0;    // variable to store the servo position

void setup() {
  xservo.attach(9);  // attaches the servo on pin 9 to the servo object
  yservo.attach(10);
  tservo.attach(11);
}

void loop() {
  xservo.write(0);
  yservo.write(0);
  tservo.write(0);
}