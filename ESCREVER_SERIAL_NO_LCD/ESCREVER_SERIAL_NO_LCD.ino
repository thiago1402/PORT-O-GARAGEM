// Biblioteca

#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

}

void loop() {
  
  
  // put your main code here, to run repeatedly:
  if lcd.begin(16, 2);{
  lcd.print("Hello Word");
  
  (Serial.available() > 0) {
    String mensagem = Serial.readString();
    for (int posicao = 0 ;  posicao < 16 ; posicao++) {
      lcd.scrollDisplayLeft();
      lcd.setCursor(0, 1);
      lcd.print(mensagem);
      delay(250);
    }
  }
  for (int posicao = 0 ;  posicao < 1 ; posicao++) {
    lcd.print("");
    lcd.setCursor(0, 1);
    delay(10);
  }
}

