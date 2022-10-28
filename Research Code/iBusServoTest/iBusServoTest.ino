// Include Libraries
#include <IBusBM.h>
#include <Servo.h>

IBusBM ibus;  // Create iBus Object
Servo rmotor; //Create right motor
Servo lmotor;

int rmotorval;  // Var iable to read value from (analog pin)
int lmotorval;

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

void setup() {
  Serial.begin(115200); // Start serial monitor
  ibus.begin(Serial1);  // Attach iBus object to serial port

  rmotor.attach(9);
  lmotor.attach(10);
}

void loop() {
  int value1 = readChannel(1, -100, 100, 0); // Read channel 1
  int value2 = readChannel(3, -100, 100, 0); // Read channel 2

  rmotorval = map(value1, -100, 100, 0, 180);
  lmotorval = map(value2, -100, 100, 0, 180);

  if (rmotorval > 159) {
    rmotor.write(159);
    rmotor.write(159);  }
  if (rmotorval < 30)  {
    rmotor.write(30);
    lmotor.write(30); }
  if (rmotorval >= 30 && rmotorval <= 159)  {
    rmotor.write(rmotorval);
    lmotor.write(rmotorval);  } 

  
  delay(10);
}
