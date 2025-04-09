#include <Arduino.h>
#include "Genius_functions.h"
#include "Display.h"

// Flags para identificar qual botão foi pressionado
volatile bool buttonFlags[4] = {false, false, false, false};

// Prototipação das funções de interrupção
void isrBotao0() { buttonFlags[0] = true; }
void isrBotao1() { buttonFlags[1] = true; }
void isrBotao2() { buttonFlags[2] = true; }
void isrBotao3() { buttonFlags[3] = true; }

//Configuração do Esp32
void setup() {
  //inicialização dos pinos
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(BuzzerPin, OUTPUT);

  // Conecta interrupções
  attachInterrupt(digitalPinToInterrupt(buttonPins[0]), isrBotao0, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPins[1]), isrBotao1, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPins[2]), isrBotao2, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPins[3]), isrBotao3, FALLING);

  //inicialização do display
  // Inicializa o I2C com seus pinos personalizados (SDA, SCL)
  Wire.begin(8, 9); // GPIO8 = SDA, GPIO9 = SCL
  Initial_screen();

  Serial.begin(115200);

  // Configura o canal PWM do buzzer
  ledcSetup(0, 2000, 8);  // freq inicial: 2kHz
  ledcAttachPin(BuzzerPin, 0);

// Gerador de numeros aleatórios (assume o pino 3 como flutuante ou desconectado):
  randomSeed(analogRead(3));
}

void loop() {
    /*o jogo começa com o pressionar de qualquer botão:
      1. A sequencia de cores é gerada.
      2. É a vez do genius, ele joga até a posição do nivel atual,
      3. Compara-se o que o jogador reproduzir com a sequencia gerada no passo 1.
      4. Se errado, ele recebe o alerta de game over, e o jogo espera um toque em qualquer botão.
         se correto, ele volta ao passo 2. */
  Start_screen();
  if((read_buttons() >= 0) && (read_buttons() < 4)){
    int level=1;
    sequence_generate();
    for(byte i=0; i<=SequenceLength; i++){
      level = level + i; 
      genius_turn(level);
      if(!compare_sequence(level)){
        game_over();
        i=SequenceLength+2;
        level = 1;
      }
      else{level++;}
    }
  }
  delay(1000);
}

/*Na jogada do genius ele precisa repetir a sequencia do começo e pedir os botões do começo.
está gerando a sequencia, mostrando de quem é a jogada, a captura do botão tá ok*/