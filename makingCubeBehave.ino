/*making cube behave*/

int lightPin1 = 0;  //define a pin for Photo resistor

int ledPin = 3;     //define a pin for LED

int sensorValue = 0; //calibrate the value on the beginning
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value
int averageValue = 0;

int counter = 0; // counter for the average value

int lightOn = 0; // was the movement on or not --- 0  or  1

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT ); //seting the port as OUTPUT for LED

    calibrateLDR();
}

void loop()
{

    
    
    //Serial.println(sensorValue); //Write the value of the photoresistor to the serial monitor.

    if(lightOn == 0){
        calibrate();
        calibrateLDR();
    }

    sensorValue = analogRead(lightPin1); // copy current value on the sensor
    Serial.println(sensorValue);
    
    if(sensorValue < averageValue){
      
    digitalWrite(ledPin, HIGH);
    //delay(100);
    lightOn = 0;
    
    }else{
    
    digitalWrite(ledPin, LOW);
    //delay(100);
    lightOn = 1;
    
    }
   
   //delay(100); //short delay for faster response to light.

}

void calibrate(){
  
    sensorValue = analogRead(lightPin1);
    
    counter = 0;
    averageValue = 0;
    
    for(int i = 0; i < 20; i++){
       counter += analogRead(lightPin1);
       if(i == 19){ averageValue = (counter/20);}
    }

    /*if(averageValue == sensorValue){
      Serial.println("yes");
    }else{ Serial.println("no");}*/

    /*Serial.print((averageValue));
    Serial.print(",");
    Serial.print((sensorValue));
    Serial.print("\n");*/
}

void calibrateLDR(){
  // calibrate during the first five seconds 
    while (millis() < 5000) {
      sensorValue = analogRead(lightPin1);

   // record the maximum sensor value
   if (sensorValue > sensorMax) {
     sensorMax = sensorValue;
   }

   // record the minimum sensor value
   if (sensorValue < sensorMin) {
     sensorMin = sensorValue;
   }
 }
}

