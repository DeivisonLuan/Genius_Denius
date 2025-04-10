#include "Display.h"
#include <string>

using namespace std;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void define_display(){
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao inicializar o display SSD1306"));
    while (true); // trava o código
    }
    display.clearDisplay(); // <- limpa o logo padrão da Adafruit antes de desenhar
}

//Tela de apresentação
void Initial_screen(){
    define_display();
    
    const char* words[] = { "Genius", "Tech!"};
    int textLen = 3;
    int lineHeight = 8 * textLen;

    for (int i = 0; i < 2; i++) {
        const char* word = words[i];
        int textWidth = strlen(word) * 6 * textLen;
        int x = (SCREEN_WIDTH - textWidth) / 2;
        int y = i * lineHeight; 

        display.setTextSize(textLen);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(x, y);
        display.println(word);
    }

    display.display();
    delay(2000);
}

//Tela que indica como começar o jogo
void Start_screen(){
    define_display();

    const char* words[] = { "Pressione", "Qualquer", "botao pra", "iniciar!"};
    int textLen = 2;
    int lineHeight = 8 * textLen;

    for (int i = 0; i < 4; i++) {
        const char* word = words[i];
        int textWidth = strlen(word) * 6 * textLen;
        int x = (SCREEN_WIDTH - textWidth) / 2;
        int y = i * lineHeight; 

        display.setTextSize(textLen);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(x, y);
        display.println(word);
    }
    display.display();
}

//Tela que indica de quem é a vez
void play_screen(char id, int level){
    define_display();

    String points = "Nivel: " + String(level);
    if(id == 'g'){
        String words[] = { "Vez do", "Genius!", " ", points};
        int textLen = 2;
        int lineHeight = 8 * textLen;

        for (int i = 0; i < 2; i++) {
            String word = words[i];
            int textWidth = word.length() * 6 * textLen;
            int x = (SCREEN_WIDTH - textWidth) / 2;
            int y = i * lineHeight; 

            display.setTextSize(textLen);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(x, y);
            display.println(word);
        }
        display.display();
    }
    else if(id =='p'){
        String words[] = { "Sua vez!", " ", points};
        int textLen = 2;
        int lineHeight = 8 * textLen;
    
        for (int i = 0; i < 3; i++) {
            String word = words[i];
            int textWidth = word.length() * 6 * textLen;
            int x = (SCREEN_WIDTH - textWidth) / 2;
            int y = i * lineHeight; 
    
            display.setTextSize(textLen);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(x, y);
            display.println(word);
        }
        display.display();
    }
}
void game_over_screen(int level){
    define_display();
    
    String points = "Nivel: " + String(level);
    String words[] = { "Game Over!", " ", " ", points};
    int textLen = 2;
    int lineHeight = 8 * textLen;

    for (int i = 0; i < 4; i++) {
        String word = words[i];
        int textWidth = word.length() * 6 * textLen;
        int x = (SCREEN_WIDTH - textWidth) / 2;
        int y = i * lineHeight; 

        display.setTextSize(textLen);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(x, y);
        display.println(word);
    }

    display.display();
}

void Congratulation(){
    define_display();
    
    const char* words[] = { "Voce", "venceu!", "Parabéns!"};
    int textLen = 2;
    int lineHeight = 8 * textLen;

    for (int i = 0; i < 3; i++) {
        const char* word = words[i];
        int textWidth = strlen(word) * 6 * textLen;
        int x = (SCREEN_WIDTH - textWidth) / 2;
        int y = i * lineHeight; 

        display.setTextSize(textLen);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(x, y);
        display.println(word);
    }

    display.display();
}