// Libraries
#include "Servo.h"

// Servo Dec
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

// Arrays

int sweepLDR5read[50];
int sweepLDR6read[50];

// Variable Initialization
int sensorPinQ1 = A0; // select the input pin for LDR
int sensorPinQ2 = A1;
int sensorPinQ3 = A2;
int sensorPinQ4 = A3;
int sensorPinT1 = A4; 
int sensorPinT2 = A5;

int posX = 0;  // variable to store the initial servo position
int posY = 62.5;    
int posT = 10;

int diff = 0;

int minValue;

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


// Initialisation

void setup() {
    Serial.begin(9600); // Intialises serial port for communication

    xservo.attach(9); // Intialises Servo Motors
    yservo.attach(10);
    tservo.attach(11);
}

// Main Loop

void loop() {
    baseLDRread[0] = LabeledData("Q1",analogRead(sensorPinQ1)); // read the value from the sensor
    baseLDRread[1] = LabeledData("Q2",analogRead(sensorPinQ2));
    baseLDRread[2] = LabeledData("Q3",analogRead(sensorPinQ3));
    baseLDRread[3] = LabeledData("Q4",analogRead(sensorPinQ4));

    bubbleSort(baseLDRread, dataSize);

    char qLowestRes[3];
    strcpy(qLowestRes, baseLDRread[0].label);

    char qNextLowestRes[3];
    strcpy(qNextLowestRes, baseLDRread[1].label);

    Serial.println(qLowestRes);
    Serial.println(qNextLowestRes);

    if (strcmp(qLowestRes, "Q1") == 0) {
      if (strcmp(qNextLowestRes, "Q2") == 0) {
        posX = 85;
        xservo.write(posX);
        yservo.write();
        tservo.write();
        for (posX; posX <= 175; posX+= 2) {
          xservo.write(posX);
          delay(15);
          sweepLDR5read[posX-85].append(analogRead(sensorPinT1));
          sweepLDR6read[posX-85].append(analogRead(sensorPinT2)); 
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR5 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR5 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR5read[i] < minValue) {
              minValueLDR5 = sweepLDR5read[i];
              minIndexLDR5 = i;
            }
          }
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR6 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR6 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR6read[i] < minValue) {
              minValueLDR6 = sweepLDR6read[i];
              minIndexLDR6 = i;
            }
        }

        if (minValueLDR6 == minValueLDR5) {
          xservo.write(minIndexLDR5 + 85);
        } else {
          xservo.write(minValueLDR6 + 85);
        }

        if (minValueLDR6 < minValueLDR5) {
          do {
            tservo.write(21.25 + 2);
            yservo.write(62.5 + 2);
          } while (minIndexLDR5 != minIndexLDR6)
        } else if (minValueLDR6 > minValueLDR5) {
          do { 
            tservo.write(21.25 - 2);
            yservo.write(62.5 - 2);
          } while (minIndexLDR5 != minIndexLDR6)
        }


      }
      if (strcmp(qNextLowestRes, "Q3") == 0) {
        xservo.write(posX);
        yservo.write(posY);    
        tservo.write(posT);
      }
      if (strcmp(qNextLowestRes, "Q4") == 0) {
        posX = 85;
        xservo.write(posX);
        yservo.write(62.5);
        tservo.write(21.25);
        for (posX; posX <= 180; posX+= 2) {
          xservo.write(posX);
          delay(15);
          sweepLDR5read[posX-85].append(analogRead(sensorPinT1));
          sweepLDR6read[posX-85].append(analogRead(sensorPinT2)); 
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR5 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR5 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR5read[i] < minValue) {
              minValueLDR5 = sweepLDR5read[i];
              minIndexLDR5 = i;
            }
          }
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR6 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR6 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR6read[i] < minValue) {
              minValueLDR6 = sweepLDR6read[i];
              minIndexLDR6 = i;
            }
        }

        if (minValueLDR6 == minValueLDR5) {
          xservo.write(minIndexLDR5 + 85);
        } else {
          xservo.write(minValueLDR6 + 85);
        }

        if (minValueLDR6 < minValueLDR5) {
          do {
            tservo.write(21.25 + 2);
            yservo.write(81.25 + 2);
          } while (minIndexLDR5 != minIndexLDR6)
        } else if (minValueLDR6 > minValueLDR5) {
          do { 
            tservo.write(21.25 - 2);
            yservo.write(81.25 - 2);
          } while (minIndexLDR5 != minIndexLDR6)
        }
} 
    } else if (strcmp(qLowestRes, "Q2") == 0) {
      if (strcmp(qNextLowestRes, "Q1") == 0) {
        posX = 85;
        xservo.write(posX);
        yservo.write();
        tservo.write();
        for (posX; posX <= 180; posX+= 2) {
          xservo.write(posX);
          delay(15);
          sweepLDR5read[posX-85].append(analogRead(sensorPinT1));
          sweepLDR6read[posX-85].append(analogRead(sensorPinT2)); 
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR5 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR5 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR5read[i] < minValue) {
              minValueLDR5 = sweepLDR5read[i];
              minIndexLDR5 = i;
            }
          }
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR6 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR6 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR6read[i] < minValue) {
              minValueLDR6 = sweepLDR6read[i];
              minIndexLDR6 = i;
            }
        }

        if (minValueLDR6 == minValueLDR5) {
          xservo.write(minIndexLDR5 + 85);
        } else {
          xservo.write(minValueLDR6 + 85);
        }

        if (minValueLDR6 < minValueLDR5) {
          do {
            tservo.write(21.25 + 2);
            yservo.write(62.5 + 2);
          } while (minIndexLDR5 != minIndexLDR6)
        } else if (minValueLDR6 > minValueLDR5) {
          do { 
            tservo.write(21.25 - 2);
            yservo.write(62.5 - 2);
          } while (minIndexLDR5 != minIndexLDR6)
        }


      }
      if (strcmp(qNextLowestRes, "Q4") == 0) {
        xservo.write(posX);
        yservo.write(posY);    
        tservo.write(posT);
      }
      if (strcmp(qNextLowestRes, "Q3") == 0) {
        posX = 85;
        xservo.write(posX);
        yservo.write(62.5);
        tservo.write(21.25);
        for (posX; posX <= 180; posX+= 2) {
          xservo.write(posX);
          delay(15);
          sweepLDR5read[posX-85].append(analogRead(sensorPinT1));
          sweepLDR6read[posX-85].append(analogRead(sensorPinT2)); 
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR5 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR5 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR5read[i] < minValue) {
              minValueLDR5 = sweepLDR5read[i];
              minIndexLDR5 = i;
            }
          }
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR6 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR6 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR6read[i] < minValue) {
              minValueLDR6 = sweepLDR6read[i];
              minIndexLDR6 = i;
            }
        }

        if (minValueLDR6 == minValueLDR5) {
          xservo.write(minIndexLDR5 + 85);
        } else {
          xservo.write(minValueLDR6 + 85);
        }

        if (minValueLDR6 < minValueLDR5) {
          do {
            tservo.write(21.25 + 2);
            yservo.write(81.25 + 2);
          } while (minIndexLDR5 != minIndexLDR6)
        } else if (minValueLDR6 > minValueLDR5) {
          do { 
            tservo.write(21.25 - 2);
            yservo.write(81.25 - 2);
          } while (minIndexLDR5 != minIndexLDR6)
        }
    } else if (strcmp(qLowestRes, "Q3") == 0) {
      if (strcmp(qNextLowestRes, "Q2") == 0) {
        posX = 85;
        xservo.write(posX);
        yservo.write();
        tservo.write();
        for (posX; posX <= 180; posX+= 2) {
          xservo.write(posX);
          delay(15);
          sweepLDR5read[posX-85].append(analogRead(sensorPinT1));
          sweepLDR6read[posX-85].append(analogRead(sensorPinT2)); 
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR5 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR5 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR5read[i] < minValue) {
              minValueLDR5 = sweepLDR5read[i];
              minIndexLDR5 = i;
            }
          }
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR6 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR6 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR6read[i] < minValue) {
              minValueLDR6 = sweepLDR6read[i];
              minIndexLDR6 = i;
            }
        }

        if (minValueLDR6 == minValueLDR5) {
          xservo.write(minIndexLDR5 + 85);
        } else {
          xservo.write(minValueLDR6 + 85);
        }

        if (minValueLDR6 < minValueLDR5) {
          do {
            tservo.write(21.25 + 2);
            yservo.write(62.5 + 2);
          } while (minIndexLDR5 != minIndexLDR6)
        } else if (minValueLDR6 > minValueLDR5) {
          do { 
            tservo.write(21.25 - 2);
            yservo.write(62.5 - 2);
          } while (minIndexLDR5 != minIndexLDR6)
        }


      }
      if (strcmp(qNextLowestRes, "Q1") == 0) {
        xservo.write(posX);
        yservo.write(posY);    
        tservo.write(posT);
      }
      if (strcmp(qNextLowestRes, "Q4") == 0) {
        posX = 85;
        xservo.write(posX);
        yservo.write(62.5);
        tservo.write(21.25);
        for (posX; posX <= 180; posX+= 2) {
          xservo.write(posX);
          delay(15);
          sweepLDR5read[posX-85].append(analogRead(sensorPinT1));
          sweepLDR6read[posX-85].append(analogRead(sensorPinT2)); 
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR5 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR5 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR5read[i] < minValue) {
              minValueLDR5 = sweepLDR5read[i];
              minIndexLDR5 = i;
            }
          }
          int arraySize = sizeof(sweepLDR5read[]) / sizeof(myArray[0]);

          // Initialize the minimum value with the first element of the array
          int minValueLDR6 = sweepLDR5read[];

          // Initialize the index of the minimum value
          int minIndexLDR6 = 0;

          // Iterate through the array to find the minimum value and its index
          for (int i = 1; i < arraySize; i++) {
            if (sweepLDR6read[i] < minValue) {
              minValueLDR6 = sweepLDR6read[i];
              minIndexLDR6 = i;
            }
        }

        if (minValueLDR6 == minValueLDR5) {
          xservo.write(minIndexLDR5 + 85);
        } else {
          xservo.write(minValueLDR6 + 85);
        }

        if (minValueLDR6 < minValueLDR5) {
          do {
            tservo.write(21.25 + 2);
            yservo.write(81.25 + 2);
          } while (minIndexLDR5 != minIndexLDR6)
        } else if (minValueLDR6 > minValueLDR5) {
          do { 
            tservo.write(21.25 - 2);
            yservo.write(81.25 - 2);
          } while (minIndexLDR5 != minIndexLDR6)
        }

    delay(10000);
}