# Genius_Denius
# 🎮 Genius OLED - Sistema Embarcado com ESP32-C3

Este repositório apresenta o desenvolvimento de um sistema embarcado baseado no microcontrolador **ESP32-C3**, que implementa uma versão customizada do clássico jogo **Genius (Simon Says)**. Este projeto é parte da disciplina de **Fluxo e Metodologias de Projeto de Sistemas Embarcados** do **Programa de Pós-Graduação em Engenharia Mecatrônica (PPgEMECA/UFRN)**.

Além das funcionalidades clássicas do jogo (memória e repetição de sequências de luzes e sons), o sistema conta com uma **tela OLED** para exibir a pontuação, mensagens ao usuário e status do jogo, enriquecendo a experiência de interação.

---

## 🚀 Funcionalidades

- 💡 Botões com LEDs para jogabilidade visual.
- 🔊 Feedback sonoro (buzzer).
- 🖥️ **Display OLED** para:
  - Mostrar a pontuação.
  - Exibir mensagens como "Início", "Vitória", "Erro" e "Game Over".
- 🔋 Sistema otimizado para uso em aplicações portáteis.
- 👤 Projeto **individual**, desenvolvido para fins acadêmicos.

---

## 🧰 Tecnologias e Ferramentas

- **Microcontrolador:** ESP32-C3
- **Linguagem:** C / C++ (Plataforma Arduino)
- **IDE:** Visual Studio Code + PlatformIO
- **Display:** OLED 128x64 via I2C
- **Buzzer:** Piezoelétrico
- **LEDs e Botões:** Entradas digitais
- **Bibliotecas:** 
  - `Wire.h`
  - `Adafruit_SSD1306.h`
  - `Adafruit_GFX.h`

---

## 📦 Instalação e Execução

1. **Clone o repositório:**

```bash
git clone https://github.com/seu-usuario/genius-oled-esp32c3.git
cd genius-oled-esp32c3
```
2. Abra o projeto no Visual Studio Code com a extensão PlatformIO instalada.

3. Conecte seu ESP32-C3 via cabo USB e certifique-se de que a porta serial correta esteja selecionada.

4. Compile e envie o código para a placa com o seguinte comando:
```bash
pio run --target upload
```
5.Para visualizar os logs de execução (opcional), use:
```bash
pio device monitor
```
---

## 🧪 Testes e Uso

- Ao energizar o dispositivo, o jogo será iniciado automaticamente.
- Pressione qualquer botão para iniciar a partida.
- O jogo exibirá uma sequência de LEDs e sons.
- O jogador deve repetir corretamente a sequência.
- A cada acerto, a sequência é aumentada automaticamente.
- A pontuação é atualizada e exibida na tela OLED.
- Em caso de erro, o jogo exibe a mensagem de "Game Over" e reinicia após alguns segundos.

---

## 🛠️ Estrutura do Projeto

```bash
genius-oled-esp32c3/
├── src/
│   └── main.cpp          # Código principal do jogo
├── include/
│   └── *.h               # Arquivos de cabeçalho, se houver
├── lib/
│   └── ...               # Bibliotecas adicionais
├── platformio.ini        # Configuração do ambiente PlatformIO
└── README.md             # Documentação principal do projeto
```

---

## 📄 Licença

Este projeto está licenciado sob a **Licença MIT**.

Você tem permissão para usar, copiar, modificar, mesclar, publicar, distribuir, sublicenciar e/ou vender cópias do software, desde que preserve os créditos ao autor original.

Toda a documentação necessária para uso, compilação e execução do sistema está incluída neste repositório. O objetivo é incentivar o aprendizado e a reutilização de soluções em projetos embarcados abertos.

Para mais detalhes, consulte o arquivo [LICENSE](LICENSE) incluído neste repositório.

## 👨‍🔧 Autor

- **Nome:** Nome do Autor
- **Instituição:** Programa de Pós-Graduação em Engenharia Mecatrônica (PPgEMECA) – UFRN
- **Disciplina:** Fluxo e Metodologias de Projeto de Sistemas Embarcados
- **Tipo de Projeto:** Trabalho individual acadêmico
- **Contato:** seu.email@exemplo.com

---

## ✨ Observações Finais

Este projeto foi desenvolvido com o objetivo de aplicar na prática os conhecimentos adquiridos na disciplina de sistemas embarcados, integrando hardware e software em um jogo interativo e educativo.

A adição de uma tela OLED amplia as possibilidades de comunicação com o usuário, permitindo um sistema mais amigável e dinâmico. Além disso, o uso do ESP32-C3 proporciona uma plataforma moderna, eficiente e com excelente suporte a projetos embarcados.

Sinta-se livre para explorar, modificar e expandir o projeto conforme sua criatividade. Divirta-se jogando e aprendendo!

