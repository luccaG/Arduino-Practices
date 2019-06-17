#include<Keypad.h>
#include<Wire.h>//MAnejo simple de i2c
#include<LCD.h>//manejo de la pantalla
#include<LiquidCrystal_I2C.h>//manejo de porotocolo
LiquidCrystal_I2C lcd (0x27,2,1,0,4,5,6,7);//indico los pines de las lineas de control
                                          //RS , ENABLE, RW ,D4,D5,D6
                                          
const byte FILAS=4;
const byte COLUMNAS=4;
char teclas[FILAS][COLUMNAS]={
  {'R','7','4','1'},
  {'0','8','5','2'},
  {'>','9','6','3'},
  {'D','C','B','A'}
 };
byte row_pins[FILAS]={9,8,7,6};
byte col_pins[COLUMNAS]={5,4,3,2};

Keypad tecladito=Keypad(makeKeymap(teclas),row_pins ,col_pins,FILAS, COLUMNAS);
char tecla;   

char clave[7]; // son 6 digitos + le caracter null
char pass[7]="123456";
byte indice =0;
String cadena="";


void setup() {
  
  lcd.setBacklightPin(3,POSITIVE);//numero de puerto paralelo para activar luminocidad
  lcd.setBacklight(HIGH); //enciendo la iluminacion posterior
  lcd.begin(16,2);//16 columnas por 2 filas
  lcd.clear(); // limpio pantalla
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
 tecla=tecladito.getKey();
 //Serial.print(tecla);
 /*if (tecla){
   
  clave[indice]=tecla; //pone el valor en el idice 0 del array
  indice ++ ;//para el proximo indice
  Serial.print(tecla);
  cadena=cadena+tecla;
  lcd.print(cadena);
 }*/
  switch (tecla)
    {
       case 'A':
        comando1();
       break;
    }
}

void comando1()
{
  
  
  lcd.print("comando 1...");
  delay(2000);
  lcd.clear();
  //char fila[16];
  //cadena.remove(0,cadena.length());
  cadena="";
  tecla=tecladito.getKey();
  cadena=cadena+tecla;
  
  lcd.print(cadena);
  if(cadena.length()>16){
    for (int i=0 ; i<3;i++){
      lcd.display();
      delay(500);
      lcd.noDisplay();
      delay(500);
    
  }
  }
}
