#include<Arduino.h>
#include<ESP8266WiFi.h>

const char* ssid  = "pk";
const char* password = "123456789";

WiFiServer server(80);
int relay = 4;

void setup()
{
  pinMode(relay,OUTPUT);
  Serial.begin(115200);
  Serial.print("connecting to");
  Serial.print(ssid);
  WiFi.begin(ssid,password);
  digitalWrite(relay, LOW);
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.print("WiFi connected");
  server.begin();
  Serial.print("Connected to:");
  digitalWrite(relay, HIGH);
  Serial.print(WiFi.localIP());
}
void loop()
{
  WiFiClient client = server.available();
  if(!client)
  {
    return;  
  }
  while(!client.available())
  {
    delay(1);  
  }
}

   
