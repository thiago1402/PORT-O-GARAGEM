// Inclusão da biblioteca do sensor
// Essa biblioteca não vem por padrão com o arduino e
// precisa ser instalada pelo gerenciador de bibliotecas
#include <Ultrasonic.h>

// Inicializa o objeto do sensor ultrasônico
// Usando as portas 12 e 13 para trigger e echo
Ultrasonic ultrasonic(12, 13);
int ledVermelho (11);
int ledAmarelo (10);
int ledVerde (9);

void setup() {
  pinMode (ledVermelho , OUTPUT);
  pinMode (ledAmarelo , OUTPUT);
  pinMode (ledVerde , OUTPUT);
 
  // Inicializa a porta Serial
  Serial.begin(9600);
}

void acendeLed(int ligaLed, int desligaLed1 , int desligaLed2 ){
   digitalWrite (ligaLed ,HIGH);
    digitalWrite (desligaLed1, LOW);
    digitalWrite (desligaLed2, LOW);
}

void loop() {
  // Lê o valor do sensor
  int distancia = ultrasonic.distanceRead();
  if (distancia < 100 && distancia > 80) {
    acendeLed(ledAmarelo,ledVermelho,ledVerde);
    Serial.print("1");
  }
  else if (distancia < 80 && distancia > 60) {
    acendeLed(ledVermelho,ledAmarelo,ledVerde);
    Serial.print("2");
  }
  else if (distancia < 60 ) {
    acendeLed(ledVerde,ledVermelho,ledAmarelo);
    Serial.print("3 ");
  }
    else {
    digitalWrite (ledVermelho , LOW);
    digitalWrite (ledAmarelo, LOW);
    digitalWrite  (ledVerde, LOW);
  }
  // Escreve o valor da distância no painel Serial
  Serial.print("Distance in CM: ");
  Serial.println(distancia);

  delay(500);
}
