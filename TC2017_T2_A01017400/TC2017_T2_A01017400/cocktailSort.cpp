//
//  cocktailSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*ORDENAMIENTO ASCENDENTE*/
void cocktailSort(int a[], int n)
{
	int i,j,temp;
    for (int i = 1; i <= (n/2)-1; i++) { //pone enmedio y por burbuja de izq a der
        for (int j = 0; j <= n-2; j++)
            if (a[j] > a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
            }
        
        //usa ordenamiento por burbuja de derecha a izquierda
        for (int j = n-i; j > i; j--)
            if (a[j] < a[j-1]){
              	temp=a[j];
	      		a[j]=a[j-1];
	      		a[j-1]=temp;
            }
    }
}

void imprime(int a[],int n)
{
    for(int i=0;i<=n-1;i++)
        cout<<a[i]<<" ";
}

int main ()
{
	int tamanio;
    cout << "Introduce el tamaño del arreglo" << endl;
    cin >> tamanio;
    
    int a[tamanio];
    
    srand((unsigned)time(0));
    
    cout << "\nArreglo desordenado: " << endl;
    for(int i=0; i<tamanio; i++) {
        a[i] = (rand()%1000000)+1;
    }
    if (tamanio<=100)
        imprime(a,tamanio);
    else
        cout << "Arreglo muy grande para imprimir";
    
    cout << "\n\n";
    
    clock_t inicio, fin;
    
	inicio = clock();
    cocktailSort(a,tamanio);
    fin = clock();
    
    cout << "Arreglo ordenado: " << endl;
    if (tamanio<=100)
        imprime(a,tamanio);
    else
        cout << "Arreglo muy grande para imprimir";
    
    cout << "\n\n";
    
    cout << "Tiempo de ejecucion: " <<
    (double)(fin-inicio)/CLOCKS_PER_SEC <<
    " seg\n" << endl;
    
    return 0;
}
