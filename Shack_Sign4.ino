#include <DigiUSB.h> //Must reduce RING_BUFFER_SIZE define to 64!
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
#define BRIGHTNESS  128

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t color = strip.Color(0, 0, 0);

void setup() {
  DigiUSB.begin();
  // initialize pseudo-random number generator with some random value
  randomSeed(analogRead(RNDPIN));
  
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Initialize all pixels to 'off'  
}

void loop() {
  
  if (DigiUSB.available()) {
    // something to read
    char ch = DigiUSB.read();

    if (ch >= '0' && ch <= '9')
      color = color * 10 + ch - '0';
    else {

      for( int i = 0; i<NUMPIXELS; i++){
        strip.setPixelColor(i, color);
      }
  
      strip.show();
      color = strip.Color(0, 0, 0);
    }
  }
      
  DigiUSB.delay(10);
}
