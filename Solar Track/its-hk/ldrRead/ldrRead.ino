// Libraries
#include "Servo.h"

//Servo Dec
Servo xservo;
Servo yservo;
Servo tservo;

// Objects
class Data {
public:
    int value;

    Data() : value(0) {}

    Data(int val) : value(val) {}
};


//Variable Initialization
int sensorPinQ1 = A0; // select the input pin for LDR
int sensorPinQ2 = A1;
int sensorPinQ3 = A2;
int sensorPinQ4 = A3;
int sensorPinT1 = A4; 
int sensorPinT2 = A5;

int sensorValueQ1 = 0; // variable to store the value coming from the sensor
int sensorValueQ2 = 0;
int sensorValueQ3 = 0;
int sensorValueQ4 = 0;
int sensorValueT1 = 0; 
int sensorValueT2 = 0;

int posX = 0;  // variable to store the initial servo position
int posY = 62.5;    
int posT = 10;

int diff = 0;

const int dataSize = 4;

Data dataArray[dataSize];

// Functions

void bubbleSort(Data arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
            // Swap the elements if they are in the wrong order
            Data temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }
}

void printData() {
    Serial.print("Data: ");
    for (int i = 0; i < dataSize; i++) {
    Serial.print(dataArray[i].value);
    Serial.print(" ");
    }
    Serial.println();
}

void setup() {
    Serial.begin(9600); // Intialises serial port for communication

    xservo.attach(9); // Intialises Servo Motors
    yservo.attach(10);
    tservo.attach(11);
}

void loop() {

    dataArray[0].value = analogRead(sensorPinQ1); // read the value from the sensor
    dataArray[1].value = analogRead(sensorPinQ2); 
    dataArray[2].value = analogRead(sensorPinQ3); 
    dataArray[3].value = analogRead(sensorPinQ4);
    printData();
    delay(1000);
}