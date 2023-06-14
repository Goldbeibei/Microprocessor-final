//#include "DHT.h"
//#include <PubSubClient.h>
//#include <LWiFi.h>
//
//#define DHTPIN 3 
//#define DHTTYPE DHT22 
//
//DHT dht(DHTPIN, DHTTYPE);
#include <LWiFi.h>

char ssid[] = "E605";      //  your network SSID (name)
char pass[] = "E605E605";  // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;               // your network key Index number (needed only for WEP)


#define HOST    "api.thingspeak.com" // ThingSpeak IP Address: 184.106.153.149
#define PORT    80

String GET = "GET /update?key=EFQ5USXQC9KV4B96"; //輸入自己API的key

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(117,185,24,248);
char server[] = "api.thingspeak.com"; 

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);
    }

    int h = 458; //自已隨便寫濕度
    int t = 458; //自已隨便寫溫度
  
    Serial.println("Connected to wifi");
    printWifiStatus();

    Serial.println("\nStarting connection to server...");
    // if you get a connection, report back via serial:
    if (client.connect(server, 80)) {
        Serial.println("connected to server (GET)");

        Serial.print( "Humidityh: " );
        Serial.print( h );
        Serial.print( ", Temperature: " );
        Serial.println( t );

        String getStr = GET + "&field1=" + String((int)t) +
                              "&field2=" + String((int)h) +
                              " HTTP/1.1\r\n";;
        client.print( getStr );
        client.print( "Host: api.thingspeak.com\n" );
        client.print( "Connection: close\r\n\r\n" );
       
        delay(1000);

       // if there are incoming bytes available
       // from the server, read them and print them:
          while (client.available()) {
              char c = client.read();
              Serial.write(c);
              }
    }
}

void loop() {


    // if the server's disconnected, stop the client:
    if (!client.connected()) {
        Serial.println();
        Serial.println("disconnecting from server.");
        client.stop();

        // do nothing forevermore:
        while (true);
    }
}


void printWifiStatus() {
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}
