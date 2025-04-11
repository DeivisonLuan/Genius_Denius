#include <Arduino.h>
#include "Genius_functions.h"
#include "Display.h"

int geniusSequence[SequenceLength]= {0};

// Estados para debounce
bool lastButtonStates[4] = {HIGH, HIGH, HIGH, HIGH};
unsigned long lastDebounceTimes[4] = {0, 0, 0, 0};

// Gera a sequencia inteira e retorna o valor da jogada
void sequence_generate(){
    /* Vermelho(R) = 0 
       Azul (B)    = 1
       Verde (G)   = 2 
       Amarelo(Y)  = 3 */
  
    for(byte i=0; i < SequenceLength; i++){
      geniusSequence[i] = random(0,4);
    }
    Serial.print("Sequencia gerada: ");
    for(byte i=0; i < SequenceLength; i++){
      Serial.print(geniusSequence[i]);
      Serial.print(" ");
    } 
    Serial.println();
  }
  
  // lê os botões pressionados
  int read_buttons(){
    bool algumPressionado = false;
    for (int i = 0; i < 4; i++) {
      int leituraAtual = digitalRead(buttonPins[i]);
      // Se o estado mudou, atualiza o tempo
      if (leituraAtual != lastButtonStates[i]) {
        lastDebounceTimes[i] = millis();
        lastButtonStates[i] = leituraAtual;
      }
      // Se passou o tempo de debounce
      else if ((millis() - lastDebounceTimes[i]) > debounceDelay) {
        if (leituraAtual == LOW) {  // Botão está pressionado
          ledcSetup(0, ColorTone[i], 8);  // freq de cada cor em Hz, resolução de 8 bits
          ledcAttachPin(BuzzerPin, 0);  // Associa pino ao canal PWM
          byte time_ms = 75;
          ledcWrite(0, 127);
          digitalWrite(ledPins[i], HIGH);
          delay(time_ms);
          digitalWrite(ledPins[i], LOW);
          ledcWrite(0, 0); // Para o som
          delay(time_ms);
          return i;
        }
      }
      else if (!algumPressionado) {
        ledcWrite(0, 0);  // Silencia buzzer se nenhum botão estável pressionado
      }
      delay(10);  // Suaviza varredura
    }
    return 5; //nenhum botão pressionado
  }
  
  //pisca o led por um tempo determinado
  void blink_led(int value, int level){
    int time_ms = frequence(level);
    digitalWrite(ledPins[value], HIGH);
    delay(time_ms);
    digitalWrite(ledPins[value], LOW);
    delay(time_ms);
  }
  
  //Jogada do Genius
  void genius_turn(int level){
    Serial.println(" || Vez do genius!");
    play_screen('g', level);
    delay(200);
    for(byte i=0; i<level; i++){
      ledcSetup(0, ColorTone[geniusSequence[i]], 8);  // freq de cada cor em Hz, resolução de 8 bits
      ledcAttachPin(BuzzerPin, 0);  // Associa pino ao canal PWM
      int time_ms = frequence(level);
      ledcWrite(0, 127);
      digitalWrite(ledPins[geniusSequence[i]], HIGH);
      delay(time_ms);
      digitalWrite(ledPins[geniusSequence[i]], LOW);
      ledcWrite(0, 0); // Para o som
      delay(time_ms);
    }
  }
  
  //toca a nota referente a cada cor por um tempo determinado
  void play_tone(int value, int level){
    // Alternativa ao Tone/noTone:
    ledcSetup(0, ColorTone[value], 8);  // freq de cada cor em Hz, resolução de 8 bits
    ledcAttachPin(BuzzerPin, 0);  // Associa pino ao canal PWM
    int time_ms = frequence(level);
    ledcWrite(0, 127);  
    delay(time_ms);
    ledcWrite(0, 0); // Para o som
    delay(time_ms);
  }
  
  
  //compara a sequencia original com o pressionado pelo jogador e retorna se ele acertou(true) ou não(false)
  bool compare_sequence(int level){
    int pressed;
    bool error;
    play_screen('p', level);
    //delay(200);
    Serial.print("Nivel: ");
    Serial.print(level);
    Serial.print(": ");

    for(byte i=0; i<level; i++){
      error = true;
      unsigned long startTime = millis();
      for(byte j=0; (millis() - startTime < duration) && (error == true);j++){
        pressed = read_buttons();
        if(geniusSequence[i] == pressed){
          error = false;
          Serial.print("Acertou: ");
          Serial.print(pressed);
          Serial.print(" | ");
        }
        else if(pressed == 5){
          error=true;
        }
        else{
          Serial.print("Errou! Era ");
          Serial.print(geniusSequence[i]);
          Serial.print(" e apertou ");
          Serial.println(pressed);
          Serial.print(" | ");
          return false;
        }
      }
      if((millis() - startTime >= duration) && (error == true)){
        Serial.println(" Passou o tempo!");
        return false;
      }
      //delay(200);
    }
  
    return true; //caso passe por todas as verificações só pode ser verdadeiro
  }
  
  //pisca todos os leds e toca uma nota grave 3 vezes
  void game_over(int level){
    game_over_screen(level);
    for(byte j=0; j<3; j++){
      ledcWrite(0, 110);
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

  //Velocidade do jogo: Freq_base = 1,2 Hz com acrescimo de 0,2 Hz a cada 5 jogadas
  int frequence(int level){
    float currentFreq = 1/(baseFreq + addFreq*(level/5));
    int time_ms = int(currentFreq*1000);
    return time_ms;
  }