#include <Adafruit_NeoPixel.h>
#define PIN 8
#define NUMPIXELS 30
#define DELAY_TIME 50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Inicializamos nuestra cinta led RGB
  pixels.begin();
  randomSeed(850);

}

void loop() 
{
  NormalTimePixelSetting();
  delay(3000);
  GoUPNDown();
  delay(3000);
  GoUp();
  delay(3000);
  GoUpDown();
  delay(3000);
  
}

uint32_t getARandomColor()
{
  int r=random(0,255);
  int g=random(0,255);
  int b=random(0,255);
  return pixels.Color(r,g,b);
}
 void NormalTimePixelSetting()
 {
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i,getARandomColor());
    pixels.show();
    delay(DELAY_TIME);
  }
 }

 void GoUPNDown()
 {
  NormalTimePixelSetting();
  TurnOffPixelsSequentiallyDown();
 }

 void TurnOffPixelsSequentiallyDown()
 {
  for(int i=NUMPIXELS;i>=0;i--)
  {
    pixels.setPixelColor(i,pixels.Color(0,0,0));
    pixels.show();
    delay(DELAY_TIME);
  }
 }

  void TurnOffPixelsSequentiallyUP()
 {
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i,pixels.Color(0,0,0));
    pixels.show();
    delay(DELAY_TIME);
  }
 }

 void GoUp()
 {
  NormalTimePixelSetting();
  TurnOffPixelsSequentiallyUP();
 }

 void GoUpDown()
 {
  GoUPNDown();
  GoUp();
 }
