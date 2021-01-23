/*
   Librería para la implementación de listas.
   (Archivo principal)

   Autor : Naoki Nakao
   --- En desarrollo ---
*/

#include "lists.h"

/* Funciones */

/*
   Función    : pushFront
   Argumentos : List** list_ref (referencia de la cabeza de la lista).
                int new_value (valor a asignar).
   Objetivo   : insertar un nuevo elemento al inicio de la lista.
   Retorno    : ---
*/
void pushFront(List** list_ref, int new_value)
{
   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   if (element == NULL)
   {
      printf("\nERROR: no se pudo localizar suficiente espacio en memoria.\n");
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
   Argumentos : List* prev (elemento previo).
                int new_value (valor del nuevo elemento).
   Objetivo   : insertar un elemento posterior a otro existente.
   Retorno    : ---
*/
void insertAfter(List* prev_element, int new_value)
{
   if (prev_element == NULL)
   {
      printf("\nERROR: el elemento anterior no puede ser nulo.\n");
      return;
   }

   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   if (element == NULL)
   {
      printf("\nERROR: no se pudo localizar suficiente espacio en memoria.\n");
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
   Argumentos : List** list_ref (referencia de la cabeza de la lista).
                int new_value (valor a asignar).
   Objetivo   : insertar un nuevo elemento al final de la lista.
   Retorno    : ---
*/
void pushBack(List** list_ref, int new_value)
{
   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   if (element == NULL)
   {
      printf("\nERROR: no se pudo localizar suficiente espacio en memoria.\n");
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

/*
   Función    : insertBefore
   Argumentos : List** list_ref (referencia de la cabeza de la lista).
                List* next_element (siguiente elemento).
                int new_value (valor a asignar).
   Objetivo   : insertar un nuevo elemento anterior a otro.
   Retorno    : ---
*/
void insertBefore(List** list_ref, List* next_element, int new_value)
{
   if (next_element == NULL) // comprobando si el siguiente elemento es nulo
   {
      printf("\nERROR: el elemento siguiente dado no puede ser nulo.\n");
      return;
   }

   List* element; // nuevo elemento a asignar
   element = (List*)malloc(sizeof(List)); // creando espacio en memoria al nuevo elemento

   element->value = new_value; // asignando valor al nuevo elemento
   element->prev = next_element->prev; // el elemento anterior del nuevo elemento será el anterior del posterior
   next_element->prev = element; // el anterior del siguiente elemento será el nuevo elemento
   element->next = next_element; // el siguiente del nuevo elmento será el posterior

   if (element->prev != NULL) // actualizando el siguiente del elemento anterior
      element->prev->next = element;
   else
      (*list_ref) = element; // si el anterior del nuevo elemento es nulo, el nuevo elemento será la referencia

   return;
}

/*
   Función    : equalElements
   Argumentos : char* str1 (cadena de texto 1).
                char* str2 (cadena de texto 2).
   Objetivo   : comprobar si str1 y str2 son iguales.
   Retorno    : TRUE (1) si son iguales; FALSE (0) en caso contrario.
*/
static int equalElements(char* str1, char* str2)
{
   int i;

   for (i = 0; str1[i] != NULL; i++)
   {
      if (str1[i] != str2[i]) return FALSE;
   }

   return TRUE;
}

/*
   Función    : printList
   Argumentos : List *e (referencia de lista a imprimir)
                char direction[] (dirección en que se imprimirán los elementos).
   Objetivo   : imprimir lista en pantalla.
   Retorno    : ---.
*/
void printList(List* e, char direction[])
{
   char f[] = "forward", b[] = "backward";

   if (!equalElements(direction, f) && !equalElements(direction, b))
   {
      printf("\nLa direcci%cn solo acepta 'forward' o 'backward'.\n", O_TILDE);
      return;
   }

   if (equalElements(direction, f)) // comienzo desde el inicio de la lista
   {
      while (e != NULL)
      {
         printf("%d\n", e->value);
         e = e->next;
      }
   }
   else // comienzo desde el final de la lista
   {
      while (e != NULL)
      {
         printf("%d\n", e->value);
         e = e->prev;
      }
   }

   return;
}

/*
   Función    : listLength
   Argumentos : List* list_ref (refernecia de lista).
   Objetivo   : retornar la cantidad de elementos en la lista.
   Retorno    : total (cantidad de elementos en la lista).
*/
int listLength(List* list_ref)
{
   int total = 0; // contador

   List* current = list_ref; // iterador

   while (current != NULL)
   {
      current = current->next;
      total++;
   }

   return total;
}

/*
   Función    : deleteElement
   Argumentos : List** list_ref (referencia de la cabeza de la lista).
                List* e (elemento a eliminar).
   Objetivo   : eliminar un elemento de la lista.
   Retorno    : ---
*/
void deleteElement(List** list_ref, List* e)
{
   if (*list_ref == NULL || e == NULL) return; // la lista está vacía

   if (*list_ref == e) // el elemento a eliminar es la cabeza de la lista
      *list_ref = e->next;

   if (e->next != NULL) // se cambia el siguiente si el elemento a eliminar no es el último
      e->next->prev = e->prev;

   if (e->prev != NULL) // se cambia el anterior si el elemento a eliminar no es el primero
      e->prev->next = e->next;

   free(e); // se elimina el espacio en memoria del elemento a eliminar

   return;
}

/*
   Función    : listFront
   Argumentos : List* list_ref (referencia de lista).
   Objetivo   : retornar el primer elemento de la lista.
   Retorno    : List* list_ref (primer elemento de la lista).
*/
List* listFront(List* list_ref)
{
   while (list_ref->prev != NULL)
      list_ref = list_ref->prev;

   return list_ref;
}

/*
   Función    : listBack
   Argumentos : List* list_ref (referencia de lista).
   Objetivo   : retornar el primer elemento de la lista.
   Retorno    : List* list_ref (primer elemento de la lista).
*/
List* listBack(List* list_ref)
{
   while (list_ref->next != NULL)
      list_ref = list_ref->next;

   return list_ref;
}


















































