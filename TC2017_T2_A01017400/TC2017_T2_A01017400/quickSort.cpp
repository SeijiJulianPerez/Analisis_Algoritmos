//
//  quickSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;


void quickSort(int x[], int primero, int ultimo);

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
        a[i] = (rand()%100)+1;
    }
    if (tamanio<=100)
        imprime(a,tamanio);
    else
        cout << "Arreglo muy grande para imprimir";
    
    cout << "\n\n";
    
    clock_t inicio, fin;      //inicializa el clock
	inicio = clock();
    quickSort(a,0,tamanio-1);
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


void quickSort(int x[], int primero, int ultimo){
    
    int up;
    int down;
    int aux;
    int pivote;
    
    up = primero + 1;
    down = ultimo;
    
    pivote = x[primero];
    
    
    if (primero>=ultimo) {
        
        return;
        
    }
    
    while(up<=down){
        
        while(x[up]<=pivote){
            up++;
        }
        while(x[down]>=pivote){
            down--;
        }
        
        if(up<=down)
        {
            
            aux = x[down];
            x[down] = x[up];
            x[up] = aux;
            
            
            
        }
        
    }
    
    
    aux = x[down];
    x[down] = x[primero];
    x[primero] = aux;
    
    quickSort(x,primero,down - 1);
    quickSort(x,up,ultimo);
    
    
}