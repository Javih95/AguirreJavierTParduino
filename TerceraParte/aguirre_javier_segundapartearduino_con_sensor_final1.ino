/* 
Nombre del Proyecto: Contador de 2 dígitos con Display de 7 Segmentos y Botones.
  Autor: Aguirre Javier
  Fecha: 09/10/2023
  Descripción: Este código controla un contador de dos dígitos utilizando un display de 7 segmentos.
  Los botones "SUBE" PARA MOSTRAR EL PROXIMO NUMERO PRIMO Y UN SWITCH PARA CAMBIAR EL DISPLAY PARA MOSTRAR EL VALOR DE LA TEMPERATURA QUE SE OBTIENE DEL SENSOR QUE ACTIVA O DESACTIVA EL MOTOR DE CC
*/
// Definición de Pines para el Display y Botones
#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define interruptor 3
#define UNIDAD A4
#define DECENA A5
#define APAGADOS 0
#define TIMEDELAY 10
#define MotorPin1 6
#define MotorPin2 4
#define Activar 5
#define SUBE 2
#define LUZsensor A1

// Variables para el Contador y Estados de los Botones
int CONTADOR = 0;
int sube = 1;
int subePrev =1;
int minLuz = 200; // Valor bajo para luz tenue
int maxLuz = 1200; // Valor alto para luz brillante

// Configuración de Pines de Entrada y Salida
void setup()
{
  pinMode(SUBE, INPUT_PULLUP);
  pinMode(interruptor, INPUT_PULLUP);
  pinMode(MotorPin1,OUTPUT);
  pinMode(MotorPin2,OUTPUT);
  pinMode(Activar,OUTPUT);
  pinMode(LUZsensor, INPUT);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(UNIDAD,OUTPUT);
  pinMode(DECENA,OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  int estadoInterruptor = digitalRead(interruptor);
  if (estadoInterruptor == LOW) 
  {
    PrintTemperatura();
    if(CONTADOR > 23)
    {
      variarDireccion();
    }
    else
    {
   	  ApagarMotor();
    }
  }
  else if (estadoInterruptor == HIGH)
  {
    ApagarMotor();
    PrintNumeroPrimo();
	int presionado = KeyPressed();
    if(presionado == 	SUBE)
     {
    	sumar();
     }
  } 
}
void PrintNumeroPrimo()
{// Si el interruptor está en la posición "números primos," muestra el número primo actual en el Display
  while (!esPrimo(CONTADOR))
  { 
    CONTADOR++;
    if (CONTADOR > 99)
      {
          CONTADOR = 0;
      }
  }
   PrendeDigito(APAGADOS);
   printDigit(CONTADOR/10);
   PrendeDigito(DECENA);
   PrendeDigito(APAGADOS);
   printDigit(CONTADOR-10*((int) CONTADOR/10));
   PrendeDigito(UNIDAD);
}
bool esPrimo(int numero) 
{
    if (numero <= 1)
    {
        return false; // 0 y 1 no son primos
    }
    for (int i = 2; i < numero; i++) 
    {
        if (numero % i == 0)
        {
            return false; // Si es divisible por algún número en el rango [2, sqrt(numero)], no es primo
        }
    }
    return true; // Si no es divisible por ningún número en ese rango, es primo
}
void PrintTemperatura()
{
  int sensorValue = analogRead(A0);
  float voltage = (sensorValue / 1023.0) * 5.0; // Convierte el valor a voltaje
  float temperatureC = (voltage - 0.5) * 100.0; // Convierte el voltaje a temperatura en grados Celsius	
  int Temperatura = int (temperatureC);
  CONTADOR = Temperatura;
  delay(10);
  PrintCount();
  
}
void ActivarMotorIzquierda()
{
 digitalWrite(Activar, HIGH); 
 digitalWrite(MotorPin1, LOW);
 digitalWrite(MotorPin2,HIGH);
}
void ActivarMotorDerecha()
{
 digitalWrite(Activar, HIGH); 
 digitalWrite(MotorPin1, HIGH);
 digitalWrite(MotorPin2,LOW);
}
void ApagarMotor()
{
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
}
void variarDireccion()
{
  int IntensidadLuz = analogRead(LUZsensor); 
  if (IntensidadLuz > minLuz)
  {
    ActivarMotorIzquierda();
  }
  else if (IntensidadLuz < maxLuz) 
  {
    ActivarMotorDerecha();
  }
}
void sumar()
{
 CONTADOR ++;
  if(CONTADOR > 99)
  {
    CONTADOR = 0;
  }
}
// Función para mostrar un dígito en el Display de 7 Segmentos
void printDigit(int digit)
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  switch (digit)
  {
    case 0:
    digitalWrite(A, LOW);
  	digitalWrite(B, LOW);
  	digitalWrite(C, LOW);
  	digitalWrite(D, LOW);
  	digitalWrite(E, LOW);
  	digitalWrite(F, LOW);
  	digitalWrite(G, HIGH);
    break;
    case 1:
    digitalWrite(A, HIGH);
  	digitalWrite(B, LOW);
  	digitalWrite(C, LOW);
  	digitalWrite(D, HIGH);
  	digitalWrite(E, HIGH);
  	digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
    case 2:
    digitalWrite(A, LOW);
  	digitalWrite(B, LOW);
  	digitalWrite(C, HIGH);
  	digitalWrite(D, LOW);
  	digitalWrite(E, LOW);
  	digitalWrite(F, HIGH);
  	digitalWrite(G, LOW);
    break;
    case 3:
    digitalWrite(A, LOW);
  	digitalWrite(B, LOW);
  	digitalWrite(C, LOW);
  	digitalWrite(D, LOW);
  	digitalWrite(E, HIGH);
  	digitalWrite(F, HIGH);
  	digitalWrite(G, LOW);
    break;
    case 4:
    digitalWrite(A, HIGH);
  	digitalWrite(B, LOW);
  	digitalWrite(C, LOW);
  	digitalWrite(D, HIGH);
  	digitalWrite(E, HIGH);
  	digitalWrite(F, LOW);
  	digitalWrite(G, LOW);
    break;
    case 5:
    digitalWrite(A, LOW);
  	digitalWrite(B, HIGH);
  	digitalWrite(C, LOW);
  	digitalWrite(D, LOW);
  	digitalWrite(E, HIGH);
  	digitalWrite(F, LOW);
  	digitalWrite(G, LOW);
    break;
    case 6:
    digitalWrite(A, LOW);
  	digitalWrite(B, HIGH);
  	digitalWrite(C, LOW);
  	digitalWrite(D, LOW);
  	digitalWrite(E, LOW);
  	digitalWrite(F, LOW);
  	digitalWrite(G, LOW);
    break;
    case 7:
    digitalWrite(A, LOW);
  	digitalWrite(B, LOW);
  	digitalWrite(C, LOW);
  	digitalWrite(D, HIGH);
  	digitalWrite(E, HIGH);
  	digitalWrite(F, HIGH);
  	digitalWrite(G, HIGH);
    break;
    case 8:
    digitalWrite(A, LOW);
  	digitalWrite(B, LOW);
  	digitalWrite(C, LOW);
  	digitalWrite(D, LOW);
  	digitalWrite(E, LOW);
  	digitalWrite(F, LOW);
  	digitalWrite(G, LOW);
    break;
    case 9:
    digitalWrite(A, LOW);
  	digitalWrite(B, LOW);
  	digitalWrite(C, LOW);
  	digitalWrite(D, HIGH);
  	digitalWrite(E, HIGH);
  	digitalWrite(F, LOW);
  	digitalWrite(G, LOW);
    break;
  }
  delay(TIMEDELAY);
  
}
void PrendeDigito(int digito)
{
  if(digito == UNIDAD)
  {
    digitalWrite(UNIDAD , HIGH);
    digitalWrite(DECENA , LOW);
    delay(TIMEDELAY);
  }
  else if(digito == DECENA)
  {
    digitalWrite(UNIDAD , LOW);
    digitalWrite(DECENA , HIGH);
    delay(TIMEDELAY);
  }
  else if(APAGADOS)
  {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(TIMEDELAY);
  }
  else
  {
    digitalWrite(UNIDAD , LOW);
    digitalWrite(DECENA , LOW);
  }
  
}
int KeyPressed(void)
{
  sube = digitalRead(SUBE);
  if (sube == 1)
  {
    subePrev = 1;
  }
  if (sube == 0 && sube != subePrev)
    {
      subePrev = sube;
      return SUBE;
    }
   return 0;
}
// Función para mostrar el dígito en el Display correspondiente
void PrintCount()
{
   PrendeDigito(APAGADOS);
   
   printDigit(CONTADOR/10);
   PrendeDigito(DECENA);
   
   PrendeDigito(APAGADOS);
   printDigit(CONTADOR-10*((int) CONTADOR/10));
   PrendeDigito(UNIDAD);
}