#include <LiquidCrystal.h>//include the library code
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int ledred = 8;//ledred connected to digital pin 8
int ledgreen = 7;//ledgreen connected to digital pin 7
void setup() {
  Serial.begin(9600);//setup serial
  lcd.begin(16, 2);//lcd sise
  pinMode(ledred, OUTPUT);//sets the digital pin as output
  pinMode(ledgreen, OUTPUT);//sets the digital pin as output
}
void loop() {
  float voltage = analogRead(A2);
  float Temp = voltage * 0.48828125;
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(Temp);
  lcd.print(" *C");
  
  if (Temp > 30)
  { digitalWrite(ledred, HIGH);//turns the ledred on
  lcd.setCursor(0, 1);
    lcd.print("warm");//show temp
  }
  else
  { digitalWrite(ledred, LOW);//turns the ledred off
    digitalWrite(ledgreen, HIGH);//turns the ledgreen on
    lcd.setCursor(0, 1);
    lcd.print("cold");//show temp
  }
  delay(2000);//waits for 2 seconds
  lcd.clear();//clear lcd
}
