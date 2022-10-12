void buttonPressed()
{
  int stateButton = digitalRead(pinButton);
    if(stateButton == 1 && LED_STATE == 1) 
    {
      
    // Serial.println("PRESSED");
      Serial.print("The LED_STATE IS ");
      Serial.println(LED_STATE);
      LED_STATE += 1;
      // Add if statement here to see if we are in a test, and if we are not, do the delay. 
      delay(500);
    }
  else if(stateButton == 1 && LED_STATE >= 2) 
  
  { 
    Serial.println("PRESSED");
    Serial.print("The LED_STATE IS ");
    Serial.println(LED_STATE);
    LED_STATE += 1;
    if(LED_STATE > 7)
    {
      LED_STATE = 1;
    }
    delay(500);
  }
}
void fade()
{
  for(int i = 0; i < NUM_LEDS; i++) 
  {
    leds[i].nscale8_video( 256);
  }
}
void serial_checking()
{
  if (Serial.available() > 0)
    {
      // leds[0] = CRGB::Black;
      
      // speed_input = Serial.read();
      // Serial.println(" Serial Function is being called");
      speed_input = Serial.parseInt();    // parse int data
      // speed_input_string = Serial.readString();
      // speed_input = speed_input_string.toInt();

      //Do something with the data - like print it
      Serial.println(speed_input);
      if(speed_input == 1)
      {
        // LED_STATE = speed_input;
        LED_STATE = 1;
      }
      else{LED_STATE = 1;}
    }
}

void tracking()
{
  for(int i = 0; i < NUM_LEDS; i++) // Picks out the spot of i LED
  {
    buttonPressed();
    
    Serial.println(stateButton);
    // buttonPressed();
 
    for(int c = 0; c < 7; c++) // This is for the loop of lights up each of the 7 leds after i
    {
      
        leds[i + c] = CRGB::Cyan; 
        leds[236] = CRGB::Pink; 
        leds[207] = CRGB::Pink;
        
      
      
    }
    
    
    
    // second light tracking code
    int LESS_LED = NUM_LEDS-20;
    if(i < LESS_LED)
    {
      int cart = i + 10;
      for(int j = 0; j < 10; j++)
      {
        if(i + j > 224)
          {
            leds[i+j]= CRGB::Black;
            // Serial.println(i);
          }
        else{leds[cart+j] = CRGB::Red;}
      }
      
      
      // code for 3rd tracking is inside this if statement
      cart = i + 21;                            // i is the inital start point. so i + 21 is the start point of green
      for(int k = 0; k < 9; k++)
        {
          if(i + k > 215)
          {
            leds[i+k]= CRGB::Black;
            // Serial.println(i);
          }
          else if(LED_STATE ==10) // This number needs to change when we work on transision
          {
            int endingCart = cart + 228; 
            leds[endingCart + k] = CRGB::Blue;  // This should extend the end of the loop, but it breaks.
            
            leds[cart+k] = CRGB::Blue;
            
            if(i + 215 == 236)
            {
              LED_STATE =1;
            }
            
          }
          else{leds[cart+k] = CRGB::Green;}
          
          
        }
      if(i == 207)
      {
        Serial.print("The LED_STATE IS ");
        Serial.println(LED_STATE);
        if(LED_STATE == 2)
        {
          break;
        }
        i = 0;
        Serial.println("i is zero");
        serial_checking();  // Check for Serial input
        
        // if(LED_STATE == 2 )
        // {
        //   green_end_transision();
        //   // break;
        // }
        
      }
        // Serial.println(i);
      
    
    
  }
    
    // code for second LED strip lights
    // second_LEDS[i] = CRGB::Cyan;
    // second_LEDS[i+1] = CRGB::Cyan;
    
    // firstExtended(i);
    // second_tracking(i);
    // third_tracking(i);
    
    FastLED.show();
		fade();
		delay(speed_input);
		// Serial.println(speed_input);
  }
}
