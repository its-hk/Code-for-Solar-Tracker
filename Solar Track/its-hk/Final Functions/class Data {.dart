class Data {
public:
  Char label[3];
  int value;

  // Default constructor
  LabeledData() : label(' '), value(0) {}

  // Parameterized constructor
  LabeledData(char lbl, int val) : label(lbl), value(val) {}
};

const int dataSize = 4;
Data dataArray[dataSize] = {Data(4), Data(2), Data(1), Data(3)}; // Initial data

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
  // Your setup code here
  Serial.begin(9600);

  // Print original data
  printData();
}

void loop() {
  // Your loop code here

  // Check some condition and update the data
  if (/* your condition here */) {
    dataArray[0].value = 5;
    dataArray[1].value = 2;
    dataArray[2].value = 8;
    dataArray[3].value = 1;

    // Print updated data
    printData();

    // Sort the data
    bubbleSort(dataArray, dataSize);

    // Print smallest and second smallest values
    Serial.print("Smallest Value: ");
    Serial.println(dataArray[0].value);

    Serial.print("Second Smallest Value: ");
    Serial.println(dataArray[1].value);

    // Add a delay if needed
    delay(1000);
  }
}
