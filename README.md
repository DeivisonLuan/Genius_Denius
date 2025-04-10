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
  - Exibir mensagens como "Início", "Vitória", "Nível" e "Game Over".
- 🔋 Sistema otimizado para uso em aplicações portáteis.
- 👤 Projeto **individual**, desenvolvido para fins acadêmicos.

---

## 🧰 Tecnologias e Ferramentas

- **Microcontrolador:** ESP32-C3
- **Linguagem:** C / C++ (framework Arduino)
- **IDE:** Visual Studio Code + PlatformIO
- **Display:** OLED 128x64 via I2C
- **Buzzer:** Piezoelétrico
- **LEDs e Botões:** Entradas digitais
- **Bibliotecas:** 
  - `Wire.h`
  - `Adafruit_SSD1306.h`
  - `Adafruit_GFX.h`
  - `Adafruit_BusIO-Master`

---

## 📦 Instalação e Execução

1. **Clone o repositório:**

```bash
git clone https://github.com/seu-usuario/genius-oled-esp32c3.git
```
2. Abra o projeto no Visual Studio Code com a extensão PlatformIO instalada.

3. Clique no icone de build da barra de ferramentas da extensão platformIO

4. No arquivo diagram.json (se a extensão workwi estiver corretamente instalada) clique no icone "play" pra iniciar a simulação.

---

## 🧪 Testes e Uso

- Ao energizar o dispositivo (mudar o estado da chave slider), o jogo será iniciado automaticamente.
- Pressione qualquer botão para iniciar a partida.
- O jogo exibirá uma sequência de LEDs e sons.
- O jogador deve repetir corretamente a sequência.
- A cada acerto, a sequência é aumentada automaticamente.
- A pontuação é atualizada e exibida na tela OLED.
- Em caso de erro, o jogo exibe a mensagem de "Game Over" e reinicia após alguns segundos.

---

## 📄 Licença

Você tem permissão para usar, copiar, modificar, mesclar, publicar, distribuir, sublicenciar e/ou vender cópias do software, desde que preserve os créditos ao autor original.

Toda a documentação necessária para uso, compilação e execução do sistema está incluída neste repositório. O objetivo é incentivar o aprendizado e a reutilização de soluções em projetos embarcados abertos.

Sinta-se livre para explorar, modificar e expandir o projeto conforme sua criatividade. Divirta-se jogando e aprendendo!

---

## 👨‍🔧 Autor

- **Nome:** Deivison Luan
- **Instituição:** Programa de Pós-Graduação em Engenharia Mecatrônica (PPgEMECA) – UFRN
- **Disciplina:** Fluxo e Metodologias de Projeto de Sistemas Embarcados
- **Tipo de Projeto:** Trabalho individual acadêmico
