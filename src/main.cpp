#include <Arduino.h>
#include <pitches.h>

/* Definição dos pinos dos LEDs, botões e buzzer: Vermelho(R), Azul (B), verde (G), Amarelo(Y) */
const int buttonPins[] = {6, 5, 19, 0}; 
const int ledPins[] = {7, 4, 18, 1};
#define BuzzerPin 2

//Definição das notas para cada cor: Vermelho(R), Azul (B), verde (G), Amarelo(Y)
const int ColorTone[] = {NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G5}; 

//definição do vetor sequência
#define SequenceLength 31
int geniusSequence[SequenceLength] = {0};

//Configuração do Esp32
void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(BuzzerPin, OUTPUT);

  // The following line primes the random number generator.
  // It assumes pin 10 is floating (disconnected):
  randomSeed(analogRead(10));
}

void loop() {
  // put your main code here, to run repeatedly:




}

// gera a sequencia inteira e retorna o valor da jogada
int sequence_generate(){
  /* Vermelho(R) = 0 
     Azul (B)    = 1
     Verde (G)   = 2 
     Amarelo(Y)  = 3 */

  for(byte i=0; i < 32; i++){
    geniusSequence[i] = random(0,4);
  }
}

//Jogada do Genius
void Genius_turn(int level){
  for(byte i=0; i<level; i++){
    play_tone(geniusSequence[i]);
    blink_led(geniusSequence[i]);
  }
}

//toca a nota referente a cada cor por um tempo determinado
void play_tone(int value){
  tone(BuzzerPin, ColorTone[value], 300);
  delay(300);
}

//pisca o led por um tempo determinado
void blink_led(int value){
    digitalWrite(ledPins[value], HIGH);
    delay(300);
    digitalWrite(ledPins[value], LOW);
    delay(300);
}

// lê os botões pressionados e compara?????
int read_buttons(){
  for(byte i=0; i<4; i++){
    if(digitalRead(buttonPins[i])){
      return i;
    };
  }
}

bool compare_sequence(int level){
  byte equal = 0;
  for(byte i=0; i<level; i++){
    if(geniusSequence[i] =! read_buttons()){
      return false;
    }
  }
}

//pisca todos os leds e toca uma nota grave 3 vezes
void game_over(){
  for(byte j=0; j<3; j++){
      for(byte i=0; i<4; i++){
      digitalWrite(ledPins[i], HIGH);
    }
    tone(BuzzerPin, 200);
    delay(300);
    for(byte i=0; i<4; i++){
      digitalWrite(ledPins[i], LOW);
    }
    noTone(BuzzerPin);
    delay(300);
  }
}