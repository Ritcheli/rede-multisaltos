#ifdef MASTER

unsigned int received = 0; //numero de mensagens que conseguiu enviar
const unsigned long interval = 2000;
unsigned long lastPrint = 0;  //tempo que a ultima mensagem foi enviada

void loop() {
  network.update();
  
  //Enquanto existir algum dado para ser lido
  while (network.available()) {
    //Variaveis para armazenar o cabecalho e o dado recebido
    RF24NetworkHeader headerIn;
    unsigned long incomingData; //pode ser trocado por um array para receber diversos valores de uma vez

    //Faz a leitura da mensagem não é preciso mandar ACK pois a biblioteca RF24network já faz isso
    network.read(headerIn, &incomingData, sizeof(incomingData));
    received++;
  }

  if (millis() - lastPrint >= interval) {
    lastPrint = millis(); //atualiza tempo do ultimo envio
    Serial.println("Em 2s recebeu: " + String(received));
    received = 0;
  }
  //Pode ser adicionado algum tipo de sleep nessa parte
}

#endif
