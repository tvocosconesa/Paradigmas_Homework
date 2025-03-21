# Paradigmas_Homework

## Ejecución
Los programas se ejecutan con el comando `make` en la terminal, siempre asegurándose de estar en el directorio correcto.

---

## Ejercicio 1
Para trabajar con la matriz de este punto, dividí el proceso en tres funciones:

- **`create_matrix`**: Crea la matriz e inserta los números en ella.
- **`print_matrix`**: Imprime la matriz con el formato requerido en la consigna. Para hacerlo con un solo ciclo `for`, inicialicé el iterador en `N*N - 1` y lo recorrí de forma decreciente. Luego usé las operaciones `i / N` y `i % N` para referirme a la fila y columna correspondiente a la hora de hacer el cout.
- **`delete_matrix`**: Recorre las filas de la matriz y las elimina una por una. Finalmente, libera el puntero de la matriz.

Cuando se ejecuta el programa, se le pide al usuario que ingrese un número `N`, el cual determina el tamaño de la matriz (`N x N`).

---

## Ejercicio 2
### Ejecución
Este programa se maneja a través de la terminal y permite interactuar con la función `Log_message` mediante dos opciones:

1. **Redactar información / Reportar un aviso**
    - Se selecciona una prioridad para el mensaje que quiero enviar. Las opciones disponibles se muestran en la terminal.
    - Una vez elegida la prioridad (ingresando su número correspondiente a la misma), el usuario puede escribir su mensaje, que será registrado en el archivo `log_system.txt`.

2. **Iniciar sesión en el sistema**
    - Se solicita un nombre de usuario.
    - Dependiendo del nombre ingresado, se otorgará o denegará el acceso.
    - Este resultado se registrará en `log_system.txt`. Solo el usuario **"Bjarne Stroustrup"** tiene acceso permitido.

### Funcionamiento
El programa cuenta con tres funciones `Log_Message`, que son llamadas dependiendo de los argumentos que se les ponga en el `main`:

- **`void logMessage(string message, int n)`**
    - Determina la prioridad a partir de `n` mediante un `switch`.
    - Llama a `create_message`, que escribe el mensaje en `log_system.txt` con la prioridad correspondiente.

- **`void logMessage(string Mensaje_de_Error, string Archivo, int Linea_de_Codigo)`**
    - Se activa si se elige la prioridad 4 (**ERROR**).
    - Recibe el mensaje de error, el archivo y la línea donde ocurrió.
    - Registra esta información en `log_system.txt`.

- **`void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario)`**
    - Se activa cuando se selecciona la opción de iniciar sesión.
    - Si el nombre de usuario ingresado es "Bjarne Stroustrup", se registra que el acceso fue otorgado; de lo contrario, se indica que fue denegado.

En el `main`, se solicitan los datos para las funciones `Log_message` y, si la prioridad ingresada no es válida (el numero no coincide con ninguna de las opciones validas del menú), se genera un mensaje de error en `log_system.txt`.

---

## Ejercicio 3
En este punto, implemento una **lista simplemente enlazada** con sus primitivas. Adicionalmente, creé una función auxiliar `create_node` para evitar la repetición de código al crear nodos.

Utilicé exclusivamente **smart pointers**, particularmente `shared_ptr`, ya que permiten compartir el ownership de un nodo sin necesidad de usar `move` para cambiarla. Esto me facilitó bastante la manipulación de punteros al insertar, reasignar roles o acceder a nodos auxiliares.

En `main`, incluí ejemplos de inserción y eliminación de nodos, con impresiones del estado de la lista luego de cada operación.

---

## Ejercicio 4
Este ejercicio consiste en una función recursiva que verifica si dos textos son iguales. Implementé tres versione, las cuales en escencia son lo mismo pero utilizan distintos tipos de argumentos:

1. **Con `string`**
2. **Con `const char*`**
3. **Con Comparación en tiempo de compilación: `constexpr const char*`**

Todas las versiones están en el archivo, la que no está comentada es la más eficiente en tiempo de ejecución. En el caso de querer ejecutar alguna de las otras uno tiene que descomentar la funcion deseada y su respectivo header en el archivo `ej4.h`

### Comparación de eficiencia
- **`const char*` vs `string`**
    - `const char*` resultó ser considerablemente más rápido. Esto se debe a que accede de manera directa a la memoria como si fuera un array. Decidí agregarle el `const` como medida de seguridad para que el texto no sea modificado por acciddente y que simplemente se observe su direccion de memoria sin poder tocarlo.
    - Por otro lado el `string` al parecer tiene verificaciones internas las cuales lo hacen mas seguro en sierto sentido, pero termina sieno mas lento

- **Comparación en tiempo de compilación**
    - Usando `constexpr` para las variables y la función, se logra realizar la comparación en tiempo de compilación.
    - Esto reduce significativamente el tiempo de ejecución y lo hace el mas rapido de los tres.

### Conclusión
La implementación más eficiente en ejecución es la que usa `const char*` con `constexpr`. Debido a su acceso directo a memoria y al hecho de que la funcion compara los textos en tiempo de compilado esta combinacion termina siendo muchisimo mas rapida que el `string` o el `const char*` solo.

---

