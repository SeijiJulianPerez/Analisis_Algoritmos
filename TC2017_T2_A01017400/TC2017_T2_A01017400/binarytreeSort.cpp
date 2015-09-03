//
//  BinaryTreeSort.cpp
//  TC2017_T2_A01017400
//
//  Created by SeijiJulianPerezSchimidzu on 03/09/15.
//  Copyright (c) 2015 ITESM CSF. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
using namespace std;

struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;

void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;

int main( )
{
    struct btreenode *bt ;
    int i ;
    int tamanio;
    clock_t fin, inicio;
    
    
    cout<< "Establece el tamaño de tu arreglo:" << endl;
    cin >> tamanio;
    
    
    int a[tamanio];
    
    srand((unsigned)time(0));
    
	for(i=0;i<tamanio;i++)
		a[i]=(rand()%100)+1;
    
    inicio = clock();
    
    
    bt = NULL ;
    
    
    for ( i = 0 ; i < tamanio ; i++ )
        insert ( &bt, a[i] ) ;
    
    fin = clock();
    
    cout << "Tiempo de ejecucion: "
    << (double)(fin-inicio)/CLOCKS_PER_SEC
    << " seconds." << "\n\n";
    
    return 0;
}

void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = (struct btreenode*) malloc ( sizeof ( struct btreenode ) ) ;
        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

