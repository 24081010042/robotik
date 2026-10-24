# LAPORAN MODUL 2
## KONTROL MOTOR DC DAN LED MENGGUNAKAN PWM PADA ESP32 DENGAN KOMUNIKASI SERIAL

### 1. Tujuan Praktikum

1. Memahami cara mengontrol motor DC menggunakan ESP32.
2. Memahami penggunaan PWM (*Pulse Width Modulation*) untuk mengatur kecepatan motor.
3. Mengontrol LED sebagai indikator kondisi motor.
4. Menghubungkan ESP32 dengan Python melalui komunikasi serial.
5. Menerapkan perintah untuk menghidupkan, mematikan, serta menaikkan dan menurunkan kecepatan motor.

### 2. Alat dan Bahan

1. ESP32.
2. Motor DC.
3. Driver motor yang sesuai dengan motor DC.
4. LED atau LED bawaan ESP32.
5. Kabel USB.
6. Komputer atau laptop.
7. Arduino IDE.
8. Visual Studio Code.
9. Python dan pustaka `pyserial`.

### 3. Dasar Teori

**ESP32** merupakan mikrokontroler yang dapat digunakan untuk mengendalikan perangkat elektronik melalui pin input dan output. Pada praktikum ini, ESP32 digunakan untuk mengontrol motor DC dan LED.

**PWM (Pulse Width Modulation)** adalah teknik pengaturan daya dengan mengubah nilai *duty cycle*. Pada program ini, nilai PWM berada pada rentang 0 sampai 255. Nilai yang lebih tinggi umumnya membuat motor berputar lebih cepat, tergantung pada motor, driver, dan beban yang digunakan.

**Komunikasi serial** digunakan untuk mengirimkan perintah dari Python di Visual Studio Code menuju ESP32. Perintah tersebut kemudian diproses oleh program yang telah diunggah melalui Arduino IDE.

### 4. Perancangan Sistem

Praktikum ini menggunakan dua program yang saling terhubung, yaitu:

1. `modul2_kontrol_pwm.ino`, yaitu program Arduino IDE yang dijalankan pada ESP32.
2. `Tes_IMCLab_naik_turun.ipynb`, yaitu program Python yang digunakan untuk mengirimkan perintah melalui komunikasi serial.

Alur kerja sistem:

Python di Visual Studio Code → Komunikasi Serial USB → ESP32 → Driver Motor → Motor DC.

LED digunakan sebagai indikator ketika motor dihidupkan atau dimatikan.

### 5. Implementasi Program

#### 5.1 Program Arduino IDE

Program Arduino IDE berfungsi sebagai firmware yang dijalankan oleh ESP32. Program mengatur pin LED, pin arah motor, dan pin PWM.

Pin yang digunakan dalam program adalah:

| Komponen | Pin ESP32 |
|---|---|
| LED | GPIO 2 |
| Arah motor 1 | GPIO 27 |
| Arah motor 2 | GPIO 26 |
| PWM motor | GPIO 12 |

Frekuensi PWM yang digunakan adalah 30.000 Hz dengan resolusi 8 bit. Nilai awal PWM adalah 200.

Program menerima perintah serial berikut:

| Perintah | Fungsi |
|---|---|
| `1` | Menghidupkan motor dan LED |
| `0` | Mematikan motor dan LED |
| `+` | Menaikkan PWM sebesar 10 |
| `-` | Menurunkan PWM sebesar 10 |
| `PWM:150` | Mengatur PWM langsung menjadi 150 |

#### 5.2 Program Python di Visual Studio Code

Program Python berfungsi untuk mendeteksi port serial, menghubungkan komputer dengan ESP32, serta mengirimkan perintah kontrol motor.

Program menggunakan pustaka `pyserial` untuk komunikasi serial dengan baud rate 115200. Program juga memiliki fitur pengujian otomatis dan mode interaktif agar pengguna dapat memasukkan perintah secara langsung.

Pada pengujian otomatis, program menghidupkan motor, menaikkan PWM sebanyak tiga kali, menurunkannya sebanyak dua kali, mengatur PWM menjadi 150, lalu mematikan motor.

### 6. Langkah-Langkah Praktikum

1. Menyiapkan ESP32, motor DC, driver motor, dan kabel penghubung.
2. Membuka program `modul2_kontrol_pwm.ino` di Arduino IDE.
3. Memilih board dan port ESP32 yang sesuai.
4. Mengunggah program ke ESP32.
5. Memastikan ESP32 terhubung ke komputer melalui USB.
6. Membuka notebook `Tes_IMCLab_naik_turun.ipynb` di Visual Studio Code.
7. Memastikan pustaka Python `pyserial` telah terpasang.
8. Menjalankan notebook untuk mendeteksi port dan menghubungkan Python dengan ESP32.
9. Mengamati respons motor terhadap perintah yang dikirim.
10. Menguji mode interaktif dan memastikan motor berhenti saat diberikan perintah `0`.

### 7. Hasil dan Pembahasan

Pengujian dilakukan dengan mengirimkan perintah dari Python ke ESP32 melalui komunikasi serial. ESP32 menerima perintah tersebut dan menjalankan fungsi yang sesuai.

| Pengujian | Perintah | Hasil yang diharapkan |
|---|---|---|
| Menghidupkan motor | `1` | Motor berputar dan LED menyala |
| Menaikkan kecepatan | `+` | Nilai PWM bertambah 10 |
| Menurunkan kecepatan | `-` | Nilai PWM berkurang 10 |
| Mengatur PWM langsung | `PWM:150` | Nilai PWM menjadi 150 |
| Mematikan motor | `0` | Motor berhenti dan LED mati |

Perintah `+` dan `-` mengubah nilai PWM dengan selisih 10. Program membatasi nilai PWM agar tetap berada pada rentang 0 sampai 255. Pengaturan tersebut mencegah nilai PWM melebihi batas yang telah ditentukan.

Program Python juga menyediakan mode interaktif sehingga pengguna dapat mengontrol motor tanpa harus menjalankan ulang seluruh pengujian otomatis.

*Catatan: Tabel di atas berisi hasil yang diharapkan berdasarkan kode. Sesuaikan dengan hasil pengamatan praktikum yang benar-benar dilakukan.*

### 8. Kesimpulan

Berdasarkan rancangan dan implementasi program, ESP32 dapat digunakan untuk mengontrol motor DC dan LED melalui komunikasi serial dengan Python. PWM digunakan untuk mengatur nilai kendali kecepatan motor, sedangkan perintah serial memudahkan pengguna menghidupkan, mematikan, menaikkan, menurunkan, dan mengatur nilai PWM secara langsung.

Praktikum ini menunjukkan penerapan komunikasi antara program Python di komputer dan mikrokontroler ESP32. Keberhasilan pengujian secara fisik perlu disesuaikan dengan hasil pengamatan saat perangkat dijalankan.

### 9. Dokumentasi

Dokumentasi praktikum Modul 2 terdiri dari:

1. **Screenshot Hasil Pengujian Serial**
   ![Hasil Pengujian Serial](dokumentasi/Screenshot%20hasil%20pengujian%20serial.png)
   Menampilkan hasil komunikasi antara Python dan ESP32, termasuk perintah motor ON/OFF serta perubahan nilai PWM.

3. **Foto ESP32 dan Motor DC Saat Pengujian**
  ![ESP32 dan Motor DC](dokumentasi/Foto%20ESP32%20dan%20motor%20DC%20saat%20pengujian.jpg)
   Menampilkan perangkat keras yang digunakan saat praktikum berlangsung.

Dokumentasi ini digunakan sebagai bukti pelaksanaan pengujian sistem kontrol motor DC menggunakan PWM pada ESP32.

