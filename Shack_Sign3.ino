#include <Adafruit_NeoPixel.h>

// set to pin connected to data input of WS8212 (NeoPixel) strip
#define PIN         0

// any pin with analog input (used to initialize random number generator)
#define RNDPIN      2

// number of LEDs (NeoPixels) in your strip
// (please note that you need 3 bytes of RAM available for each pixel)
#define NUMPIXELS   12

// max LED brightness (1 to 255) – start with low values!
// (please note that high brightness requires a LOT of power)
#define BRIGHTNESS  255

// decrease to speed up, increase to slow down flicker
#define DELAY       50

// decrease to speed up, increase to slow down color change
#define CYCLES      20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // initialize pseudo-random number generator with some random value
  randomSeed(analogRead(RNDPIN));
  
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  theaterChase(strip.Color(255, 0, 0), DELAY); // Red
  theaterChase(strip.Color(127, 127, 127), DELAY); // White
  theaterChase(strip.Color(0, 0, 255), DELAY); // Blue
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<CYCLES; j++) {
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
