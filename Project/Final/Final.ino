#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
#define DHTPIN1 5
#define DHTPIN2 7
#define DHTPIN3 10
const int LED_r_PIN = 13;  // LED燈的接腳
const int LED_b_PIN = 11; // LED燈的接腳
const int LED_g_PIN = 12;  //LED燈的接腳
const int buttonPin = 8;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
// Uncomment whatever type you're using!
// #define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  pinMode(buttonPin, INPUT);
  pinMode(LED_r_PIN, OUTPUT);
  pinMode(LED_b_PIN, OUTPUT);
  pinMode(LED_g_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  float t1 = dht1.readTemperature();
  float t2 = dht2.readTemperature();
  float t3 = dht3.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  // float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(t1) || isnan(t) || isnan(t2)|| isnan(t3)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  buttonState = digitalRead(buttonPin);
  //  Serial.print("Humidity: ");
  //  Serial.print(h);
  //  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  if(t>=30)
  {
    while(!(t-t3>=1&&t-t2>=1&&t-t1>=1))
    {
      
    }
    
  }
  else if(
  if(t-t1>=0.5&&t>=28)
    { digitalWrite(LED_r_PIN, HIGH);
      digitalWrite(LED_b_PIN, LOW);
      digitalWrite(LED_g_PIN, LOW);
    }  
  else if(t-t1>=0.5&&t>=24&&t<=28)
    { digitalWrite(LED_r_PIN, HIGH);
      digitalWrite(LED_b_PIN, LOW);
      digitalWrite(LED_g_PIN, HIGH);
    } 
  else if(t-t1>=0.5&&t<=24)
 { digitalWrite(LED_r_PIN, LOW);
   digitalWrite(LED_b_PIN, HIGH);
   digitalWrite(LED_g_PIN, LOW);
 } 
  }
  Serial.print(" %\n");
  Serial.print("Temperature1: ");
  Serial.print(t1);
  Serial.print(" %\n");
  Serial.print("Temperature2: ");
  Serial.print(t2);
  Serial.print(" %\n");
  Serial.print("Temperature3: ");
  Serial.print(t3);
  Serial.print(" %\n");
  Serial.print("----------------------------------------------------------------------------------------------------- %\n");
}
