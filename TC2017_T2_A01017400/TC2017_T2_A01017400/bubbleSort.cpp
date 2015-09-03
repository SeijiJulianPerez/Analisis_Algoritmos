//
//  bubbleSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

/*ORDENAMIENTO ASCENDENTE*/
void bubbleSort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<=n-2;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];     //funcion swap
                a[j]=a[j+1];   //o de intercambio
                a[j+1]=temp;
            }
        }
    }
}

/*ORDENAMIENTO DESCENDENTEMENTE*/
/*
 void bubbleSort(int a[],int n)
 {
 int i,j,temp;
 for(i=1;i<=n;i++)
 {
 for(j=n;j>i;j--)
 {
 if(a[j-1]>a[j])
 {
 temp=a[j-1];     //funcion swap
 a[j-1]=a[j];   //o de intercambio
 a[j]=temp;
 }
 }
 }
 }
 */

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
    
	srand((unsigned)time(0));    //genera numeros aleatorios
	cout << "\nArreglo desordenado: " << endl;
	for(int i=0; i<tamanio; i++) {
		a[i] = (rand()%1000000)+1;   //rango de num aleatorios
	}
	if (tamanio<=100)
		imprime(a,tamanio);
	else
		cout << "Arreglo muy grande para imprimir";
	
	cout << "\n\n";
    
	clock_t inicio, fin;      //inicializa el clock
	inicio = clock();
	bubbleSort(a,tamanio);
	fin = clock();            //termina el clock
    
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
