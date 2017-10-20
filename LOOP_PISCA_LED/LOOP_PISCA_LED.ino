// Criação de variáveis
// int = integer / Números inteiros
// pinoLedVermelho = nome da variável
//11 = valor da variavel / numero do pino que queremos controlar
int pinoLedVermelho = 11;


// setup = função / trecho de codigo que é executado uma única vez ao gravar
// o código no arduino
void setup() {
  // Função que configura a porta como INPUT ou OUTPUT
  // Tomem muito cuidado com os nomes, pois a linguagem é CASE-SENTIVE,
  // ou seja, ela faz distinção de letras maiúsculas e minusculas, logo
  // PinMode é difenrete de pinMode
  pinMode (pinoLedVermelho, OUTPUT);
}

void loop() {
  // Esse loop é uma estrutura de repetição que entram em atividade
  // No momento em que o código for gravado no arduino, logo após a
  // execução do setup
  digitalWrite(pinoLedVermelho, HIGH);
  delay(1000);
  digitalWrite(pinoLedVermelho, LOW);
  delay(1000);

}
