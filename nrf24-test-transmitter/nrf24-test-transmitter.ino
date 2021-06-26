/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8, 7); // CE, CSN
const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  const char text[] = "We are constantly improving our service. Right now we support over 20 input formats to convert to WAV. For example: MP3 to WAV, WMA to WAV, OGG to WAV, FLV to WAV, WMV to WAV and more. If you have a file that we can't convert to WAV please contact us so we can add another WAV converter.";
  radio.write(&text, sizeof(text));
  delay(1000);
}
