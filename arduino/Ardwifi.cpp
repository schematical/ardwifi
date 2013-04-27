#include "Arduino.h"
#include "Ardwifi.h"


Ardwifi::Ardwifi(int pin)
{

}
void Ardwifi::SDInit()
{
    Serial.begin(9600);
    while (!Serial) {
     ; // wait for serial port to connect. Needed for Leonardo only
   }


   Serial.print("Initializing SD card...");
   // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
   // Note that even if it's not used as the CS pin, the hardware SS pin
   // (10 on most Arduino boards, 53 on the Mega) must be left as an output
   // or the SD library functions will not work.
    pinMode(10, OUTPUT);

   if (!SD.begin(4)) {
     Serial.println("initialization failed!");
     return;
   }
   Serial.println("initialization done.");

   // open the file. note that only one file can be open at a time,
   // so you have to close this one before opening another.
   myFile = SD.open("ardwifi.txt", FILE_WRITE);

}
void Ardwifi::SDReadConfig()
{


   // if the file opened okay, write to it:
   if (myFile) {
     Serial.print("Writing to ardwifi.txt...");
     myFile.println("testing 1, 2, 3.");
 	// close the file:
     myFile.close();
     Serial.println("done.");
   } else {
     // if the file didn't open, print an error:
     Serial.println("error opening test.txt");
   }


}

void Ardwifi::SDWriteConfig()
{

   if (myFile) {
     Serial.println("ardwifi.txt");

     // read from the file until there's nothing else in it:
     while (myFile.available()) {
     	Serial.write(myFile.read());
     }
     // close the file:
     myFile.close();
   } else {
   	// if the file didn't open, print an error:
     Serial.println("error opening ardwifi.txt");
   }
}