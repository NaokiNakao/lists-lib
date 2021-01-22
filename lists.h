/*
   Librería para la implementación de listas.
   (Archivo de cabecera)

   Autor : Naoki Nakao
*/

#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

// Estructura de lista doblemente enlazada
typedef struct Node {
   int value; // almacena el valor del nodo
   struct Node* next; // apunta al nodo siguiente
   struct Node* prev; // apunta al nodo anterior
}List;

/* Prototipos de función */

void pushFront(List** list_ref, int new_value);
void insertAfter(List* prev_element, int new_value);
void pushBack(List** list_ref, int new_value);
void insertBefore(List** list_ref, List* next_element, int new_value);

#endif // _LISTS_H_


















