# Modul 3 — Integrasi ESP32 dengan Blynk Cloud

## 1. Deskripsi
Modul ini membahas integrasi mikrokontroler ESP32 dengan platform Blynk Cloud untuk mengendalikan dan memantau sistem motor melalui jaringan Wi-Fi.

## 2. Tujuan
- Menghubungkan ESP32 dengan jaringan Wi-Fi.
- Mengintegrasikan ESP32 dengan Blynk Cloud.
- Mengendalikan motor melalui dashboard Blynk.
- Memahami konfigurasi program dan komunikasi perangkat dengan Blynk.

## 3. Alat dan Bahan
- ESP32
- Driver motor dan motor DC
- Laptop atau komputer
- Kabel USB
- Arduino IDE
- Blynk IoT
- Library Blynk untuk ESP32

## 4. Konfigurasi
Program menggunakan library `WiFi.h` dan `BlynkSimpleEsp32.h`. Konfigurasi meliputi Template ID, Template Name, Auth Token, SSID Wi-Fi, dan password Wi-Fi.

Kredensial asli disimpan secara pribadi dan tidak dicantumkan dalam repository publik.

## 5. Cara Kerja
ESP32 terhubung ke jaringan Wi-Fi, kemudian berkomunikasi dengan Blynk Cloud. Perintah dari dashboard Blynk digunakan untuk mengendalikan motor sesuai program yang telah dibuat.

## 6. Pengujian
Pengujian dilakukan dengan memeriksa koneksi ESP32, mengoperasikan kontrol motor melalui dashboard Blynk, dan mengamati respons perangkat.

Hasil pengujian serta dokumentasinya dicantumkan berdasarkan praktik yang benar-benar dilakukan.

## 7. Dokumentasi
Folder `bukti-pengujian/` berisi screenshot program, Serial Monitor, dashboard Blynk, dan dokumentasi rangkaian.

## 8. Kesimpulan
Modul ini bertujuan menerapkan komunikasi ESP32 dengan Blynk Cloud untuk mendukung kontrol motor melalui jaringan Wi-Fi. Keberhasilan setiap fungsi dicatat berdasarkan hasil pengujian praktikum.
