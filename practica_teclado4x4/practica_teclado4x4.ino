#include<Keypad.h>

const byte FILAS=4;
const byte COLUMNAS=4;
char teclas[FILAS][COLUMNAS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
 };
byte row_pins[FILAS]={9,8,7,6};
byte col_pins[COLUMNAS]={5,4,3,2};

Keypad tecladito=Keypad(makeKeymap(teclas),row_pins ,col_pins,FILAS, COLUMNAS);
char tecla;   

char clave[7]; // son 6 digitos + le caracter null
char pass[7]="123456";
byte indice =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 tecla=tecladito.getKey();
 //Serial.print(tecla);
 if (tecla){
  clave[indice]=tecla; //pone el valor en el idice 0 del array
  indice ++ ;//para el proximo indice
  Serial.print(tecla);
 }
 if(indice ==6){
  if(!strcmp(clave, pass))//COmparo las 2 CADENAS
    Serial.println("Correcta");
   else
    Serial.println("incorrecta"); 
    indice=0;
 }
}
