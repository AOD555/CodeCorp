void photoresistor()
{
  Serial.flush();// Flush everything before getting analog read
  delay(1000);
  light = analogRead(photoPin);
  Serial.print(" The light level is ");
  Serial.println(light);
  // Serial.write(light);
  delay(100);

}
void resetHBridge()
{

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
	
	delay(1000);
}
const unsigned int MAX_MESSAGE_LENGTH = 10;
const unsigned int size = "";
static char message[MAX_MESSAGE_LENGTH];
char zero_pos_byte = size;
char l = 'l';  // This checks if we want to check for the light level photoresistor
void hidserver_Read()
  {
    
    int i = 0;
    // photoresistor();
    
    while (!Serial.available());
    delay(100);   // VERY IMPORTANT to give time to read all the write commands from python
    zero_pos_byte = Serial.read();
    
    if(zero_pos_byte == l)
    {
      // Serial.flush();
      photoresistor();
      
    }
    else if (trigger == 0 && zero_pos_byte != 'l')
    {
      // resetting the values to zero
      // array[0] = 0;
      // array[1] = 0;
      delay(100);
      message[0] = zero_pos_byte;
      for(i = 1; i < 4 ; i++)
      {

        char inByte = Serial.read();
        if(inByte == '\n')
        {
          trigger = 1;
          break;
        }
        else
        {
          message[i] = inByte;        // The 'i' is the position the byte is moving into. The posiions for Sub are S -> 1 u -> 2 b -> 3
        }
        
        
      }
      message[i] = '\0';
      int number = atoi(message);   // Converts string input to int
      array[0] = number;
      
      if(array[0] > 255){array[0] = 255;}
      firstLight = array[0];
      
      
      
      delay(100);
    }
    
    
    else if (trigger == 1 && zero_pos_byte != 'l')
    {
      // array[0] = 0;
      message[0] = zero_pos_byte;
      for(i = 1; i < 4 ; i++)
      {
        char inByte = Serial.read();
        if(inByte == '\n')
        {
          trigger = 0;
          Serial.flush();
          break;
        }
        else
        {
          message[i] = inByte;        // The 'i' is the position the byte is moving into. The posiions for Sub are S -> 1 u -> 2 b -> 3
        }
        
        
      }
      message[i] = '\0';
      int number = atoi(message);   // Converts string input to int
      array[1] = number;
      
      if(array[1] > 255){array[1] = 255;}
      secondLight = array[1];
      
      delay(100);
      
    }
    
    
 
    
   
  }
  

// This function lets you control direction of PWM waves
void directionControl(int input) {
// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 255);
	analogWrite(enB, 255);

	// Turn on Light A & B via H bridge 
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);  
	Serial.println("\nChanging direction\n"); // Changing PWM direction
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}

// This function will set the light level according to the input
void lightControl(int input) {
	// Turn on Lights via H bridge
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

  
	analogWrite(enA, firstLight);
	analogWrite(enB, secondLight);
// 	Serial.println(firstLight);
// 	Serial.println(secondLight);
}
