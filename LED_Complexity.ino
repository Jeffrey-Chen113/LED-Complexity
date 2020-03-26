//RGB Spectrum Cycling
//By: Jeffrey Chen
//This is essentially the Art 385 Sample Code switched around
//Comments are purely for my own understanding of the sample code

// Corresponds to the pins on RGB LED
const int redLED = 12;  //(pin 1)
const int greenLED = 27;  //(pin 3)
const int blueLED = 33;  //(pin 4)


//Frequence at 5000. Dunno why by it said so in the LoopStick and RandomNerd tutorials.
const int freq = 5000;
// 16 PWM channels available (0-15)
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;

//Resolution sets the range of the duty cycles
const int resolution = 8;
 
void setup(){
  //ledcSetup([which channel it will effect],[dunno],[range will be from 0-255)
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);
  
  //ledcAttachPin([Output pin],[settings for pin])
  ledcAttachPin(redLED, redChannel);
  ledcAttachPin(greenLED, greenChannel);
  ledcAttachPin(blueLED, blueChannel);
}
 
void loop(){
  //loops through the colour spectrum
  redUp();
  greenDown();
  blueUp();
  redDown();
  greenUp();
  blueDown();
}

//Functions for increasing/decreasing rate at which LED flashes
void redUp(){
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(redChannel, dutyCycle);
    delay(15);
  }
}
void redDown(){
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(redChannel, dutyCycle);  
    delay(15); 
  }
}
void greenUp(){
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(greenChannel, dutyCycle);
    delay(15);
  }
}
void greenDown(){
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(greenChannel, dutyCycle); 
    delay(15);  
  }
}
void blueUp(){
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(blueChannel, dutyCycle);
    delay(15);
  }
}
void blueDown(){
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(blueChannel, dutyCycle);
    delay(15);   
  }
}
