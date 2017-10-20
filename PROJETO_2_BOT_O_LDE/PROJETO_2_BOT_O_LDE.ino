  // variaveis 
  
  const int pinoled = 12 ;  // valor 0
  const int botao = 8;
  const int pinoled2 = 7;// valor 1 
  int estadoBotao = LOW;
  int ultimoaceso = 0;




  //o que cada pino se torna output / input
void setup() {
  // put your setup code here, to run once:
  pinMode (pinoled , OUTPUT);
  pinMode (botao , INPUT);
  pinMode(pinoled2 , OUTPUT);
}

void loop() {
  // leitura da variavel botão e escrita conforme leitura
  estadoBotao = digitalRead(botao);
    if(estadoBotao == HIGH){
    if (ultimoaceso == 1 ){
      digitalWrite(pinoled2, LOW );
      digitalWrite(pinoled, HIGH );
      ultimoaceso = 0;
      delay(200);
    }
    else{
       digitalWrite(pinoled, LOW );
       digitalWrite(pinoled2, HIGH );
       ultimoaceso = 1;
       delay(200);
      }

    
}

  

}
