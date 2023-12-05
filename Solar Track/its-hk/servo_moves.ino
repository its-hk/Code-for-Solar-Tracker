#include "Servo.h"

//Servo Dec
Servo xservo;
Servo yservo;
Servo tiltServo;

int pos = 0;    // variable to store the servo position

void setup() {
  xservo.attach(9);  // attaches the servo on pin 9 to the servo objec
  yservo.attach(10);
  tiltServo.attach(11);
}

void loop() {
  for (pos; pos <= 180; pos+= 5) {
    xservo.write(pos);
    delay(1000);
  }
}