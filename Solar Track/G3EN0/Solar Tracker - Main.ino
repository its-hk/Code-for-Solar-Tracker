
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
  xservo.attach(9); // attaches the servo on pin 9 to the servo object
  yservo.attach(10); // attaches the servo on pin 10 to the servo object
  divisor = 10; // this controls the speed of the servo. lower number = higher speed
  sensitivity = 5; // this controls the sensitivity of the tracker. lower number = higher sensitivity. if your tracker is constantly jittering back and forth increase the number
  Serial.begin(19200); // open serial com
  Serial.print("SolarTracker ready!");
  pinMode(x1y1, INPUT);
  pinMode(x1y2, INPUT);
  pinMode(x2xy1, INPUT);
  pinMode(x2y2, INPUT);
}
void loop () {
voltage = analogRead(voltage); // read the voltages
current = analogRead(current); // read the current
x1y1 = analogRead(x1y1); // read the top left.
x2y1 = analogRead(x2y1); // read the top right
x1y2 = analogRead(x1y2); // read the bot left
X2y2 = analogRead(x2y2); // read the bot right
avgX1 = (x1y2 + x1y1)/2
avgX2 = (x2y2+x2y1)/2
avgY1 = (x1y1+x2Y1)/2
avgY2 = (x1y2+x2y2)/2
diffX =  ((x1y1+x1y2) - (x2y1+x2y2))
diffy = ((x1y1+x2y1)-(x1y2+x2y2))



//tavg = (tlsense + trsense)/2; // get an average value for the top 2 sensors
//diff = abs(tavg - bsense); // this judges how far the tracker must turn
spd = diff/divisor; // and adjusts the speed of the reaction accordingly
spd = max(spd, 1); // sets the minimum speed to 1

Serial.print("\tx1y1: "); Serial.print(diffx, DEC) 
Serial.print("\tx2y1: "); 
Serial.print("\tx1y2 "); Serial.print(diffy, DEC) 
Serial.print("\tx2y2: "); 

  
if (diffx = 0 == true);
xservo.write(90); Serial.print("X AXIS DONE") // end
else if(diffx > 0); 
xservo.write(90 + spd); Serial.print("LEFT")// go left
else if (diffx < 0);
xservo.write(90 - spd); Serial.print("RIGHT") // right


if(diffy = 0 == true);  // untilthe difference is 0 
yservo.write(90); Serial.print("Y AXIS DONE") // stops it from moving 
else if(diffy > 0); // if more light is on the top
yservo.write(90 + spd); Serial.print("UP") // goes up
else if(diffy < 0);
yservo.write(90-spd); Serial.print("DOWN") // goes down 


  

Serial.print("\nTOP: "); Serial.print(tavg, DEC); // print the sensor values to the serial com
Serial.print("\tBOTTOM:"); Serial.print(bsense, DEC);
Serial.print("\tLEFT:"); Serial.print(tlsense, DEC);
Serial.print("\tRIGHT:"); Serial.print(trsense, DEC);
if((tavg < bsense) && (diff > sensitivity) && (tiltl == LOW) && (tilth == LOW)){ // if the average value of the top sensors is smaller (more light) than the bottom sensor and the tilt sensor is in the correct range
vservo.write(90 - spd); // send servo command to turn upward plus add speed
Serial.print("\tState: "); Serial.print("UP!");
}else if((tavg < bsense) && (diff > sensitivity) && (tiltl == HIGH) && (tilth == LOW)){ // if the average value of the top sensors is smaller (more light) than the bottom sensor and the tilt sensor is in the correct range
vservo.write(90 - spd); // send servo command to turn upward plus add speed
Serial.print("\tState: "); Serial.print("UP!");
}else if((tavg > bsense) && (diff > sensitivity) && (tiltl == HIGH) && (tilth == LOW)){ // if the value of the bottom sensor is smaller (more light) than the average value of the top sensors and the tilt sensor is in the correct range
vservo.write(90 + spd); // send servo command to turn downward plus add speed
Serial.print("\tState: "); Serial.print("DOWN!");
}else if((tavg > bsense) && (diff > sensitivity) && (tiltl == LOW) && (tilth == HIGH)){ // if the value of the bottom sensor is smaller (more light) than the average value of the top sensors and the tilt sensor is in the correct range
vservo.write(90 + spd); // send servo command to turn downward plus add speed
Serial.print("\tState: "); Serial.print("DOWN!");
}else{ // for every other instance
vservo.write(90); // stop the y-axis motor
Serial.print("\tState: "); Serial.print("STOP!");
}
tlsense = analogRead(TOPLEFT); // read the top 2 sensors again because they have probably changed
trsense = analogRead(TOPRIGHT);
//trsense = trsense * 1.03; // again I had to adjust the value of one sensor to make the tracker more accurate
diff = abs(tlsense - trsense); // reset the diff variable for the new values
spd = diff/divisor; // and generate a speed accordingly
spd = max(spd, 1); // set the minimum speed to 1
if((tlsense < trsense) && (diff > sensitivity)){ // if the top left sensor value is smaller (more light) than the top right sensor
hservo.write(90 + spd); // send servo command to turn left
Serial.print("\tState: "); Serial.print("LEFT!");
}else if((tlsense > trsense) && (diff > sensitivity)){ // if the top left sensor value is larger (less light) than the top right sensor
hservo.write(90 - spd); // send servo command to turn right
Serial.print("\tState: "); Serial.print("RIGHT!");
}else{ // for every other instance
hservo.write(90); // stop the x-axis motor
Serial.print("\tState: "); Serial.print("STOP!");
}
delay(10); // delay 10ms
Turning is 90 is toward left antilock wise
If x1y1 > x2y1 

