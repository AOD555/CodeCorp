/*

*/
// Motor H Bridge connection A
int enA = 9;
int in1 = 8;
int in2 = 7;
//Motor H Bridge connection B
int enB = 3;
int in3 = 5;
int in4 = 4;


int x = -1 ;
int array[2];

int firstLight = 0;
int secondLight = 0;
int testing = 6;
String input1;
int input2 = 0;
void directionControl(int x);
void lightControl(int x);
void check(int x);

// setup for millis
int period = 1000;
unsigned long time_now = 0;
int trigger = 0;
int readSignal = 0;
int light = 0;      // Light level that is being read
String light_status;

// Interval is how long we wait
int interval=1000;
// Tracks the time since last event fired
unsigned long previousMillis=0;

int photoPin = A0;  // pin the read from the photoresistor
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
	
  // Serial turn on Has to be 115200for it to work, but if you add phototresistor it can be 9600
  Serial.begin(9600);  
  
  // Setup for reading items from hidserver
  Serial.setTimeout(1);
  pinMode(testing,OUTPUT);  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  

  
  
  hidserver_Read();
  lightControl(x);
  if (trigger == 0)
  {
    delay(2000);
    photoresistor();
  }
  
  
 
  
  
    
}














