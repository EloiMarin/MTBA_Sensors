/*
 Science Hack!
 */

int breathPin = A2;
int breathSignal = 0;

void setup() {
  Serial.begin(19200);
  Serial.write(123);
  delay(100);
}

void loop() {
  breathSignal = analogRead(breathPin);  
  
  byte msbBreathSignal = breathSignal>>8;  
  byte lsbBreathSignal = breathSignal&255;
  
  Serial.write(msbBreathSignal);
  Serial.write(lsbBreathSignal);
    
}
