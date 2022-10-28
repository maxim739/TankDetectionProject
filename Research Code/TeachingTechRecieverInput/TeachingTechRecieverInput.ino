int ch1,ch2,ch3,ch4;
const int in1 = A0, in2 = A1, in3 = A2, in4 = A3;
 
void setup() {
  Serial.begin(9600);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
}
 
void loop() {
  ch1 = pulseIn(in1, HIGH, 35000); 
  ch2 = pulseIn(in2, HIGH, 35000);
  ch3 = pulseIn(in3, HIGH, 35000);
  ch4 = pulseIn(in4, HIGH, 35000);
 
  Serial.print("1: ");
  Serial.print(ch1);
  Serial.print(", 2: ");
  Serial.print(ch2);
  Serial.print(", 3: ");
  Serial.print(ch3);
  Serial.print(", 4: ");
  Serial.println(ch4);
}
