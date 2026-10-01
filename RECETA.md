# Receta: El mayor de tres números

``` text
Invariante: justo antes de mostrar, "mayor" es uno de los tres números
y es mayor o igual que los otros dos.

1. MOSTRAR "Bienvenido a mi programa"
2. numero1 ← leerDecimal("Escribe el primer numero: ")
3. numero2 ← leerDecimal("Escribe el segundo numero: ")
4. numero3 ← leerDecimal("Escribe el tercer numero: ")
5. SI numero1 >= numero2 Y numero1 >= numero3 ENTONCES
       mayor ← numero1
   SINO SI numero2 >= numero1 Y numero2 >= numero3 ENTONCES
       mayor ← numero2
   SINO
       mayor ← numero3
   FIN SI
6. MOSTRAR "El mayor es: ", mayor
7. FIN
```

Notas:
- Los datos inválidos (texto, "12abc", nan, inf) los rechaza `leerDecimal`, que vuelve a preguntar.
- Con empates se usa `>=`: con 7, 7, 3 gana el primero (7) y con 5, 5, 5 también (5). Siempre se muestra un único resultado.
