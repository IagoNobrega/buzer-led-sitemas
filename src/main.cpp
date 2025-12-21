#include <Arduino.h>

#define BUZZER_PIN 18
#define LED1_PIN   19
#define LED2_PIN   21

#define BUZZER_CHANNEL 0
#define BUZZER_RESOLUTION 8

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  ledcSetup(BUZZER_CHANNEL, 2000, BUZZER_RESOLUTION);
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);

  randomSeed(analogRead(0));
}

void shotSound() {
  // ESTALO inicial (tiro)
  ledcWriteTone(BUZZER_CHANNEL, 1800);
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);
  delay(15);

  // Ruído rápido (eco / impacto)
  for (int i = 0; i < 20; i++) {
    ledcWriteTone(BUZZER_CHANNEL, random(400, 2000));

    if (i % 2 == 0) {
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
    } else {
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
    }
    delay(8);
  }

  // Desliga tudo
  ledcWriteTone(BUZZER_CHANNEL, 0);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  shotSound();   // dispara o tiro
  delay(600);    // tempo entre tiros
}
