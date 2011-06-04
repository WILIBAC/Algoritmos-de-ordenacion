#include <iostream.h>
#define TAMANO 7          //Definimos el tamaño de la muestra

// Prueba de Algoritmo de Ordenamiento por Burbuja

void ordenar(int[]);      //Funcion para ordenar el parametro recibido

static int CANT = 0;      //Contador de instrucciones que ejecuta el algoritmo

void main() {
	int vector[TAMANO];		//Vector para almacenar la muestra

	cout<< "Prueba de Rendimiento por Camilo Nova - 20022020090" << endl;
   cout<< "\nOrdenamiento por Burbuja" << endl;

   //Recopilamos los datos de la muestra
   CANT++; //La asignacion de la variable i
   for(int i=0; i < TAMANO; i++) {
   	CANT += 2; //La comparacion y el incremento de la variable
   	cout<< "\nDigite el elemento " << (i+1) << ":\t";
      cin>> vector[i];
      CANT++; //La asignacion del elemento a vector[i]
   }

   ordenar(vector);	//Llamamos a la funcion para ordenar la muestra

   cout<< "\nLos elementos ordenados son: ";
   //Mostramos los datos ordenados
   for(int m=0; m < TAMANO; m++)
   	cout<< vector[m] << " ";

   cout<< "\n\nLa cantidad de instrucciones ejecutadas son:\t" << CANT << endl;

   cin.get();
   cin.get();
}

//Algoritmo de Ordenamiento de Burbuja
void ordenar(int vect[]) {
	CANT++; //La asignacion de la variable i
	for(int i=0; i < TAMANO; i++) {
   	CANT+= 2; //La comparacion y el incremento de la variable
      CANT++; //La asignacion de la variable k
   	for(int k=0; k < TAMANO-1; k++) {
	   	CANT+= 2; //La comparacion y el incremento de la variable
      	if(vect[k] > vect[k+1]) {
         	CANT++; //La comparacion del if
         	int a = vect[k];
            CANT++; //La asignacion del valor
            vect[k] = vect[k+1];
            CANT++; //La asignacion del valor
            vect[k+1] = a;
            CANT++; //La asignacion del valor
         }
      }
   }
}

