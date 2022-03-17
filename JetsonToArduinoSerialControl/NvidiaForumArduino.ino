int data1;
int data2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    delay(10);
    data1 = Serial.readStringUntil(' ').toInt();
    data2 = Serial.readStringUntil(' ').toInt();
    delay(10);
    Serial.print("\nReceived Data:");
    Serial.print(data1, data2);
  }
}
