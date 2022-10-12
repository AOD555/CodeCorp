#include <FastLED.h>
#include <math.h>

#define LED_PIN     3
#define SECOND_LED_PIN 5
#define NUM_LEDS    237 // 237 leds on strip plus 20 so we can properlly fade into the next loop and not crash the Arduino
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
CRGB second_leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100




CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


uint8_t brightness = 250;  // THis was originally in pallets
int LED_STATE = 1;          // Global variable to help determine the state we are in
const int pinButton = 8;    // // external Big Arduino Button


int speed_input = 25;      // Global variable determining speed input for train
int stateButton = 0;        // Global variable status for the button
String speed_input_string = "";


void setup() {
    delay( 3000 ); // power-up safety delay
    Serial.begin(9600);
    pinMode(pinButton, INPUT);
    Serial.println("set up initiated");
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, SECOND_LED_PIN, COLOR_ORDER>(second_leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    // attachInterrupt(digitalPinToInterrupt(2),buttonPressed1,RISING);  //  function for creating external interrupts at pin2 on Rising (LOW to HIGH)
    
    FastLED.setBrightness(  BRIGHTNESS );
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}

// void tracking(void);
// void serial_checking(void); 
void loop()
{
  
  
  
  if( LED_STATE == 1) 
    {
      // Serial.println("LED_STATE 3");
      // serial_checking();  // Check for Serial input
      tracking();
      
      // fade();
      // int value = analogRead(A0);
      // Serial.println("Analog Value: ");
      // Serial.println(value);
    }
  // else if(LED_STATE == 2)
  // {
  //   // endTracking();
  // }
  // else if(LED_STATE == 2)
  // {
  //   Serial.println("LED_STATE has changed");
  //   green_end_transision();
  // }
  else if(LED_STATE > 1 )
  {
    // stateButton = digitalRead(pinButton);
    buttonPressed();
    
  
  
      ChangePalettePeriodically();
      
      static uint8_t startIndex = 0;
      startIndex = startIndex + 1; /* motion speed */
      
      FillLEDsFromPaletteColors( startIndex);
      
      FastLED.show();
      FastLED.delay(1000 / UPDATES_PER_SECOND);
  }
   // delay(250);
    
}

