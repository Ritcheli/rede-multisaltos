#ifdef SENSOR
#include <Ultrasonic.h>

//Tempo em milissegundos entre envio de mensagens, pode ser substituido por tempo de sleep
//Por enquanto está sendo usado para teste de rede
const unsigned long readInterval = 80;
const unsigned long interval = 2000;
unsigned long distance; //variável responsavel por armazenar o valor de distancia do sensor HC-SR04
unsigned long last_sent = 0;  //tempo que a ultima mensagem foi enviada
unsigned long lastPrint = 0;  //tempo que a ultima mensagem foi enviada
unsigned int sent = 0;    //numero de mensagens que tentou enviar
unsigned int success = 0; //numero de mensagens que conseguiu enviar

Ultrasonic ultrassom(8,7); // define o nome do sensor(ultrassom) e onde está ligado o trig(8) e o echo(7) respectivamente

//Pode retirar se funcionar sem o setup
//void setup() {
//  Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.
//}

void loop() {
  network.update();
  
  if (millis() - last_sent >= readInterval && sent < 20) {   //Se passou do intervalo para enviar o dado
    RF24NetworkHeader headerOut(IDnext);   // (Endereço de envio)

    //faz a leitura e tenta enviar
    unsigned long valor;
    valor = analogRead(A0); //leitura analogica da porta 0
    bool ok = network.write(headerOut, &valor, sizeof(valor)); // Envia o dado da leitura
    sent++;
    if (ok) success++; //se conseguiu enviar
    
    last_sent = millis(); //atualiza tempo do ultimo envio
  }

  //Essa parte abaixo é usada para testar a rede, pode ser removida depois
  if (millis() - lastPrint >= interval) {
    lastPrint = millis(); //atualiza tempo do ultimo envio
    Serial.print("Em 2s -> Enviou: " + String(sent));
    Serial.print("\tSucesso: " + String(success));
    Serial.println("\tProporcao: " + String(100 * success / sent) + "%");
    sent = 0;
    success = 0;
  }

  void SENSOR_HC_SR_04() {
    distance = ultrassom.Ranging(CM);// retorna a distancia em centímetros (CM)
    delay(100);
    
    return distance
  }
  //Pode ser adicionado algum tipo de sleep nessa parte
}

#endif
