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
      sensorsValues[i] = constrain(sensorsValues[i], 0, 255);
    }*/

    //sensorsValues[0] = analogRead(lightPin[0]);
    //Serial.println((sensorsValues[0]));
    /*Serial.print("  ||  ");
    Serial.print((sensorsValues[1]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[2]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[3]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[4]));
    Serial.print("  ||  ");
    Serial.print((sensorsValues[5]));
    Serial.println("");*/

    for(int i = 0; i < 6; i++){
      sensorsValues[i] = analogRead(lightPin[i]);   
      Serial.print(analogRead(lightPin[i]));
      Serial.print(",");
    }

    Serial. println("");
    
    for(int i = 0; i < 6; i++){
      
      if(sensorsValues[i] < 350){
        analogWrite(ledPin[i], 255);
        delay(10);
        //analogWrite(ledPin[i], 0);
      }else{
        analogWrite(ledPin[i], 0);
        delay(10);
        //analogWrite(ledPin[i], 0);
        //digitalWrite(13,LOW);
      }
    }
}
