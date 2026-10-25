# Tugas 4 — Pemrograman OTA Berbasis Blynk pada ESP32

## 1. Deskripsi Proyek

Proyek ini merupakan implementasi sistem kendali motor DC menggunakan ESP32 dengan aplikasi Blynk IoT sebagai antarmuka kontrol dan monitoring. Sistem dilengkapi dengan fitur Over-The-Air (OTA), yaitu pembaruan program ESP32 melalui jaringan Wi-Fi tanpa harus mengunggah program menggunakan kabel USB setiap kali terjadi perubahan kode.

Selain mengendalikan motor, sistem juga membaca kecepatan putaran motor menggunakan sensor RPM dan menampilkan hasil pembacaannya melalui Serial Monitor.

## 2. Tujuan

- Mengimplementasikan komunikasi ESP32 dengan Blynk IoT.
- Mengendalikan motor DC melalui aplikasi Blynk.
- Mengatur kecepatan motor menggunakan PWM.
- Membaca dan memantau putaran motor dalam RPM.
- Menerapkan pembaruan firmware ESP32 melalui ArduinoOTA.

## 3. Alat dan Bahan

Perangkat dan perangkat lunak yang digunakan dalam proyek ini meliputi:

- ESP32 sebagai mikrokontroler.
- Motor DC dan driver motor.
- Sensor RPM untuk membaca kecepatan putaran.
- Kabel USB dan sumber daya.
- Laptop atau komputer.
- Arduino IDE.
- Blynk IoT.
- Library ArduinoOTA.

## 4. Konfigurasi Pin ESP32

| Komponen | GPIO |
|---|---|
| LED | GPIO 2 |
| Arah motor 1 | GPIO 27 |
| Arah motor 2 | GPIO 26 |
| PWM motor | GPIO 12 |
| Sensor RPM | GPIO 13 |

Sensor RPM dikonfigurasi dengan dua lubang pembacaan per putaran sesuai pengaturan program.

## 5. Fitur Sistem

### Kontrol Motor

Motor dapat dinyalakan atau dimatikan melalui tombol pada dashboard Blynk. Program juga menyediakan kontrol melalui Serial Monitor menggunakan perintah `1` untuk ON dan `0` untuk OFF.

### Pengaturan PWM

Nilai PWM digunakan untuk mengatur keluaran kendali kecepatan motor. Program menyediakan perintah `+` untuk menaikkan PWM dan `-` untuk menurunkannya.

### Monitoring RPM

Sensor membaca pulsa putaran motor dan program menghitung kecepatan putaran dalam satuan RPM. Hasil pembacaan ditampilkan melalui Serial Monitor dan dapat dipantau melalui dashboard Blynk sesuai konfigurasi program.

### Pembaruan Firmware OTA

ArduinoOTA digunakan agar firmware ESP32 dapat diperbarui melalui jaringan Wi-Fi. Perangkat harus terhubung ke jaringan yang dapat dijangkau komputer pengunggah, dan proses upload dilakukan melalui port jaringan ESP32.

## 6. Konfigurasi Blynk

Virtual pin yang digunakan dalam program:

| Virtual Pin | Fungsi |
|---|---|
| V0 | Monitoring RPM |
| V1 | Monitoring PWM |
| V2 | Kontrol nilai PWM |
| V3 | Kontrol ON/OFF motor |

Template Blynk, token autentikasi, serta koneksi Wi-Fi harus dikonfigurasi sebelum program dijalankan. Informasi autentikasi tidak disertakan dalam repository publik.

## 7. Langkah Penggunaan

1. Buka file `Tugas4_OTA_Blynk.ino` melalui Arduino IDE.
2. Pastikan library yang dibutuhkan sudah tersedia.
3. Masukkan konfigurasi Wi-Fi dan Blynk yang sesuai.
4. Hubungkan ESP32 ke komputer melalui USB untuk konfigurasi dan pengujian awal.
5. Unggah program dan periksa koneksi ESP32 melalui Serial Monitor.
6. Buka dashboard Blynk dan uji kontrol motor serta monitoring RPM.
7. Setelah ESP32 terhubung ke jaringan, pilih port jaringan ESP32 di Arduino IDE untuk melakukan upload OTA.

## 8. Hasil Pengujian

Berdasarkan pengujian yang telah dilakukan:

- ESP32 menampilkan alamat IP `192.168.32.47` pada Serial Monitor.
- Hostname OTA yang digunakan adalah `iMCLab-ESP32`.
- Motor merespons perintah kontrol dari dashboard Blynk.
- Sensor RPM menghasilkan pembacaan, antara lain 30, 60, 90, dan 180 RPM pada waktu pengamatan yang berbeda.
- ESP32 merespons perintah ping melalui jaringan dengan kehilangan paket 0% pada pengujian tersebut.

Hasil di atas menunjukkan bahwa fungsi dasar kendali dan monitoring telah berjalan saat pengujian. Keberhasilan upload firmware melalui OTA perlu dikonfirmasi melalui hasil proses upload yang menyatakan berhasil.

## 9. Dokumentasi

## Blynk dasboard

![Tampilan Blynk dasboard](Dokumentasi/Blynk%20dasboard.jpg)
## Serial Monitor

![Tampilan Serial Monitor](Dokumentasi/serial%20monitor.jpg)

## 10. Kesimpulan

Proyek ini menerapkan kendali motor DC dan monitoring RPM menggunakan ESP32 serta Blynk IoT. ESP32 dapat terhubung ke jaringan, menerima perintah kontrol motor, dan menampilkan pembacaan sensor RPM. ArduinoOTA disiapkan untuk mendukung pembaruan firmware melalui Wi-Fi. Keberhasilan proses pembaruan OTA harus didukung oleh bukti upload yang berhasil.


