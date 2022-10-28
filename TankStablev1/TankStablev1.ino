#include <Servo.h>

Servo mright;
Servo mleft;

int fval;
int sval;
int rval;
int lval;
int turnright;
int turnleft;

// Define Input Connections
#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9


// Integers to represent values from sticks and pots
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value; 


// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

void setup(){
  // Set up serial monitor
  Serial.begin(115200);

  mright.attach(10);
  mleft.attach(11);
  
  // Set all pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
}


void loop() {
  
  // Get values for each channel
  ch1Value = readChannel(CH1, -100, 100, 0);
  ch2Value = readChannel(CH2, -100, 100, 0);
  ch3Value = readChannel(CH3, -100, 100, -100);
  ch4Value = readChannel(CH4, -100, 100, 0);

  fval = map(ch1Value, -100, 100, 30, 150);
  sval = map(ch3Value, -100, 100, 150, 30);

// This is for setting the starting throttle values for each motor
    rval = fval;
    lval = fval;

// Here convert ch4 to sideways steering
  if (sval < 90) {
    rval = (rval - (sval - 90));  }   // Turn right - decrease right motor
  if (sval > 90)  {
    lval = (lval - (90 - sval));  }   // Turn left - decrease left motor

  mright.write(rval);
  mleft.write(lval);
  
  // Print to Serial Monitor
  /*Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print(" | Ch2: ");
  Serial.print(ch2Value);
  Serial.print(" | Ch3: ");
  Serial.print(ch3Value);
  Serial.print(" | Ch4: ");
  Serial.print(ch4Value);
  Serial.print(" Vals: Rval-");
  Serial.print(rval);
  Serial.print(": Lval-");
  Serial.println(lval);
*/
 Serial.print("Ch1 ");
 Serial.print(ch1Value);
 Serial.print(" Ch3 ");
 Serial.print(ch3Value);
 Serial.print(" Fval ");
 Serial.print(fval);
 Serial.print(" Sval ");
 Serial.print(sval);
 Serial.print(" Rval ");
 Serial.print(rval);
 Serial.print(" Lval ");
 Serial.println(lval);
  
 delay(10);
}
