#include <iostream.h>
#define TAMANO 4          //Definimos el tamaño de la muestra

// Prueba de Algoritmo de Ordenamiento por Seleccion

void ordenar(int[]);      //Funcion para ordenar el parametro recibido

static int CANT = 0;      //Contador de instrucciones que ejecuta el algoritmo

void main() {
	int vector[TAMANO];		//Vector para almacenar la muestra

	cout<< "Prueba de Rendimiento por Camilo Nova - 20022020090" << endl;
   cout<< "\nOrdenamiento por Seleccion" << endl;

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

//Algoritmo de Ordenamiento por Seleccion
void ordenar(int vect[]) {
	CANT++;	//La asignacion de la variable i
	for(int i=0; i < TAMANO; i++) {
   	CANT+= 2;	//La comparacion y el incremento de la variable i
   	int valorMenor = vect[i];
      CANT++;	//La asignacion de valorMenor con vect[i]

      CANT++;	//La asignacion de la variable q
   	for(int q=i; q < TAMANO; q++) {
      	CANT+= 2;	//La comparacion y el incremento de la variable q
      	if(vect[q] < valorMenor) {
         	CANT++;	//La comparacion de vect[q] y valorMenor
         	valorMenor = vect[q];
            CANT++;	//La asignacion de valorMenor con vect[q]
            int a = vect[i];
            CANT++;	//La asignacion de la variable a
   		   vect[i] = vect[q];
            CANT++;	//La asignacion de vect[i] con vect[q]
      		vect[q] = a;
            CANT++;	//La asignacion de vect[q] con a
         }
      }
   }
}
