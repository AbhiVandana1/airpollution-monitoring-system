#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int pin8 = 8;
int analogPin = A0;
int sensorValue = 0;
void setup() {
  pinMode(analogPin, INPUT);
  pinMode(pin8,OUTPUT);
  lcd.begin(16,2);
  lcd.print("What is the air");
  lcd.print("quality today?");
  Serial.begin(9600);
  lcd.display();
}
void loop() {
  delay(1000);
  sensorValue = analogRead(analogPin);
  Serial.print("Air Quality in PPM:");
  Serial.println(sensorValue);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("Air Quality: ");
  lcd.print (sensorValue);

  if (sensorValue<=500)
   {
   serial.print("Fresh Air ");
   serial.print ("\r\n");
   lcd.setCursor(0,1);
   lcd.print("Fresh Air");
   }
else if ( sensorValue>=500 && sensorVlue<=650 )
 {
 Serial.print("Poor Air");
 Serial.print ("\r\n");
 lcd.setCursor(0,1);
 lcd.print("Poor Air");
 }
else if (sensorValue>=650)
 {
 Serial.print("Very Poor Air");
 Serial.print ("r\n");
 lcd.setCursor(0,1);
 lcd.print("Very Poor Air");
 }
 if (sensorValue >650) {
    digitalWrite(pin8,HIGH);
}
else {
   digitalWrite(pin8, LOW);
}
}
