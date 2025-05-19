@echo off
TITLE SonarQube Server
echo ====================================
echo Memulai SonarQube Server...
echo ====================================

REM Set JAVA_HOME menjadi JDK yang terinstal 
set JAVA_HOME=C:\Program Files\Java\jdk-21
echo JAVA_HOME diatur ke: %JAVA_HOME%

REM Set SonarQube Home
set SONAR_HOME=C:\Users\User\Downloads\sonarqube-25.3.0.104237 (1)\sonarqube-25.3.0.104237
echo SONAR_HOME diatur ke: %SONAR_HOME%

REM Memeriksa Java Version
echo Versi Java:
"%JAVA_HOME%\bin\java" -version

REM Tambahkan parameter JVM untuk SonarQube
set SONAR_JAVA_OPTS=-Xmx1024m -XX:+HeapDumpOnOutOfMemoryError -Djava.net.preferIPv4Stack=true

echo.
echo Memulai SonarQube Server dengan parameter JVM: %SONAR_JAVA_OPTS%
echo.
echo CATATAN: Jangan tutup jendela ini! Server akan berhenti jika jendela ditutup.
echo.
echo Tunggu beberapa menit... SonarQube akan tersedia di http://localhost:9000
echo.

REM Menjalankan SonarQube
cd "%SONAR_HOME%\bin\windows-x86-64"
StartSonar.bat

pause