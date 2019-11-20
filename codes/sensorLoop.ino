#ifdef SENSOR

//Tempo em milissegundos entre envio de mensagens, pode ser substituido por tempo de sleep
//Por enquanto está sendo usado para teste de rede
const unsigned long readInterval = 80;
const unsigned long interval = 2000;
unsigned long last_sent = 0;  //tempo que a ultima mensagem foi enviada
unsigned long lastPrint = 0;  //tempo que a ultima mensagem foi enviada
unsigned int sent = 0;    //numero de mensagens que tentou enviar
unsigned int success = 0; //numero de mensagens que conseguiu enviar

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

  //Pode ser adicionado algum tipo de sleep nessa parte
}

#endif
