// Biblioteca

#include <LiquidCrystal.h>
#include <Ultrasonic.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Ultrasonic ultrasonic(12, 13);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Distancia =");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int distancia = ultrasonic.distanceRead();
  
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    delay(1000);
}
