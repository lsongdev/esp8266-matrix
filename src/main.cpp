#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <FastLED_NeoMatrix.h>
#include <FastLED.h>
#include <Fonts/TomThumb.h>

#define LED_PIN D2
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 8
#define NUM_LEDS (MATRIX_WIDTH * MATRIX_HEIGHT)
#define TOMTHUMB_USE_EXTENDED 1

CRGB leds[NUM_LEDS];
FastLED_NeoMatrix *matrix;

const char text[] = "Hello World!";
int16_t offset = MATRIX_WIDTH;

void setup() {
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    matrix = new FastLED_NeoMatrix(
        leds,
        MATRIX_WIDTH,
        MATRIX_HEIGHT,
        NEO_MATRIX_TOP +
        NEO_MATRIX_LEFT +
        NEO_MATRIX_COLUMNS +
        NEO_MATRIX_ZIGZAG
    );

    matrix->begin();
    matrix->setTextWrap(false);
    matrix->setBrightness(30);
    matrix->setFont(&TomThumb);
    matrix->setTextColor(matrix->Color(255, 0, 255));
}

void loop() {
    matrix->clear();
    matrix->setCursor(offset, 6);
    matrix->print(text);
    matrix->show();
    
    offset--;
    
    int16_t textWidth = strlen(text) * 3;
    if (offset < -textWidth) {
        offset = MATRIX_WIDTH;
    }
    
    delay(100);
}