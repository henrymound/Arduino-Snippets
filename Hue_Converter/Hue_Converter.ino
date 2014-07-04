void setup() {
  Serial.begin(9600);
}

void loop() { 

 int red, green, blue;
 int hue = 830;
 toRGB(hue, red, green, blue);
 
  Serial.print(hue);
  Serial.print(": ");
  Serial.print(red);
  Serial.print(", ");
  Serial.print(green);
  Serial.print(", ");
  Serial.println(blue);
  
// toRGB(830);
// toRGB(1029);
// toRGB(439);
// toRGB(873);

}

void static toRGB(int hue, int red, int green, int blue){
  /*Converts the int hue to three different ints in an array
  the first int is red, second - green, third - blue each on a 255 scale*/
  
  if(hue >= 0 && hue <= 255){red = 255; green = 0; blue = 255 - hue;}
  else if (hue >= 256 && hue <= 510){red = 255; green = hue - 255; blue = 0;}
  else if (hue >= 511 && hue <= 765){red = 765 - hue; green = 255; blue = 0;}
  else if (hue >= 766 && hue <= 1020){red = 0; green = 255; blue = hue - 765;}
  else if (hue >= 1021 && hue <= 1275){red = 0; green = 1275 - hue; blue = 255;}
  else if (hue >= 1276 && hue <= 1530){red = hue - 1275; green = 0; blue = 255;}


}
