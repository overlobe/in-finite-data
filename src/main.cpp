#include <Arduino.h>
#include <WiFi.h>

// WiFi credentials - update these with your network details
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// LED pin (built-in LED on most ESP32 boards)
#define LED_PIN 2

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(1000);

  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("\n\n=== ESP32 WiFi Example ===");
  Serial.print("Chip Model: ");
  Serial.println(ESP.getChipModel());
  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());
  Serial.print("Flash Size: ");
  Serial.println(ESP.getFlashChipSize());

  // Connect to WiFi
  Serial.print("\nConnecting to WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Blink while connecting
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Signal Strength (RSSI): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
    digitalWrite(LED_PIN, HIGH); // LED on when connected
  } else {
    Serial.println("\nFailed to connect to WiFi");
    digitalWrite(LED_PIN, LOW);
  }
}

void loop() {
  // Print WiFi status every 10 seconds
  static unsigned long lastCheck = 0;

  if (millis() - lastCheck > 10000) {
    lastCheck = millis();

    if (WiFi.status() == WL_CONNECTED) {
      Serial.print("WiFi Status: Connected | IP: ");
      Serial.print(WiFi.localIP());
      Serial.print(" | RSSI: ");
      Serial.print(WiFi.RSSI());
      Serial.println(" dBm");
    } else {
      Serial.println("WiFi Status: Disconnected");
      // Try to reconnect
      WiFi.reconnect();
    }
  }

  // Blink LED to show the board is running
  static unsigned long lastBlink = 0;
  if (millis() - lastBlink > 1000) {
    lastBlink = millis();
    if (WiFi.status() == WL_CONNECTED) {
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    }
  }
}
