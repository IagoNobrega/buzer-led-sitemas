# 🎵 Projeto ESP32 - Melodia Batman com LEDs e Relé

Este projeto utiliza um **ESP32** para tocar a melodia clássica do Batman em um buzzer, alternar LEDs e acionar um relé quando um botão é pressionado.

---

## ⚙️ Funcionalidades
- 🔘 Botão: inicia a execução da melodia.
- 🔊 Buzzer: reproduz notas musicais da música tema do Batman.
- 💡 LEDs: piscam alternadamente conforme as notas.
- ⚡ Relé: é acionado durante a execução da melodia.

---

## 🛠️ Componentes Utilizados
- ESP32 DevKit
- 1 Buzzer passivo
- 2 LEDs (com resistores de 220 Ω)
- 1 Módulo Relé (5V ou compatível com ESP32)
- 1 Botão (push button)
- Resistores (10kΩ para pull-down se necessário)
- Protoboard e jumpers

---

## 🔌 Conexões
- **Buzzer** → Pino 18 e GND  
- **LED1** → Pino 19 com resistor de 220 Ω para GND  
- **LED2** → Pino 21 com resistor de 220 Ω para GND  
- **Botão** → Pino 23 e GND (usando `INPUT_PULLUP`)  
- **Relé** → IN no Pino 22, VCC em 5V, GND em GND  

---

## 📜 Código Principal
O código está em `src/main.cpp` e implementa:
- Configuração dos pinos no `setup()`
- Função `playNote()` para tocar notas e alternar LEDs
- Loop principal que aguarda o botão ser pressionado para executar a melodia e acionar o relé

---

## ▶️ Como Executar
1. Instale o [PlatformIO](https://platformio.org/) ou use a IDE Arduino.  
2. Conecte o ESP32 via USB.  
3. Carregue o código no dispositivo.  
4. Pressione o botão para iniciar a melodia e observar LEDs + relé funcionando.

---

## 📈 Possíveis Melhorias
- Adicionar mais músicas ou sequências de notas.  
- Controlar o tempo de acionamento do relé de forma independente.  
- Implementar debounce no botão para evitar múltiplos disparos.  

---

## 👨‍💻 Autor
**Iago Nobrega Araujo**  
📍 Ilhéus, Bahia, Brasil  
🔗 [LinkedIn](https://www.linkedin.com/in/iago-nobrega-38087a208/) | [GitHub](https://github.com/IagoNobrega)
