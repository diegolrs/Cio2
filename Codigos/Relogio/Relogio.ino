 #include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68
//---------------------------------
// Converte de números decimais para BCD
byte decToBcd(byte val)
{return( (val/10*16) + (val%10) );}

// Converte de BCD para números decimais
byte bcdToDec(byte val)
{return( (val/16*10) + (val%16) );}
//---------------------------------

//Primeiro digito dos min
#define PinoA0 6
#define PinoA1 7
#define PinoA2 8
#define PinoA3 9

//Segundo digito dos min
#define PinoA4 2
#define PinoA5 3
#define PinoA6 4
#define PinoA7 5

//Primeiro digito das horas
#define PinoA8 10
#define PinoA9 11
#define PinoA10 12
#define PinoA11 13

//Segundo digite das horas
#define PinoA12 22
#define PinoA13 23
#define PinoA14 24
#define PinoA15 25


void setup() {
  Wire.begin(); //Inicia a comunicação com a biblioteca
  Serial.begin(9600);
  // Configure o tempo do DS3231 aqui:
  // Ordem exata: Segundos => Minutos => Horas
   setDS3231time(00,00,16);
   
   
   pinMode(PinoA0, OUTPUT);
   pinMode(PinoA1, OUTPUT);
   pinMode(PinoA2, OUTPUT);
   pinMode(PinoA3, OUTPUT);
   pinMode(PinoA4, OUTPUT);
   pinMode(PinoA5, OUTPUT);
   pinMode(PinoA6, OUTPUT);
   pinMode(PinoA7, OUTPUT);
   pinMode(PinoA8, OUTPUT);
   pinMode(PinoA9, OUTPUT);
   pinMode(PinoA10, OUTPUT);
   pinMode(PinoA11, OUTPUT);
   pinMode(PinoA12, OUTPUT);
   pinMode(PinoA13, OUTPUT);
   pinMode(PinoA14, OUTPUT);
   pinMode(PinoA15, OUTPUT);
  //Mensagem inicial serial Monitor
  Serial.println("Teste de CD4511n");
}
void setDS3231time(byte second, byte minute, byte hour)
{
  // Aplica o horário escolhido acima no DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0);
  Wire.write(decToBcd(second)); // Setando segundos
  Wire.write(decToBcd(minute)); // Setando minutos
  Wire.write(decToBcd(hour)); // Setando horas
  Wire.endTransmission(); // Fim da transmissão
}
void readDS3231time(byte *second,
byte *minute,
byte *hour)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // Setar o registrador do DS3231 para 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // Requisita 7 bytes a partir do registro 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
}
void displayTime()
{
  byte second, minute, hour;
  
  // Exibe os dados do DS3231
  readDS3231time(&second, &minute, &hour);

  /*------------------------------------------------------------------------------------------------------
    O Horário utilizado é separado por dígito
  --------------------------------------------------------------------------------------------------------*/

  int minuto1, minuto2;

  Serial.print("minutos em decimal: ");
  
  minuto1 = minute / 10;
  Serial.print(minuto1);
  minuto2 = minute % 10;
  Serial.print(minuto2);
  Serial.print("\n");

    Serial.print("O primeiro número é");
    if(minuto1 == 0) {
      digitalWrite(PinoA0, LOW);  
      digitalWrite(PinoA1, LOW);  
      digitalWrite(PinoA2, LOW);  
      digitalWrite(PinoA3, LOW);
      Serial.print(" zero");
      //delay(1000);
      }
    if(minuto1 == 1) {
      Serial.print(" um");
      digitalWrite(PinoA0, HIGH);  
      digitalWrite(PinoA1, LOW);  
      digitalWrite(PinoA2, LOW);  
      digitalWrite(PinoA3, LOW);
      //delay(1000);
    }
    if(minuto1 == 2){ 
      Serial.print(" dois");
      digitalWrite(PinoA0, LOW);  
      digitalWrite(PinoA1, HIGH);  
      digitalWrite(PinoA2, LOW);  
      digitalWrite(PinoA3, LOW);
      //delay(1000);
    }
    if(minuto1 == 3){ 
      Serial.print(" três");
      digitalWrite(PinoA0, HIGH);  
      digitalWrite(PinoA1, HIGH);  
      digitalWrite(PinoA2, LOW);  
      digitalWrite(PinoA3, LOW);
      //delay(1000);
    }
    if(minuto1 == 4){ 
      Serial.print(" quatro");
      digitalWrite(PinoA0, LOW);  
      digitalWrite(PinoA1, LOW);  
      digitalWrite(PinoA2, HIGH);  
      digitalWrite(PinoA3, LOW);
      //delay(1000);
    }
    if(minuto1 == 5){
      Serial.print(" cinco");
      digitalWrite(PinoA0, HIGH);  
      digitalWrite(PinoA1, LOW);  
      digitalWrite(PinoA2, HIGH);  
      digitalWrite(PinoA3, LOW);
      //delay(1000);
    }
    
    
    // Pula linha
      Serial.println("");
      
    Serial.print("O segundo número é");
    if(minuto2 == 0) {Serial.print(" zero");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 1){ Serial.print(" um");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 2) {Serial.print(" dois");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 3){ Serial.print(" três");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 4){ Serial.print(" quatro");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 5){ Serial.print(" cinco");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 6){ Serial.print(" seis");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 7){ Serial.print(" sete");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(minuto2 == 8) {Serial.print(" oito");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, HIGH);}
    if(minuto2 == 9){ Serial.print(" nove");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, HIGH);}

       int hora1, hora2;

  Serial.print("\nhoras em decimal: ");
  
  hora1 = hour / 10;
  Serial.print(hora1);
  hora2 = hour % 10;
  Serial.print(hora2);
  Serial.print("\n");

    Serial.print("O primeiro número é");
    if(hora1 == 0) {
      digitalWrite(PinoA8, LOW);  
      digitalWrite(PinoA9, LOW);  
      digitalWrite(PinoA10, LOW);  
      digitalWrite(PinoA11, LOW);
      Serial.print(" zero");
      //delay(1000);
      }
    if(hora1 == 1) {
      Serial.print(" um");
      digitalWrite(PinoA8, HIGH);  
      digitalWrite(PinoA9, LOW);  
      digitalWrite(PinoA10, LOW);  
      digitalWrite(PinoA11, LOW);
      //delay(1000);
    }
    if(hora1 == 2){ 
      Serial.print(" dois");
      digitalWrite(PinoA8, LOW);  
      digitalWrite(PinoA9, HIGH);  
      digitalWrite(PinoA10, LOW);  
      digitalWrite(PinoA11, LOW);
      //delay(1000);
    }
       
    // Pula linha
      Serial.println("");
      
    Serial.print("O segundo número é");
    if(hora2 == 0) {Serial.print(" zero");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 1){ Serial.print(" um");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 2) {Serial.print(" dois");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 3){ Serial.print(" três");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 4){ Serial.print(" quatro");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 5){ Serial.print(" cinco");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 6){ Serial.print(" seis");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 7){ Serial.print(" sete");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(hora2 == 8) {Serial.print(" oito");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, HIGH);}
    if(hora2 == 9){ Serial.print(" nove");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, HIGH);}

    

    

 // Pula linha
  Serial.println("");
   
 // Printa uma linha de 30 "-"
  for(int i=0; i<15; i++){
  Serial.print("--");}

 // Pula linha
  Serial.println("");
  

}



void loop() {
  // put your main code here, to run repeatedly:
  displayTime(); // Chamada de função para exibir o tempo real
  delay(1000); // Exibe a cada segundo
}
