#include<stdio.h>

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


int main(){
    int opcion = 0;
    int numUno = 0;
    int numDos = 0;
    int resultado = 0;
    int num = 0;

    printf("Ingrese la opcion. \n");
    printf("1. Sumar dos numeros. \n");
    printf("2. Calcular Fibonacci recursivo. \n");
    printf("3. Calcular Fibonacci iterativo. \n");
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
    default:
        printf("Opción no válida. \n");
        break;
    }

    return 0;
}