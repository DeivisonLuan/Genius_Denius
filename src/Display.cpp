#include "Display.h"

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
    int textLen = 2;
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
void play_screen(char id){
    define_display();

    if(id == 'g'){
        const char* words[] = { "Vez do", "Genius!"};
        int textLen = 2;
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
    }
    else if(id =='p'){
        const char* words[] = { "Sua", "Vez!"};
        int textLen = 2;
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
    }
}
void game_over_screen(){
    define_display();
    
    const char* words[] = { "Game", "Over!"};
    int textLen = 2;
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
}