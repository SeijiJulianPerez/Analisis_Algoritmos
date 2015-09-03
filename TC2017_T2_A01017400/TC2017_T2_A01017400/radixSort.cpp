//
//  radixSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//


#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

void radixSort(int [], int); //prototipo

/*ASCENDENTE*/
void radixSort(int x[], int n)
{
    int front[10], rear[10];
    struct {
        int info;
        int next;
    }
    node[n];
    int exp, first, i, j, k, p, q, y;
    
    //Incicializa una lista vinculada
    
    for (i = 0; i < n-1; i++) {
        node[i].info = x[i];
        node[i].next = i+1;
    }
    node[n-1].info = x[n-1];
    node[n-1].next = -1;
    first = 0; 		//cabeza de la lista vinculada
    for (k = 1; k <= 6; k++) {
        //Suponer que tenemos números de seis dígitos
        for (i = 0; i < 10; i++) {
            //Inicializa colas
            rear[i] = -1;
            front[i] = -1;
        }
        //Se procesa cada elemento en la lista
        while (first != -1) {
            p = first;
            first = node[first].next;
            y = node[p].info;
            
            exp = pow(10, k-1);       // elevar 10 a la (k-1)ésima potencia */
            j = (y/exp) % 10;
            // Insertar "y" en queue[j]
            q = rear[j];
            if (q == -1)
                front[j] = p;
            else
                node[q].next = p;
            rear[j] = p;
        }
        
        /* En este punto, cada registro está en su cola basándose en el dígito k
         Ahora se forma una lista única de todos los elementos de la cola.
         Encontrar el primer elemento. */
        for (j = 0; j < 10 && front[j] == -1; j++);
        ;
        first = front[j];
        
        /* Vincular las colas restantes */
        while (j <= 9) {    /* Verificar si se ha terminado */
            /*Encontrar el elemento siguiente */
            for (i = j+1; i < 10 && front[i] == -1; i++);
            ;
            if (i <= 9) {
                p = i;
                node[rear[j]].next = front[i];
            }
            j = i;
        }
        node[rear[p]].next = -1;
    }
    
    /* Copiar de regreso al archivo original */
    for (i = 0; i < n; i++) {
        x[i] = node[first].info;
        first = node[first].next;
    }
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
    
    clock_t inicio, fin;
	inicio = clock();
    radixSort(a,tamanio);
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
