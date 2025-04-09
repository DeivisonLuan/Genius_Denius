#include <Arduino.h>
#include "Genius_functions.h"

int geniusSequence[SequenceLength]= {0};

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
          Serial.println("erro de botão igual");
        }
        else if(pressed == 5){
          error=true;
        }
        else{
          Serial.println("erro else final");
          Serial.println(pressed);
          return false;
        }
      }
      if((millis() - startTime >= duration) && (error == true)){
        Serial.println("erro if de passou o tempo");
        return false;
      }
      delay(200);
    }
  
    return true; //caso passe por todas as verificações só pode ser verdadeiro
  }
  
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