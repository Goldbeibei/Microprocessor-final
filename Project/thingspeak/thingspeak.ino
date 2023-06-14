#include <LWiFi.h>

#include <WiFiClient.h>

#define SITE_URL "www.mediatek.com"

#define WIFI_AP "E605" //請輸入所要連的AP名稱

#define WIFI_PWD "E605E605" // 請輸入AP 密碼

WiFiClient c;



void setup() {

 Serial.begin(115200);

 WiFi.begin(WIFI_AP,WIFI_PWD);



 Serial.println();

 Serial.print("Connecting to AP...");

 if(WiFi.connectWEP(WIFI_AP, WIFI_PWD) < 0)

 {

 Serial.println("FAIL!");

 return;

 }

 Serial.println("ok");

 Serial.print("Connecting to site...");

 if(!c.connect(SITE_URL, 80))

 {

 Serial.println("FAIL!");

 return;

 }

 Serial.println("ok");

 Serial.println("send HTTP GET request");

 c.println("GET / HTTP/1.1");

 c.println("Host: " SITE_URL);

 c.println("Connection: close");

 c.println();

}



void loop() {

 int v;

 while(c.available())

 {

 v = c.read();

 if(v < 0)

 break;

 Serial.print((char)v);

 }

 delay(100);

}
