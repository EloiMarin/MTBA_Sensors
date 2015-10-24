/*
 Science Hack!
 */

int heartPin = A7;
int heartSignal = 0;

void setup() {
  Serial.begin(19200);
}

void loop() {
  heartSignal = analogRead(heartPin);
  
  Serial.print("Heart " + String(heartSignal) + ";");
  Serial.print("\n");
}
