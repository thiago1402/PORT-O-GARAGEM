int botao = 2;
int estadoBotao = LOW;


void setup() {
  // put your setup code here, to run once:
pinMode (botao , INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoBotao = digitalRead (botao);
  if (estadoBotao == HIGH){
    Serial.println("aqui");
  }
}
