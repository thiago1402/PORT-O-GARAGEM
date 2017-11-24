#include "ThingSpeak.h"
#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xEE, 0xFF};
EthernetClient client;

unsigned long myChannelNumber = 366123;
const char * myWriteAPIKey = "NEYRZZU7VDDJWFYQ";

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);
  ThingSpeak.begin(client);
}

void loop() {
  if (Serial.available() > 0){
  int valor = Serial.parseInt();
  ThingSpeak.writeField(myChannelNumber, 1, valor, myWriteAPIKey);
  }
  delay(10000);
}
