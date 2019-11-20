/* REDES SEM FIO - 2019.2
 * 
 * Criação de rede com 10 nodos e até 3 saltos utilizando as bibliotecas RF24.h e RF24Network.h
 * Detalhes sobre o funcionamento dessas bibliotecas podem ser encontrados nos links abaixo:
 * http://tmrh20.github.io/RF24/classRF24.html
 * https://tmrh20.github.io/RF24Network/classRF24Network.html
 * https://howtomechatronics.com/tutorials/arduino/how-to-build-an-arduino-wireless-network-with-multiple-nrf24l01-modules/
*/

/***Configuracao do nodo***/
//  Indica o ID do nodo, é o numero escrito na entrada USB do arduino
//  Consulte a topologia da rede para mais detalhes
#define ID 00

//  Potencia usada na transmissão, pode assumir um dos quatro valores abaixo:
//    RF24_PA_MIN  : saida de -18dBm
//    RF24_PA_LOW  : saida de -12dBm
//    RF24_PA_HIGH : saida de  -6dBm
//    RF24_PA_MAX  : saida de   0dBm
#define LEVEL RF24_PA_MIN
/***************************/




#include <RF24.h>
#include <RF24Network.h>

//Define função do nodo baseado em seu ID
//Nodo pode ser: mestre, intermediario, ou sensor
#if ID == 00
#define MASTER
#elif (ID == 011) || (ID == 0112) || (ID == 01113)
#define SENSOR
#else
#define INTERMEDIATE
#endif

//Definições dos ID's dos nodos que este irá se comunicar
const uint16_t IDself = (uint16_t)ID; //ID deste nodo - o mesmo valor dado pelo #define ID, mas tipado para uint16_t
const uint16_t IDnext = (uint16_t)ID % (ID < 010 ? 01 : (ID < 0100 ? 010 : (ID < 01000 ? 0100 : 01000))); //ID do nodo destino

//Criação dos objetos usados na comunicação sem fio
RF24 radio(7, 8);  //Cria um objeto RF24 chamado radio - 7 e 8 são os pinos CE e CSN
RF24Network network(radio);  //Cria uma network e adiciona o objeto radio na mesma


void setup() {
  Serial.begin(9600);
  radio.begin();
  network.begin(90, IDself);  //(channel, node address)
  radio.setPALevel(LEVEL);
  radio.setDataRate(RF24_2MBPS);
}
