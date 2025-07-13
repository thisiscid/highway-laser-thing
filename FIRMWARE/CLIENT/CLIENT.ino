#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";

void waitForserver() {
  HTTPClient http;

  while (true) {
    if (WiFi.status() == WL_CONNECTED) {
      http.begin("");

      int httpCode = http.GET();
      if (httpCode > 0) {
        Serial.printf("example.com is online! HTTP code: %d\n", httpCode);
        http.end();
        break; // meow~ we can exit setup now, it's online owo
      } else {
        Serial.printf("Failed to reach example.com: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.println("WiFi not connected... trying again nya~");
    }

    delay(5000); // wait a bit before retrying
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi! Checking if example.com is online... nya~");
  waitForServer()
}

void loop() {
  // uwu finally free to do whatever you want!
  Serial.println("Doing main loop things~ ✨");
  delay(5000);
}
