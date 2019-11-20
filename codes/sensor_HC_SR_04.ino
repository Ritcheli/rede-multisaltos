#include <Ultrasonic.h>

Ultrasonic ultrassom(8,7); // Define o nome do sensor e os pinos que estão conectados trig(8) e echo(7) respectivamente 
unsigned long distance; 

void loop() {
  void SENSOR_HC_SR_04() {
    distance = ultrassom.Ranging(CM);
    delay(100);
    return distance;
  }
}
