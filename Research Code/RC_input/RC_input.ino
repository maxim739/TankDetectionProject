
const int THR_PIN = 9;
int angle;
int THR;
#include <Servo.h>
Servo myServo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(11);
}

void loop() {

int pulse1 = pulseIn(THR_PIN, HIGH, 48000);
int pulse2 = pulseIn(THR_PIN, HIGH, 48000);
int pulse3 = pulseIn(THR_PIN, HIGH, 48000);
int pulse4 = pulseIn(THR_PIN, HIGH, 48000);

THR = (pulse1 + pulse2 + pulse3 + pulse4) / 4;
Serial.println(pulse1);
Serial.println(pulse2);
Serial.println(pulse3);
Serial.println(pulse4);
//Serial.println(THR);
if (THR > 1100)
angle = map(THR, 1150, 1930, 0, 179);

else 
angle = 90;

myServo.write(angle);
Serial.println(angle);

Serial.println(" ");
//delay(5000);
}


