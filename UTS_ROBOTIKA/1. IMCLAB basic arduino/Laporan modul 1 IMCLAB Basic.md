# MODUL 1 — BASIC ROBOTIKA MENGGUNAKAN KIT iMCLab

**Nama:** Valan Akbar Saputra  
**NPM:** 24081010042  
**Mata Kuliah:** Robotika

## 1. Tujuan

Memahami dasar pengendalian LED dan motor DC menggunakan ESP32 pada kit iMCLab melalui Serial Monitor Arduino IDE.

## 2. Alat dan Bahan

- Kit robotika iMCLab dengan ESP32
- Motor DC dan driver motor
- LED
- Kabel USB
- Laptop atau komputer
- Arduino IDE

## 3. Dasar Teori

ESP32 merupakan mikrokontroler yang dapat digunakan untuk mengendalikan perangkat elektronik. Pada praktikum ini, ESP32 menerima perintah melalui Serial Monitor untuk mengontrol LED dan motor DC.

Perintah `1` digunakan untuk menyalakan LED dan motor, sedangkan perintah `0` digunakan untuk mematikan LED dan motor. Pengaturan motor menggunakan sinyal PWM (*Pulse Width Modulation*) melalui driver motor.

## 4. Langkah-Langkah Praktikum

1. Menghubungkan kit iMCLab ke laptop menggunakan kabel USB.
2. Membuka Arduino IDE dan memasukkan program kontrol LED dan motor.
3. Memilih board ESP32 dan port yang sesuai.
4. Mengunggah program ke ESP32.
5. Membuka Serial Monitor dengan baud rate 115200.
6. Mengirim perintah `1` untuk menyalakan LED dan motor.
7. Mengirim perintah `0` untuk mematikan LED dan motor.
8. Mengamati hasil pengujian dan mengambil dokumentasi.

## 5. Hasil Pengujian

| Perintah | Hasil yang Diharapkan |
|---|---|
| `1` | LED menyala dan motor berputar |
| `0` | LED mati dan motor berhenti |

Berdasarkan pengujian yang dilakukan, motor berhasil berputar ketika diberikan perintah untuk menyala. Pengujian perintah mati dilakukan melalui Serial Monitor untuk memastikan motor dan LED dapat dikendalikan.

## 6. Dokumentasi

### Proses upload program

![Proses Upload Program](Dokumentasi/Proses%20upload%20program.jpg)

### Pengujian LED dan motor menyala

![Motor ON](Dokumentasi/motor%20ON.jpg)

### Pengujian LED dan motor mati

![Motor OFF](Dokumentasi/motor%20OFF.jpg)


## 7. Analisis

Pada praktikum ini, ESP32 berfungsi sebagai pengendali LED dan motor DC. Perintah yang dikirim melalui Serial Monitor diproses oleh program untuk mengatur kondisi LED dan motor.

Sinyal PWM digunakan untuk mengatur daya yang diberikan kepada motor. Dengan praktikum ini, dapat dipahami cara menghubungkan program mikrokontroler dengan perangkat keras pada kit iMCLab.

## 8. Kesimpulan

Praktikum Modul 1 memberikan pemahaman dasar mengenai penggunaan ESP32 untuk mengendalikan LED dan motor DC melalui Serial Monitor. Praktikum ini menjadi dasar untuk mempelajari pengendalian robot menggunakan Python, Blynk, dan OTA pada modul berikutnya.

## 9. File Program

Kode program Arduino disimpan secara terpisah pada file `modul1_basic_robotika.ino`.
