#include<stdio.h>
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

    default:
        printf("Opción no válida. \n");
        break;
    }

    return 0;
}