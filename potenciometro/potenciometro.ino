int potenciometro = A0;
int valorPotenciometro = 0;
int buzer = 11;

void setup() {
Serial.begin (9600);
pinMode (buzer , OUTPUT);
}

void loop() {
  valorPotenciometro = analogRead (potenciometro);
  Serial.println (valorPotenciometro);
  tone (buzer , valorPotenciometro ,1000);
  
}
