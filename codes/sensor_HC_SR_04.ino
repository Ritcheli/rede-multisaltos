#include <Ultrasonic.h>

Ultrasonic ultrassom(8,7); // Define o nome do sensor e os pinos que estão conectados trig(8) e echo(7) respectivamente 
unsigned long distance; 

void loop() {
  unsigned long sensor_ultrasonic() {
    distance = ultrassom.Ranging(CM); // Coloca o valor da distância em centimetros (CM)
    delay(100);
    return distance;
  }
}
