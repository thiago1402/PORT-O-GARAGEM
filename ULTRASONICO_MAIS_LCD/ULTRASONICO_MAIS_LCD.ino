// Biblioteca

#include <LiquidCrystal.h>
#include <Ultrasonic.h>

const int rs = 9, en = 8, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Ultrasonic ultrasonic(A1, A0);

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
