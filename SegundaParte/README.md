# Aguirre-Javier-SegundaParteArduino
examenSPD contador con numeros primos
# integrantes
Aguirre-Javier
# Proyecto: Contador binario con switch y contador Primos
![Aguirre Javier SegundaParteArduino](https://github.com/Javih95/arduinoTP2/assets/138259835/eab9e3d6-bc72-46ae-8c57-0da31899f61a)
# Descripción
Este proyecto consiste en un contador de dos dígitos que utiliza una pantalla de 7 segmentos para mostrar el valor del contador. Los botones "SUBE", "BAJA" y "Interruptor" permiten incrementar, disminuir y cambiar el contador para mostrar numeros primos respectivamente.
# Función principal
determina si un numero es Primo o no para enviarlo a la funcion PrintNumeroPrimo().
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
