#ifdef INTERMEDIATE

unsigned int sent = 0;    //numero de mensagens que tentou enviar
unsigned int success = 0; //numero de mensagens que conseguiu enviar
const unsigned long interval = 2000;
unsigned long lastPrint = 0;  //tempo que a ultima mensagem foi enviada

void loop() {
  network.update();
   
  //Enquanto existir algum dado para ser lido
  while ( network.available() ) {
    //Variaveis para armazenar o cabecalho e o dado recebido
    RF24NetworkHeader headerIn;
    unsigned long incomingData; //pode ser trocado por um array para receber diversos valores de uma vez

    //Faz a leitura da mensagem não é preciso mandar ACK pois a biblioteca RF24network já faz isso
    network.read(headerIn, &incomingData, sizeof(incomingData));

    //Repassa o dado para o próximo nodo em direção ao mestre
    RF24NetworkHeader headerOut(IDnext); // (Endereço de envio)
    bool ok = network.write(headerOut, &incomingData, sizeof(incomingData));

    //uint16_t anIn = analogRead(A0);
    
    //Essa parte abaixo é usada para testar a rede, pode ser removida depois
    sent++;
    if (ok) success++;
  }

  if (millis() - lastPrint >= interval) {
    lastPrint = millis(); //atualiza tempo do ultimo envio
    Serial.print("Em 2s -> Enviou: " + String(sent));
    Serial.print("\tSucesso: " + String(success));
    Serial.println("\tProporcao: " + String(100 * success / sent) + "%");
    sent = 0;
    success = 0;
  }

  //Pode ser adicionado algum tipo de sleep nessa parte
}

#endif
