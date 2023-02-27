#include <Arduino.h>
#include <Wifi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "env.h"

 String url = "https://ecse-three-led-api.onrender.com/api/state";


const int pin1_led = 18;
const int pin2_led= 19;
const int pin3_led = 21;

void setup() {
  Serial.begin(9600);
  pinMode(pin1_led, OUTPUT);
  pinMode(pin2_led, OUTPUT);
  pinMode(pin3_led, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  Serial.println("");

  Serial.println("Loading");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    Serial.println("Connected to WIFI");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    
    String http_response;


    http.begin(url);
    http.addHeader("X-API-Key", API_KEY);

    int httpResponseCode = http.GET();

    Serial.println("");
    Serial.println("");

    if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        Serial.print("Response from server: ");
        http_response = http.getString();
        Serial.println(http_response);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();

      StaticJsonDocument<1024> doc;

      DeserializationError error = deserializeJson(doc, http_response);

      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
      }
      
      bool control_light_1 = doc["light_switch_1"]; 
      bool control_light_2 = doc["light_switch_2"]; 
      bool control_light_3 = doc["light_switch_3"]; 
  
      Serial.println("");
      Serial.println(control_light_1);
      Serial.println(control_light_2);
      Serial.println(control_light_3);
      digitalWrite(pin1_led, control_light_1);
      digitalWrite(pin2_led,control_light_2);
      digitalWrite(pin3_led, control_light_3);
      Serial.println("LED states updated");
      
  }
  else {
    return;
  }
}