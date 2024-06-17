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


### Uso e Aplicação

O sistema pode ser utilizado para captar dados de velocidade em simulações de corridas de Fórmula, onde a precisão e a rapidez na exibição das informações são cruciais para os espectadores e apostadores. A exibição da velocidade no display LCD permite uma visualização imediata dos resultados, proporcionando uma experiência interativa e informativa para os usuários.

Link para simulador: https://www.tinkercad.com/things/0mVrVU1adKU-bettery-sensor/editel?sharecode=J860wvIX9yFqDLhoCrfYioMbQGV5nOpb7OsIna2iiE8

### Conclusão
O projeto Bettery apresenta uma solução inovadora e prática para a medição e exibição de velocidades em ambientes de corridas de Fórmula, integrando tecnologia de sensores ultrassônicos com o display LCD para fornecer dados precisos e em tempo real. Com essa implementação, a Bettery visa aprimorar a experiência dos apostadores, oferecendo informações detalhadas que podem influenciar as decisões de apostas.

O uso do Arduino, juntamente com sensores ultrassônicos e a biblioteca LiquidCrystal, demonstra como componentes acessíveis e técnicas de programação eficazes podem ser combinados para criar sistemas de medição robustos e precisos. A conversão de unidades para km/h torna os dados mais relevantes e compreensíveis, aumentando a utilidade prática do sistema em contextos de apostas esportivas.

A aplicação do sistema em simulações de corridas de Fórmula reforça o compromisso da Bettery em fornecer dados confiáveis e em tempo hábil, garantindo uma experiência de usuário melhorada e mais envolvente. A flexibilidade e a adaptabilidade do sistema permitem futuras expansões e melhorias, alinhando-se às demandas dinâmicas do mercado de apostas esportivas.

Por fim, o projeto Bettery exemplifica o potencial da integração tecnológica em melhorar serviços tradicionais, como as casas de apostas, oferecendo aos usuários uma plataforma moderna, interativa e baseada em dados precisos. Para desenvolvedores e entusiastas, este projeto serve como um ponto de partida inspirador para explorar mais aplicações inovadoras no campo das medições de velocidade e suas interações com sistemas de apostas.




Arthur Bueno de Oliveira RM 558396
João Vitor Carotta Ribeiro RM 555187
Victor Magdaleno Marcos RM 556729
Diego Faduli Eleuterio RM 557218

