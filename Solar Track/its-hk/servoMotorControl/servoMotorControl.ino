// Library Import
#include "math.h"
#include "Servo.h"

//Servo Dec
Servo yservo;

int pos = 0;    // variable to store the servo position

void setup() {
  yservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos; pos <= 180; pos+= 5) {
    yservo.write(pos);
    delay(1000);
  }


}