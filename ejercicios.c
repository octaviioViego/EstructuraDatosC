#include<stdio.h>

int suma(int numUno, int numDos){
    return numUno + numDos;
}

int main(){
    int numUno = 1;
    int numeDos = 2;

    int resultado = suma(numUno,numeDos);
    printf("El resultado de la suma es: %d \n", resultado);
    
    return 0;
}