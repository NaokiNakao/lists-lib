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

    return 0;
}
