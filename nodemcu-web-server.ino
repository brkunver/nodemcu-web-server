#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "id";
const char* password = "pass";
ESP8266WebServer server(80);
void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected..!");
  Serial.print("Your IP : ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);

  server.begin();
  Serial.println("HTTP Server Started");
}
void loop() {
  server.handleClient();
}

String page = "<!DOCTYPE html><html><head> <title>NodeMcu</title></head><body> <h1>NodeMCU Server</h1></body></html>";

void handle_OnConnect() {
  server.send(200, "text/html", page);
}
