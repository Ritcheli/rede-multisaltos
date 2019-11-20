#include "DHT.h"
 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup()
{
  dht.begin();
}
 
void loop()
{
  float h = dht.readHumidity();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    return h;
  }
}
