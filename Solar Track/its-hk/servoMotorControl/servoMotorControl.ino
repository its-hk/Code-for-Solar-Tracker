// Library Import
#include "math.h"
#include "Servo.h"

//Servo Dec
Servo yservo;
Servo xservo;

int pos = 0;    // variable to store the servo position

void setup() {
  xservo.attach(9);  // attaches the servo on pin 9 to the servo object
  yservo.attach(10);
}

void loop() {
  for (pos; pos <= 180; pos += 1) {
    xservo.write(pos);
    yservo.write(pos);
    delay(100);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    xservo.write(pos);              // tell servo to go to position in variable 'pos'
    yservo.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}