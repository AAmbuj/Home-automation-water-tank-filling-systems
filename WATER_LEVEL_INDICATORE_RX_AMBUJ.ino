#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//motor driver output
int in1=10;
//Variables
    void setup()
{
pinMode(in1,OUTPUT);
digitalWrite(in1,LOW);
lcd.begin(16, 2);
lcd.print("Water Level");
lcd.setCursor(0, 1);
lcd.print("Controller");
delay(5000);            
lcd.clear();
Serial.begin(9600);
}
void loop()
{
   if(Serial.available()>0) 
  {               
   int dataIn = Serial.parseInt();
  lcd.setCursor(0, 0);
  lcd.print("Level=");
  lcd.print(dataIn);
  lcd.print(" CM");
  if (dataIn > 70)
  {
     
  digitalWrite(in1,HIGH);
  lcd.setCursor(0, 1);
  lcd.print("MOTER ON");   
  }
    if (dataIn < 11)
  {
    
    digitalWrite(in1,LOW); 
    lcd.setCursor(0, 1);
    lcd.print("MOTOR OFF");     
  }
  delay(100);
  lcd.clear();
  }
   }
