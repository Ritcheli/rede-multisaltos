const int LM35 = A1; //Seta o pino A1 para o sensor
float temperature; //Declara a variável para armazenar a temperatura

void setup() {
  Serial.begin(9600); 
} 

void loop() {
  float temperature_function(){
    temperature = (float(analogRead(LM35))*5/(1023))/0.01; //Realiza os cálculos para determinar a temperatura em Celsius 
    delay(100);  
    return temperature;
  }
}
