# CiO2
![](https://github.com/dlrds/Cio2/blob/master/Imagens/logo%20(2).png)
Projeto final para a disciplina de Circuitos Lógicos ministrada pelo Professor Eudisley Gomes dos Anjos do Centro de Informatica da Universidade Federal da Paraıba


## Introdução
Sabe-se que crise hídrica mundial é uma realidade firmada, e que o mal uso da água pode agravar bastante a situação. Dentre as formas de desperdício de água, está o desperdicio da água pelos ares-condicionados.  


No caso de lugares com grandes estruturas, como as universidades,  esse desperdício tende a ser muito maior, pensando nisso, este projeto visa reutilizar a água desperdiçada dos ares-condicionados do Centro de Informática da Universidade Federal da Paraíba como uma alternativa para  a irrigação de plantas que serão cultivadas na instituição, quando estas necessitarem de tal recurso. Além disso serão exibidas a hora, a umidade e a temperatura locais.

## Metodologia

O trabalho foi dividido em quatro frentes: a criação do ambiente projetado em maquete, a constução do sistema de irrigação, a montagem do relógio digital e a mostra da temperatura e da umidade.	

A maquete foi baseada na estrutura do Centro de Informática para melhor entendimento da aplicação do projeto. A montagem do prédio principal feito de caixa de papelão, o jardim com acriílico e as árvores e plantas em plástico.

Para a exibição da hora foi utilizado o relógio Real Time Clock RTC DS3231, módulo utilizado como memória,  displays de sete segmentos e 4 codificadores de binário,  para a montagem destes.
    

Já a exibição dos valores de temperatura e umidade, lidos a partir do sensor DHT11, foi feito de forma semelhante ao circuito do relógio, com displays de sete segmentos e codificadores de binário para os displays.
	E por fim, para a montagem do sistema de irrigação, foi projetado um sensor de umidade do solo caseiro e um clock com o CI555, estes utilizados no flip-flop tipo D que irá controlar uma válvula solenóide, que permite ou não a passagem da água.



## Descrição do projeto

Para a execução do projeto foi utilizado como materiais:

* 80 Jumpers (estimativa)
* 5 Protoboards
* 9 Displays de sete segmentos
* 15 Resistores
* 1 Válvula solenoide 
* 1 Pedaço de cano
* 2 Adaptadores para canos
* 2 Arduinos Mega
* 1 Capacitor de 47µF
* 1 CI 4013 (Flip Flop  tipo D)
* 1 CI 555

Serão exibidas em displays de sete segmentos a temperatura e a umidade do ar. O momento em que a água será liberada para essas plantas ocorrerar a partir do monitoramento de um sensor de umidade do solo caseiro.  E ainda, os sistemas serão simulados e representados com o auxílio de uma maquete.


## Execução do projeto, testes e resultados

Primeiramente foi feito a leitura do sensor de umidade e temperatura DHT11, a partir dessa leitura, com o auxílio  da placa do Arduino e seu ambiente de desenvolvimento, foi convertido cada algarismo dessas variáveis em números binários, que com o auxílio do CI 4511, se fez possível exibir estas em displays de sete segmentos.

Posteriormente foi feito a montagem do higrômetro com o transistor do tipo PNP BC 327,  um led , um resistor de 1,8kΩ e outro resistor de 470Ω. Seu funcionamento se dá a partir da capacidade de condução de corrente da água que caso houvesse umidade, haveria condução de corrente de um fio para o outro, e caso não houvesse corrente, não haveria, isto causado pela resistência presente na terra, que seca, não permite a passagem de corrente.
	
O controle da saída do higrômetro é efetuado pelo Flip Flop tipo D, na qual converte os valores analógos em boleanos. 
Em seguida foi feito a montagem do clock com o CI 555, um capacitor de 47µF e dois resistores de 500kΩ.


## Relógio

### Circuito do relógio
![](https://github.com/dlrds/Cio2/blob/master/Imagens/Circuito.jpeg)

### Código do relógio
```c
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
``` 


### Circuito sensor de umidade
![](https://github.com/dlrds/Cio2/blob/master/Imagens/Circuito2.jpeg)


### Circuito DHT11
![](https://github.com/dlrds/Cio2/blob/master/Imagens/dht.jpg)


### Código do DHT11
```c
    
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

``` 
# Conclusão

Conclui-se com este projeto que ao desviar a água dos ar-condicionados por meio do CiO², se reutiliza os litros de água desperdiciada, tornando-se uma solução solúvel a todas as intitituições de ensino no qual desperdiçam vários litros de água diariamente e melhorando em si o meio ambiente.

# Referências
 * MEIRA, Marcos Cavalcante; NETO, José Diniz; LIMA, Cláudio Galeno Queiroga Oliveira; JÚNIOR, Walmeran José Trindade;DIAS, José Artur Alves; BARBACENA, Ilton Luiz. Estudo e desenvolvimento de um circuito de um relógio digital utilizandofundamentalmente conhecimentos em circuitos lógicos. Circuitos lógicos, portas lógicas, relógio digital, Instituto Federalda Paraiba, 2012. Disponível em:http://propi.ifto.edu.br/ocs/index.php/connepi/vii/paper/viewFile/1076/2509. Acesso em: 9 ago. 2019.
 
 * SANTOS, Jean Carlos Fabiano dos. Sistema Inteligente de Automatização de Bombas de Irrigação por Temperatura eUmidade, Centro de Tecnologia e Urbanismo Departamento de Engenharia Elétrica, 17 nov. 2014. Disponível em:http://www.uel.br/ctu/deel/TCC/TCC2014-JeanCarlosFabianoSantos.pdf. Acesso em: 10 ago. 2019.
 
 * CAPUANO, Francisco Gabriel; IDOETA, Ivan Valeiji. Estudo e desenvolvimento de um circuito de um relógio digital utilizandofundamentalmente conhecimentos em circuitos lógicos. In: CAPUANO, Francisco Gabriel; IDOETA, Ivan Valeiji. ElementosDe Eletrônica Digital. 41. ed. São Paulo: érica, 2012. cap. Circuitos Combinacionais, p. 175-248. ISBN 978-85-7194-019-2.
 
 * SENSOR de Umidade Super Fácil. Produção: TDC PROJETOS. [S. l.: s. n.], 2015. Disponível em: https://www.clubedohardware.com.br/forums/topic/1263932-sensor-de-umidade-caseiro/. Acesso em: 14 set. 2019.
 
<p align="center">
  <a>Criado por</a>
  <a href="https://github.com/diegolrs">Diego Reis</a>
  <a >, </a>
  <a href="https://github.com/yasminmedeiros00">Yasmin Medeiros</a>
  <a >, </a>
  <a href="https://github.com/RaissaVieira">Raissa Vieira</a>
  <a > e </a>
  <a href="https://github.com/MtHonorio">Matheus Honório</a>
</p>
