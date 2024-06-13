# GPS Tracker Project with ESP8266, NEO-6M, SIM800C, and Arduino Uno

This repository contains the documentation and instructions for building a GPS tracker using an ESP8266, NEO-6M GPS module, SIM800C GSM module, and Arduino Uno. The tracker reads GPS coordinates from the NEO-6M GPS module and sends the data to a server using the SIM800C module.

## Repository Description

This project demonstrates how to build a GPS tracker using the following components:
- ESP8266 for Wi-Fi connectivity
- NEO-6M GPS module for obtaining GPS coordinates
- SIM800C GSM module for sending data via GSM network
- Arduino Uno for interfacing and controlling the modules

The system reads GPS coordinates and sends them to a specified server, making it useful for various tracking applications.

## Hardware Components

1. **Arduino Uno**:
   - Acts as the main controller.
   - Provides interfacing for the GPS and GSM modules.

2. **ESP8266**:
   - Provides Wi-Fi connectivity for future expansions.
   - Currently, the primary communication is through GSM.

3. **NEO-6M GPS Module**:
   - Used to obtain the GPS coordinates (latitude and longitude).

4. **SIM800C GSM Module**:
   - Sends the GPS data to a remote server using the GSM network.

5. **External Power Sources**:
   - A stable 4.2V to 4.4V power supply for the SIM800C module.
   - 5V power supply for the Arduino Uno and GPS module.

## Wiring Connections

1. **SIM800C Module**:
   - RX to Arduino pin 4
   - TX to Arduino pin 5
   - GND to Arduino GND
   - VCC to a stable 4.2V to 4.4V power source

2. **NEO-6M GPS Module**:
   - RX to Arduino pin 14 (D5)
   - TX to Arduino pin 12 (D6)
   - GND to Arduino GND
   - VCC to Arduino 5V

## Setup Instructions

1. **Hardware Setup**:
   - Connect the modules as per the wiring connections above.
   - Ensure all connections are secure and correct.
   - Provide the appropriate external power sources to the modules.

2. **Software Setup**:
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Install the required libraries: `SoftwareSerial` and `TinyGPSPlus` via the Arduino Library Manager.

3. **Testing the Modules**:
   - Open the Arduino IDE and upload the provided code to the Arduino Uno.
   - Open the Serial Monitor and set the baud rate to 9600.
   - Send AT commands to test the SIM800C module and verify its functionality.

## List of AT Commands

Here are some useful AT commands for testing the SIM800C module:
- `AT`: Check if the module is working (should return `OK`).
- `AT+CPIN?`: Check SIM card status.
- `AT+CSQ`: Check signal strength.
- `AT+CREG?`: Check network registration status.
- `AT+CGATT?`: Check GPRS attachment status.
- `AT+CIPSHUT`: Shut down any open connections.
- `AT+CIPSTATUS`: Get connection status.
- `AT+CIPMUX=0`: Set single connection mode.
- `AT+CSTT="your_apn"`: Set APN for your network provider (replace `your_apn` with your actual APN, e.g., `hutch3g` for Hutch in Sri Lanka).
- `AT+CIICR`: Bring up wireless connection.
- `AT+CIFSR`: Get local IP address.
- `AT+CIPSTART="TCP","<server_ip>","<port>"`: Start a TCP connection (replace `<server_ip>` and `<port>` with your server's IP address and port).
- `AT+CIPSEND`: Send data through the established connection.

## Example APN Settings

Replace `your_apn` with the actual APN for your network provider. For example:
- For Hutch: `AT+CSTT="hutch3g"`
- For Mobitel: `AT+CSTT="mobitel"`

## Troubleshooting

- Ensure the SIM card is active and has sufficient balance/data.
- Verify the power supply to the SIM800C module is adequate.
- Check all connections are secure and correct.
- Use `Serial.println` statements in the code to debug and monitor the communication.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
