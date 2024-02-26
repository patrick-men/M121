const int reedSwitchPin = 2; // Pin connected to the reed switch sensor
const int ledPin = 13; // Built-in LED pin for indication
bool doorOpen = false; // Variable to track door status

void setup() {
  pinMode(reedSwitchPin, INPUT_PULLUP); // Reed switch pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT); // LED pin as output
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorState = digitalRead(reedSwitchPin); // Read the state of the reed switch sensor
  
  if (sensorState == LOW && !doorOpen) {
    Serial.println("Door is open!"); // Print message to serial monitor
    digitalWrite(ledPin, HIGH); // Turn on LED to indicate door open
    doorOpen = true; // Update door status
    executePythonScript(); // Execute Python script
    delay(1000); // Delay to prevent multiple detections
  } else if (sensorState == HIGH && doorOpen) {
    digitalWrite(ledPin, LOW); // Turn off LED if door is closed
    doorOpen = false; // Update door status
  }
}

void executePythonScript() {
  // Execute Python script
  system("python my_script.py"); // Replace my_script.py with the name of your Python script
}
