/*
   Librería para la implementación de listas.
   (Archivo principal)

   Autor : Naoki Nakao
*/

#include "lists.h"

/* Funciones */

/*
   Función    : pushFront
   Argumentos : List** list_ref (referencia de la cabeza de la lista)
                int new_value (valor a asignar)
   Objetivo   : insertar un nuevo valor al inicio de la lista
   Retorno    : ---
*/
void pushFront(List** list_ref, int new_value)
{
   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   if (element == NULL)
   {
      printf("\nERROR: no se pudo localizar suficiente espacio en memoria\n");
      return;
   }

   element->value = new_value; // asignando valor al nuevo elemento
   element->next = (*list_ref); // el nuevo elemento apunta a la referencia de la lista
   element->prev = NULL; // el anterior del nuevo elemento es un valor nulo (no hay)

   if ((*list_ref) != NULL) // cambiando el siguiente de la referencia
      (*list_ref)->prev = element;

   (*list_ref) = element; // la referencia ahora es el nuevo elemento

   return;
}

/*
   Función    : insertAfter
   Argumentos : List* prev (elemento previo)
                int new_value (valor del nuevo elemento)
   Objetivo   : insertar un elemento posterior a otro existente
   Retorno    : ---
*/
void insertAfter(List* prev_element, int new_value)
{
   if (prev_element == NULL)
   {
      printf("\nERROR: el elemento anterior no puede ser nulo\n");
      return;
   }

   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   if (element == NULL)
   {
      printf("\nERROR: no se pudo localizar suficiente espacio en memoria\n");
      return;
   }

   element->value = new_value; // asignando valor al nuevo elemento
   element->next = prev_element->next; // el siguiente del nuevo elemento será el siguiente del elemento previo
   prev_element->next = element; // el siguiente del elemento previo será el nuevo elemento
   element->prev = prev_element; // el anterior del nuevo elemento será el elemento previo

   if (element->next != NULL)
      element->next->prev = element; // el anterior del siguiente elemento será el nuevo elemento

   return;
}

/*
   Función    : pushBack
   Argumentos : List** list_ref (referencia de la cabeza de la lista)
                int new_value (valor a asignar)
   Objetivo   : insertar un nuevo valor al final de la lista
   Retorno    : ---
*/
void pushBack(List** list_ref, int new_value)
{
   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   if (element == NULL)
   {
      printf("\nERROR: no se pudo localizar suficiente espacio en memoria\n");
      return;
   }

   List* last;
   last = *list_ref; // elemento auxiliar para iteración en la lista

   element->value = new_value; // asignando valor al nuevo elemento
   element->next = NULL; // el nuevo elemento estará al final de la lista, por lo tanto no apunta a nada

   if (*list_ref == NULL) // se crea una nueva referencia si la lista está vacía
   {
      element->prev = NULL;
      *list_ref = element;
      return;
   }

   while (last->next != NULL) // iterando en la lista hasta encontrar el último elemento
      last = last->next;

   last->next = element; // el siguiente del último elemento será el nuevo elemento
   element->prev = last; // el anterior del nuevo elemento será el que era último

   return;
}


















































