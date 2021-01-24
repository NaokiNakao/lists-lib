/*
   Librería para la implementación de listas.
   --- Archivo de cabecera ---

   Autor : Naoki Nakao
   Fecha : 23 de enero, 2021
*/

#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

/* Directivas de preprocesador */

#define TRUE        1
#define FALSE       0
#define O_TILDE   162

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
void printList(List* e, char direction[]);
int listLength(List* list_ref);
void deleteElement(List** list_ref, List* e);
List* listFront(List* list_ref);
List* listBack(List* list_ref);
int searchElement(List* list_ref, int x);
void quickSort(List* list_ref);

#endif // _LISTS_H_



















