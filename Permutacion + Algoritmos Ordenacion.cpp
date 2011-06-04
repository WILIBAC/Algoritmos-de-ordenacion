#include <iostream.h>
#include <stdlib.h>
#include <fstream.h>

void burbuja(int[]);
void seleccion(int[]);
void insercion(int[]);
void permutar(char *, int l=0);

static int TAMANO = 0;
static int CANT = 0;
static ofstream archivo("resultado.txt");

void main() {
   char *cadena = "";

	cout<< "Generador de permutaciones + tiempo de ejecucion" << endl;
   cout<< "Digite una cadena de numeros:\t";
   cin>> cadena;

   cout<< "\nLas permutaciones siguientes seran escritas en el archivo:" << endl;

	archivo<< "Resultados Generacion de Permutaciones y Tiempo de Ejecucion" << endl;
   archivo<< "Permutacion\tBurbuja\tInstrucciones\tSeleccion\tInstrucciones\tInsercion\tInstrucciones" << endl;

   permutar(cadena);

   archivo.close();
   cin.get();
   cin.get();
}

void permutar(char *cad, int l) {
   char c;    /* variable auxiliar para intercambio */
   int i, j;  /* variables para bucles */
   int n = strlen(cad);
   TAMANO = n;
   int *permutado = new int[TAMANO];

   for(i = 0; i < n-l; i++) {
      if(n-l > 2)
      	permutar(cad, l+1);
      else {
      	cout << cad << ", ";

         //--------------------------------------------------//
			for(int m=0; m < TAMANO; m++)
         	permutado[m] = cad[m]-48;
         CANT = 0;
         burbuja(permutado);
         archivo<< cad << "\t";
         for(int a=0; a < TAMANO; a++)
         	archivo<< permutado[a];
         archivo<< "\t" << CANT << "\t";

			for(int m=0; m < TAMANO; m++)
         	permutado[m] = cad[m]-48;
         CANT = 0;
         seleccion(permutado);
         for(int a=0; a < TAMANO; a++)
         	archivo<< permutado[a];
         archivo<< "\t" << CANT << "\t";

			for(int m=0; m < TAMANO; m++)
         	permutado[m] = cad[m]-48;
         CANT = 0;
         insercion(permutado);
         for(int a=0; a < TAMANO; a++)
         	archivo<< permutado[a];
         archivo<< "\t" << CANT << endl;
      }
      /* Intercambio de posiciones */
      c = cad[l];
      cad[l] = cad[l+i+1];
      cad[l+i+1] = c;
      if(l+i == n-1) {
         for(j = l; j < n; j++)
         	cad[j] = cad[j+1];
         cad[n] = 0;
      }
   }
}

//Algoritmo de Ordenamiento por Insercion
void insercion(int vect[]) {
	int a;
	CANT++;	//La asignacion de la variable i = 1
   for(int i=1; i < TAMANO; i++) {
   	CANT+= 2;	//La comparacion y el incremento de la variable i
      CANT++;		//La asignacion de la variable a = i
   	a = i;
   	while(vect[a] < vect[a-1] && a > 0) {
      	CANT+= 2;	//La comparacion de los elemento y la comprobacion de a>0
         CANT++;		//La asignacion de la variable t
      	int t = vect[a];
         CANT++;		//La asignacion del valor
         vect[a] = vect[a-1];
         CANT++;		//La asignacion del valor
         vect[a-1] = t;
         CANT++;		//La disminucion de la variable a
         a--;
      }
   }
}

//Algoritmo de Ordenamiento por Seleccion
void seleccion(int vect[]) {
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

//Algoritmo de Ordenamiento de Burbuja
void burbuja(int vect[]) {
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
