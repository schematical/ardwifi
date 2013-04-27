/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Ardwifi
{
  public:
    Ardwifi(int pin);
    void SDInit();
    void SDReadConfig();
    void SDWriteConfig();
  private:
    File myFile;
};

#endif