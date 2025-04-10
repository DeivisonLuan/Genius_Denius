
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Tamanho da tela
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Instância do display (endereços padrão 0x3C ou 0x3D)
#define OLED_RESET    -1

//Assinatura de funções
void define_display();
void Initial_screen();
void Start_screen();
void play_screen(char id, int level);
void game_over_screen(int level);
void Congratulation();