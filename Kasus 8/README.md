# Panduan Instalasi dan Penggunaan SonarQube

## Prasyarat
- Java 11+ (Anda telah menginstal Java 21, ini sudah cukup)
- RAM minimal 4GB (disarankan 8GB+)
- Ruang disk minimal 2GB

## Langkah Instalasi

1. Unduh SonarQube
   - Kunjungi https://www.sonarsource.com/products/sonarqube/downloads/
   - Unduh versi Community Edition (gratis)

2. Ekstrak file zip yang diunduh
   ```
   Expand-Archive -Path "lokasi\sonarqube-*.zip" -DestinationPath .
   ```

3. Konfigurasi (opsional)
   - SonarQube menggunakan database H2 untuk pengujian, tetapi untuk lingkungan produksi, sebaiknya gunakan PostgreSQL, Oracle, atau Microsoft SQL Server

4. Jalankan SonarQube
   - Masuk ke folder hasil ekstrak
   - Jalankan skrip startup:
     ```
     .\sonarqube-x.y.z\bin\windows-x86-64\StartSonar.bat
     ```

5. Akses SonarQube
   - Setelah server berjalan, buka browser dan kunjungi http://localhost:9000
   - Login dengan kredensial default:
     - Username: admin
     - Password: admin

## Penggunaan
1. Ganti password default saat pertama kali login
2. Buat proyek baru di SonarQube
3. Analisis kode menggunakan scanner yang sesuai (SonarScanner, Maven, Gradle, dll.)

## Mematikan Server
- Untuk menghentikan server, tutup jendela command prompt atau tekan Ctrl+C

## Catatan
- SonarQube membutuhkan waktu untuk memulai, biasanya 1-2 menit
- Port default adalah 9000, pastikan port ini tidak digunakan oleh aplikasi lain 