Implementasi ESP32 dengan Blynk pada Sistem iMCLab
Laporan Praktikum Robotika
Nama: Valan Akbar Saputra
NPM: 24081010042
Topik: iMCLab Blynk
1. Pendahuluan
Internet of Things (IoT) memungkinkan perangkat elektronik dipantau dan dikendalikan melalui jaringan internet. Pada praktikum ini, ESP32 digunakan sebagai pengendali yang menjalankan program Arduino dan disiapkan untuk berkomunikasi dengan platform Blynk. Integrasi ini ditujukan untuk membantu pemantauan RPM serta pengaturan PWM dan kondisi motor pada sistem iMCLab.
2. Tujuan Praktikum
- Mengunggah program Arduino ke papan ESP32.
- Menyiapkan komunikasi ESP32 dengan platform Blynk.
- Menggunakan virtual pin untuk pemantauan RPM dan PWM serta kontrol motor.
- Memeriksa program melalui Serial Monitor.
3. Dasar Teori
3.1 ESP32
ESP32 adalah mikrokontroler yang memiliki kemampuan komunikasi nirkabel, termasuk Wi-Fi. Perangkat ini dapat menjalankan program untuk membaca sensor, mengendalikan keluaran, dan bertukar data dengan layanan IoT.
3.2 Blynk
Blynk merupakan platform IoT yang menyediakan dashboard untuk memantau dan mengendalikan perangkat. Datastream virtual pin menjadi jalur pertukaran data antara program pada ESP32 dan widget dashboard.
3.3 PWM dan RPM
Pulse Width Modulation (PWM) digunakan untuk mengatur daya rata-rata ke motor melalui driver motor. Program menggunakan rentang PWM 0–255. RPM menunjukkan jumlah putaran motor per menit dan diperoleh dari sensor putaran.
4. Alat dan Bahan
- Papan ESP32 dan kabel USB.
- Komputer/laptop dengan Arduino IDE.
- Library Blynk untuk ESP32.
- Jaringan Wi-Fi 2,4 GHz.
- Akun dan template perangkat pada Blynk Console.
- Motor iMCLab, driver motor, dan sensor RPM untuk pengujian perangkat keras.
5. Konfigurasi Sistem
Bagian	Konfigurasi	Fungsi
Mikrokontroler	ESP32	Menjalankan program
IDE	Arduino IDE	Menulis, memeriksa, dan mengunggah program
Template ID	TMPL6lyzv5423	Identitas template Blynk
GPIO LED	2	LED indikator
Pin arah motor	27 dan 26	Mengendalikan arah motor
Pin PWM	12	Keluaran PWM motor
Pin sensor RPM	13	Masukan sensor putaran
V0	RPM	Tampilan RPM
V1	PWM Monitor	Pemantauan PWM
V2	PWM Control	Slider PWM 0–255
V3	Motor Switch	Kontrol ON/OFF bernilai 0 atau 1


Keamanan: Jangan mencantumkan Auth Token Blynk atau kata sandi Wi-Fi pada README atau repository publik. Gunakan placeholder pada kode yang diunggah ke GitHub.

6. Langkah Kerja
1. Membuka Arduino IDE dan memastikan board ESP32 serta library Blynk tersedia.
2. Mengisi Template ID, Template Name, Auth Token, nama Wi-Fi, dan kata sandi Wi-Fi secara lokal pada program.
3. Memastikan pengaturan PWM sesuai versi ESP32 Arduino Core 3.x.
4. Menekan Verify untuk memeriksa kompilasi program.
5. Menghubungkan ESP32 ke komputer melalui USB dan memilih port yang sesuai.
6. Menekan Upload untuk mengunggah program.
7. Membuka Serial Monitor dengan baud rate 115200.
8. Membuat datastream V0, V1, V2, dan V3 di Blynk Console serta menghubungkan widget yang sesuai.
9. Menguji koneksi, kontrol PWM, ON/OFF motor, dan pembacaan RPM.
7. Hasil Pengamatan
Proses upload menunjukkan penulisan data mencapai 100% dan verifikasi hash berhasil. Serial Monitor menampilkan pesan boot ESP32, teks Menghubungkan ke Blynk... dan kemudian iMCLab + Blynk Ready beserta daftar perintah serial. Hal ini menunjukkan program berjalan dan menu perintah serial ditampilkan.

Pesan tersebut saja belum cukup untuk memastikan perangkat berstatus Online di Blynk atau bahwa motor dan sensor RPM telah berhasil diuji.
Pengujian	Pengamatan	Status
Kompilasi	Verify selesai tanpa error berdasarkan konfirmasi pengguna	Berhasil
Upload	100% dan Hash of data verified	Berhasil
Program berjalan	Muncul iMCLab + Blynk Ready	Teramati
Koneksi Blynk	Status Online belum dikonfirmasi	Perlu verifikasi
Motor dan PWM	Belum ada hasil pengujian fisik yang dikonfirmasi	Perlu pengujian
Sensor RPM	Belum ada nilai RPM yang dikonfirmasi	Perlu pengujian


8. Analisis
Keberhasilan kompilasi dan upload menunjukkan program dapat dibangun dan dikirim ke ESP32. Pesan iMCLab + Blynk Ready menandakan bagian program yang menampilkan status siap telah dijalankan. Status koneksi Blynk tetap harus diperiksa melalui Blynk Console atau pesan koneksi yang jelas pada Serial Monitor.

Pengujian lanjutan perlu memastikan perubahan V1 saat slider V2 digerakkan, respons motor terhadap V3, serta pembacaan RPM pada V0 ketika motor berputar. Pengujian motor harus memperhatikan keselamatan, sambungan driver, catu daya, dan kondisi mekanis.
9. Dokumentasi
- [ ] Screenshot proses upload berhasil.
- [ ] Screenshot Serial Monitor yang menampilkan iMCLab + Blynk Ready.
- [ ] Screenshot dashboard Blynk dan status perangkat.
- [ ] Foto atau screenshot pengujian motor dan sensor RPM.
10. Kesimpulan
Program iMCLab berbasis ESP32 berhasil dikompilasi dan diunggah ke papan ESP32. Serial Monitor menampilkan pesan bahwa program berjalan dan siap digunakan. Integrasi Blynk dirancang menggunakan V0 untuk RPM, V1 untuk pemantauan PWM, V2 untuk pengaturan PWM, dan V3 untuk kontrol ON/OFF motor.
