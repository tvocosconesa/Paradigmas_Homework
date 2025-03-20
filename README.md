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
### Como ejecutar:
Este programa se maneja totalmente por la terminal y en base a una serie de opciones uno va a poder interactuar de diferentes maneras con las funciones Log_message. Al ejecutar el codigo a uno va a tener que tomar la decision de elegir entre dos opciones de operacion:
    1. Redactar info / reportar un aviso:
        En esta opcion uno va a tener que seleccionar una prioridad para asignarle a su mensaje. Las opciones de estas van a ser mostradas por la terminal. Una vez seleccionada su prioridad, introduciendo el numero correspondiente a su prioridad, uno va a poder escribir el mensaje que desea enviar al archivo log_system.txt .  
    2. Iniciar sesion en el sistema:
        Al usuario se le va a pedir que ingrese un nombre de usuario. En base a lo que el usuario ingrese el acceso se le va a ser otorgado o denegado. Este resultado va a ser registrado en el archivo log_system.txt . Hay solo un Nombre de usuario al cual se le otorga acceso, este es "Bjarne Stroustrup" 
### funcionamiento:
El programa tiene tres funciones Log_Message las cuales van a ser llamadas dependiendo del tipo de argumento el cual se les otorgue en el main. 
    - void logMessage(string message, int n):
        Esta es la mas generica de todas. tiene un switch el cual que en base al n que se le pasa selecciona una prioridad. Una vez seleccionada la prioridad esta es asignada como argumento de la funcion create_message. Esta funcion luego procede a ingresar en el archivo txt el mensaje junto con su prioridad
    - void logMessage( string Mensage_de_Error, string Archivo, int Línea_de_Código):
        Si uno selecciona la prioridad 4 (ERROR) uno va a tener que pasar por terminal los datos correspondientes a los argumentos de esta funcion. Una vez hecho esto la funcion procede a enviar el mensaje al txt diciendo que en el tal archivo ha un error en la linea x, y junto con esto se deja el mensaje de descripción del error.
    - void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario):
        Finalmente esta es la funcion para cuando se selecciona la opcion de iniciar sesion en el sistema. Si el nombre ingresado coincide con el username habilitado (Bjarne Stroustrup) en el archivo txt aparecera que el accesoo fue otorgado al usuario. Por lo contrario en el txt aparecera que este fue denegado.

En el main de la función es que al usuario se le piden los datos para las funciones. En el caso de que el numero de prioridad ingresado no coincida con las opciones posibles, aparecera en el archivo txt un mensaje del tipo ERROR en el que se avisara de que dicho numero es invalido.





# Ej 3:
En este punto implemento una lista simplemente enlazada y creo algunas de sus primitivas. Adicionalmente hice una funcion auxiliar create_node, la cual llamo cuando es necesario crear un nodo, para ahorrar repeticion de codigo. En este punto utilizé pura y eaxlusivamente smart pointers, mas especificamente shared pointers. Opté por este tipo de punteros ya que pueden tener mas de un owner, lo que hace que no tenga que preocuparme por usar la funcion move y pueda reasignar los punteros de manera mas libre a la hora de insertar un nodo o utilizar un nodo auxiliar por ejemplo.
En mi main opte por poner algunos ejemplos de inserciones y eliminaciones de elementos en la lista. A estos se les va haciendo un seguimiento luego de cada accion mediante una impresión del estado de la lista en cada momento.


# Ej 4:
En este punto creo una funcion recursiva la cual verifique si es que dos textos son iguales. En total hice 3 versiones de esta funcion, una con strings, una con const char* y finalmente una la cual compara los textos en tiempo de compilado. 
En el archivo se encuentran todas las etapas de esta funcion. La que no esta comentada es la mas eficiente en tiempo de ejecución. Asimismo en el main esta la posibilidad de utilizar los mismos textos bajo otro tipo de variable para probar las otras funciones.

    En un principio compare las dos funciones que se ejecutan totalmente en tiempo de ejecución. Entre ellas pude comprobar que
la funcion con const char* fue considerablemente mas rapida que la de string. Esto se debe a que la funcion const char* accede de manera directa a las distintas posiciones de memoria como si fueran un array. por otro lado, ingagando mas profundamente, leí que el string usa una capa adicional para gestionar memoria y ademas tiene verificaciones internas. Como el string no modifica el acceso a memoria es mas seguro en cierto sentido, pero siendo que el char * que utilicé es const uno no deberia preocuparse de algun tipo de cambio indeseado en la memoria. 
    Por el lado de la funcion que compara en tiempo de compilado, esta resulto todavia mas eficiente que la const char*. utilicé 
la declaracion constexpr para las variables de texto y la funcion que compara. De esta manera puse comparar los textos en tiempo de compilado y como consecuencia el tiempo de ejecución fue casi 5 veces menos que el del const char*.


En conclusion en cuanto al tiempo de ejecucion, la funcion mas eficiente es l que utiliza const char* sumado aconstexpr para  correr hacer la comparacion en timpo de compilado. Esto se debe a la combinacion de acceso a memori mas directo y la posibilidad de commparar en la compilacion.