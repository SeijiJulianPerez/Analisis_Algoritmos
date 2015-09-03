//
//  countingSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//


#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;

void countingSort(int [], int);  //prototipo de la funcion

void countingSort(int a[], int n) {
	int i, j, k;
	int x = 0;
	int min, max;
    
	min = max = a[0];
	for(i = 1; i < n; i++) {
		min = (a[i] < min) ? a[i] : min;
		max = (a[i] > max) ? a[i] : max;
	}
    
	k = max - min + 1;
	
	//crea x buckets
	int *B = new int [k];
	for(i = 0; i < k; i++)
		B[i] = 0;
	
	for(i = 0; i < n; i++)
		B[a[i] - min]++;
	
	for(i = min; i <= max; i++)
		for(j = 0; j < B[i - min]; j++)
			a[x++] = i;
	delete [] B;   //limpia memoria
}

void imprime(int a[],int n) //imprime los elementos del arreglo
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
    
    clock_t inicio, fin;      //inicializa el clock
	inicio = clock();
    countingSort(a,tamanio);
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