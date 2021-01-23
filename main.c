#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main()
{
    List* l = NULL;

    pushBack(&l, 6);
    pushFront(&l, 7);
    pushFront(&l, 1);
    pushBack(&l, 4);
    insertAfter(l->next, 8);

    printList(l, "forward");
    printf("\nLa cantidad de elementos en la lista es : %d\n", listLength(l));

    /*int val = 10;

    if (searchElement(l, val))
      printf("%d se encuentra en la lista.\n");
    else
      printf("%d no se encuentra en la lista.\n");*/

    /*List* i = listBack(l);
    printf("\n%d\n", i->value);*/

    /*deleteElement(&l, l); // eliminando el nodo cabeza
    deleteElement(&l, l->next); // eliminando el segundo elemento*/

    return 0;
}
