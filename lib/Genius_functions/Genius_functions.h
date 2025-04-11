//definição do vetor sequência
#define SequenceLength 32

/* Definição dos pinos dos LEDs, botões e buzzer: Vermelho(R), Azul (B), verde (G), Amarelo(Y) */
const int buttonPins[] = {6, 19, 0, 5}; 
const int ledPins[] = {7, 18, 1, 4};
#define BuzzerPin 2

#define baseFreq 1.5
#define addFreq 0.285
#define duration 5000

//Definição das notas para cada cor: Vermelho(R), Azul (B), verde (G), Amarelo(Y)
const int ColorTone[] = {261, 440, 329, 392}; 

const unsigned long debounceDelay = 50;

//Assinatura das funções:
void sequence_generate();
int read_buttons();
void blink_led(int value, int level);
void play_tone(int value, int level);
void genius_turn(int level);
void game_over(int level);
bool compare_sequence(int level);
int frequence(int level);