#include <Arduino.h>
#include <WiFi.h>

/*
 * ESP32 WiFi Scanner Example
 * Scans for available WiFi networks and displays them
 * To use: copy this file to src/main.cpp
 */

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n=== ESP32 WiFi Scanner ===");

  // Set WiFi to station mode and disconnect from any AP
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("WiFi Scanner initialized");
}

void loop() {
  Serial.println("\n\n--- Scanning for WiFi networks ---");

  // Start WiFi scan
  int n = WiFi.scanNetworks();

  Serial.println("Scan complete!");

  if (n == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found:");
    Serial.println("-------------------------------------------");
    Serial.println("Nr | SSID                  | RSSI | Channel | Encryption");
    Serial.println("-------------------------------------------");

    for (int i = 0; i < n; ++i) {
      // Print network number
      Serial.printf("%2d", i + 1);
      Serial.print(" | ");

      // Print SSID
      String ssid = WiFi.SSID(i);
      Serial.print(ssid);
      for (int j = ssid.length(); j < 20; j++) {
        Serial.print(" ");
      }
      Serial.print(" | ");

      // Print RSSI (signal strength)
      Serial.printf("%4d", WiFi.RSSI(i));
      Serial.print(" | ");

      // Print channel
      Serial.printf("%7d", WiFi.channel(i));
      Serial.print(" | ");

      // Print encryption type
      switch (WiFi.encryptionType(i)) {
        case WIFI_AUTH_OPEN:
          Serial.print("Open");
          break;
        case WIFI_AUTH_WEP:
          Serial.print("WEP");
          break;
        case WIFI_AUTH_WPA_PSK:
          Serial.print("WPA-PSK");
          break;
        case WIFI_AUTH_WPA2_PSK:
          Serial.print("WPA2-PSK");
          break;
        case WIFI_AUTH_WPA_WPA2_PSK:
          Serial.print("WPA/WPA2-PSK");
          break;
        case WIFI_AUTH_WPA2_ENTERPRISE:
          Serial.print("WPA2-Enterprise");
          break;
        default:
          Serial.print("Unknown");
      }

      Serial.println();
      delay(10);
    }
  }

  Serial.println("-------------------------------------------");

  // Wait 5 seconds before next scan
  Serial.println("\nWaiting 5 seconds before next scan...");
  delay(5000);
}
