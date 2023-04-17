# Hovercraft-Controller

Dieses Projekt ist ein Hovercraft-Controller mit einem ESP8266-Mikrocontroller und einem einfachen Webserver, um die Bewegung des Hovercrafts mit einer Joystick- und Tastenschnittstelle zu steuern.

## Funktionen

- Joystick-Steuerung des Hovercraft
- Schwebetaste zum Aktivieren/Deaktivieren der Schwebemotoren
- Webinterface zur Steuerung des Hovercrafts
- Echtzeitaktualisierung der Joystick-Werte im Webinterface
- ESP8266 als WLAN-Zugangspunkt (AP)

## Anforderungen

- [PlatformIO](https://platformio.org/) Entwicklungsumgebung
- ESP8266-Mikrocontroller (z.B. NodeMCU, Wemos D1 Mini, etc.)
- Motortreiber (z.B. L298N, L9110, etc.)
- Hovercraft-Motoren und Propeller
- Stromversorgung, die für Motoren geeignet ist
- Grundlegende Elektronikkomponenten (Kabel, Steckbrett, etc.)

## Installation und Einrichtung

1. Klone dieses Repository auf deinen lokalen Rechner.

2. Öffne das Projekt in PlatformIO.

3. Verbinde den ESP8266-Mikrocontroller mit deinem Computer.

4. Richte die Hardware-Verbindungen entsprechend dem Code ein:

    ```
    #define MotorLeft D5
    #define MotorRight D6
    #define HoverMotors D3
    ```

5. Bearbeite `main.cpp` und ändere die Variablen `ssid` und `pw` auf den gewünschten WLAN-Netzwerknamen und das Passwort.

    ```
    const char* ssid = "107";
    const char* pw = "MiLaLou100241!";
    ```

6. Lade den Code mit PlatformIO auf den ESP8266-Mikrocontroller hoch.

7. Versorge die Motoren und Motortreiber mit einer geeigneten Stromversorgung.

8. Verbinde dich mit dem vom ESP8266 erstellten WLAN-Netzwerk (SSID und Passwort sind die in Schritt 5 festgelegten).

9. Öffne einen Webbrowser und navigiere zu der im seriellen Monitor angezeigten IP-Adresse (z.B. `192.168.4.1`).

10. Verwende den Joystick und die Taste auf der Web-Oberfläche, um das Hovercraft zu steuern.

## Verwendung

Die Web-Oberfläche besteht aus einem Joystick zur Steuerung der linken und rechten Bewegung des Hovercrafts, einer Schwebetaste zum Aktivieren oder Deaktivieren der Schwebemotoren und einer Tabelle, die die aktuellen Werte des Joysticks und der Taste anzeigt.

- Bewege den Joystick nach links oder rechts, um die linke und rechte Bewegung des Hovercrafts zu steuern.
- Drücke die Schwebetaste, um die Schwebemotoren zu aktivieren oder zu deaktivieren.
- Die Tabelle zeigt die aktuellen Werte des Joysticks und der Taste zu Debugging-Zwecken an.

## Projektstruktur

- `main.cpp`: Haupt-Code-Datei mit den Setup- und Loop-Funktionen.
- `/data/index.html`: HTML-Datei für das Webinterface.
- `/data/joy.js`: JavaScript-Datei für die Joystick-Funktionalität.
- `/data/style.css`: CSS-Datei zum Gestalten der Web-Oberfläche.



English Version:

# Hovercraft Controller

This project is a Hovercraft Controller using an ESP8266 microcontroller with a simple web server to control the hovercraft's movement with a joystick and button interface.

## Features

- Joystick control for left and right movement
- Hover button to enable/disable hover motors
- Web interface to control the hovercraft
- Real-time updates of joystick values in the web interface
- ESP8266 as a WiFi Access Point (AP)

## Requirements

- [PlatformIO](https://platformio.org/) development environment
- ESP8266 microcontroller (e.g., NodeMCU, Wemos D1 Mini, etc.)
- Motor drivers (e.g., L298N, L9110, etc.)
- Hovercraft motors and propellers
- Power supply suitable for motors
- Basic electronics components (wires, breadboard, etc.)

## Installation and Setup

1. Clone this repository to your local machine.

2. Open the project in PlatformIO.

3. Connect the ESP8266 microcontroller to your computer.

4. Set up the hardware connections as shown in the code:

    ```
    #define MotorLeft D5
    #define MotorRight D6
    #define HoverMotors D3
    ```

5. Edit `main.cpp` and change the `ssid` and `pw` variables to your desired WiFi network name and password.

    ```
    const char* ssid = "107";
    const char* pw = "MiLaLou100241!";
    ```

6. Upload the code to the ESP8266 microcontroller using PlatformIO.

7. Power the motors and motor drivers with an appropriate power supply.

8. Connect to the WiFi network created by the ESP8266 (SSID and password are the ones set in step 5).

9. Open a web browser and navigate to the IP address displayed on the Serial Monitor (e.g., `192.168.4.1`).

10. Use the joystick and button on the web interface to control the hovercraft.

## Usage

The web interface consists of a joystick for controlling the left and right movement of the hovercraft, a hover button to enable or disable the hover motors, and a table displaying the current values of the joystick and button.

- Move the joystick left or right to control the left and right movement of the hovercraft.
- Press the hover button to enable or disable the hover motors.
- The table will display the current values of the joystick and button for debugging purposes.

## Project Structure

- `main.cpp`: Main code file containing the setup and loop functions.
- `/data/index.html`: HTML file for the web interface.
- `/data/joy.js`: JavaScript file for the joystick functionality.
- `/data/style.css`: CSS file for styling the web interface.
