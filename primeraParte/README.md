# Aguirre-Javier-PrimeraParteArduino
examenSPD
# Integrantes
Aguirre-Javier
# Proyecto: Contador binario.
![Aguirre Javier PrimeraParteArduino](https://github.com/Javih95/Aguirre-Javier-PrimeraParteArduino/assets/138259835/5e24eae8-3d29-4129-8b76-c0d8a17f207e)
# Descripción
Este proyecto consiste en un contador de dos dígitos que utiliza un display de 7 segmentos para mostrar el valor del contador. Los botones "SUBE," "BAJA" y "RESET" permiten incrementar, decrementar y restablecer el contador, respectivamente.
# Función principal
monitorea constantemente si se han presionado los botones "SUBE", "BAJA" o "RESET", y toma acciones en función de los botones presionados, como incrementar, decrementar o restablecer el contador. Además, se encarga de mostrar el valor del contador en el Display de 7 segmentos.
void loop()
{
  PrintCount();// Muestra el valor del contador en el Display
  int presionado = KeyPressed();// Detecta si se ha presionado uno de los botones
  if(presionado == 	SUBE)
  {
    sumar();
  }
  if(presionado == BAJA)
  {
    restar();
  }
  if(presionado == RESET)
  {
    resetear();
  }
  
}
#  Enlace al proyecto
https://www.tinkercad.com/things/6TdLueMVKp7

