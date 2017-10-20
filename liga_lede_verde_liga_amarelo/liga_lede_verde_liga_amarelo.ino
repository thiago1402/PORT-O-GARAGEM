#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xF1, 0x63 };
char server[] = "192.168.3.186";

EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  Ethernet.begin(mac);
  
  delay(1000);
  Serial.println("connecting...");

  if (client.connect(server, 3000)) {
    Serial.println("connected");
    client.println("GET /teste HTTP/1.1");
    client.println("Host: 192.168.3.186:3000");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
  }
}

void loop() {
  if (client.available()) {
    char resposta = client.read();
    Serial.print(resposta);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    
    while (true);
  }
}
