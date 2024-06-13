# SIM800C Module Testing with Arduino

This repository contains code for testing the SIM800C GSM module using an Arduino. The code forwards data between the serial monitor and the SIM800C module, allowing users to send AT commands and receive responses. This setup is tested with Mobitel and Hutch SIM cards.

## Repository Description

The code provided helps in testing the SIM800C module by setting up a simple serial communication bridge. This allows you to manually send AT commands from the Arduino Serial Monitor to the SIM800C module and receive the responses. It is a useful tool for verifying the module's functionality and troubleshooting.

## Hardware Setup

1. Connect the SIM800C module to the Arduino:
    - SIM800C RX to Arduino pin 4
    - SIM800C TX to Arduino pin 5
    - SIM800C GND to Arduino GND
    - SIM800C VCC to a suitable power source (usually 4.2V to 4.4V)

2. Insert a Mobitel or Hutch SIM card into the SIM800C module.

## Software Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the `SoftwareSerial` library if not already included.

## How to Use
Open the Arduino IDE.
Select the correct board and port.
Upload the code to your Arduino.
Open the Serial Monitor in the Arduino IDE.
Set the baud rate to 9600.
Type AT commands in the Serial Monitor and press Enter.
Observe the responses from the SIM800C module.

## List of AT Commands
Here are some useful AT commands for testing the SIM800C module:

* AT: Check if the module is working (should return OK).
* AT+CPIN?: Check SIM card status.
* AT+CSQ: Check signal strength.
* AT+CREG?: Check network registration status.
* AT+CGATT?: Check GPRS attachment status.
* AT+CIPSHUT: Shut down any open connections.
* AT+CIPSTATUS: Get connection status.
* AT+CIPMUX=0: Set single connection mode.
* AT+CSTT="your_apn": Set APN for your network provider (replace your_apn with your actual APN, e.g., dialogbb for Dialog in Sri Lanka).
* AT+CIICR: Bring up wireless connection.
* AT+CIFSR: Get local IP address.
* AT+CIPSTART="TCP","<server_ip>","<port>": Start a TCP connection (replace <server_ip> and <port> with your server's IP address and port).
* AT+CIPSEND: Send data through the established connection.

Example AT Commands for Mobitel or Hutch
Replace your_apn with the actual APN for Mobitel or Hutch:

For Mobitel: AT+CSTT="mobitel3g"
For Hutch: AT+CSTT="hutch3g"

## Troubleshooting
Ensure the SIM card is active and has sufficient balance/data.
Verify the power supply to the SIM800C module is adequate.
Check all connections are secure and correct.
Use the Serial.println statements in the code to debug and monitor the communication.

## Code

Upload the following code to your Arduino:

```cpp
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


