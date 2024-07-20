#include "WiFi.h"
#include "ESPAsyncWebServer.h"
// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "sardibahuthai";
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);
  IPAddress Ip(192, 168, 123, 123);    //setto IP Access Point same as gateway
  IPAddress NMask(255, 255, 255, 0);
  WiFi.softAPConfig(Ip, Ip, NMask);

  Serial.println("IP address: ");
  Serial.print("AP IP address: ");
  Serial.println(Ip);
  
  // Start server
  server.begin();
}
void loop(){}
