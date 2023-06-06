// constants won't change. They're used here to set pin numbers:
const int buttonPin = 8;     // the number of the pushbutton pin


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.print( buttonState);
  Serial.println();
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.print( buttonState);
  } else {
  Serial.print( buttonState);
  }
}
