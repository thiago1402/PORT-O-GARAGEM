// Incluindo bibliotecas

#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>
#include <LiquidCrystal.h>

//MENU DE REDE

byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xF1, 0x63 };
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println(topic);
}
EthernetClient ethClient;
PubSubClient client("m10.cloudmqtt.com", 14614, callback, ethClient);
long lastReconnectAttempt = 0;
boolean reconnect() {
  Serial.println("reconectando...");
  if (client.connect("arduinoClient", "thiago", "thiago")) {
    Serial.println("conectado");
    // client.publish("vaga/1","hello world");
    client.subscribe("vaga/#");
  }
  return client.connected();
}

//MENU SENSOR ULTRASONICO

Ultrasonic ultrasonic(A1, A0);

//MENU LCD

const int rs = 9, en = 8, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);
  lcd.begin(16, 2);
  lcd.print("VAGAS LIBERADAS");
  lastReconnectAttempt = 0;
}

void loop() {
  int distancia = ultrasonic.distanceRead();
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  delay(1000);

  if (!client.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      Serial.println("reconectando...");
      lastReconnectAttempt = now;

      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    client.loop();
  }
  
}
