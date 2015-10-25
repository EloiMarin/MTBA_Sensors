/*
 Science Hack!
 */

int skinPin = A0;
int skinSignal = 0;

void setup() {
  Serial.begin(19200);
}

void loop() {
  skinSignal = analogRead(skinPin);  

  byte msbSkinSignal = skinSignal>>8;  
  byte lsbSkinSignal = skinSignal&255;
  
  Serial.write(msbSkinSignal);
  Serial.write(lsbSkinSignal);
}
