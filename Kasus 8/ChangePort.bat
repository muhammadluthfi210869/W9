@echo off
TITLE SonarQube Port Changer
echo ====================================
echo Mengubah Port SonarQube
echo ====================================

REM Set SonarQube Home
set SONAR_HOME=C:\Users\User\Downloads\sonarqube-25.3.0.104237 (1)\sonarqube-25.3.0.104237
echo SONAR_HOME diatur ke: %SONAR_HOME%

REM Tentukan port baru
set /p NEW_PORT="Masukkan port baru (misalnya 9090): "

echo.
echo Mengubah port menjadi %NEW_PORT%...
echo.

REM Buat backup file konfigurasi
copy "%SONAR_HOME%\conf\sonar.properties" "%SONAR_HOME%\conf\sonar.properties.bak"
echo File backup dibuat: %SONAR_HOME%\conf\sonar.properties.bak

REM Ubah port di file konfigurasi
type "%SONAR_HOME%\conf\sonar.properties" | findstr /v "sonar.web.port=" > "%SONAR_HOME%\conf\sonar.properties.new"
echo sonar.web.port=%NEW_PORT% >> "%SONAR_HOME%\conf\sonar.properties.new"
move /y "%SONAR_HOME%\conf\sonar.properties.new" "%SONAR_HOME%\conf\sonar.properties"

echo.
echo Port SonarQube berhasil diubah menjadi %NEW_PORT%
echo Silakan restart SonarQube dengan menggunakan RunSonarQube.bat
echo.

pause 