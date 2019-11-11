# Rede de sensores multisaltos

Este projeto tem por objetivo a implementação de uma rede de sensores capaz de monitorar e coletar dados reais de um ambiente. Desta maneira, pela característica dispersa de seus nodos em relação à rede, uma [topologia](docs/img/topologia.png) foi definida a fim de testar os diversos saltos da mesma.

## Topologia

Esta rede será composta por 10 arduinos dispostos na topologia apresentada anteriormente, os dados serão coletados a partir de três sensores: dois sensores de temperatura e um ultrassônico, onde os dois primeiros serão colocados nas rotas de três e dois saltos e o último na rota de somente um salto, devido ao seu tempo de coleta ser bem mais rápido e transmitir mais frequentemente.

### Pré-Requisitos

Os components abaixo foram utilizadas no projeto e são necessários para replicá-lo de acordo com esse tutorial.

10x Arduino UNO
1x Sensor de distância ultrassônico HCSR-40
2x Sensores de temperatura DHT11


### Montagem

Config master:

Config intermediário:

Config sensores:


## Funcionamento

Explicar funcionamento

## Bibliotecas utilizadas

* [NRF24L01+](https://tmrh20.github.io/RF24/) - Optimized High Speed NRF24L01+ Driver Class Documenation

## Licença 

Este projeto é feito sob a licença GNU General Public License v3.0 - veja [LICENSE.md](LICENSE.md) para mais detalhes