/*
 Science Hack!
 */

int heartPin = A7;
int heartSignal = 0;

int skinPin = A5;
int skinSignal = 0;

void setup() {
  Serial.begin(19200);
}

void loop() {
  heartSignal = analogRead(heartPin);
  //skinSignal = analogRead(skinPin);  

  byte msbHeartSignal = heartSignal>>8;  
  byte lsbHeartSignal = heartSignal&255;
  
  Serial.write(msbHeartSignal);
  Serial.write(lsbHeartSignal);
  
  //Serial.print("Skin " + String(skinSignal) + ";");
  //Serial.print("\n");
}
