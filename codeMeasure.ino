// Measuring part of the artificial flower.
// by Benjamin H Paffhausen; MIT Licence
// Measures the attendence of bees (copper plate under the feeding opening conected to the FDC), 
// the successfull presentation of sucrosewater and the ON/OFF state of the rewarding LED.
// Thopse values are saved to a table on the SD card.
// The FDC1004 Lib is from https://github.com/beshaya/FDC1004

#include <Wire.h>
#include <FDC1004.h> 
#include <SPI.h>
#include <SD.h>
FDC1004 fdc(FDC1004_100HZ);
const int chipSelect = 10;
unsigned long zeit = millis();
unsigned long zeit2 = millis();

void setup() {
  Wire.begin();
  SD.begin(chipSelect);

  Serial.begin(250000);

}

void loop() {

  String dataString = "";
  
//for (int kk=0;kk<25;kk++){
int32_t  capacitance1 = fdc.getCapacitance(0);
 dataString += String(capacitance1);
   dataString += " ";
   analogRead(A0);
   analogRead(A0);
 dataString += String(analogRead(A0)+analogRead(A0)+analogRead(A0)+analogRead(A0)+analogRead(A0)+analogRead(A0)+analogRead(A0)+analogRead(A0));
   dataString += " ";
   analogRead(A1);
   analogRead(A1);
    dataString += String(analogRead(A1));
   dataString += " ";
   
//}



//   dataString += " ";

   
   dataString += String(millis() - zeit);

   File dataFile = SD.open("datalog.txt", FILE_WRITE);

//  Serial.println(dataString);
  zeit = millis();
  // zeit2 = millis();
//    Serial.print("  ");
//  Serial.print(capacitance1);
//    Serial.print("  ");
//  Serial.print(capacitance2);
//    Serial.print("  ");
//  Serial.print(capacitance3);
//    Serial.print("  ");
//  Serial.print(capacitance4);
//    Serial.print("  ");
//  Serial.print(capacitance5);
//    Serial.print("  ");
//  Serial.print(capacitance6);
//    Serial.print("  ");
//  Serial.print(capacitance7);
//    Serial.print("  ");
//  Serial.print(capacitance8);
//   Serial.print("  ");
//   Serial.print(capacitance9);
//     Serial.print("  ");
//  Serial.println(capacitance0);

   dataFile.println(dataString);

   dataFile.close();
}














