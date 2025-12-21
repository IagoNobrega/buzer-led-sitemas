#include <Arduino.h>
#define BUZZER_PIN 18
#define LED1_PIN 19   // primeiro LED
#define LED2_PIN 21   // segundo LED

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() {
  // Som de queda (apito descendo)
  for (int freq = 1000; freq > 100; freq -= 20) {
    tone(BUZZER_PIN, freq);
    digitalWrite(LED1_PIN, HIGH);   // LED1 acende durante a queda
    digitalWrite(LED2_PIN, LOW);
    delay(30);
  }
  noTone(BUZZER_PIN);
  digitalWrite(LED1_PIN, LOW);

  delay(200); // pausa antes da "explosão"

  // Explosão (tons rápidos + LEDs piscando)
  for (int i = 0; i < 50; i++) {
    int freq = random(200, 2000); // frequências aleatórias
    tone(BUZZER_PIN, freq);

    // alterna LEDs para simular flash
    if (i % 2 == 0) {
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
    } else {
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
    }

    delay(20);
  }
  noTone(BUZZER_PIN);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);

  delay(500); // pausa longa antes de repetir
}
