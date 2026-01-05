#include <Arduino.h>

#define BUZZER_PIN 18
#define LED1_PIN   19
#define LED2_PIN   21
#define BUTTON_PIN 23   // Pino do botão
#define RELAY_PIN  22   // Pino do relé

#define BUZZER_CHANNEL 0
#define BUZZER_RESOLUTION 8

// Notas
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_DS4 311   
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_C5  523

// Tema clássico do Batman (simplificado)
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_E4,
  NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4,
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,
  NOTE_E4, NOTE_G4, NOTE_E4
};

int duration[] = {
  200, 200, 200, 400,
  400, 200, 400, 400,
  400, 200, 200, 400,
  400, 600, 800
};

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Botão com resistor interno

  ledcSetup(BUZZER_CHANNEL, 2000, BUZZER_RESOLUTION);
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);
}

void playNote(int freq, int timeMs, int index) {
  ledcWriteTone(BUZZER_CHANNEL, freq);

  if (index % 2 == 0) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
  } else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
  }

  delay(timeMs);

  ledcWriteTone(BUZZER_CHANNEL, 0);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  delay(40);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(RELAY_PIN, HIGH); // Liga o relé

    int total = sizeof(melody) / sizeof(melody[0]);
    for (int i = 0; i < total; i++) {
      playNote(melody[i], duration[i], i);
    }

    digitalWrite(RELAY_PIN, LOW); // Desliga o relé após execução
    delay(1000);
  }
}
