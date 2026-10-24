
#include <Arduino.h>
#include <esp_arduino_version.h>

#define LED_PIN 2
#define MOTOR_IN1 27
#define MOTOR_IN2 26
#define MOTOR_PWM 12

#define PWM_FREQ 30000
#define PWM_RESOLUTION 8

int duty = 200;
bool motorAktif = false;

void tulisPWM(int nilai) {
  nilai = constrain(nilai, 0, 255);

#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcWrite(MOTOR_PWM, nilai);
#else
  ledcWrite(0, nilai);
#endif
}

void motorOn() {
  motorAktif = true;
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  digitalWrite(LED_PIN, HIGH);
  tulisPWM(duty);
  Serial.println("Motor ON");
}

void motorOff() {
  motorAktif = false;
  tulisPWM(0);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Motor OFF");
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcAttach(MOTOR_PWM, PWM_FREQ, PWM_RESOLUTION);
#else
  ledcSetup(0, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(MOTOR_PWM, 0);
#endif

  motorOff();
  Serial.println("ESP32 siap menerima perintah Python");
}

void loop() {
  if (Serial.available()) {
    String perintah = Serial.readStringUntil('\n');
    perintah.trim();

    if (perintah == "1") {
      motorOn();
    }
    else if (perintah == "0") {
      motorOff();
    }
    else if (perintah == "+") {
      duty = min(duty + 10, 255);
      if (motorAktif) tulisPWM(duty);
      Serial.printf("PWM = %d\n", duty);
    }
    else if (perintah == "-") {
      duty = max(duty - 10, 0);
      if (motorAktif) tulisPWM(duty);
      Serial.printf("PWM = %d\n", duty);
    }
    else if (perintah.startsWith("PWM:")) {
      int nilai = perintah.substring(4).toInt();
      duty = constrain(nilai, 0, 255);
      if (motorAktif) tulisPWM(duty);
      Serial.printf("PWM diatur ke %d\n", duty);
    }
    else if (perintah.length() > 0) {
      Serial.println("Perintah tidak dikenal");
    }
  }
}
