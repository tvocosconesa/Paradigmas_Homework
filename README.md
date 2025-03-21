# Paradigmas_Homework

## Ejecución
Los programas se ejecutan con el comando `make` en la terminal, siempre asegurándose de estar en el directorio correcto.

---

## Ejercicio 1
Para trabajar con la matriz de este punto, dividí el proceso en tres funciones:

- **`create_matrix`**: Crea la matriz e inserta los números en ella.
- **`print_matrix`**: Imprime la matriz con el formato requerido en la consigna. Para hacerlo con un solo ciclo `for`, inicialicé el iterador en `N*N - 1` y lo recorrí de forma decreciente. Usé las operaciones `i / N` y `i % N` para referirme a la fila y columna correspondiente.
- **`delete_matrix`**: Recorre las filas de la matriz y las elimina una por una. Finalmente, libera el puntero de la matriz.

Cuando se ejecuta el programa, se le pide al usuario que ingrese un número `N`, el cual determina el tamaño de la matriz (`N x N`).

---

## Ejercicio 2
### Ejecución
Este programa se maneja a través de la terminal y permite interactuar con la función `Log_message` mediante dos opciones:

1. **Redactar información / Reportar un aviso**
    - Se debe seleccionar una prioridad para el mensaje. Las opciones disponibles se muestran en la terminal.
    - Una vez elegida la prioridad (ingresando su número correspondiente), el usuario puede escribir el mensaje, que será registrado en el archivo `log_system.txt`.

2. **Iniciar sesión en el sistema**
    - Se solicita un nombre de usuario.
    - Según el nombre ingresado, se otorgará o denegará el acceso.
    - Este resultado se registrará en `log_system.txt`. Solo el usuario **"Bjarne Stroustrup"** tiene acceso permitido.

### Funcionamiento
El programa cuenta con tres funciones `Log_Message`, que se invocan según los argumentos pasados en `main`:

- **`void logMessage(string message, int n)`**
    - Determina la prioridad a partir de `n` mediante un `switch`.
    - Llama a `create_message`, que escribe el mensaje en `log_system.txt` con la prioridad correspondiente.

- **`void logMessage(string Mensaje_de_Error, string Archivo, int Linea_de_Codigo)`**
    - Se activa si se elige la prioridad 4 (**ERROR**).
    - Recibe el mensaje de error, el archivo y la línea donde ocurrió.
    - Registra esta información en `log_system.txt`.

- **`void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario)`**
    - Se activa cuando se selecciona la opción de iniciar sesión.
    - Si el nombre de usuario coincide con "Bjarne Stroustrup", se registra que el acceso fue otorgado; de lo contrario, se indica que fue denegado.

En `main`, se solicitan los datos al usuario y, si la prioridad ingresada no es válida, se genera un mensaje de error en `log_system.txt`.

---

## Ejercicio 3
En este punto, implemento una **lista simplemente enlazada** con sus primitivas básicas. Además, creé una función auxiliar `create_node` para evitar la repetición de código al crear nodos.

Utilicé exclusivamente **smart pointers** (`shared_ptr`), ya que permiten compartir la propiedad de un nodo sin necesidad de `move`. Esto facilita la manipulación de punteros al insertar o acceder a nodos auxiliares.

En `main`, incluí ejemplos de inserción y eliminación de nodos, con impresiones del estado de la lista tras cada operación.

---

## Ejercicio 4
Este ejercicio consiste en una función recursiva que verifica si dos textos son iguales. Implementé tres versiones:

1. **Con `string`**
2. **Con `const char*`**
3. **Comparación en tiempo de compilación**

Todas las versiones están en el archivo, pero la que no está comentada es la más eficiente en tiempo de ejecución.

### Comparación de eficiencia
- **`const char*` vs `string`**
    - `const char*` es considerablemente más rápido porque accede directamente a la memoria como un array.
    - `string` introduce una capa adicional para la gestión de memoria y verificaciones internas, lo que lo hace más seguro pero más lento.

- **Comparación en tiempo de compilación**
    - Usando `constexpr` para las variables y la función, se logra realizar la comparación en tiempo de compilación.
    - Esto reduce significativamente el tiempo de ejecución, siendo aproximadamente 5 veces más rápido que `const char*`.

### Conclusión
La implementación más eficiente en ejecución es la que usa `const char*` con `constexpr`, debido a su acceso directo a memoria y la posibilidad de evaluar en tiempo de compilación.

---

