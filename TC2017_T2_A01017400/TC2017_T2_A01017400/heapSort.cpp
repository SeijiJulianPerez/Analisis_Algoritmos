//
//  heapSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;

void swap(int array[], int left, int right);
void repairTop(int array[], int bottom, int topIndex);
void heapSort(int a[],int length);
int heapsize;

/*ORDENAMIENTO DESCENDIENTE*/
void heapSort(int array[], int size) {
    for (int i = size/2 - 1; i >= 0; i--) {
        repairTop(array, size - 1, i);
    }
    for (int i = size - 1; i > 0; i--) {
        swap(array, 0, i);
        repairTop(array, i - 1, 0);
    }
}

//mueve la cima del heap a su lugar correcto
void repairTop(int array[], int bottom, int topIndex) {
    int tmp = array[topIndex];
    int succ = topIndex*2 + 1;
    if (succ < bottom && array[succ] > array[succ+1]) succ++;
    
    while (succ <= bottom && tmp > array[succ]) {
        array[topIndex] = array[succ];
        topIndex = succ;
        succ = succ*2 + 1;
        if (succ < bottom && array[succ] > array[succ+1]) succ++;
    }
    array[topIndex] = tmp;
}

//Intercambia dos elementos del heap
void swap(int array[], int left, int right) {
    int tmp = array[right];
    array[right] = array[left];
    array[left] = tmp;
}

void imprime(int a[],int n) //imprime los elementos del arreglo
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
    
    clock_t inicio, fin;      //inicializa el clock
	inicio = clock();
    heapSort(a,tamanio);
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