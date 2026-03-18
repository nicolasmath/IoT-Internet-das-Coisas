/**
  Arduino Ethernet
  @author Nicolas e Sara
*/

// As linhas abaixo usam as bibliotecas do módulo Ethernet
// Obs: Este módulo usa os pinos 4,10,11,12 e 12 - Portas bloqueadas
#include <SPI.h>
#include <Ethernet.h>

// Gerar o MAC ADDRESS (https://ssl.crox.net/arduinomac)
byte mac[6] = { 0x90, 0xA2, 0xDA, 0x45, 0xDD, 0xC8 };  // MAC ADDRESS do roteador

// Instanciar o servidor(processo de criar um objeto concreto (uma instância) a partir de uma classe (modelo/biblioteca), permitindo usar seus métodos e variáveis)
EthernetServer server(80);  // 80 porta http

void setup() {
  Serial.begin(9600);
  // A linha abaixo configura a placa de rede como DHCP
  Ethernet.begin(mac);
  // A linha abaixo inicia o servidor
  server.begin();  // ponto-> é a função que o objeto exerce
  // Exibir as configurações da rede
  Serial.println("Arduino Ethernet Shield");  // println escreve e quebra uma linha
  Serial.print("IP: ");                       // print apenas escreve - Aspas é um texto
  Serial.println(Ethernet.localIP());
  Serial.print("Máscara: ");
  Serial.println(Ethernet.subnetMask());  //Exibir a máscara da rede
  Serial.print("Gateway: ");
  Serial.println(Ethernet.gatewayIP());  //Exibir o gateway da rede
  Serial.print("DNS: ");
  Serial.println(Ethernet.dnsServerIP());  // Exibir DNS
}

void loop() {
}
