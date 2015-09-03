//
//  mergeSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//Prototipos de las funciones
void mergeSort(int arregla[], int temporal[], int array_size);
void m_sort(int arregla[], int temporal[], int inicio, int fin);
void merge(int arregla[], int temporal[], int inicio, int enMedio, int fin);

/*ORDENAMIENTO ASCENDENTE*/
void mergeSort(int arregla[], int temporal[], int array_size)
{
    m_sort(arregla, temporal, 0, array_size - 1);
}

void m_sort(int arregla[], int temporal[], int inicio, int fin)
{
    int enMedio;
    
    if (fin > inicio)
    {
        enMedio = (fin + inicio) / 2;
        m_sort(arregla, temporal, inicio, enMedio);
        m_sort(arregla, temporal, (enMedio+1), fin);
        
        merge(arregla, temporal, inicio, (enMedio+1), fin);
    }
}

void merge(int arregla[], int temporal[], int inicio, int enMedio, int fin)
{
    int i, finDelInicio, num, posTemp;
    
    finDelInicio = (enMedio - 1);
    posTemp = inicio;
    num = (fin - inicio + 1);
    
    while ((inicio <= finDelInicio) && (enMedio <= fin))
    {
        if (arregla[inicio] <= arregla[enMedio])
        {
            temporal[finDelInicio] = arregla[inicio];
            posTemp++;
            inicio++;
        }
        else
        {
            temporal[posTemp] = arregla[enMedio];
            posTemp++;
            enMedio++;
        }
    }
    
    while (inicio <= finDelInicio)
    {
        temporal[posTemp] = arregla[inicio];
        inicio++;
        posTemp++;
    }
    
    while (enMedio <= fin)
    {
        temporal[posTemp] = arregla[enMedio];
        enMedio++;
        posTemp++;
    }
    
    
    for (i=0; i < num; i++)
    {
        arregla[fin] = temporal[fin];
        fin--;
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
    
    int a[tamanio], b[tamanio];
    
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
    mergeSort(a,b,tamanio);
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