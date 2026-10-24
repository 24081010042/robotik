
/*
  MODUL 1: Basic Robotika
  Kontrol LED dan Motor DC menggunakan ESP32

  Perintah Serial Monitor:
  1 = Motor dan LED ON
  0 = Motor dan LED OFF
*/

const int ledPin = 2;
const int motorIN1 = 27;
const int motorIN2 = 26;
const int motorPWM = 12;

const int freq = 5000;
const int resolution = 8;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);

  // Konfigurasi PWM ESP32 versi 3.x
  if (!ledcAttach(motorPWM, freq, resolution)) {
    Serial.println("Gagal mengatur PWM!");
    while (true) {
      delay(1000);
    }
  }

  // Kondisi awal: semua output mati
  digitalWrite(ledPin, LOW);
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, LOW);
  ledcWrite(motorPWM, 0);

  Serial.println("Modul 1 siap.");
  Serial.println("Ketik 1 untuk ON dan 0 untuk OFF.");
}

void loop() {
  if (Serial.available() > 0) {
    char perintah = Serial.read();

    if (perintah == '1') {
      digitalWrite(ledPin, HIGH);
      digitalWrite(motorIN1, HIGH);
      digitalWrite(motorIN2, LOW);
      ledcWrite(motorPWM, 200);

      Serial.println("Motor dan LED ON");
    }
    else if (perintah == '0') {
      ledcWrite(motorPWM, 0);
      digitalWrite(motorIN1, LOW);
      digitalWrite(motorIN2, LOW);
      digitalWrite(ledPin, LOW);

      Serial.println("Motor dan LED OFF");
    }
  }
}
