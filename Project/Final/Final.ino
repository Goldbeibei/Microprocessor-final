#include "DHT.h"
#include <IRremote.h>

IRsend irsend;

void testRaw(char *label, unsigned int *rawbuf, int rawlen) {
    irsend.sendRaw(rawbuf, rawlen, 38 /* kHz */);
    delay(200);
}   

#define DHTPIN 2     // what digital pin we're connected to
#define DHTPIN1 5
//#define DHTPIN2 7
//#define DHTPIN3 10
const int LED_r_PIN = 13;  // LED燈的接腳
const int LED_b_PIN = 11; // LED燈的接腳
const int LED_g_PIN = 12;  //LED燈的接腳
const int buttonPin = 8;     // the number of the pushbutton pin
bool buttonState = 0;         // variable for reading the pushbutton status
bool ACState =0;           //冷氣狀態
// Uncomment whatever type you're using!
// #define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
DHT dht1(DHTPIN1, DHTTYPE);
//DHT dht2(DHTPIN2, DHTTYPE);
//DHT dht3(DHTPIN3, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  pinMode(buttonPin, INPUT);
  pinMode(LED_r_PIN, OUTPUT);
  pinMode(LED_b_PIN, OUTPUT);
  pinMode(LED_g_PIN, OUTPUT);
  dht.begin();
}
 // right on
unsigned int sendbuf1[] = { 
9032,4480,892,1384,536,1680,580,560,544,560,544,572,548,556,548,1680,568,1672,572,564,552,564,540,564,552,1680,576,556,548,556,548,568,548,1668,568,564,552,564,540,564,556,564,540,568,548,560,544,572,544,560,548,568,548,556,552,564,540,564,544,564,552,564,540,564,552,564,540,572,548,556,548,568,548,556,548,572,532,1680,568,576,540,1676,568,564,552,560,544,572,544,560,548,568,548,556,548,568,556,552,540,564,552,564,540,564,552,564,544,564,552,1680,572,560,544,560,548,568,536,568,552,564,544,564,540,564,552,564,540,564,552,572,532,572,548,556,548,568,548,556,548,560,544,572,540,564,552,564,540,564,556,564,540,564,552,556,548,572,544,1668,576,556,548,572,544,560,552,564,540,564,552,564,544,564,552,564,540,568,548,556,548,1704,544,564,548,1680,568,564,540,564,552,564,544,564,552,556,548,572,532,572,544,560,544,572,548,1668,580,1672,568,564,552,564,544,20164};
// right off
unsigned int sendbuf2[]  = { 
 9032,4472,892,1380,548,1700,564,556,536,568,548,556,548,572,544,1704,536,1708,548,560,552,564,540,572,548,1688,564,548,564,552,544,560,552,1696,552,560,552,564,540,564,552,560,544,572,548,556,548,568,548,556,548,560,544,572,552,552,552,564,544,564,552,564,540,564,552,556,548,572,544,560,544,572,548,556,548,560,544,1704,548,560,552,1700,548,568,544,560,544,572,548,556,548,568,548,560,544,560,552,564,540,564,552,564,540,564,552,564,544,568,548,1668,572,572,548,556,548,568,556,548,556,552,552,564,540,564,552,564,540,564,556,556,548,568,548,560,544,572,544,560,548,568,552,552,552,564,544,564,540,564,552,564,540,564,552,560,548,568,548,556,548,568,548,556,548,572,540,564,552,564,540,564,560,548,552,564,540,564,552,556,548,1680,576,556,548,1680,568,564,552,564,540,564,552,564,544,564,552,556,548,560,544,572,544,560,548,1680,568,564,552,564,540,564,552,20160};


void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  float t1 = dht1.readTemperature();
//  float t2 = dht2.readTemperature();
//  float t3 = dht3.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
//  if (isnan(t1) || isnan(t) || isnan(t2)|| isnan(t3)) {
//    Serial.println("Failed to read from DHT sensor!");
//    return;
//  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  buttonState = digitalRead(buttonPin);
  Serial.print("buttonState:");
  Serial.println(buttonState);
  if(buttonState)
  {
    ACState =!ACState;
    Serial.print("change state \nACState:");
    Serial.println(ACState);
  }
  if(t>=30)
  {
    if(t1>=25)
    {
      testRaw("RAW1", sendbuf1, sizeof(sendbuf1)/sizeof(int));
      testRaw("RAW1", sendbuf1, sizeof(sendbuf1)/sizeof(int));
      Serial.print("irsend \n");
      delay(1000);
      ACState =0;
    }
    else
    {
      ACState =1;
      Serial.print("AC on \n");
    }
  }
  else if(t<20)
  {
    if(t1<25)
    {
      testRaw("RAW2", sendbuf2, sizeof(sendbuf2)/sizeof(int));
      testRaw("RAW2", sendbuf2, sizeof(sendbuf2)/sizeof(int));
      Serial.print("irsend \n");
      delay(1000);
      ACState =1;
    }
    else
    {
      ACState =0;
      Serial.print("AC off \n");
    }
  }

  if(ACState)
  {
    if(t>=30)
        { 
          digitalWrite(LED_r_PIN, HIGH);
          digitalWrite(LED_b_PIN, LOW);
          digitalWrite(LED_g_PIN, LOW);
          Serial.print("LED red \n");
        }  
        else if(t<=30&&t>=28)
        {
          digitalWrite(LED_r_PIN, HIGH);
          digitalWrite(LED_b_PIN, LOW);
          digitalWrite(LED_g_PIN, HIGH);
          Serial.print("LED yellow \n");
        }
        else if(t<=28&&t1>=25)
        {
          digitalWrite(LED_r_PIN, LOW);
          digitalWrite(LED_b_PIN, LOW);
          digitalWrite(LED_g_PIN, HIGH); 
          Serial.print("LED green \n");              
        }
        else
        {
          digitalWrite(LED_r_PIN, LOW);
          digitalWrite(LED_b_PIN, HIGH);
          digitalWrite(LED_g_PIN, LOW);
          Serial.print("LED blue \n");
        }
  }
  //  Serial.print("Humidity: ");
  //  Serial.print(h);
  //  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" \n");
  Serial.print("Temperature1: ");
  Serial.print(t1);
  Serial.print(" \n");
//  Serial.print("Temperature2: ");
//  Serial.print(t2);
//  Serial.print(" %\n");
//  Serial.print("Temperature3: ");
//  Serial.print(t3);
//  Serial.print(" %\n");
  Serial.print("----------------------------------------------------------------------------------------------------- %\n");
}
