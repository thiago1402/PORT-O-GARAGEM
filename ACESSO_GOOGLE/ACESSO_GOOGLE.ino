#include <SPI.h>
#include <UIPEthernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xF1, 0x63 };
char server[] = "www.google.com";
int ledVermelho = 8;
int botao = 4;
int estadoBotao = LOW;
EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  pinMode (ledVermelho , OUTPUT);
  pinMode (botao , INPUT);
  Ethernet.begin(mac);
  
  delay(1000);
  Serial.println("connecting...");

  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
  }
}

void loop() {
   estadoBotao = digitalRead(botao);
   if (estadoBotao == HIGH){
      digitalWrite (ledVermelho , HIGH);   
          Serial.println("0");
   
           }
     else {
      digitalWrite (ledVermelho , HIGH);
          Serial.println("1");

     }
  
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    
    while (true);
  }
}
