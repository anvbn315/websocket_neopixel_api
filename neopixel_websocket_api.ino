#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>
#include "websocket.h"
#include "config.h"
#include "wifi_connect.h"
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include "neopixel_bar.h"
#include "rtc.h"

WebSocketsClient webSocket;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);  
  pinMode(BTN, INPUT_PULLUP);  

  Serial.begin(115200);
  Serial.println("ESP8266 WebSocket Client");
  
  connect_wifi(ssid, password, ip_host, port);
  connect_websocket(webSocket, ip_host, port);
  handle_websocket_evt(webSocket);

  neopixel_setup();
  // setup_rtc();
}


void loop() {
  // Serial.println("loop");
  webSocket.loop();
  // uint8_t current_hour = rtc.now().hour(); // Extract the current hour
  // displayLedBaseOnHour(current_hour); // Call the function with the current hour
  displayHourOnNeoPixel();
  // print_now();
}