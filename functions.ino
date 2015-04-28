//Strip on function
void fronton() {
  frontStrip.setBrightness(200);
  for(uint16_t i=0; i<=frontNumber; i++) {
    frontStrip.setPixelColor(i, frontBlue);
  }
  frontStrip.show();
}

void backon() {
  backStrip.setBrightness(200);
  for(uint16_t i=0; i<=frontNumber; i++) {
    backStrip.setPixelColor(i, backOrange);
  }
  backStrip.show();
}

//Strip off function
void frontoff() {
  frontStrip.setBrightness(200);
  for(uint16_t i=0; i<=frontNumber; i++) {
    frontStrip.setPixelColor(i, frontStrip.Color(0,0,0));
  }
  frontStrip.show();
}

void backoff() {
  backStrip.setBrightness(200);
  for(uint16_t i=0; i<=frontNumber; i++) {
    backStrip.setPixelColor(i, backStrip.Color(0,0,0));
  }
  backStrip.show();
}

//pulse function
void pulsefront(uint8_t wait){
  for(uint16_t i=0; i<=frontNumber; i++) {
    frontStrip.setPixelColor(i, frontBlue);
  }

  frontBrightness = frontBrightness + frontFade;

  if(frontBrightness == 0 || frontBrightness == frontsetBrightness) {
    frontFade = -frontFade;
  }

  frontStrip.setBrightness(frontBrightness);
  frontStrip.show();
  delay(wait);

}

void pulseback(uint8_t wait){
  for(uint16_t i=0; i<=frontNumber; i++) {
    backStrip.setPixelColor(i, backOrange);
  }

  backBrightness = backBrightness + backFade;

  if(backBrightness == 0 || backBrightness == frontsetBrightness) {
    backFade = -backFade;
  }

  backStrip.setBrightness(backBrightness);
  backStrip.show();
  delay(wait);

}

//arrow side function
void arrowblue(uint8_t wait) {

  sideStrip.setBrightness(sidesetBrightness);


  for(uint16_t i=0; i<=sideNumber/2; i++) {
    sideStrip.setPixelColor(i, sideBlue);
    sideStrip.setPixelColor(sideNumber-i, sideBlue);
    sideStrip.show();
    delay(wait);
  }

  sideStrip.setBrightness(0);
  sideStrip.show();
}


void arroworange(uint8_t wait) {

  sideStrip.setBrightness(sidesetBrightness);


  for(uint16_t i=0; i<=sideNumber/2; i++) {
    sideStrip.setPixelColor(i, sideOrange);
    sideStrip.setPixelColor(sideNumber-i, sideOrange);
    sideStrip.show();
    delay(wait);
  }

  sideStrip.setBrightness(0);
  sideStrip.show();
}
