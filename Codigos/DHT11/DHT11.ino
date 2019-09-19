
#include "dht.h"

//Primeiro digito dos min
#define PinoA0 6
#define PinoA1 7
#define PinoA2 8
#define PinoA3 9

//Segundo digito da tempx
#define PinoA4 2
#define PinoA5 3
#define PinoA6 4
#define PinoA7 50

//Primeiro digito das horas
#define PinoA8 22
#define PinoA9 23
#define PinoA10 24
#define PinoA11 25

//Segundo digite das horas
#define PinoA12 10
#define PinoA13 11
#define PinoA14 12
#define PinoA15 13

//Definindo a porta da DHT11
const int pinoDHT11 = A2; //PINO ANALÓGICO UTILIZADO PELO DHT11
 
dht DHT; //Variável do tipo DHT
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL

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
}

  /*Variáveis usadas para temperatura/umidade:
    temp e umid = O valor real da temperatura e umidade, respectivamente.
    tempDigito1 e umidDigito1 = O primeiro valor das variáveis de temperatura e umidade, respectivamente.
    tempDigito2 e umidDigito12 = O segundo valor das variáveis de temperatura e umidade, respectivamente.
  */
  
  int temp, tempDigito1, tempDigito2;
  int umid, umidDigito1, umidDigito2;
  


void loop(){
  digitalWrite(PinoA4, HIGH);
  DHT.read11(pinoDHT11); //LÊ AS INFORMAÇÕES DO SENSOR

//TEMPERATURA--------------------------------------------------------------------

  temp = (DHT.temperature);
  
  Serial.print("  Temperatura: "); 
  Serial.print(temp); //Imprime o valor real na Serial
  Serial.println("°C"); 
  
  Serial.print("  Primeiro dígito: ");
  tempDigito1 = temp / 10;
  Serial.println(tempDigito1);
    if(tempDigito1 == 0) {Serial.print(" zero");
      digitalWrite(PinoA0, LOW);
      digitalWrite(PinoA1, LOW);
      digitalWrite(PinoA2, LOW);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1== 1){ Serial.print(" um");
      digitalWrite(PinoA0, HIGH);
      digitalWrite(PinoA1, LOW);
      digitalWrite(PinoA2, LOW);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1== 2) {Serial.print(" dois");
      digitalWrite(PinoA0, LOW);
      digitalWrite(PinoA1, HIGH);
      digitalWrite(PinoA2, LOW);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1== 3){ Serial.print(" três");
      digitalWrite(PinoA0, HIGH);
      digitalWrite(PinoA1, HIGH);
      digitalWrite(PinoA2, LOW);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1== 4){ Serial.print(" quatro");
      digitalWrite(PinoA0, LOW);
      digitalWrite(PinoA1, LOW);
      digitalWrite(PinoA2, HIGH);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1 == 5){ Serial.print(" cinco");
      digitalWrite(PinoA0, HIGH);
      digitalWrite(PinoA1, LOW);
      digitalWrite(PinoA2, HIGH);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1 == 6){ Serial.print(" seis");
      digitalWrite(PinoA0, LOW);
      digitalWrite(PinoA1, HIGH);
      digitalWrite(PinoA2, HIGH);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1 == 7){ Serial.print(" sete");
      digitalWrite(PinoA0, HIGH);
      digitalWrite(PinoA1, HIGH);
      digitalWrite(PinoA2, HIGH);
      digitalWrite(PinoA3, LOW);}
    if(tempDigito1 == 8) {Serial.print(" oito");
      digitalWrite(PinoA0, LOW);
      digitalWrite(PinoA1, LOW);
      digitalWrite(PinoA2, LOW);
      digitalWrite(PinoA3, HIGH);}
    if(tempDigito1 == 9){ Serial.print(" nove");
      digitalWrite(PinoA0, HIGH);
      digitalWrite(PinoA1, LOW);
      digitalWrite(PinoA2, LOW);
      digitalWrite(PinoA3, HIGH);}

  // Segundo dígito
  Serial.print("  Segundo dígito: ");
  tempDigito2 = temp % 10;
  Serial.println(tempDigito2);
  if(tempDigito2 == 0) {Serial.print(" zero");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2== 1){ Serial.print(" um");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2== 2) {Serial.print(" dois");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2== 3){ Serial.print(" três");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2== 4){ Serial.print(" quatro");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2 == 5){ Serial.print(" cinco");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2 == 6){ Serial.print(" seis");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2 == 7){ Serial.print(" sete");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, HIGH);
      digitalWrite(PinoA6, HIGH);
      digitalWrite(PinoA7, LOW);}
    if(tempDigito2 == 8){Serial.print(" oito");
      digitalWrite(PinoA4, LOW);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, HIGH);}
    if(tempDigito2 == 9){ Serial.print(" nove");
      digitalWrite(PinoA4, HIGH);
      digitalWrite(PinoA5, LOW);
      digitalWrite(PinoA6, LOW);
      digitalWrite(PinoA7, HIGH);}
 
//UMIDADE------------------------------------------------------------------------

    umid = (DHT.humidity);
  
    Serial.print("  Umidade: "); 
    Serial.print(umid); //Imprime o valor real na Serial
    Serial.println("%"); 
    
    Serial.print("  Primeiro dígito: ");
    umidDigito1 = umid / 10;
   // Serial.println(umidDigito1);
    if(umidDigito1 == 0) {Serial.print(" zero");
      digitalWrite(PinoA8, LOW);
      digitalWrite(PinoA9, LOW);
      digitalWrite(PinoA10, LOW);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 1){ Serial.print(" um");
      digitalWrite(PinoA8, HIGH);
      digitalWrite(PinoA9, LOW);
      digitalWrite(PinoA10, LOW);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 2) {Serial.print(" dois");
      digitalWrite(PinoA8, LOW);
      digitalWrite(PinoA9, HIGH);
      digitalWrite(PinoA10, LOW);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 3){ Serial.print(" três");
      digitalWrite(PinoA8, HIGH);
      digitalWrite(PinoA9, HIGH);
      digitalWrite(PinoA10, LOW);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 4){ Serial.print(" quatro");
      digitalWrite(PinoA8, LOW);
      digitalWrite(PinoA9, LOW);
      digitalWrite(PinoA10, HIGH);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 5){ Serial.print(" cinco");
      digitalWrite(PinoA8, HIGH);
      digitalWrite(PinoA9, LOW);
      digitalWrite(PinoA10, HIGH);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 6){ Serial.print(" seis");
      digitalWrite(PinoA8, LOW);
      digitalWrite(PinoA9, HIGH);
      digitalWrite(PinoA10, HIGH);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 7){ Serial.print(" sete");
      digitalWrite(PinoA8, HIGH);
      digitalWrite(PinoA9, HIGH);
      digitalWrite(PinoA10, HIGH);
      digitalWrite(PinoA11, LOW);}
    if(umidDigito1 == 8) {Serial.print(" oito");
      digitalWrite(PinoA8, LOW);
      digitalWrite(PinoA9, LOW);
      digitalWrite(PinoA10, LOW);
      digitalWrite(PinoA11, HIGH);}
    if(umidDigito1 == 9){ Serial.print(" nove");
      digitalWrite(PinoA8, HIGH);
      digitalWrite(PinoA9, LOW);
      digitalWrite(PinoA10, LOW);
      digitalWrite(PinoA11, HIGH);}
  
    // Segundo dígito
    Serial.print("\n  Segundo dígito: ");
    umidDigito2 = umid % 10;
    //Serial.println(umidDigito2);
    if(umidDigito2 == 0) {Serial.print(" zero");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 1){ Serial.print(" um");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 2) {Serial.print(" dois");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 3){ Serial.print(" três");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 4){ Serial.print(" quatro");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 5){ Serial.print(" cinco");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 6){ Serial.print(" seis");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 7){ Serial.print(" sete");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, HIGH);
      digitalWrite(PinoA14, HIGH);
      digitalWrite(PinoA15, LOW);}
    if(umidDigito2 == 8){Serial.print(" oito");
      digitalWrite(PinoA12, LOW);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, HIGH);}
    if(umidDigito2 == 9){ Serial.print(" nove");
      digitalWrite(PinoA12, HIGH);
      digitalWrite(PinoA13, LOW);
      digitalWrite(PinoA14, LOW);
      digitalWrite(PinoA15, HIGH);}

      Serial.println("");
//Seção Final------------------------------------------------------------------------
    // Printa uma linha de 30 "-"
    for(int i=0; i<15; i++) {Serial.print("--");}
  
   // Pula linha
    Serial.println("");
    delay(2000); //Intervalo de 2 segundos * Não alterar!!!  
}

            
