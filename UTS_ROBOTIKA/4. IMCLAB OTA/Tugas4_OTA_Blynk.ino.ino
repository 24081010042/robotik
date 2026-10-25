
#define BLYNK_TEMPLATE_ID "TMPL6lyzv5423"
#define BLYNK_TEMPLATE_NAME "iMCLab ESP32"
#define BLYNK_AUTH_TOKEN "OOilsd05fFt8C8vYcQUHDxVY08AQdXtI"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ArduinoOTA.h>

// Ganti sesuai Wi-Fi yang digunakan
char ssid[] = "Cod Tengah";
char pass[] = "11111111";

// Konfigurasi pin ESP32
const int LED_PIN = 2;
const int MOTOR_IN1 = 27;
const int MOTOR_IN2 = 26;
const int MOTOR_PWM = 12;
const int RPM_PIN = 13;

// Konfigurasi PWM
const int PWM_FREQ = 30000;
const int PWM_RESOLUTION = 8;
int pwmValue = 200;
bool motorOn = false;

// Sensor RPM: 2 lubang per putaran
const int HOLES_PER_ROTATION = 2;
volatile unsigned long pulseCount = 0;
unsigned long rpm = 0;

BlynkTimer timer;

// Menghitung pulsa sensor RPM
void IRAM_ATTR countPulse() {
  pulseCount++;
}

// Mengatur motor
void setMotor(bool state) {
  motorOn = state;

  digitalWrite(LED_PIN, motorOn ? HIGH : LOW);

  if (motorOn) {
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    ledcWrite(MOTOR_PWM, pwmValue);
  } else {
    ledcWrite(MOTOR_PWM, 0);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
  }

  if (Blynk.connected()) {
    Blynk.virtualWrite(V1, pwmValue);
    Blynk.virtualWrite(V3, motorOn ? 1 : 0);
  }

  Serial.println(motorOn ? "Motor ON" : "Motor OFF");
}

// Slider PWM Blynk: V2
BLYNK_WRITE(V2) {
  pwmValue = constrain(param.asInt(), 0, 255);

  if (motorOn) {
    ledcWrite(MOTOR_PWM, pwmValue);
  }

  Blynk.virtualWrite(V1, pwmValue);

  Serial.print("PWM: ");
  Serial.println(pwmValue);
}

// Switch motor Blynk: V3
BLYNK_WRITE(V3) {
  setMotor(param.asInt() == 1);
}

// Membaca dan mengirim RPM
void readRPM() {
  noInterrupts();
  unsigned long pulses = pulseCount;
  pulseCount = 0;
  interrupts();

  // Periode pembacaan 1 detik
  rpm = (pulses * 60UL) / HOLES_PER_ROTATION;

  Blynk.virtualWrite(V0, rpm);

  Serial.print("RPM: ");
  Serial.println(rpm);
}

// Memproses perintah Serial Monitor
void readSerial() {
  if (!Serial.available()) return;

  char cmd = Serial.read();

  if (cmd == '1') {
    setMotor(true);
  } else if (cmd == '0') {
    setMotor(false);
  } else if (cmd == '+') {
    pwmValue = min(pwmValue + 10, 255);
    if (motorOn) ledcWrite(MOTOR_PWM, pwmValue);
    if (Blynk.connected()) Blynk.virtualWrite(V1, pwmValue);
    Serial.printf("PWM: %d\n", pwmValue);
  } else if (cmd == '-') {
    pwmValue = max(pwmValue - 10, 0);
    if (motorOn) ledcWrite(MOTOR_PWM, pwmValue);
    if (Blynk.connected()) Blynk.virtualWrite(V1, pwmValue);
    Serial.printf("PWM: %d\n", pwmValue);
  } else if (cmd == 'R' || cmd == 'r') {
    Serial.printf("RPM terakhir: %lu\n", rpm);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(RPM_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);

  // ESP32 Arduino Core 3.x
  if (!ledcAttach(MOTOR_PWM, PWM_FREQ, PWM_RESOLUTION)) {
    Serial.println("Gagal mengatur PWM!");
    while (true) delay(1000);
  }
  ledcWrite(MOTOR_PWM, 0);

  attachInterrupt(digitalPinToInterrupt(RPM_PIN),
                  countPulse, FALLING);

  Serial.println("Menghubungkan ke Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Konfigurasi OTA
  ArduinoOTA.setHostname("iMCLab-ESP32");
  ArduinoOTA.setPassword("Bela negara 2024");

  ArduinoOTA
    .onStart([]() {
      Serial.println("OTA dimulai...");
      setMotor(false);
    })
    .onEnd([]() {
      Serial.println("\nOTA selesai!");
    })
    .onProgress([](unsigned int progress,
                   unsigned int total) {
      Serial.printf("Progres OTA: %u%%\r",
                    (progress * 100) / total);
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error OTA [%u]\n", error);
    });

  ArduinoOTA.begin();

  timer.setInterval(1000L, readRPM);

  Serial.println("\n==============================");
  Serial.println("iMCLab + Blynk + OTA Ready");
  Serial.println("==============================");
  Serial.println("1 = ON | 0 = OFF");
  Serial.println("+ = PWM naik | - = PWM turun");
  Serial.println("R = lihat RPM");
  Serial.print("Alamat IP ESP32: ");
  Serial.println(WiFi.localIP());
  Serial.println("OTA Hostname: iMCLab-ESP32");
}

void loop() {
  Blynk.run();
  ArduinoOTA.handle();
  timer.run();
  readSerial();
}
