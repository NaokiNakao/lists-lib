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
   Objetivo   : almacenar un nuevo valor al inicio de la lista
   Retorno    : ---
*/
void pushFront(List** list_ref, int new_value)
{
   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   element->value = new_value; // asignando valor al nuevo elemento
   element->next = (*list_ref); // el nuevo elemento apunta a la referencia de la lista
   element->prev = NULL; // el anterior del nuevo elemento es un valor nulo (no hay)

   if ((*list_ref) != NULL) // cambiando el siguiente de la referencia
      (*list_ref)->prev = element;

   (*list_ref) = element; // la referencia ahora es el nuevo elemento

   return;
}













