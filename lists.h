/*
   Librería para la implementación de listas.
   (Archivo de cabecera)

   Autor : Naoki Nakao
*/

#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int value; // almacena el valor del nodo
   struct Node* next; // apunta al nodo siguiente
   struct Node* prev; // apunta al nodo anterior
}List;

#endif // _LISTS_H_
