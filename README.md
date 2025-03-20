# Paradigmas_Homework

# Ejecucion:
los programas se ejecutan con el comando make en la terminal, siempre teniendo en cuenta que se este en el archivo deseado.

# Ej 1:
Para trabajar con la matriz de este punto decidi dividir el proceso en tres funciones: create_matrix - delete_matrix - print_matrix.
- create_matrix: Esta funcion crea la matriz e inserta los numeros dentro de la misma.
- print_matrix: En esta funcion imprimo los valores con el formato mostrado en la consigna. Para poder hacerloo con un solo ciclo for hice inicialice el for de manera decreciente con su iterador comenzando por el tamaño de la matriz menos 1. luego para el cuout utilicé las operaciones i/n y i%n para referirme a la fila y columna deseada respectivamente.
- delete_matrix: Esta funcion recorre las filas de la matriz y las va eliminando una por una, luego termina por eliminar el puntero a la matriz en si.

Cuando se ejecute el programa se le va a pedir por consola al usuario que inserte un numero N. Esta variable va a ser para determinar el tamaño de la matriz ( N x N )


# Ej 2:


# Ej 3:
En este punto implemento una lista simplemente enlazada y creo algunas de sus primitivas. Adicionalmente hice una funcion auxiliar create_node, la cual llamo cuando es necesario crear un nodo, para ahorrar repeticion de codigo. En este punto utilizé pura y eaxlusivamente smart pointers, mas especificamente shared pointers. Opté por este tipo de punteros ya que pueden tener mas de un owner, lo que hace que no tenga que preocuparme por usar la funcion move y pueda reasignar los punteros de manera mas libre a la hora de insertar un nodo o utilizar un nodo auxiliar por ejemplo.
En mi main opte por poner algunos ejemplos de inserciones y eliminaciones de elementos en la lista. A estos se les va haciendo un seguimiento luego de cada accion mediante una impresión del estado de la lista en cada momento.


# Ej 4:
En este punto creo una funcion recursiva la cual verifique si es que dos textos son iguales. En total hice 3 versiones de esta funcion, una con strings, una con const char * y finalmente una la cual compara los textos en tiempo de compilado.
    En un principio compare las dos funciones que se ejecutan totalmente en tiempo de ejecución. Entre ellas pude comprobar que
la funcion con const char* fue considerablemente mas rapida que la de string. Esto se debe a que la funcion const char* accede de manera directa a las distintas posiciones de memoria como si fueran un array. por otro lado, ingagando mas profundamente, leí que el string usa una capa adicional para gestionar memoria y ademas tiene verificaciones internas. Como el string no modifica el acceso a memoria es mas seguro en cierto sentido, pero siendo que el char * que utilicé es const uno no deberia preocuparse de algun tipo de cambio indeseado en la memoria. 
    Por el lado de la funcion que compara en tiempo de compilado, esta resulto todavia mas eficiente que la const char*. utilicé 
la declaracion constexpr para las variables de texto y la funcion que compara. De esta manera puse comparar los textos en tiempo de compilado y como consecuencia el tiempo de ejecución fue casi 5 veces menos que el del const char*.

En conclusion en cuanto al tiempo de ejecucion, la funcion mas eficiente es l que utiliza const char* sumado aconstexpr para  correr hacer la comparacion en timpo de compilado. Esto se debe a la combinacion de acceso a memori mas directo y la posibilidad de commparar en la compilacion.