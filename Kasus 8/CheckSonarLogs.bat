@echo off
TITLE SonarQube Log Checker
echo ====================================
echo Memeriksa Log SonarQube untuk Error
echo ====================================

REM Set SonarQube Home
set SONAR_HOME=C:\Users\User\Downloads\sonarqube-25.3.0.104237 (1)\sonarqube-25.3.0.104237
echo SONAR_HOME diatur ke: %SONAR_HOME%

echo.
echo === LOG TERAKHIR DARI SONARQUBE ===
echo.

REM Menampilkan log terakhir, fokus pada error
cd "%SONAR_HOME%\logs"
type sonar.log | findstr -i "error exception failed failure"

echo.
echo === SELESAI ===
echo.

pause 