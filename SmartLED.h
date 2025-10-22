#pragma once
#include <Adafruit_NeoPixel.h>

#define SLED_NUMPIXELS  1
#define SLED_BRIGHTNESS 20

enum SmartLEDState {
    SLED_Init,
    SLED_Error,
    SLED_Run
};

class SmartLED {
public:
    SmartLED() : _pixels(SLED_NUMPIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800), _state(SLED_Init) {
        #if defined(NEOPIXEL_POWER)
            pinMode(NEOPIXEL_POWER, OUTPUT);
            digitalWrite(NEOPIXEL_POWER, HIGH);
        #endif
        _pixels.begin();
        _pixels.setBrightness(SLED_BRIGHTNESS);
        update();
    }

    void set(SmartLEDState state) {
        _state = state;
        update();
    }

    void setColor(uint8_t red, uint8_t green, uint8_t blue) {
        _pixels.fill(_pixels.Color(red, green, blue));
        _pixels.show();
    }

private:
    Adafruit_NeoPixel _pixels;
    SmartLEDState _state;

    void update() {
        uint32_t color = 0;
        switch (_state) {
            case SLED_Init:  color = _pixels.Color(255, 255, 0); break;
            case SLED_Error: color = _pixels.Color(255, 0, 0); break;
            case SLED_Run:   color = _pixels.Color(0, 255, 0); break;
        }
        _pixels.fill(color);
        _pixels.show();
    }
};
