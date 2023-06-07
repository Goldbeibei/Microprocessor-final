const int LED_r_PIN = 13;  // LED燈的接腳
const int LED_b_PIN = 11; // LED燈的接腳
const int LED_g_PIN = 12;  //LED燈的接腳
void setup()
{
  Serial.begin(115200);
  pinMode(LED_r_PIN, OUTPUT);
  pinMode(LED_b_PIN, OUTPUT);
  pinMode(LED_g_PIN, OUTPUT);
}

void loop() 
{
// if(t-t1>=0.5&&t>=28)
// { digitalWrite(LED_r_PIN, HIGH);
//   digitalWrite(LED_b_PIN, LOW);
//   digitalWrite(LED_g_PIN, LOW);
// }  
// else if(t-t1>=0.5&&t>=24&&t<=28)
// { digitalWrite(LED_r_PIN, HIGH);
//   digitalWrite(LED_b_PIN, LOW);
//   digitalWrite(LED_g_PIN, HIGH);
// } 
// else if(t-t1>=0.5&&t<=24)
// { digitalWrite(LED_r_PIN, LOW);
//   digitalWrite(LED_b_PIN, HIGH);
//   digitalWrite(LED_g_PIN, LOW);
// } 
   digitalWrite(LED_r_PIN, HIGH);
   digitalWrite(LED_b_PIN, LOW);
   digitalWrite(LED_g_PIN, LOW);
   delay(1000);
   digitalWrite(LED_r_PIN, HIGH);
   digitalWrite(LED_b_PIN, LOW);
   digitalWrite(LED_g_PIN, HIGH);
   delay(1000);
   digitalWrite(LED_r_PIN, LOW);
   digitalWrite(LED_b_PIN, HIGH);
   digitalWrite(LED_g_PIN, LOW);
   delay(1000);
   

}
