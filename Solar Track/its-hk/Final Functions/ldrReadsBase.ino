//Variable Initialization
int sensorPinQ1 = A0; // select the input pin for LDR
int sensorPinQ2 = A1;
int sensorPinQ3 = A2;
int sensorPinQ4 = A3;
int sensorValueQ1 = 0; // variable to store the value coming from the sensor
int sensorValueQ2 = 0;
int sensorValueQ3 = 0;
int sensorValueQ4 = 0;
int diff = 0;

void setup() {
Serial.begin(9600); //sets serial port for communication
}

void loop() {
sensorValueQ1 = analogRead(sensorPinQ1); // read the value from the sensor
sensorValueQ2 = analogRead(sensorPinQ2); // read the value from the sensor
sensorValueQ3 = analogRead(sensorPinQ3); // read the value from the sensor
sensorValueQ4 = analogRead(sensorPinQ4); // read the value from the sensor
delay(100);
}