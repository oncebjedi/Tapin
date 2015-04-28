//for Ford ODB tap-in/tap-out pad

#include <Adafruit_NeoPixel.h>

#define frontneoPin 2
#define backneoPin 4
#define sideneoPin 3

#define frontsensorPin A0
#define backsensorPin A1

//number of pixels
int frontNumber = 16;
int sideNumber = 18;

//strip setup
Adafruit_NeoPixel frontStrip = Adafruit_NeoPixel(frontNumber, frontneoPin);
Adafruit_NeoPixel backStrip = Adafruit_NeoPixel(frontNumber, backneoPin);
Adafruit_NeoPixel sideStrip = Adafruit_NeoPixel(sideNumber, sideneoPin);

//color setup
uint32_t frontBlue = frontStrip.Color(44, 163, 225);
uint32_t backOrange = backStrip.Color(255, 69, 0);

uint32_t sideBlue = sideStrip.Color(44, 163, 225);
uint32_t sideOrange = sideStrip.Color(255, 69, 0);

//brightness setup
int frontsetBrightness = 200;
int sidesetBrightness = 200;

//delay setup
int pulseDelay = 5;
int arrowDelay = 50;

//real-time brightness of LEDs pulsing
int frontBrightness = 0;
int backBrightness = 0;

//real-time fade of LEDs pulsing
int frontFade = 1;
int backFade = 1;

//real-time sensor value
int frontValue = 0;
int backValue = 0;

//Flags
int frontFlag = 0;
int backFlag = 0;

//Begin or End
int frontState = 0;
int backState = 0;

//Analog reading start value
int analogstart = 580;

void setup() {

  Serial.begin (9600);

  pinMode(frontsensorPin, INPUT);
  pinMode(backsensorPin, INPUT);

  frontStrip.begin();

  backStrip.begin();

  sideStrip.begin();


}
void loop() {
  //clean analog read
  frontValue = 0;
  backValue = 0;

  //check to start pulsing
  frontValue = analogRead (frontsensorPin);
  backValue = analogRead (backsensorPin);


  if(frontValue >= analogstart && frontState == 0) {
    frontState = 1;
    delay(1000);
  }

  if(backValue >= analogstart && backState == 0) {
    backState = 1;
    delay(1000);
  }

  //start pulsing
  if(frontState == 1 || backState == 1) {
    pulsefront(pulseDelay);
    pulseback(pulseDelay);

    //clean analog read
    frontValue = 0;
    backValue = 0;

    //check to start tap-in/tap-out
    frontValue = analogRead (frontsensorPin);
    backValue = analogRead (backsensorPin);

    //tap-in flag hold until a pulse complete
    if(frontValue >= analogstart) {
      frontFlag = 1;
    }

    //tap-in behaviour
    if(frontFlag == 1 && frontBrightness == 0)  {
      delay(600);

      fronton();
      delay(100);
      frontoff();
      delay(100);
      fronton();
      delay(200);
      frontoff();
      delay(500);

      arrowblue(arrowDelay);
      arrowblue(arrowDelay);
      arrowblue(arrowDelay);

      frontBrightness = 0;
      frontFade = 1;
      backBrightness = 0;
      backFade = 1;
      frontFlag = 0;
      delay(1000);

      frontState = 0;
      backState = 0;

    }

    //tap-out flag hold until a pulse complete    
    if(backValue >= analogstart) {
      backFlag = 1;
    }

    //tap-out behaviour
    if(backFlag == 1 && backBrightness == 0)  {
      delay(600);

      backon();
      delay(100);
      backoff();
      delay(100);
      backon();
      delay(200);
      backoff();
      delay(500);

      arroworange(arrowDelay);
      arroworange(arrowDelay);
      arroworange(arrowDelay);

      frontBrightness = 0;
      frontFade = 1;
      backBrightness = 0;
      backFade = 1;
      backFlag = 0;
      delay(1000);

      frontState = 0;
      backState = 0;

    }
  }
}







