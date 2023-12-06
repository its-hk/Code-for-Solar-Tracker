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

const int dataSize = 4;
LabeledData dataArray[dataSize] = {LabeledData("Q1", 4), LabeledData("Q2", 2), LabeledData("Q3", 1), LabeledData("Q4", 3)};

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
    Serial.print(dataArray[i].label);
    Serial.print(":");
    Serial.print(dataArray[i].value);
    Serial.print(" ");
  }
  Serial.println();
}

void setup() {
  // Your setup code here
  Serial.begin(9600);

  // Print original data
  printData();
}

void loop() {
  // Your loop code here

  // Check some condition and update the data
  if (/* your condition here */) {
    // Update the data dynamically
    dataArray[0] = LabeledData("Q1", 5);
    dataArray[1] = LabeledData("Q2", 2);
    dataArray[2] = LabeledData("Q3", 8);
    dataArray[3] = LabeledData("Q4", 1);

    // Print updated data
    printData();

    // Sort the data
    bubbleSort(dataArray, dataSize);

    // Print sorted data
    Serial.println("Sorted Data:");

    for (int i = 0; i < dataSize; i++) {
      Serial.print(dataArray[i].label);
      Serial.print(":");
      Serial.print(dataArray[i].value);
      Serial.print(" ");
    }
    Serial.println();

    // Add a delay if needed
    delay(1000);
  }
}
