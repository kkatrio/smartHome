int incomingByte = 0; // for incoming serial data
int pinDeight = 8;
bool alarmRaised = false;

void generateSound(){
  for(unsigned int freq = 500; freq < 1000; freq++)
  {
    tone(pinDeight, freq, 100);
    delay(100);
  }

  //int inputValue = 1000;
  //int thisPitch = map(inputValue, 400, 1000, 120, 1500);
  //tone(pinDeight, thisPitch, 10000); // pin, frequency , duration
  //delay(1);        // delay in between reads for stability
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:+
    incomingByte = Serial.read();

    if (incomingByte == 49){

        alarmRaised = true;

        // turn on the lights
        digitalWrite(LED_BUILTIN, HIGH);

    }
    else if(incomingByte == 48){

      alarmRaised = false;

      // turn off the lights
        digitalWrite(LED_BUILTIN, LOW);
    }
    else
    {
      Serial.print("I received shit.");
    }
  }

  while(alarmRaised){
    generateSound();
  }
}
