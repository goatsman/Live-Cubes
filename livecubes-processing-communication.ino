
int lightPin[] = {0,1,2,3,4,5};  //define a pin for Photo resistor
int ledPin[] = {3,5,6,9, 10,11};     //define a pin for LED
int sensorsValues[] = {0,0,0,0,0,0}; //calibrate the value on the beginning
int sensorsMIN[] = {1023,1023,1023,1023,1023,1023};
int sensorsMAX[] = {0,0,0,0,0,0};

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    
    for(int i = 0; i < 6; i++){
      pinMode( ledPin[i], OUTPUT );
    }

    // calibrate during the first five seconds 
    while (millis() < 5000) {

    for(int i = 0; i < 6; i++){
      sensorsValues[i] = analogRead(lightPin[i]);

      if (sensorsValues[i] > sensorsMAX[i]) {
        sensorsMAX[i] = sensorsValues[i];
      }

      if (sensorsValues[i] < sensorsMIN[i]) {
        sensorsMIN[i] = sensorsValues[i];
      }
    }
  }
}

void loop()
{

    /*for(int i = 0; i < 6; i++){
      sensorsValues[i] = analogRead(lightPin[i]);
      sensorsValues[i] = map(sensorsValues[i], sensorsMIN[i], sensorsMAX[i], 0, 255);
      Serial.println(sensorsValues[i]);
      //Serial.print(sensorsValues[i]);
      //Serial.print(",");
      //sensorsValues[i] = constrain(sensorsValues[i], 0, 255);
    }*/

    for(int i = 0; i < 6; i++){
      sensorsValues[i] = analogRead(lightPin[i]);   
      Serial.print(analogRead(lightPin[i]));
      Serial.print(",");
    }

    for(int i = 0; i < 6; i++){
      Serial.print(sensorsMIN[i]);
      Serial.print(",");
    }

    Serial. println("");
    
    for(int i = 0; i < 6; i++){
      
      if(sensorsValues[i] < sensorsMIN[i]){
        analogWrite(ledPin[i], 255);
        delay(10);
      }else{
        analogWrite(ledPin[i], 0);
        delay(10);
      }
    }
}
