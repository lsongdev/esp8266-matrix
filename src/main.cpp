#include <Arduino.h>
#include <Adafruit_GFX.h>

#include <FastLED_NeoMatrix.h>
#include <FastLED.h>
#include <Fonts/TomThumb.h>

#define LED_PIN D2       // LED 数据线引脚
#define MATRIX_WIDTH 32  // 矩阵宽度
#define MATRIX_HEIGHT 8  // 矩阵高度
#define NUM_LEDS (MATRIX_WIDTH * MATRIX_HEIGHT)

// Matrix Settings
CRGB leds[NUM_LEDS];
FastLED_NeoMatrix *matrix;

void setup()
{
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
	matrix->clear();
	matrix->setTextColor(matrix->Color(255, 0, 255));
	matrix->setCursor(0, 6);
	matrix->print("hello");
	matrix->show();
}

void loop()
{
}
