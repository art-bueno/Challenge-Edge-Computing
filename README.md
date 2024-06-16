# Challenge-Edge-Computing
### Projeto Bettery - Medidor de Velocidade em Fórmula

Este projeto implementa um sistema para medir a velocidade entre dois pontos usando um sensor de distância ultrassônico. Ele foi desenvolvido para captar dados e calcular a velocidade em km/h de um veículo, simulando um ambiente de apostas esportivas focadas em competições de Fórmula.

### Componentes Utilizados

- Arduino Uno
- Sensor de distância ultrassônico (HC-SR04)
- Display LCD 16x2
- Biblioteca LiquidCrystal

### Funcionamento do Código

O código principal consiste em duas partes principais: a medição da distância entre dois pontos usando o sensor ultrassônico e o cálculo da velocidade com base nessas medições.

1. **Inicialização:**
   - Configuração dos pinos do Arduino para o sensor ultrassônico e o display LCD.
   - Inicialização da comunicação serial para debug.

2. **Loop Principal:**
   - O loop principal executa a cada 5 segundos (definido pelo `intervalo`).
   - Verifica se a primeira medição já foi feita (`medido`).
   - Se não, realiza a primeira medição, armazena a distância e marca `medido` como verdadeiro.
   - Se sim, realiza a segunda medição, calcula a velocidade entre os dois pontos e exibe no LCD.

3. **Funções Auxiliares:**
   - **limpaTrigger() e ativaTrigger():** Funções para acionar o sensor ultrassônico e medir a distância.
   - **distanciaMedida():** Calcula a distância em centímetros usando o sensor ultrassônico.
   - **calculaVelocidade():** Calcula a velocidade em km/h com base nas duas distâncias medidas e nos tempos correspondentes.
   - **imprimeResultadoNoLCD():** Exibe as distâncias e a velocidade no LCD.

### Conversão de Unidades

A velocidade é calculada inicialmente em cm/s e então convertida para km/h usando a fórmula de conversão aproximada:

\[ \text{velocidade\_km\_h} = \text{velocidade\_cm\_s} \times 0.036 \]

Essa conversão é feita para exibir a velocidade em uma unidade mais compreensível para os usuários finais.

### Uso e Aplicação

O sistema pode ser utilizado para captar dados de velocidade em simulações de corridas de Fórmula, onde a precisão e a rapidez na exibição das informações são cruciais para os espectadores e apostadores. A exibição da velocidade no display LCD permite uma visualização imediata dos resultados, proporcionando uma experiência interativa e informativa para os usuários.



---

Este documento README fornece uma visão geral do projeto Bettery e como o código implementado captura e processa dados de velocidade para serem utilizados em uma casa de apostas focada em competições de Fórmula. Ele destaca a funcionalidade principal do código, os componentes utilizados e a lógica por trás das medições e conversões de unidades.
