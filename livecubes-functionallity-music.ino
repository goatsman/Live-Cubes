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

    for(int i = 0; i < 6; i++){
      sensorsValues[i] = analogRead(lightPin[i]);
      sensorsValues[i] = map(sensorsValues[i], sensorsMIN[i], sensorsMAX[i], 0, 255);
      sensorsValues[i] = constrain(sensorsValues[i], 0, 255);
    }

    Serial.print((sensorsValues[0]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[1]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[2]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[3]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[4]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[5]));
    Serial.println("");
    
        
      if(sensorsValues[3] == 0){
        analogWrite(ledPin[0], 255);
        analogWrite(ledPin[1], 255);
        analogWrite(ledPin[2], 255);
        analogWrite(ledPin[3], 255);
        analogWrite(ledPin[4], 255);
        analogWrite(ledPin[5], 255);
        delay(100);
        //analogWrite(ledPin[i], 0);
        /*analogWrite(ledPin[0], 0);
        analogWrite(ledPin[1], 0);
        analogWrite(ledPin[2], 0);
        analogWrite(ledPin[3], 0);
        analogWrite(ledPin[4], 0);
        analogWrite(ledPin[5], 0);
        delay(100);*/
      
      }else{
        analogWrite(ledPin[0], 0);
        analogWrite(ledPin[1], 0);
        analogWrite(ledPin[2], 0);
        analogWrite(ledPin[3], 0);
        analogWrite(ledPin[4], 0);
        analogWrite(ledPin[5], 0);
        delay(100);
      }
    }
