#include<stdio.h>
#include<stdlib.h>

// Ejercicio: Sumar dos numeros
int suma(int numUno, int numDos){
    return numUno + numDos;
}

// Ejercicio: Fibonacci recursivo
int fibinacciRecursivo(int num){

    if (num <=1){
        return num;
    }
    
    return fibinacciRecursivo(num -1) + fibinacciRecursivo(num-2);
}

// Ejercicio: Fibonacci iterativo
int fibinacciIterativo(int num){
    if(num <= 1){
        return num;
    }

    int a=0, b=1, c=0;
    for(int i=2; i<= num; i++){
        c = a + b;
        a = b ;
        b = c;
    }

    return c;
}

//Función de un arreglo en C

/*
    Arreglo

    Un arreglo es una coleaccion de elementos del mismo tipo de datos, almacenadis
    en ubicaciones de memoria contiguas. Esto significa que cada elemento están uno
    al lado del otro en memoria

    Caracteristicas principales:
    - Tamaño fijo: El tamaño de un arreglo se define al momento de su creación y 
    no se puede cambiar.
    - Acceso directo: Puedes acceder a cualquier elemento usando su indice.
    - Memoria contigua: Todos los elementos ocupan un bloque de memoria sin interrupciones.
*/
void opeArreglos(){
    int opc=0;
    int tam=0;
    int indice = 0;

    printf("Ingrese el tamaño del arreglo(1 a 100): ");
    scanf("%d", &tam);
    int arr[tam];
    printf("Ingrese los elementos del arreglo; \n");
    for(int i=0;i<tam;i++){
        scanf("%d", &arr[i]);
    }

    printf("Opciones de arreglos: \n");
    printf("1. Mostrar elementos del arreglo. \n");
    printf("2. Mostrar un elemento del arreglo. \n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    
    switch (opc)
    {
    case 1:
        printf("Elementos del arreglo:");
        for(int i=0; i<tam; i++){
            printf(" %d", arr[i]);
        }
        printf("\n");    
        break;
    case 2:
        printf("Ingrese el indice del elemento que desea ver: ");
        scanf("%d", &indice);
        indice = indice - 1;
        if(!(indice>=0 && indice<=tam)){
            printf("Indice fuera de rango. \n");
            return;
        }
        printf("Elemento en el indice %d: %d \n", indice+1, arr[indice]);
        break;
    default:
        printf("Opción no válida. \n");
        break;
    }
    
}

/*
    Listas enlazadas (Linked Lists)

    Una lista enlazada es una colección de elementos llamdos nodos, donde cada nodo
    contiene dos partes: el dato y un puntero que apunta al siguiente nodo en la secuencia.
    El primer nodo de la lista se llama cabeza (head). A diferencia de los arreglos, los nodos
    no necesitan estar en memoria contigua.  

    Características principales:
    - Tamaño dinamico: El tamaño de una lista enlazada puede crecer o disminuir en tiempo de 
      ejecución.
    - Inserción y eliminación eficientes: Es muy facil añadir o quitar nodos en cualquier posición 
      sin mover los demás nodos.
    - Acceso secuencial: Para llegar a un elemento especifico, debes empezar desde el inicio
      (head) y seguir los punteros uno por uno.
*/

/*
    Para implementar una lista enlazada devemos crear una estructura para el nodo
*/

// Estructura para los nodos
struct Nodo{
    int dato; //Dato que almacena el nodo
    struct Nodo* siguiente; //Puntero al siguiente nodo
};

// Función para imprimir la lista
void ImprimirLista(struct Nodo* nodo){
    while(nodo != NULL){
        printf("%d", nodo->dato);
        nodo = nodo->siguiente; //Avanza al siguiente nodo.
        printf("\n");
    }
}

//Función para insertar nodos a la lista
void InsertarNodos(){
    struct Nodo* cabeza = NULL;
    struct Nodo* segundo = NULL;
    struct Nodo* tercero = NULL;
    struct Nodo* cuarto = NULL;

    //Asignart memoria para nodos
    cabeza = (struct Nodo*)malloc(sizeof(struct Nodo));
    segundo = (struct Nodo*)malloc(sizeof(struct Nodo));
    tercero = (struct Nodo*)malloc(sizeof(struct Nodo));
    cuarto = (struct Nodo*)malloc(sizeof(struct Nodo));

    //Asignamos datos y enlazamos los nodos
    cabeza->dato =1;
    cabeza->siguiente=segundo;
    
    segundo->dato=2;
    segundo->siguiente=tercero;

    tercero->dato=3;
    tercero->siguiente=cuarto;

    cuarto->dato=4;
    cuarto->siguiente=NULL; //El último nodo apunta a NULL

    //Imprimir la lista
    printf("Lista enlazada es: ");
    ImprimirLista(cabeza);
}

// Función principal
int main(){
    int opcion = 0;
    int numUno = 0;
    int numDos = 0;
    int resultado = 0;
    int num = 0;
    int tam = 0;
    

    printf("Ingrese la opcion. \n");
    printf("1. Sumar dos numeros. \n");
    printf("2. Calcular Fibonacci recursivo. \n");
    printf("3. Calcular Fibonacci iterativo. \n");
    printf("4. Interactuar con un arreglo. \n");
    printf("5. Interactuar con una lista ligada. \n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)  
    {
    case 1:
        printf("Ingrese numero 1: ");
        scanf("%d", &numUno);
        printf("Ingrese numero 2: ");
        scanf("%d", &numDos);
        resultado = suma(numUno, numDos);
        printf("El resultado de la suma es: %d \n", resultado);
        break;
    case 2:
        printf("Ingrese el número para calcular el Fibonacci reculsivo: ");
        scanf("%d", &num);
        resultado = fibinacciRecursivo(num);
        printf("El resultado del Fibonnaci recursivo es: %d \n", resultado);
        break;
    case 3:
        printf("Ingrese el número para calcular el Fibonacci iterativo: ");
        scanf("%d", &num);
        resultado = fibinacciIterativo(num);
        printf("El resultado del Fibonnaci iterativa es: %d \n", resultado);
        break;
    case 4:
        opeArreglos();
        break;
    case 5:
        InsertarNodos();
        break;

    default:
        printf("Opción no válida. \n");
        break;
    }

    return 0;
}