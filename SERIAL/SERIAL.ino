  int red = 11;
  int green = 12;
  int yellow = 8;
  int buzzer = 10;

  

void setup(){
  
  //Inicializando porta do arduino
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode (buzzer, OUTPUT);
}

void acendeApagaLed ( int ledAceso , int ledApagado1, int ledApagado2){
    digitalWrite(ledAceso, HIGH);
    digitalWrite(ledApagado1, LOW);
    digitalWrite(ledApagado2, LOW);
}

void apagaTodosLed (){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
}
void loop() {


  //verifica se tem alguma informação que posa ser lida da porta serial
if  (Serial.available()>0){

    // lê a mensagem da porta serial 
    char ch = Serial.read();
    Serial.println (ch);


    switch (ch) {
    case 'R':
      acendeApagaLed(11,12,8);
      break;
    case 'G':
      acendeApagaLed(12,11,8);
      break;
    case 'Y': 
      acendeApagaLed(8,12,11);
      // default is optional
    break;
    default:
        apagaTodosLed();
        tone(buzzer, 100, 1000); 
        delay(200);
        noTone(buzzer);
        delay(200);

  }
    
           
}
}
   
    // escrevea mensagem novamente na porta serial





