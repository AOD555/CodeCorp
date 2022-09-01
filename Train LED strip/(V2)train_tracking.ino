// Code for led tracking the train



// void second_tracking();
// This is constaly reading inputs from serial. Should work with Hidserver
void serial_checking()
{
  if (Serial.available() > 0)
    {
      // leds[0] = CRGB::Black;
      
      // speed_input = Serial.read();
      Serial.println(" Serial Function is being called");
      // speed_input = Serial.parseInt();    // parse int data
      speed_input_string = Serial.readString();
      speed_input = speed_input_string.toInt();

      //Do something with the data - like print it
      Serial.println(speed_input);
      if(speed_input == 1 || speed_input == 2)
      {
        DIRECTION = speed_input;
      }
      else{DIRECTION = 3;}
    }
}
void fade()
{
  for(int i = 0; i < NUM_LEDS; i++) 
  {
    leds[i].nscale8_video( 256);
  }
}

void third_tracking(int i_LED)
{
  int cart = i_LED + 21;
  int LESS_LED = NUM_LEDS-20;
  for(int k = 0; k < 9; k++)
    {
      leds[cart+k] = CRGB::Green;
    }
  if(i_LED > 207)
  {
    int current_cart = cart;
    current_cart = cart - 228;
    Serial.println(current_cart);
    for(int k = 0; k < 31;k++)
    {
      leds[current_cart] = CRGB::Green;
      // for(int kk = 0; kk < 10;kk++)
      // {
      //   leds[current_cart+k] = CRGB::Green;
      // }
    }
  }
  
}

void second_tracking(int i_LED)
{
  int LESS_LED = NUM_LEDS-20;
  if(i_LED < LESS_LED)
  {
    int cart = i_LED + 10;
    for(int j = 0; j < 10; j++)
    {
      leds[cart+j] = CRGB::Red;
    }
    
    // leds[cart] = CRGB::Red;
    // cart = cart +1;
    // leds[cart] = CRGB::Red;
    
    // cart = cart +10;
    // leds[cart] = CRGB::Red;
    // cart = cart +1;
    // leds[cart] = CRGB::Red;
  }
  
}
void firstExtended(int i_LED)
{
  leds[i_LED + 2] = CRGB::Cyan;
  leds[i_LED + 3] = CRGB::Cyan;
  leds[i_LED + 4] = CRGB::Cyan;
  leds[i_LED + 5] = CRGB::Cyan;
  leds[i_LED + 6] = CRGB::Cyan;
  
}

void tracking()
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    // leds[i].maximizeBrightness(255);
    leds[i] = CRGB::Cyan;
    leds[i+1] = CRGB::Cyan;
    firstExtended(i);
    second_tracking(i);
    third_tracking(i);
    
    FastLED.show();
		fade();
		delay(speed_input);
  }
}


