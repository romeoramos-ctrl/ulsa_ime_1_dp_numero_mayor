// Práctica 5: El mayor de tres números
// Traduce TU receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.

// iostream permite mostrar mensajes en pantalla (std::cout).
#include <iostream>

// Se usa leerDecimal porque el problema no pide enteros: así se pueden
// comparar valores como 2.5, 2.7 y 2.6.
#include "utilerias.h"

int main() {
    // Variables (siempre inicializadas)
    double numero1 = 0.0;
    double numero2 = 0.0;
    double numero3 = 0.0;
    // Se asigna siempre con uno de los tres números, nunca queda en 0 fijo,
    // por eso funciona también con negativos.
    double mayor = 0.0;

    // Paso 1: mensaje de bienvenida
    std::cout << "Bienvenido a mi programa" << std::endl;

    // Paso 2: leer el primer número
    numero1 = leerDecimal("Escribe el primer numero: ");

    // Paso 3: leer el segundo número
    numero2 = leerDecimal("Escribe el segundo numero: ");

    // Paso 4: leer el tercer número
    numero3 = leerDecimal("Escribe el tercer numero: ");

    // Paso 5: decidir cuál es el mayor
    // Cadena if / else if / else: solo se ejecuta un camino, así un empate
    // muestra un único resultado. Se usa >= para que ningún empate quede sin cubrir.
    if (numero1 >= numero2 && numero1 >= numero3) {
        mayor = numero1;
    } else if (numero2 >= numero1 && numero2 >= numero3) {
        mayor = numero2;
    } else {
        mayor = numero3;
    }

    // Paso 6: mostrar el resultado
    std::cout << "El mayor es: " << mayor << std::endl;

    // Paso 7: fin (0 = el programa terminó sin errores)
    return 0;
}
