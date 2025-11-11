#include <Arduino.h>

/*
 * ESP32 Blink Example - The "Hello World" of embedded systems
 * Blinks the built-in LED on GPIO 2
 * To use: copy this file to src/main.cpp
 */

#define LED_PIN 2  // Built-in LED on most ESP32 boards

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n=== ESP32 Blink Example ===");
  Serial.print("LED Pin: GPIO ");
  Serial.println(LED_PIN);

  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Serial.println("LED ON");
  digitalWrite(LED_PIN, HIGH);   // Turn the LED on
  delay(1000);                   // Wait for 1 second

  Serial.println("LED OFF");
  digitalWrite(LED_PIN, LOW);    // Turn the LED off
  delay(1000);                   // Wait for 1 second
}
