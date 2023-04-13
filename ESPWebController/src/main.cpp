#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <LittleFS.h>

#define MotorLeft D5
#define MotorRight D6
#define HoverMotors D3

int int_x, int_y;
bool b1 = false;
const char* ssid = "107";
const char* pw = "MiLaLou100241!";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void handleUpdate(AsyncWebServerRequest *request) {
  if (request->hasParam("x", true) && request->hasParam("y", true) && request -> hasParam("b1", true)) {
    int_x = request->getParam("x", true)->value().toInt();
    int_y = request->getParam("y", true)->value().toInt();
    b1 = request->getParam("b1", true)->value() == "true" ? true : false;

    //clamp the values to 0-100
    int_y = constrain(int_y, 0, 100);

    int leftDutyCycle = int_y + (int_x < 0 ? int_x : 0);
    int rightDutyCycle = int_y - (int_x > 0 ? int_x : 0);

    leftDutyCycle = constrain(map(leftDutyCycle,0,100,255,0), 0, 255);
    rightDutyCycle = constrain(map(rightDutyCycle,0,100,255,0), 0, 255);

    //write the recieved data to the motors
    analogWrite(MotorLeft, leftDutyCycle);
    analogWrite(MotorRight, rightDutyCycle);
    digitalWrite(HoverMotors, b1 == true ? LOW : HIGH);

    Serial.println(b1);

    Serial.println("x: " + String(int_x) + " y: " + String(int_y));
    request->send(200, "text/plain", "OK");
  } else {
    request->send(400, "text/plain", "Bad Request");
    digitalWrite(MotorLeft, HIGH);
    digitalWrite(MotorRight, HIGH);
    digitalWrite(HoverMotors, HIGH);
  }
}


void setup() {

  Serial.begin(74880);

  pinMode(MotorLeft, OUTPUT);
  pinMode(MotorRight, OUTPUT);
  pinMode(HoverMotors, OUTPUT);
   
  digitalWrite(MotorLeft, HIGH);
  digitalWrite(MotorRight, HIGH);
  digitalWrite(HoverMotors, HIGH);


  // Mount LittleFS file system
  if (!LittleFS.begin()) {
    Serial.println("Failed to mount LittleFS file system");
    return;
  }

  // Connect to WiFi network
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, pw);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  // you can use this url to update the values
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", "text/html");
  });
  
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/style.css", "text/css");
  });

  server.on("/joy.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/joy.js", "text/javascript");
  });

  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "404 Not found");
  });

  server.on("/update", HTTP_POST, handleUpdate);
  
  server.begin();
}



void loop() {

}
