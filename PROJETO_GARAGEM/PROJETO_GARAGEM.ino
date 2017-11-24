#include <Servo.h>
#define SERVO 11
Servo motor;                        // Variavel do Motor
int pos;                            //Posição do Servo
int led = A0;
int botao = 12;
int estadobotao = LOW;
int estadoLed = LOW;
int ultimoEstado = 1;

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
      for (pos = 30; pos <= 120; pos++) {
        motor.write(pos);
        delay(15);
      }
      delay (500);
      digitalWrite(led , HIGH);

    }
    else {
      ultimoEstado = 0;
      for (pos = 120; pos >= 30; pos--) {
        motor.write(pos);
        delay(15);
      }
      delay (500);
      digitalWrite(led , LOW);

    }

    delay(500);
  }

}

