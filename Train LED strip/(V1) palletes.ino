



// This function filles in each individual LED
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  // uint8_t brightness = 10; // MADE THIS INTO GLOBAL
  if(lidarReturn < 51)
      {
        brightness = lidarReturn * 5;
        DIRECTION = 2;
      // uint8_t brightness =  brightness2; 
        Serial.println(brightness);
        // if(brightness > 250)
        //   {
        //     brightness = 0;
        //   }
        // brightness = brightness + 1;
        if(lidarReturn < 10)
        {
          brightness = 45;
          
        }
      }
    else if(lidarReturn > 51)
    {
      brightness = 250;
      DIRECTION = 1;
    }
    else if(OPPOSITE_BRIGHT == 1)
    {
      DIRECTION = 2;
      brightness = 250;
    }
  if (DIRECTION == 1)
  {
    for(int i = (NUM_LEDS)-1; i >= 0; i--) //Code to go other direction
      // for ( int i = 0; i < NUM_LEDS; i++) 
      {
    
    // Ad if statement here to adjust light brightness with ULTRASONIC sensor
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
      }
  }
  else if (DIRECTION == 2)
  {
    for ( int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
      colorIndex += 3;
    }
  }
  
  
}



// Based on time, the color functions will be called


void ChangePalettePeriodically()
{
  uint8_t secondHand = (millis() / 1000) % 20;  // This repeats after 20 seconds  
  static uint8_t lastSecond = 99;

  if ( lastSecond != secondHand) {
    lastSecond = secondHand;

    
    // if( secondHand ==  0)     { SetupPurpleAndGreenPalette();}   // Calling the purple function
    // if( secondHand ==  10)    {Christmas();}  // Non blend function
    // if( secondHand == 5) {Easter();} // Some Easter colors
    // if( secondHand == 5) {June();} // Some June colors
    if( DIRECTION == 1) {USA();} // Some June colors
    if(DIRECTION == 2)  {Ukraine();}
    // if( secondHand ==  0)  { currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND; }
    // if( secondHand == 10)  { currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;  }
    // if( secondHand == 15)  { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }
    // if( secondHand == 20)  { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
    // if( secondHand == 25)  { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
    // if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
    // if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
    // if( secondHand == 12)  { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }
    // if( secondHand == 45)  { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
    // if( secondHand == 50)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
    // if( secondHand == 55)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }
  }
}


// This function sets up a palette of purple and green stripes.
void SetupPurpleAndGreenPalette()
{
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;
  CRGB white  = CRGB::White;

  currentPalette = CRGBPalette16(
                     green,  green,  black,  black,
                     purple, purple, black,  black,
                     green,  green,  black,  black,
                     purple, purple, black,  black );
}
// 137, 207, 240
// Pink CRGB babyBlue = CHSV( 4, 124, 200);
void Valentine()
{
  CRGB babyBlue = CHSV( 255, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;
  CRGB white  = CRGB::White;
  CRGB hotPink = CRGB::HotPink;
  CRGB pink = CRGB::Pink;
  CRGB red = CRGB::DeepPink;
  
  currentPalette = CRGBPalette16(
                     red,  red,  black,  black,
                     hotPink, hotPink, black,  black,
                     red,  red,  black,  black,
                     hotPink, hotPink, black,  black );
}

//                                  GREAT APRIL COLOR CRGB::LightSeaGreen

void stPatrick()
{
  CRGB ForestGreen = CRGB::Yellow;
  CRGB green = CRGB::Green;
  CRGB black  = CRGB::Black;
  
  currentPalette = CRGBPalette16(
                     green,  green,  black,  black,
                     ForestGreen, ForestGreen, black,  black,
                     green,  green,  black,  black,
                     ForestGreen, ForestGreen, black,  black );
                     
  currentBlending = LINEARBLEND; 
}

void Christmas()
{
  CRGB red = CRGB::Red;
  CRGB green = CRGB::Green;
  CRGB black  = CRGB::Black;
  
  currentPalette = CRGBPalette16(
                     green,  green,  black,  black,
                     red, red, black,  black,
                     green,  green,  black,  black,
                     red, red, black,  black );
                     
  currentBlending = LINEARBLEND; 
}
void Easter()
{
  // CRGB ForestGreen = CRGB::Yellow;
  // CRGB::LightCyan;  // LightCyan is actually a peachy color
  CRGB color1 = CRGB:: Yellow;
  CRGB color2  = CRGB::MediumPurple;
  CRGB color3 = CRGB::LightSeaGreen;  // This is the realy cyan!!!
  CRGB black  = CRGB::Black;
  
  currentPalette = CRGBPalette16(
                     color1,  color1,  black,  black,
                     color2, color2, black,  black,
                     color3,  color3,  black,  black,
                     color1, color2, black,  black );
                  
                     
  currentBlending = LINEARBLEND; 
}

void June()
{
  // CRGB ForestGreen = CRGB::Yellow;
  // CRGB::LightCyan;  // LightCyan is actually a peachy color
  CRGB color1 = CRGB:: Purple;  
  CRGB color2  = CRGB( 230, 230, 0);  // Cream yellow
  CRGB color3 = CRGB(0,255,50);  // Lime
  CRGB black  = CRGB::Black;
  
  currentPalette = CRGBPalette16(
                     color1,  color1,  black,  black,
                     color2, color2, black,  black,
                     color3,  color3,  black,  black,
                     color1, color2, black,  black );
                  
                     
  currentBlending = LINEARBLEND; 
}
// DO NOT COPY THIS!   Its only for USA 
void USA()
{
  // CRGB ForestGreen = CRGB::Yellow;
  // CRGB::LightCyan;  // LightCyan is actually a peachy color
  CRGB color1 = CRGB:: Red;  
  CRGB color2  = CRGB:: White;  // Cream yellow
  CRGB color3 = CRGB:: Blue;  // Lime
  CRGB black  = CRGB::Black;
  
  currentPalette = CRGBPalette16(
                     color1,  color1,  color3,  black,
                     color1, color2, color3,  black,
                     color1,  color2,  color3,  black,
                     color1, color2, color3,  black );
                  
                     
  currentBlending = LINEARBLEND; 
}
// DO NOT COPY THIS!   Its only for UKRAINE 
void Ukraine()
{
  // CRGB ForestGreen = CRGB::Yellow;
  // CRGB::LightCyan;  // LightCyan is actually a peachy color
  CRGB color1 = CRGB:: Blue;  
  CRGB color2  = CRGB:: Yellow;  
  CRGB color3 = CRGB:: Black;  
  CRGB black  = CRGB::Black;
  
  currentPalette = CRGBPalette16(
                     color1,  color2,  color3,  black,
                     color1, color2, color3,  black,
                     color1,  color2,  color3,  black,
                     color1, color2, color3,  black );
                  
                     
  currentBlending = LINEARBLEND; 
}


