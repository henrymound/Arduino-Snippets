void setup() {
  Serial.begin(9600);
}

void loop() { 

 int red = 255;
 int green = 0;
 int blue = 0;
 int hue = 0;
 toRGB(hue, red, green, blue);
 
//Serial.print(hue);
//Serial.print(": ");
//Serial.print(red);
//Serial.print(", ");
//Serial.print(green);
//Serial.print(", ");
//Serial.println(blue);
  
//toRGB(830);
//toRGB(1029);
//toRGB(439);
//toRGB(873);

 if(digitalRead(2) == LOW){//Left
   hue--;
   if(hue <= 0){hue = hue + 1530;}
 }
 
 if(digitalRead(3)== LOW){//Down
   toRGB(hue, red, green, blue);
   red *= .1;
   green *= .1;
   blue *= .1;
 }
   
 if(digitalRead(4) == LOW){//Right
   hue++;
   if(hue >= 1530){hue = hue - 1530;}
 } 
 
 if(digitalRead(5) == LOW){//Up
   toRGB(hue, red, green, blue);
   red *= 1.1;
   green *= 1.1;
   blue *= 1.1;
 }
 
 if(digitalRead(6) == LOW)
   Serial.println("Center");


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
