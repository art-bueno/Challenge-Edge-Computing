#include <LiquidCrystal.h>

const int pinoTrig = 11;
const int pinoEcho = 10;

long duracao;
int distancia1, distancia2;
unsigned long tempo1, tempo2;
float velocidade;
bool medido = false; // Variável para controlar se a primeira medição foi feita

const int pinoRS = 2;
const int pinoEnable = 3;
const int dados_4 = 4;
const int dados_5 = 5;
const int dados_6 = 6;
const int dados_7 = 7;

LiquidCrystal lcd(pinoRS, pinoEnable, dados_4, dados_5, dados_6, dados_7);

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 5000; // 5 segundos

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  Serial.begin(9600); // Inicializa a comunicação serial para depuração
}

void loop() {
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;
    
    if (!medido) {
      limpaTrigger();
      ativaTrigger(10);
      distancia1 = distanciaMedida();
      tempo1 = millis();
      medido = true;
    } else {
      limpaTrigger();
      ativaTrigger(10);
      distancia2 = distanciaMedida();
      tempo2 = millis();
      
      velocidade = calculaVelocidade(distancia1, distancia2, tempo1, tempo2);
      imprimeResultadoNoLCD(distancia1, distancia2, velocidade);
      
      distancia1 = distancia2;
      tempo1 = tempo2;
    }
  }
}

void limpaTrigger() {
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
}

void ativaTrigger(int microSegundos) {
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(microSegundos);
  digitalWrite(pinoTrig, LOW);
}

int distanciaMedida() {
  duracao = pulseIn(pinoEcho, HIGH);
  int distancia = duracao * 0.034 / 2;
  Serial.print("Distancia: ");
  Serial.println(distancia);
  return distancia;
}

float calculaVelocidade(int d1, int d2, unsigned long t1, unsigned long t2) {
  float deltaDistancia = d2 - d1;
  float deltaTempo = (t2 - t1) / 1000.0; 
  
 
  float velocidade_cm_s = deltaDistancia / deltaTempo; 
  float velocidade_km_h = velocidade_cm_s * 0.036; 
  
  return velocidade_km_h;
}

void imprimeResultadoNoLCD(int d1, int d2, float velocidade) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("D1: ");
  lcd.print(d1);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("D2: ");
  lcd.print(d2);
  lcd.print(" cm");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Velocidade: ");
  lcd.print(velocidade);
  lcd.print(" km/h");
  delay(2000);
}

void alertaInicialLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pronto para medir");
  delay(2000);
}