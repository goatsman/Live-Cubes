int pinArray[] = {3, 5, 6, 9, 11, 10};
int count = 0;
int timer = 700;
int brightness = 0;    // how bright the LED is
int fadeAmount = 3;    // how many points to fade the LED by
int i = 0;
int lightPin = 0;  

void setup(){
  // we make all the declarations at once
  for (count=0;count<=6;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {

  /*analogWrite(pinArray[0], 255);
  analogWrite(pinArray[1], 255);
  analogWrite(pinArray[2], 255);
  analogWrite(pinArray[3], 255);
  analogWrite(pinArray[4], 255);
  analogWrite(pinArray[5], 255);*/
  
 for (count=0;count<6;count++) {
  for(i = 0; i< 50; i++){
    analogWrite(pinArray[count], brightness);
    brightness = brightness + fadeAmount;
    /*if (brightness == 5 || brightness == 255) {
      fadeAmount = -fadeAmount ;
    }*/
    delay(10);
    }
    brightness = 5;
    
    /*analogWrite(pinArray[count], 200);
    analogWrite(pinArray[count], 150);
    analogWrite(pinArray[count], 100);
    analogWrite(pinArray[count], 50);
    analogWrite(pinArray[count], 0);*/
    //Serial.println(analogRead(lightPin));
 }
 
}

