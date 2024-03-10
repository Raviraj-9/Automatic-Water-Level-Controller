#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int trigpin=2;
int echopin=3;
int led =7;
int relaypin=13;

void setup(){
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
	pinMode(led,OUTPUT);
	pinMode(trigpin,OUTPUT);
	pinMode(echopin,INPUT);
}
void loop(){
long dur,dist;
  digitalWrite(trigpin,HIGH);
  delay(1000);
  digitalWrite(trigpin,LOW);
  dur=pulseIn(echopin,HIGH);
  dist=(dur*0.034)/2;
  Serial.print(dist);
  Serial.println("cm");
  
  lcd.setCursor(0,0);
	lcd.print("Object");
  lcd.setCursor(0,1);
  lcd.print("Distance : ");
  lcd.print(dist);
  lcd.print("cm   ");
  delay(1000);
}