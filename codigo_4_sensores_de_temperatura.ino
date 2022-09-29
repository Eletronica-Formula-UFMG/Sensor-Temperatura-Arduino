#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_MLX90614.h>
#define IR1 0x5A
#define IR2 0x5B
#define IR3 0x5C
#define IR4 0x5D
Adafruit_MLX90614 mlx;

void setup() {
  Serial.begin(9600);
  while (!Serial); 
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("Card failed, or not present");
    while (1);
  }
  Serial.println("card initialized.");
  mlx.begin(); 
}

void loop() {
  File myFile = SD.open("TEST.txt", FILE_WRITE);

  mlx.AddrSet(IR1); 
  Serial.print(mlx.readObjectTempC());
  Serial.print("\t");
  myFile.print(mlx.readObjectTempC());
  myFile.print("\t");
  //delay(20);
  
  mlx.AddrSet(IR2); 
  Serial.print(mlx.readObjectTempC());
  Serial.print("\t");
  myFile.print(mlx.readObjectTempC());
  myFile.print("\t");
  //delay(20);
  
  mlx.AddrSet(IR3); 
  Serial.print(mlx.readObjectTempC());
  Serial.print("\t");
  myFile.print(mlx.readObjectTempC());
  myFile.print("\t");
  //delay(20);
  
  mlx.AddrSet(IR4); 
  Serial.println(mlx.readObjectTempC());
  myFile.println(mlx.readObjectTempC());
  //delay(20);

  myFile.close();
}
