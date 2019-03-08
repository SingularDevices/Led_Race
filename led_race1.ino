/* 
______     _________                            
___  /___________  /  _____________ ___________ 
__  / _  _ \  __  /   __  ___/  __ `/  ___/  _ \
_  /__/  __/ /_/ /    _  /   / /_/ // /__ /  __/
/_____|___/\__,_/     /_/    \__,_/ \___/ \___/  
                                                
Led Race         gbarbarov@singulardevices.com 
 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/

#include <Adafruit_NeoPixel.h>
#define PIN            A0
float speed1=2.5;
float speed2=1.25;
float dist1=0;
float dist2=0;

byte loop1=0;
byte loop2=0;

byte loop_max=5;

int NPIXELS=300;

Adafruit_NeoPixel track = Adafruit_NeoPixel(NPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int tdelay = 5; 

void setup() {
  track.begin(); 
}

void draw_p1(void){for(int i=0;i<=loop1;i++){track.setPixelColor(((word)dist1 % NPIXELS)+i, track.Color(0,255,0));};                    
                   //track.setPixelColor(((word)dist1 % NUMPIXELS)+1, track.Color(random(255),random(255),random(155)));   
  }

void draw_p2(void){for(int i=0;i<=loop2;i++){track.setPixelColor(((word)dist2 % NPIXELS)+i, track.Color(255,0,0));};            
  }
  
void loop() {
  for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(0,0,0));};
    dist1=dist1+speed1;
    dist2=dist2+speed2;
    if (dist1>NPIXELS*loop1) {loop1++;};
    if (dist2>NPIXELS*loop2) {loop2++;};

    if (loop1>loop_max) {for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(0,255,0));}; track.show();
                                                      delay(5000);loop1=0;loop2=0;dist1=0;dist2=0;
                                                     }
    if (loop2>loop_max) {for(int i=0;i<NPIXELS;i++){track.setPixelColor(i, track.Color(255,0,0));}; track.show();
                                                      delay(5000);loop1=0;loop2=0;dist1=0;dist2=0;
                                                     }
    
    draw_p1();
    draw_p2();
    track.show(); 
    delay(tdelay); 
}
