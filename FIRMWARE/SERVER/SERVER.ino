/*

 This is the firmware for the server end (the gun) of the Target Practice Game
 When the target sends a signal to stop the squirt, the squirt timer resets.
*/


// #include <ESP8266WiFi.h>
// #include <ESP8266mDNS.h>
#include <WiFiClient.h>
// #include "WIFI_CREDS.h"

// 'const char* ssid = STASSID;
// 'const char* password = STAPSK
// const int squirtTimerDurationMS = 10000;

// long squirtTimerStart;
// bool squirtTimerActive;

// TCP server at port 80 will respond to HTTP requests
// WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  Serial.println("Setting up");

  // Connect to WiFi network
  // WiFi.mode(WIFI_STA);
  // WiFi.begin(ssid, password);
  // WiFi.softAP("estrogen"); // this sets up an AP

  // IPAddress IP = WiFi.softAPIP();
  // Serial.print("AP IP address: ");
  // Serial.println(IP);

  // Serial.println(WiFi.localIP());

  // Serial.println("");

  // Wait for connection
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println("");
  // Serial.print("Connected to ");
  // Serial.println(ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.localIP());

  // Set up mDNS responder:
  // - first argument is the domain name, in this example
  //   the fully-qualified domain name is "esp8266.local"
  // - second argument is the IP address to advertise
  //   we send our IP address on the WiFi network
  // if (!MDNS.begin("missandmist")) {
  //   Serial.println("Error setting up MDNS responder!");
  //   while (1) { delay(1000); }
  // }
  // Serial.println("mDNS responder started");

  // // Start TCP (HTTP) server
  // server.begin();
  // Serial.println("TCP server started");

  // // Add service to MDNS-SD
  // MDNS.addService("http", "tcp", 80);
  // MDNS IS NOT NECESSARY with AP at least
}

void loop() {
  Serial.println(analogRead(A0));
  delay(500);
  // servershit();
  // if (squirtTimerActive and millis() - squirtTimerStart > squirtTimerDurationMS) {
  //   squirtTimerActive = false;
  //   Serial.println("womp wommp get fucked");
  // } else if (squirtTimerActive) {
  //   Serial.println(millis() - squirtTimerStart);
  // }
}

// void servershit() {
//   // MDNS.update();

//   // Check if a client has connected
//   WiFiClient client = server.accept();
//   if (!client) { return; }
//   Serial.println("");
//   Serial.println("New client");

//   // Wait for data from client to become available
//   while (client.connected() && !client.available()) { delay(1); }

//   // Read the first line of HTTP request
//   String req = client.readStringUntil('\r');

//   // First line of HTTP request looks like "GET /path HTTP/1.1"
//   // Retrieve the "/path" part by finding the spaces
//   int addr_start = req.indexOf(' ');
//   int addr_end = req.indexOf(' ', addr_start + 1);
//   if (addr_start == -1 || addr_end == -1) {
//     Serial.print("Invalid request: ");
//     Serial.println(req);
//     return;
//   }
//   req = req.substring(addr_start + 1, addr_end);
//   Serial.print("Request: ");
//   Serial.println(req);
//   client.flush();

//   String s;
//   if (req == "/") {
//     IPAddress ip = WiFi.localIP();
//     s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>sybau</html>\r\n\r\n";
//     if (squirtTimerActive) {
//       squirtTimerActive = false;
//       Serial.println("Timer STOPPED!");
//     }
//   } else if (req == "/timer") {
//       s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>TIME STARTED GO GO GO!</html>\r\n\r\n";
//       if (not squirtTimerActive) {
//         squirtTimerActive = true;
//         squirtTimerStart = millis();
//         Serial.println("Timer Started!"); 
//       }
//   } else {
//     s = "HTTP/1.1 404 Not Found\r\n\r\n";
//     Serial.println("Sending 404");
//   }
//   client.print(s);

//   Serial.println("Done with client");
// }
