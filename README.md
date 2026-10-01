# Práctica 5: El mayor de tres números

> **En esta práctica todo es tuyo:** el análisis, la receta, el código y las pruebas. Llena cada sección en la fase que se indica.

## 1. Descripción del problema (Fase 1)

El programa pide tres números al usuario, los compara y muestra cuál es el mayor. Serviría, por ejemplo, para saber cuál de tres sensores da la lectura más alta o cuál de tres motores está más caliente.

## 2. Entradas y salidas (Fase 1)

**Entradas:**
1. Primer número: `double`, el primer valor que se quiere comparar.
2. Segundo número: `double`, el segundo valor que se quiere comparar.
3. Tercer número: `double`, el tercer valor que se quiere comparar.

**Salida:**
1. El valor del mayor de los tres números (`double`), con el mensaje "El mayor es: ".

**¿Muestro el valor del mayor o cuál de los tres fue (primero, segundo o tercero)? ¿Por qué?**
Muestro el valor del mayor. Es lo que pide el problema ("cuál de los tres es el mayor") y evita ambigüedad en los empates: si dos números son iguales y mayores, "cuál fue" tendría dos respuestas, pero el valor es uno solo.

**¿Qué función de `utilerias.h` uso para leer los números? ¿Por qué esa y no la otra?**
Uso `leerDecimal`. El problema no dice que los números sean enteros, y con `leerEntero` no podría comparar 2.5, 2.7 y 2.6. `leerDecimal` acepta enteros y decimales.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- Los tres datos deben ser números (enteros o decimales).
- El programa siempre debe mostrar un resultado, sin importar los números ni los empates.

**¿Hace falta validar el rango de los números (por ejemplo, rechazar el 0 o los negativos)? ¿Por qué?**
No. A diferencia de la Práctica 3 (medidas físicas), aquí cualquier número real tiene sentido: -4, 0 o 2.5 se pueden comparar igual. Rechazar negativos o el 0 daría resultados incorrectos.

**¿Qué hace mi programa cuando dos números son iguales y son los mayores? ¿Y cuando los tres son iguales?**
Como uso `>=`, el primero de los empatados cumple la condición y se elige; muestra ese valor una sola vez (7, 7, 3 → 7). Con los tres iguales gana el primero y muestra ese valor (5, 5, 5 → 5).

**¿Quién detecta cada error?** (¿qué revisa la función de `utilerias.h` y qué reviso yo?)
`leerDecimal` revisa que lo escrito sea un número (rechaza texto, "12abc", nan e inf) y vuelve a preguntar. Mi programa no necesita revisar nada más, porque cualquier número es válido; yo me encargo de comparar bien, incluidos los empates.

**Invariante** (justo antes de mostrar el resultado, ¿qué es seguro sobre el valor que voy a mostrar?):
`mayor` es uno de los tres números y es mayor o igual que los otros dos.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Número 1 | Número 2 | Número 3 | Mayor calculado a mano |
|---|---|---|---|---|
| 1 (el mayor en primera posición) | 9 | 4 | 2 | 9 |
| 2 (el mayor en segunda posición) | 4 | 9 | 2 | 9 |
| 3 (el mayor en tercera posición) | 2 | 4 | 9 | 9 |
| 4 (con un empate) | 7 | 7 | 3 | 7 |
| 5 (con negativos) | -4 | -1 | -9 | -1 |

## 5. Receta en pseudocódigo (Fase 2)
<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 5 casos?** Sí
**¿Tuve que corregirla? ¿Qué cambié?** Mi primera idea inicializaba `mayor` en 0; al probar a mano el caso de negativos (-4, -1, -9) vi que daría 0, que ni siquiera es uno de los números. La corregí para que `mayor` siempre se asigne con uno de los tres números.
**¿Cuántas versiones de mi receta escribí hasta la final?** 2
**¿Se me ocurrió otra forma de resolver el problema? ¿Cuál? ¿Por qué elegí la que usé?**
Otra forma es revisar los números uno por uno: `mayor ← numero1`; SI `numero2 > mayor` ENTONCES `mayor ← numero2`; SI `numero3 > mayor` ENTONCES `mayor ← numero3`. Elegí la cadena if / else if / else porque con tres números es más directa de leer y de recorrer a mano, y solo ejecuta un camino. La otra se generaliza mejor a N números.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numero_mayor
./numero_mayor
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con un caso de empate (por ejemplo 7, 7 y 3). -->

```
Bienvenido a mi programa
Escribe el primer numero: 7
Escribe el segundo numero: 7
Escribe el tercer numero: 3
El mayor es: 7
```

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | `std::cout << "Bienvenido a mi programa" << std::endl;` |
| 2. Leer el primer número | `numero1 = leerDecimal("Escribe el primer numero: ");` |
| 3. Leer el segundo número | `numero2 = leerDecimal("Escribe el segundo numero: ");` |
| 4. Leer el tercer número | `numero3 = leerDecimal("Escribe el tercer numero: ");` |
| 5. Decidir cuál es el mayor | `if (numero1 >= numero2 && numero1 >= numero3) { mayor = numero1; } else if (numero2 >= numero1 && numero2 >= numero3) { mayor = numero2; } else { mayor = numero3; }` |
| 6. Mostrar el resultado | `std::cout << "El mayor es: " << mayor << std::endl;` |
| 7. Fin | `return 0;` |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
El paso 5, porque hay que escribir bien las condiciones con `&&` (en matemáticas se escribe a >= b >= c, pero en C++ no funciona así) y decidir entre `>` y `>=` para los empates.

## 9. Experimentos (Fase 3)

**Experimento A: ¿qué te dijo el compilador con `if (a > b > c)`? ¿Qué mostró el programa con 3, 2 y 1? ¿Por qué?**
El compilador avisó: `comparisons like 'X<=Y<=Z' do not have their mathematical meaning [-Wparentheses]`. Con 3, 2 y 1 mostró **1** en lugar de 3. Primero calcula `3 > 2`, que da `true` (1), y luego compara `1 > 1`, que es falso, así que cayó en otro camino y mostró el tercer número. La forma correcta es `a > b && b > c` (en mi programa, `numero1 >= numero2 && numero1 >= numero3`).

**Experimento B: al cambiar `>=` por `>` (o al revés), ¿qué mostró el programa con 7, 7, 3 y con 5, 5, 5? ¿Por qué?**
Con `>` el resultado de 7, 7, 3 fue **3** (incorrecto) y el de 5, 5, 5 fue 5 (correcto solo de casualidad). Con 7, 7, 3 ninguna comparación estricta se cumple para el 7 (7 > 7 es falso), así que se llega al `else` y se muestra el tercer número. Un solo carácter hace que el empate se maneje mal. Dejé la versión con `>=`, que funciona en todos los casos.

**Experimento C (opcional): con `if (a = b)`, ¿qué te dijo el compilador? ¿Qué le pasó al valor de `a`?**
El compilador avisó: `suggest parentheses around assignment used as truth value [-Wparentheses]`. Con 3, 8 y 5, `a` pasó a valer 8 porque `=` asigna, no compara, y el programa mostró 8 por esa asignación. `=` asigna y `==` compara. Dejé el código correcto.

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Mayor primero | 9, 4, 2 | 9 | 9 | Sí |
| Mayor en medio | 4, 9, 2 | 9 | 9 | Sí |
| Mayor al final | 2, 4, 9 | 9 | 9 | Sí |
| Empate arriba (1.º y 2.º) | 7, 7, 3 | 7 | 7 | Sí |
| Empate arriba (1.º y 3.º) | 7, 3, 7 | 7 | 7 | Sí |
| Empate abajo | 8, 3, 3 | 8 | 8 | Sí |
| Los tres iguales | 5, 5, 5 | 5 | 5 | Sí |
| Todos negativos | -4, -1, -9 | -1 | -1 | Sí |
| Con cero | -2, 0, -5 | 0 | 0 | Sí |
| Decimales cercanos | 2.5, 2.7, 2.6 | 2.7 | 2.7 | Sí |
| Texto | `abc` (luego 3), 1, 2 | vuelve a pedir el dato; 3 | Mostró "Entrada no valida" y volvió a pedir; el mayor fue 3 | Sí |
| Caso propio 1 | 0, 0, 0 | 0 | 0 | Sí |
| Caso propio 2 | -3.5, -3.5, -7 | -3.5 | -3.5 | Sí |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | En la receta, `mayor` empezaba en 0 y fallaba con negativos | `mayor` se asigna siempre con uno de los tres números (el `else` cubre el último caso) | Sí, -4, -1, -9 da -1 |
| 2 | Con `>` los empates (7, 7, 3) daban 3 (Experimento B) | Usar `>=` en todas las comparaciones | Sí, 7, 7, 3 da 7 y 5, 5, 5 da 5 |

**Reto elegido (opcional):** Ninguno.

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| Cuando hay empate gana siempre el primero; ¿es mejor avisar que hubo empate? | Lo revisé con 7, 7, 3 y 5, 5, 5; el valor mostrado es correcto, pero el programa no indica el empate (reto opcional 1). |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
Que un problema "fácil" tiene casos que hay que pensar antes de programar (empates, negativos, ceros), y que `>` y `>=` cambian el resultado en los empates. También que `a > b > c` no funciona en C++ como en matemáticas.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Escribiría la lista de casos raros antes de escribir la receta, no después, y probaría la receta a mano con ellos desde la primera versión.

**¿Qué fue lo más difícil y cómo lo resolví?**
Decidir cómo manejar los empates con las condiciones. Lo resolví recorriendo a mano 7, 7, 3 y comprobándolo con el Experimento B.

**¿Qué pregunta me quedó sin responder?**
Cómo se resolvería con muchos números (por ejemplo N en un arreglo) y cuál de las dos formas de resolverlo conviene más.

**¿Qué fue más fácil para mí: la Práctica 3 (receta propia con un paso de ejemplo), la 4 (receta ajena) o esta (todo desde cero)? ¿Por qué?**
La Práctica 4 (receta ajena) es la más fácil porque solo hay que traducir. Esta fue más difícil porque hay que pensar todo, pero se entiende mejor el problema.

**¿Pensé en los empates antes de programar o los descubrí al probar?**
Los pensé antes de programar, porque la práctica lo pide; el Experimento B me confirmó qué pasa si se usa mal `>`.

## 14. Lista de verificación antes de entregar (Fase 5)

- [x] Llené las secciones 1 a 13 (no quedan `_____`)
- [x] Escribí mi receta completa en `RECETA.md` antes de programar
- [x] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [x] Mi programa compila sin advertencias
- [x] Probé todos los casos de la tabla, incluidos los empates
- [x] Hice los Experimentos A y B y dejé el código correcto al terminar
- [x] No modifiqué `utilerias.h`
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [x] Mi fork se llama `ulsa_ime_1_dp_numero_mayor` y el código está en `main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
