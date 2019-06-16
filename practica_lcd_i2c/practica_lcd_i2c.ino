#include<Wire.h>//MAnejo simple de i2c
#include<LCD.h>//manejo de la pantalla
#include<LiquidCrystal_I2C.h>//manejo de porotocolo

LiquidCrystal_I2C lcd (0x27,2,1,0,4,5,6,7);//indico los pines de las lineas de control
                                          //RS , ENABLE, RW ,D4,D5,D6
void setup() {
  // put your setup code here, to run once:
 lcd.setBacklightPin(3,POSITIVE);//numero de puerto paralelo para activar luminocidad
 lcd.setBacklight(HIGH); //enciendo la iluminacion posterior
 lcd.begin(16,2);//16 columnas por 2 filas
 lcd.clear(); // limpio pantalla
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0,0); //donde arranco con el cursos;
  lcd.print("este es un texto demasiado");
  lcd.setCursor(0,1);//
  lcd.print(millis()/1000);
  lcd.print("seg");
}
