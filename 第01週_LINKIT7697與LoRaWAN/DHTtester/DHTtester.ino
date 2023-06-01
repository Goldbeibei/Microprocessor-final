//#include <SoftwareSerial.h>

// On LinkIt 7697, the RX pin must be one of the EINT pins, such as P2 and P3.
// There are no limitations on TX pin.
//SoftwareSerial mySerial(3, 11); // RX, TX

//=================================================================================

// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("\nDHTxx test!");

  Serial1.begin(115200);
  while (!Serial1) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
//  Serial1.println("here in Serial1!!!!!!!!");

  dht.begin();

  // set the data rate for the SoftwareSerial port
/*  mySerial.begin(19200); //this data rate is for EK-S76SXB
  while (!mySerial) {
    Serial.print(".");; // wait for serial port to connect.
  }
  delay(1000);
*/
  pinMode(12, OUTPUT);  //for rest LoRa module S76G
  digitalWrite(12, LOW);   // 
  delay(100);                       // wait for 0.1 second
  digitalWrite(12, HIGH);   // 
                       
  pinMode(12, INPUT_PULLUP);  //back to normal status 
  delay(2000);

  Serial1.print("mac join abp");  //reset the board
  Serial.println("mac join abp");
  delay(2000);

  Serial1.print("mac tx ucnf 2 1234567890");  //reset the board
  Serial.println("mac tx ucnf 2 1234567890"); //just for test
  delay(5000);
  
}

int val_h;   //humidity int part
int val_hp;  //humidity point part 
String lora_string; //string for TX

void loop() {

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  
////////////next for LoRa tx ////////////////////////////////////////////////////////////
  
  val_h = (int) h;
  val_hp=int ((h-val_h)*100);
  lora_string="mac tx ucnf 2 "; //for tx header
  if (val_h<10) lora_string+="0"; //for hex format
  lora_string+=val_h;
  if (val_hp<10) lora_string+="0";
  lora_string+=val_hp;
  Serial1.print(lora_string);  //tx now
  Serial.println(lora_string);
  
  delay(5000);
}
