int MicPin = A0;
int magnetPin = 9;
int potMeterPin = A1;

#define MicSamples (1024*2)

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(magnetPin, OUTPUT);   
  pinMode(MicPin, INPUT); 
  pinMode(potMeterPin, INPUT);   
}

void loop() {
  //read potmeter value
  int potMeterValue = analogRead(potMeterPin);
  //Serial.println(potMeterValue);

  //calc mic value
  long signalAvg = 0, signalMax = 0, signalMin = 1024, t0 = millis();
  
  for (int i = 0; i < MicSamples; i++)
  {
      int k = analogRead(MicPin);
      signalMin = min(signalMin, k);
      signalMax = max(signalMax, k);
      signalAvg += k;
  }
  signalAvg /= MicSamples;

  //set sensability
  int sensability = potMeterValue + 300;
  Serial.println(sensability);
    Serial.println("");

  //control magnet
  if(signalMax > sensability){
    
    Serial.println(signalMax);
    digitalWrite(magnetPin, HIGH);
    delay(90);
    digitalWrite(magnetPin,LOW);
    delay(90);
  
  }
  else{
     Serial.println(0);
  }
       
}
