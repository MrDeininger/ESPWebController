Version 1 of my little ESP-Controller Project. Its a PlattformIO Project for WEMOSD1 Mini Boards.

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
