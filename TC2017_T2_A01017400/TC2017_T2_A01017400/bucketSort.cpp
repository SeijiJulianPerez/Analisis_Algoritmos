//
//  bucketSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;

void bucketSort(int [], int);   //prototipo de la funcion

/*ORDENAMIENTO ASCENDENTE */
void bucketSort(int array[], int n) {
//metodo de insercion por partes
    
    
    const int max = n;
    
    //usa bucket[x][max] para mantener la cuenta actual
    int bucket[10][max+1];
    
    for(int x=0;x<10;x++)
        bucket[x][max] = 0;
    //ciclo para cada posicion del digito
    for(int digito = 1; digito <= 1000000000; digito *= 10) {
        //array a bucket
        for(int i = 0; i < max; i++) {
            //consigue un digito del 0-9
            int dig = (array[i] / digito) % 10;
            //se lo añade al bucket e incrementa la cuenta
            bucket[dig][bucket[dig][max]++] = array[i];
        }
        // bucket al array
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++) {
                array[idx++] = bucket[x][y];
            }
            //resetea los contadores internos del bucket
            bucket[x][max] = 0;
        }
    }
}


void imprime(int a[],int n)
{
    for(int i=0;i<=n-1;i++)
        cout<<a[i]<<" ";
}


int main (int argc, const char * argv[])
{
	int tamanio;
    cout << "Introduce el tamaño del arreglo" << endl;
    cin >> tamanio;
    
    int a[tamanio];
    
    srand((unsigned)time(0));
    
    cout << "\nArreglo desordenado: " << endl;
    for(int i=0; i<tamanio; i++) {
		a[i] = (rand()%100)+1;
    }
    
    if (tamanio<=100)
        imprime(a,tamanio);
    else
        cout << "Arreglo muy grande para imprimir";
    
    cout << "\n\n";
    
    clock_t inicio, fin;
    inicio = clock();
    bucketSort(a,tamanio);
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