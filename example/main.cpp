#include <Arduino.h>
#include <SmartLED.h>

SmartLED SLED;

void setup() {
  Serial.begin(115200);
  SLED.set(SLED_Init);
  delay(1000);
}

void loop() {
  SLED.set(SLED_Run);
  delay(1000);
  SLED.set(SLED_Error);
  delay(1000);
  Serial.println("reset");
}