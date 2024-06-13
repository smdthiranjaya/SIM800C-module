#include <SoftwareSerial.h>

// Define pins for SIM800C
const int simRX = 4; // Define the RX pin for SIM800C
const int simTX = 5; // Define the TX pin for SIM800C

// Create a SoftwareSerial object for communication with the SIM800C
SoftwareSerial mygsm(simRX, simTX);

void setup() {
  Serial.begin(9600); // Set baud rate for serial monitor
  mygsm.begin(9600); // Set baud rate for SIM800C communication
  Serial.println("SIM800C Test Initialized");
}

void loop() {
  // Forward data from Serial Monitor to SIM800C
  while (Serial.available()) {
    mygsm.write(Serial.read());
  }

  // Forward data from SIM800C to Serial Monitor
  while (mygsm.available()) {
    Serial.write(mygsm.read());
  }
}
