#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
* @file
* @brief Proyecto 1
* @author Santiago Solarte Castillo <santiagosolarte@unicauca.edu.co>
*/
/*
Para encontrar la representación en binario de un número entre 0 y 255 con 8 bits, almacenamos
el valor a representar en una variable entera. Posteriormente, a partir de la máxima potencia de 2
que se puede almacenar en 8 bits (128), vamos “apagando” de izquierda a derecha aquellos bits
cuyo valor exceda el valor actual de la variable y dejando “encendido” el bit cuya potencia de 2
correspondiente sea menor o igual al valor de la variable. Cada vez que dejamos un bit encendido,
restamos el valor de la potencia de 2 correspondiente a la variable, hasta llegar a la primera
potencia de 2 (20). Si en algún momento el valor de la variable es 0, los demás bits hasta la primera
potencia de 2 serán 0.

Especificación del algoritmo (para n bits)
El proceso anteriormente descrito se puede extender a nbits, buscando primero la máxima
potencia de 2 que se encuentre justo por debajo del valor a transformar. Partiendo de esta
potencia hasta llegar a 0 se van “apagando” los bits o dejando encendidos, restando el valor
correspondiente a la potencia de 2.

Entradas: el numero de bits(32 maximo, usar unsigned, long), el numero que se desea pasar a binario
Salida: el numero ingresado convertido a binario
*/

//Funcion para calcular potencia, usando la funcion pow 
int potencia(int expo){
	return (unsigned int)pow(2, expo);
}

int main (){
	//Declaracion de variables 
	int numDec, restante, numBits;
	
	//Entrada
	printf("Convertidor de números decimales a binarios\n");
	//Ciclo en caso de que los bits ingresados no esten dentro del tamaño indicado
	do{
		printf("Porfavor ingrese el número de bits con los que desea trabajar(mínimo 1 y máximo 31): \n");
		scanf("%d", &numBits);
	}while(numBits <= 0 || numBits >= 32);
	printf("Ahora ingrese el número decimal que desea convertir a binario: \n");
	scanf("%d", &numDec);
	
	//Proceso
	restante = numDec;
	printf("El binario del número %d, es: ", numDec);
	for(int i = numBits; i >= 0; i--){
		unsigned int pot=potencia(i);
		if(restante >= pot){
			restante -= pot;
			printf("1");
		}else
		   printf("0");
	}
	
	//Salida
	printf("\n");
	
	return 0;
}
	
