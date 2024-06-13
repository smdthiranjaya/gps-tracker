# GPS Tracker Project

## Project Overview

This repository contains the code for a GPS Tracker project using an ESP8266, NEO-6M GPS module, SIM800C GSM module, and Node.js backend server. The project aims to track GPS coordinates and send the data to a server for further processing without using Wi-Fi. The Arduino Uno is used solely to provide 5V and 3.3V power sources.

## Hardware Components

- ESP8266
- NEO-6M GPS Module
- SIM800C GSM Module
- Arduino Uno (for power only)
- External Power Sources
- Jumper Wires
- Breadboard (optional)

## Hardware Connections

1. **Power Connections from Arduino Uno**
   - Arduino 5V -> SIM800C VCC
   - Arduino 3.3V -> GPS VCC
   - Arduino GND -> Common Ground

2. **NEO-6M GPS Module to ESP8266**
   - GPS TX -> ESP8266 D6
   - GPS RX -> ESP8266 D5
   - GPS GND -> Common Ground

3. **SIM800C GSM Module to ESP8266**
   - SIM800C TX -> ESP8266 D1
   - SIM800C RX -> ESP8266 D2
   - SIM800C GND -> Common Ground

## ESP8266 Sketch Instructions

1. **Install Arduino IDE**
   - Download and install the Arduino IDE from [here](https://www.arduino.cc/en/software).

2. **Install ESP8266 Board Package**
   - In the Arduino IDE, go to `File` > `Preferences`.
   - In the "Additional Boards Manager URLs" field, add `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
   - Go to `Tools` > `Board` > `Boards Manager...`, search for `esp8266`, and install it.

3. **Install Required Libraries**
   - Open the Arduino IDE and go to `Sketch` > `Include Library` > `Manage Libraries...`.
   - Install the `TinyGPSPlus` library.

4. **Upload Code**
   - Copy the provided ESP8266 code into the Arduino IDE.
   - Connect your ESP8266 to your computer.
   - Select the correct board (`NodeMCU 1.0 (ESP-12E Module)`) and port in the Arduino IDE.
   - Click on the `Upload` button to upload the code to the ESP8266.

## Node.js Server Setup

1. **Install Node.js and npm**
   - Download and install Node.js and npm from [here](https://nodejs.org/).

2. **Create a Project Directory**
   - Create a new directory for your project and navigate into it.

3. **Initialize Node.js Project**
   - Run `npm init -y` to create a `package.json` file.

4. **Install Express.js**
   - Run `npm install express` to install the Express.js framework.

5. **Create Server File**
   - Create a file named `server.js` and copy the provided Node.js code into this file.

6. **Run the Server**
   - Run `node server.js` to start the server.

7. **Testing**
   - Ensure your server is running by accessing `http://localhost:8080/get?lat=0&lon=0` in your browser.

## Deployment

1. **Hosting on Render**
   - Create an account on [Render](https://render.com/).
   - Create a new web service and connect your GitHub repository or upload your project files.
   - Set the `Start Command` to `node server.js`.
   - Deploy the service and note the URL provided by Render.

## Usage

1. **Power the Hardware**
   - Connect the Arduino Uno to provide power to the GPS and GSM modules.
   - Connect the ESP8266 to an external power source if necessary.

2. **Monitor Serial Output**
   - Open the Serial Monitor in the Arduino IDE to view the GPS data and server responses.

3. **GPS Data Transmission**
   - The ESP8266 code sends GPS coordinates to the Node.js server at regular intervals.

4. **Server Logs**
   - The Node.js server logs incoming requests and prints the received latitude and longitude values.

## Troubleshooting

- **GPS Module Issues**
  - Ensure the GPS module has a clear view of the sky for accurate data.

- **SIM800C Module Issues**
  - Check for proper SIM card insertion and network availability.
  - Verify APN settings for your GSM provider.

- **Server Issues**
  - Ensure the Node.js server is running and accessible from the ESP8266.
  - Check firewall settings to allow incoming connections on the specified port.

## Conclusion

This project demonstrates a simple GPS tracker using an ESP8266 and a GSM module, sending location data to a Node.js backend server. Follow the instructions above for a successful setup and operation.

## License

This project is licensed under the MIT License.

## Contact

For any queries or support, please contact [Thiranjaya] at [s.m.d.thiranjaya@gmail.com
].
