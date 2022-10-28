#include <Servo.h>

Servo mright; //right motor esc
Servo mleft;  //left motor esc

int rpot = A0;  //right pot
int lpot = A1;  //left pot
int rval;
int lval;

#include <IBusBM.h>
#include <SoftwareSerial.h>

IBusBM ibus;
SoftwareSerial nss(4, 5); // SoftwareSerial(rxPin, txPin // serial port for GPS Tx(4). // or connect other serial devices.

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

bool readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}




void setup() {
  mright.attach(10);
  mleft.attach(9);
  Serial.begin(115200); // Between Aruino and Computer
  nss.begin(115200);  // Between reciever and Arduino
}

void loop() {
  while (nss.available()) { // When data is avaliable in serial buffer
    
  // Cycle through first 5 channels and determine values
  // Print values to serial monitor
  // Note IBusBM library labels channels starting with "0"
    
    for (byte i = 0; i < 5; i++) {
    int value = readChannel(i, -100, 100, 0);
    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(value);
    Serial.print(" | ");  }
  
    rval = analogRead(rpot);
    lval = analogRead(lpot);
    rval = map(rval, 0, 1023, 0, 179);
    lval = map(lval, 0, 1023, 0, 179);

    if (rval > 150) {
      mright.write(150); }
    if (rval < 35) {
      mright.write(35); }
    if (lval > 150) {
      mleft.write(150); }
    if (lval < 35) {
      mleft.write(35); }
      else {
        mright.write(rval);
        mleft.write(lval); }

    Serial.print("Right motor: ");
    Serial.print(rval);
    Serial.print(" - Left motor: ");
    Serial.println(lval);

  
  }
}
