#include "defs.h"

/*
 * Function: initList
 * Purpose: Initializes a list structure
 *      in: List to initialize
 */
void initList(ListType *list)
{
	list->size = 0;
	list->head = NULL;
}
