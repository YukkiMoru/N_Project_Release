# NEOPIXEL サンプル

このプロジェクトは、Adafruit NeoPixelと自作SmartLEDライブラリを使い、LEDの状態（初期化中・エラー・実行中）を色で表示するサンプルです。

## 構成

- `src/main.cpp` : メインスケッチ
- `lib/SmartLED/SmartLED.h`, `SmartLED.h` : 状態表示用LEDライブラリ

## 依存関係
Adafruit NeoPixel@^1.15.1

## 動作概要

- 初期化中はLEDが黄色
- 実行中は緑
- エラー時は赤

## 使い方

1. 必要なライブラリ
    - [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
    - SmartLED（本リポジトリのhttps://github.com/YukkiMoru/N_Project_Release）
2. `platformio.ini` でボード・ライブラリを設定
3. `PIN_NEOPIXEL` を実際の配線に合わせて定義
4. PlatformIOでビルド＆書き込み

## main.cpp のポイント

```cpp
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
```

## SmartLEDライブラリについて

- `SLED.set(SLED_Init);` : 初期化中（黄色）
- `SLED.set(SLED_Run);` : データ出力中（緑）
- `SLED.set(SLED_Error);` : エラー（赤）

---

ご質問・不具合はIssueまでどうぞ。
