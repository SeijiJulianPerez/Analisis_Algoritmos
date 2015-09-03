//
//  insertionSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//


#include <stdlib.h>
#include <cstdlib>
#include <iostream>
using namespace std;

/*ORDENAMIENTO DESCENDENTE */
void insertionSort(int a[],int n)
{
    int i,j,temp,key;
    for(j=1;j<n;j++)
    {
        key=a[j];   //este algoritmo se basa en una llave
        for(i=j-1;(i>=0)&&(a[i]<key);i--)
        {
            //Si ambas condiciones se cumplen hay intercambio
            //y el for sigue,
            //sino se sale
            temp=a[i+1]; //funcion swap
            a[i+1]=a[i]; //o de intercambio
            a[i]=temp;
        }
        a[i+1]=key;
    }
}

void imprime(int a[],int n)
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
    insertionSort(a,tamanio);
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