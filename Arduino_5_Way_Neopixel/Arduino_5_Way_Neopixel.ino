void setup() {
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(2) == LOW)
     Serial.println("Left");
  if (digitalRead(3) == LOW)
     Serial.println("Right");
  if (digitalRead(4) == LOW)
     Serial.println("Down");
  if (digitalRead(5) == LOW)
     Serial.println("Up");
  if (digitalRead(7) == LOW)
     Serial.println("Center");
     
     delay(200);
}
