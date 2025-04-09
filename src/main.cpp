#include <Arduino.h>
#include "Genius_functions.h"

int level=1;

//Configuração do Esp32
void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(BuzzerPin, OUTPUT);

  Serial.begin(115200);

  ledcSetup(0, 2000, 8);  // freq = 2000 Hz, resolução de 8 bits
  ledcAttachPin(BuzzerPin, 0);    // Associa pino ao canal PWM

  // The following line primes the random number generator.
  // It assumes pin 10 is floating (disconnected):
  randomSeed(analogRead(3));
}

void loop() {
  Serial.println("Começou");
  /*o jogo começa com o pressionar de qualquer botão:
      1. A sequencia de cores é gerada.
      2. É a vez do genius, ele joga até a posição do nivel atual,
      3. Compara-se o que o jogador reproduzir com a sequencia gerada no passo 1.
      4. Se errado, ele recebe o alerta de game over, e o jogo espera um toque em qualquer botão.
         se correto, ele volta ao passo 2. */
  if((read_buttons() >= 0) && (read_buttons() < 4)){
    sequence_generate();
    for(byte i=0; i<=SequenceLength; i++){
      level = level + i; 
      genius_turn(level);
      if(!compare_sequence(level)){
        game_over();
        i=SequenceLength+2;
        level = 1;
      }
    }
  }
  delay(1000);
}


/*tentar fazer a detecção dos botões por interrupção, está gerando a sequencia, 
mostrando qual a jogada, mas a captura do botão tá muito rapida, 
adicionar um tempo de espera pra garantir tempo hábil de resposta do jogador*/