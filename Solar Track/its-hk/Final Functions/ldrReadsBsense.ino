//Variable Initialization
int sensorPinT1 = A4; // select the input pin for LDR
int sensorPinT2 = A5;
int sensorValueT1 = 0; // variable to store the value coming from the sensor
int sensorValueT2 = 0;
int Vin = 5;
float Vout = 0;
float R1 = 10000;
float R2 = 0;
float buffer = 0;
int diff = 0;

void setup() {
Serial.begin(9600); //sets serial port for communication
}

void loop() {
sensorValueT1 = analogRead(sensorPinT1); // read the value from the sensor
sensorValueT2 = analogRead(sensorPinT2); // read the value from the sensor
diff = sensorValueT1 - sensorValueT2;
Serial.println(diff); //prints the values coming from the sensor on the screen
delay(100);
}