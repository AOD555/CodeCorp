
#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    300
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100

// libraries for lidar
#include <Wire.h>
#include <LIDARLite.h>

LIDARLite myLidarLite;

float lidarReturn = 0;
uint8_t brightness = 250;  // THis was originally in pallets
int DIRECTION = 1; //  1 is forward, 2 is backwards
int OPPOSITE_BRIGHT = 1;

// Other libraries
#include <math.h>


// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.


// variables for palletes
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;                         // Calling an external variable and labeling something else?
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
  
  // lidar setup
  Serial.begin(9600);
  myLidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  myLidarLite.configure(0); // Change this number to try out alternate configurations
  
  
  
}


void loop()
{
  ChangePalettePeriodically();

  // static uint8_t startIndex = 0;
  static float startIndex = 0;  // this allows us to slow the speed below 1*
  startIndex = startIndex + 1; /* motion speed */
  Serial.println(startIndex);
  
  
  FillLEDsFromPaletteColors( startIndex);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
  lidar();
}

