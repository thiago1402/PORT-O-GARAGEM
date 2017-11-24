#include <SPI.h>
#include <UIPEthernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xF1, 0x73 };
char server[] = "www.google.com";

EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

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
