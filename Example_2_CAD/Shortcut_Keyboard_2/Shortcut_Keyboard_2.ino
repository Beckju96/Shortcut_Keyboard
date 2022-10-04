#include <TFT_eSPI.h> 
#include <Adafruit_NeoPixel.h>
#include "PluggableUSBHID.h"
#include "USBKeyboard.h"
#include "seeed_intro.h"
#include "Contest_Screen.h"

//include pages here:
#include "page_5.h"
#include "page_6.h"
#include "page_7.h"
#include "page_8.h"

//Define the number of pages (counting from 1 not 0):
int number_of_pages = 4;

//Add all pages to the array:
const unsigned short* pages[] = {
  page_5, 
  page_6, 
  page_7, 
  page_8};


USBKeyboard Keyboard;

TFT_eSPI tft = TFT_eSPI(); 
TFT_eSprite screen = TFT_eSprite(&tft);

int touchpad = D2;
int buttonpin = A1;

//Colors of the neopixel LEDs when powering up
int r = 0;
int g = 0;
int b = 100;

int current_page = 1;
int z = 0;  //varialbe used for for swipe animation 

#define NUMPIXELS 6
int PIN = D3;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(touchpad, INPUT);
  pinMode(buttonpin, INPUT);
  pixels.begin();

  pixels.setPixelColor(0, pixels.Color(r/8, g/8, b/8));
  pixels.show();

  pinMode(D6, OUTPUT);
  digitalWrite(D6, LOW);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true);
  digitalWrite(D6, HIGH);
  screen.createSprite(320, 172);
  screen.setSwapBytes(true);
  delay(2000);
  intro();
  delay(3000);
  tft.pushImage(0, 0, 320, 172, Contest_Screen);
  delay(3000);
  tft.pushImage(0, 0, 320, 172, pages[0]);
 }

void loop() {

  //void check_touchpad();

int buttonState = digitalRead(D2);

if(buttonState == 1)
{
  current_page = current_page +1;
  if(current_page==5)
  {
    current_page=1;
  }
   set_color(current_page);
   z = z+1;
   screenswipe();
  }

int buttonvalue = analogRead(buttonpin);

if(buttonvalue  > 100)
{
delay(20);
int buttonvalue = analogRead(buttonpin); //check Value again, to avoid wrong Readings

  if (buttonvalue >= 900)
{
  delay(20);
  buttonvalue = analogRead(A1);
  if (buttonvalue >= 900)
{
 send_key(1, current_page); 
  delay(200);
  }
}
if (buttonvalue <900 && buttonvalue >820)
{
  delay(20);
  buttonvalue = analogRead(A1);
  if (buttonvalue <900 && buttonvalue >820)
{
  send_key(2, current_page); 
  delay(200);
  }
}

if (buttonvalue <=820 && buttonvalue >760)
{
  delay(20);
  buttonvalue = analogRead(A1);
  if (buttonvalue <820 && buttonvalue >760)
{
  send_key(3, current_page); 
  delay(200);
  }  
}
  
if (buttonvalue <=760 && buttonvalue >700)
{
  delay(20);
  buttonvalue = analogRead(A1);
  if (buttonvalue <=760 && buttonvalue >700)
{
  send_key(4, current_page); 
  delay(200);
  } 
}

//signalize buttonpress by showing Neopixel Animation:  
for(int i=1; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(r, g, b));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(30); // Pause before next pass through loop
}
  
for(int i=1; i<NUMPIXELS; i++) { // For each pixel...
  
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(20); // Pause before next pass through loop
}
    
  } 
}

void screenswipe()
{
int x = 0;
int y = 172;

if(z<number_of_pages){ 
  
while (x >-(172-40))
{
screen.pushImage(0, x, 320, 172, pages[z-1]);
screen.pushImage(0, y, 320, 172, pages[z]);
screen.pushSprite(0, 0);

x= x-40;
y= y-40;
delay(1);
}
screen.pushImage(0, -172, 320, 172, pages[z-1]);
screen.pushImage(0, 0, 320, 172, pages[z]);
screen.pushSprite(0, 0);


}

if(z==number_of_pages){  
while (x >-(172-40))
{
screen.pushImage(0, x, 320, 172, pages[z-1]);
screen.pushImage(0, y, 320, 172,pages[0]);
screen.pushSprite(0, 0);

x= x-40;
y= y-40;
delay(1);
}
screen.pushImage(0, -172, 320, 172, pages[z-1]);
screen.pushImage(0, 0, 320, 172, pages[0]);
screen.pushSprite(0, 0);

z=0;
}




}

void intro()
{
  int x = 70;
  tft.pushImage(0,0, 320, 172, seeed_1);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_2);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_3);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_4);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_5);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_6);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_7);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_8);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_9);
  delay(x);
  tft.pushImage(0,0, 320, 172, seeed_10);
}

