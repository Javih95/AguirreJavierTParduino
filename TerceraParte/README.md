# Aguirre-Javier-TerceraParteArduino
examenSPD contador con numeros primos , sensor de temperatura, sensor de luz ambiental y motor de cc
# integrantes
Aguirre-Javier
# Proyecto: Contador numeros primos mas sensor de temperatura y sensor de luz ambiente
![Aguirre Javier SegundaParteArduino con Sensor Final](https://github.com/Javih95/Aguirre-Javier-TerceraParteArduino/assets/138259835/f44bb4ff-6e6a-4814-bea8-6e17bbb9d558)
# Descripción
En este proyecto Utilizamos dos displays de 7 segmentos para mostrar numeros primos que van cambiando al proximo numero primo entre el 0 y 99 mediante un boton.
por otro lado se dispone de un swicth para cambiar a la funcion de Mostrar la temperatura ambiente ,la cual es obtenida por medio de un sensor tmp36.
en este modo de funcionamiento se controla el accionar de un motor de cc por medio de la temperatura, la cual pone en funcionamiento el motor o lo apaga segun su configuracion de valores, y la luz ambiente que controla el sentido de giro del mismo, esta ultima obtenida mediante un sensor de luz ambiental (fototransistor).
# Función principal
Monitorea el estado de Switch para variar entre las dos funcionalidades del proyecto
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
# Enlace al proyecto
https://www.tinkercad.com/things/kSra6bKdsOw
