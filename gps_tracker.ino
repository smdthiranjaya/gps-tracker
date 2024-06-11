#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

// Define pins for ESP8266 and NEO-6M
const int RXPin = 14; // D5
const int TXPin = 12; // D6
const uint32_t GPSBaud = 9600;

// Define pins for SIM800C
const int simRX = 4; // D2
const int simTX = 5; // D1

// Create objects for communication
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
SoftwareSerial sim800c(simRX, simTX);

void setup() {
  Serial.begin(9600); // Set serial monitor baud rate
  gpsSerial.begin(GPSBaud); // Set baud rate for GPS communication
  sim800c.begin(9600); // Set baud rate for GSM communication

  Serial.println("Initializing...");

  // Initialize GSM module
  initializeSIM800C();
}

void loop() {
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    Serial.write(c); // Print raw GPS data
    gps.encode(c);
  }

  if (gps.location.isUpdated()) {
    double latitude = gps.location.lat();
    double longitude = gps.location.lng();
    Serial.print("Latitude: ");
    Serial.println(latitude, 6);
    Serial.print("Longitude: ");
    Serial.println(longitude, 6);
    sendToServer(latitude, longitude);
  }

  if (sim800c.available()) {
    Serial.println(sim800c.readString());
  }
}

void initializeSIM800C() {
  Serial.println("Initializing SIM800C...");
  sim800c.println("AT");
  delay(1000);
  if (sim800c.find("OK")) {
    Serial.println("SIM800C is OK");
  } else {
    Serial.println("SIM800C is not responding");
    return;
  }

  sim800c.println("AT+CPIN?");
  delay(1000);
  if (sim800c.find("READY")) {
    Serial.println("SIM800C is ready");
  } else {
    Serial.println("SIM800C is not ready");
    return;
  }

  sim800c.println("AT+CREG?");
  delay(1000);
  String regStatus = sim800c.readString();
  Serial.println("Network registration status: " + regStatus);
  
  sim800c.println("AT+CGATT?");
  delay(1000);
  if (sim800c.find("OK")) {
    Serial.println("Attached to GPRS service");
  } else {
    Serial.println("Failed to attach to GPRS service");
    return;
  }

  sim800c.println("AT+CIPSHUT");
  delay(1000);
  sim800c.println("AT+CIPSTATUS");
  delay(1000);
  sim800c.println("AT+CIPMUX=0");
  delay(1000);
  sim800c.println("AT+CSTT=\"PPWAP\"");
  delay(1000);
  if (sim800c.find("OK")) {
    Serial.println("APN set successfully");
  } else {
    Serial.println("Failed to set APN");
    return;
  }

  sim800c.println("AT+CIICR");
  delay(3000); // Increase delay for CIICR
  if (sim800c.find("OK")) {
    Serial.println("GPRS brought up successfully");
  } else {
    Serial.println("Failed to bring up GPRS");
    return;
  }

  sim800c.println("AT+CIFSR");
  delay(1000);
  if (sim800c.available()) {
    String ipAddress = sim800c.readString();
    Serial.println("IP address: " + ipAddress);
  } else {
    Serial.println("Failed to get IP address");
  }

  // Additional delay to ensure network is ready
  delay(2000);
}

void sendToServer(double lat, double lon) {
  String latStr = String(lat, 6);
  String lonStr = String(lon, 6);

  Serial.println("Connected to server");
  sim800c.println("AT+CIPSTART=\"TCP\",\"112.134.244.46\",\"3000\""); // Replace with your local IP and port
  delay(5000); // Increase delay for CIPSTART
  if (sim800c.find("CONNECT OK")) {
    Serial.println("Connected to server");
  } else {
//    Serial.println("Failed to connect to server");
    return;
  }

  Serial.println("Sending data to server...");
  sim800c.println("AT+CIPSEND");
  delay(2000);
  String data = "GET /update?lat=" + latStr + "&lon=" + lonStr + " HTTP/1.1\r\nHost: 112.134.244.46\r\n\r\n"; // Replace with your local IP
  sim800c.println(data);
  delay(2000);

  Serial.println("Data sent");

  // Close the connection
  sim800c.println("AT+CIPCLOSE");
  delay(1000);
  Serial.println("Connection closed");
}
