#include <Arduino.h>

/* Definição dos pinos dos LEDs, botões e buzzer: Vermelho(R), Azul (B), verde (G), Amarelo(Y) */
const int buttonPins[] = {6, 19, 0, 5}; 
const int ledPins[] = {7, 18, 1, 4};
#define BuzzerPin 2
int level=1;

//Definição das notas para cada cor: Vermelho(R), Azul (B), verde (G), Amarelo(Y)
const int ColorTone[] = {261, 440, 329, 392}; 
//-------------- ver a frequencia ----------------

//Assinatura das funções:
void sequence_generate();
int read_buttons();
void blink_led(int value);
void play_tone(int value);
void genius_turn(int level);
void game_over();

//definição do vetor sequência
#define SequenceLength 32
int geniusSequence[SequenceLength] = {5};

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
  Serial.println("loop");
  game_over();
  delay(3000);
  /*o jogo começa com o pressionar de qualquer botão:
      1. A sequencia de cores é gerada.
      2. É a vez do genius, ele joga até a posição do nivel atual,
      3. Compara-se o que o jogador reproduzir com a sequencia gerada no passo 1.
      4. Se errado, ele recebe o alerta de game over, e o jogo espera um toque em qualquer botão.
         se correto, ele volta ao passo 2. 
  
  if((read_buttons() >= 0) && (read_buttons() < 4)){
    sequence_generate();
    genius_turn(32);
  }
  /*
    for(byte i=0; i<=SequenceLength; i++){
      level = level + i; 
      genius_turn(level);
      if(!compare_sequence(level)){
        game_over();
        i=SequenceLength+2;
        level = 1;
      }
    }
  }*/
}

// Gera a sequencia inteira e retorna o valor da jogada
void sequence_generate(){
  /* Vermelho(R) = 0 
     Azul (B)    = 1
     Verde (G)   = 2 
     Amarelo(Y)  = 3 */

  for(byte i=0; i < SequenceLength; i++){
    geniusSequence[i] = random(0,4);
  }
  for(byte i=0; i < SequenceLength; i++){
    Serial.print(geniusSequence[i]);
    Serial.print(" ");
  } 
  Serial.println();
}

// lê os botões pressionados
int read_buttons(){
  for(byte i=0; i<4; i++){
    if(digitalRead(buttonPins[i]) == LOW){
      blink_led(i);
      return i;
    }
  }
  
  return 5; //nenhum botão pressionado
}

//pisca o led por um tempo determinado
void blink_led(int value){
  digitalWrite(ledPins[value], HIGH);
  delay(300);
  digitalWrite(ledPins[value], LOW);
  delay(300);
}

//Jogada do Genius
void genius_turn(int level){
  for(byte i=0; i<level; i++){
    play_tone(geniusSequence[i]);
    blink_led(geniusSequence[i]);
  }
}

//toca a nota referente a cada cor por um tempo determinado
void play_tone(int value){
  ledcWrite(0, ColorTone[value]);
  Serial.println(ColorTone[value]);  
  delay(300);
  ledcWrite(0, 0); // Para o som
  delay(300);
}

/*
//compara a sequencia original com o pressionado pelo jogador e retorna se ele acertou(true) ou não(false)
bool compare_sequence(int level){
  int pressed;
  bool error;
  unsigned long duration = 5000;

  for(byte i=0; i<level; i++){
    error = true; //
    unsigned long startTime = millis();
    for(byte i=0; (millis() - startTime < duration) && (error == true);i++){
      pressed = read_buttons();
      if(geniusSequence[i] == pressed){
        error = false;
      }
      else if(pressed == 5){
        error=true;
      }
      else{
        return false;
      }
    }
    if((millis() - startTime >= duration) && (error == true)){
      return false;
    }
  }

  return true; //caso passe por todas as verificações só pode ser verdadeiro
}
*/

//pisca todos os leds e toca uma nota grave 3 vezes
void game_over(){
  for(byte j=0; j<3; j++){
    ledcWrite(0, 31);
    for(byte i=0; i<4; i++){
      digitalWrite(ledPins[i], HIGH);
    }
    delay(500);
    ledcWrite(0, 0);
    for(byte i=0; i<4; i++){
      digitalWrite(ledPins[i], LOW);
    }
    delay(500);
  }
}