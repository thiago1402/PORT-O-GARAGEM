#include <Servo.h>
#define SERVO 11
Servo motor;                        // Variavel do Motor
int pos;                            //Posição do Servo
int led = A0;
int botao = 12;
int estadobotao = LOW;
int estadoLed = LOW;
int ultimoEstado = 0;

void setup() {
  Serial.begin(9600);
  pinMode (led , OUTPUT );
  pinMode (botao , INPUT);
  motor.attach (SERVO);
  motor.write(30); 
  //motor.write (100);//posição zero do motor
}

void loop() {
  estadobotao = digitalRead(botao);
  if (estadobotao == HIGH ) {
    Serial.println(ultimoEstado);
    if (ultimoEstado == 0) {
      ultimoEstado = 1;
      digitalWrite(led , HIGH);
      for (pos = 30; pos <= 120; pos++){
      motor.write(pos);
      delay(15);
      }
    }
    else {
      ultimoEstado = 0;
      digitalWrite(led , LOW);
      for (pos = 120; pos >= 30; pos--){
      motor.write(pos);
      delay(15);
      }
    }
    
    delay(500);
  }

}

