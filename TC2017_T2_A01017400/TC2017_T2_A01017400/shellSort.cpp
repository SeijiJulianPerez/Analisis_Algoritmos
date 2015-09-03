//
//  shellSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//


#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int * shellSort(int *, int);   //prototipo de funcion

/*ORDENAMIENTO DESCENDENTE*/
int * shellSort(int * array, int size) {
    int gap = size / 2;
    while (gap > 0) {
        for (int i = 0; i < size - gap; i++) {
            int j = i + gap;
            int tmp = array[j];
            while (j >= gap && tmp > array[j - gap]) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = tmp;
        }
        if (gap == 2){
            gap = 1;
        } else {
            gap /= 2.2;
        }
    }
    return array;
}

void imprime(int * a,int n) //imprime los elementos del arreglo
{
    for(int i=0;i<=n-1;i++)
        cout<<a[i]<<" ";
}

int main()
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
    shellSort(a,tamanio);
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