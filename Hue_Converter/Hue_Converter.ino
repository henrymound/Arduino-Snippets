#include <Adafruit_NeoPixel.h>
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

  int red = 255;
  int green = 0;
  int blue = 0;
  int hue = 0;
  int CHANGE_BY = 3;  
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() { 
  
//  Serial.print(hue);
//  Serial.print(": ");
//  Serial.print(red);
//  Serial.print(", ");
//  Serial.print(green);
//  Serial.print(", ");
//  Serial.println(blue);
  
//toRGB(830);
//toRGB(1029);
//toRGB(439);
//toRGB(873);

 if(digitalRead(2) == LOW){//Left
   hue-=CHANGE_BY;
   if(hue <= 0){hue = hue + 1530;}
   toRGB(hue, red, green, blue);
//  Serial.print("Left");
 }
 
 if(digitalRead(5)== LOW){//Down
   if(red >= 0 && blue >= 0 && green >= 0){red = red - 1; if (red <= 0){red = 0;}}
   if(red >= 0 && blue >= 0 && green >= 0){green = green - 1; if(green <= 0){green = 0;}}
   if(red >= 0 && blue >= 0 && green >= 0){blue = blue - 1; if(blue <= 0){blue = 0;}}
//   toRGB(hue, red, green, blue);
//   Serial.print("Down");
 }
   
 if(digitalRead(4) == LOW){//Right
   hue+=CHANGE_BY;
   if(hue >= 1530){hue = 0;}
   toRGB(hue, red, green, blue);
//   Serial.print("Right");
 } 
 
 if(digitalRead(3) == LOW){//Up
   if(red < 255 && green < 255 && blue < 255){red = red + 1; if(red >= 255){red = 255;}}
   if(red < 255 && green < 255 && blue < 255){green = green + 1; if(green >= 255){green = 255;}}
   if(red < 255 && green < 255 && blue < 255){blue = blue + 1; if(blue >= 255){blue = 255;}}
//   toRGB(hue, red, green, blue);
   Serial.print("Up");
 }
 
 if(digitalRead(7) == LOW){
  
   hue += 255;
   if(hue >= 1530)hue = 0;
   delay(200);
   Serial.print("Center");
 }
 
// toRGB(hue, red, green, blue);
  
 for(uint16_t i=0; i<strip.numPixels(); i++) {strip.setPixelColor(i, strip.Color(red, green, blue));}
 strip.show();


}

void static toRGB(int h, int r, int g, int b){
  /*Converts the int hue to three different ints in an array
  the first int is red, second - green, third - blue each on a 255 scale*/
  
  if(hue >= 0 && hue <= 255){red = 255; green = 0; blue = 255 - hue;}
  else if (hue >= 256 && hue <= 510){red = 255; green = hue - 255; blue = 0;}
  else if (hue >= 511 && hue <= 765){red = 765 - hue; green = 255; blue = 0;}
  else if (hue >= 766 && hue <= 1020){red = 0; green = 255; blue = hue - 765;}
  else if (hue >= 1021 && hue <= 1275){red = 0; green = 1275 - hue; blue = 255;}
  else if (hue >= 1276 && hue <= 1530){red = hue - 1275; green = 0; blue = 255;}


}
