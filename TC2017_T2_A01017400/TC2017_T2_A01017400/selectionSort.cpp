//
//  selectionSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

void selectionSort(int [], int);   //prototipo de funcion

/*ORDENAMIENTO ASCENDENTE*/
void selectionSort(int numbers [], int n)
{
    int temp;
    int minimo = 0;
    for(int i = 0; i < n-1; i++){
        minimo = i;
        for(int j = i+1; j < n; j++){
            
            if(numbers[minimo] > numbers[j])
                minimo = j;
        }
        temp = numbers[minimo];
        numbers[minimo] = numbers[i];
        numbers[i] = temp;
        
	}
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
    
    clock_t inicio, fin;
    inicio = clock();
    selectionSort(a,tamanio);
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