// Libraries
#include "Servo.h"

//Servo Dec
Servo xservo;
Servo yservo;
Servo tservo;

// Classes
class LabeledData {
public:
  char label[3]; // Label to identify the data
  int value;     // Value associated with the label

  // Default constructor
  LabeledData() : value(0) {
    label[0] = '\0';
  }

  // Parameterized constructor
  LabeledData(const char lbl[], int val) : value(val) {
    strncpy(label, lbl, sizeof(label) - 1);
    label[sizeof(label) - 1] = '\0'; // Ensure null-terminated string
  }
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

LabeledData baseLDRread[dataSize];

// Functions

void bubbleSort(LabeledData arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j].value > arr[j + 1].value) {
        // Swap the elements if they are in the wrong order
        LabeledData temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void printData() {
  Serial.print("Data: ");
  for (int i = 0; i < dataSize; i++) {
    Serial.print(baseLDRread[i].label);
    Serial.print(":");
    Serial.print(baseLDRread[i].value);
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
    baseLDRread[0] = LabeledData("Q1",(sensorValueQ1)); // read the value from the sensor
    baseLDRread[1] = LabeledData("Q2",(sensorValueQ2));
    baseLDRread[2] = LabeledData("Q3",(sensorValueQ3));
    baseLDRread[3] = LabeledData("Q4",(sensorValueQ4));

    bubbleSort(baseLDRread, dataSize);

    char qLowestRes[3];
    strcpy(qLowestRes, baseLDRread[0].label);

    char qNextLowestRes[3];
    strcpy(qNextLowestRes, baseLDRread[1].label);

    Serial.println(qLowestRes);
    Serial.println(qNextLowestRes);

    if (strcmp(qLowestRes, "Q1") == 0) {
      if (strcmp(qNextLowestRes, "Q2") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q3") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q4") == 0) {
      } 
    } else if (strcmp(qLowestRes, "Q2") == 0) {
      if (strcmp(qNextLowestRes, "Q1") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q3") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q4") == 0) {
      } 
    } else if (strcmp(qLowestRes, "Q3") == 0) {
      if (strcmp(qNextLowestRes, "Q1") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q2") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q4") == 0) {
      } 
    } else if (strcmp(qLowestRes, "Q4") == 0) {
      if (strcmp(qNextLowestRes, "Q1") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q2") == 0) {
      }
      if (strcmp(qNextLowestRes, "Q3") == 0) {
      } 
    }
    delay(1000);
}