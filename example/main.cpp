#include <Arduino.h>
#include <SmartLED.h>
SmartLED SLED;
/*
SmartLED SLED; (#includeの上あたりに書く)
set関数
  SLED.set(SLED_Init); // 初期化LED  (黄色)
  SLED.set(SLED_Run);  // 実行LED    (緑色)
  SLED.set(SLED_Run);  // エラーLED  (赤色)
setColor関数
  SLED.setColor(R,G,B);       //それぞれ255までの値
  SLED.setColor(255,0,0);     // 赤色
  SLED.setColor(0,255,0);     // 緑色
  SLED.setColor(0,0,255);     // 青色
  SLED.setColor(255,255,255); // 白色

*/
void setup() {
  Serial.begin(115200);
  SLED.set(SLED_Init);            //初期化LED(黄色)
  delay(1000);
}

void loop() {
  SLED.set(SLED_Run);             // 実行LED(緑色)
  Serial.println("run(green)");
  delay(1000);
  SLED.setColor(0, 0, 255);       // 任意LED(青色)
  Serial.println("blue");
  delay(1000);
  SLED.setColor(255, 255, 255);   // 任意LED(白色)
  Serial.println("white");
  delay(1000);
  Serial.println("reset");
}