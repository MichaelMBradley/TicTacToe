#include "defs.h"

/*
 * Function: addToBack
 * Purpose: Adds a node to the back of a list
 *      in: List to add node to
 *      in: Node to add to list
 */
void addToBack(ListType *list, NodeType *node)
{
	// If the list is empty, set the size to one and the head to the new node
	if(list->size == 0)
	{
		list->head = node;
		list->size = 1;
		return;
	}
	// If the list is not empty
	NodeType *last = list->head;
	// Find last node
	for(NodeType *next = list->head->next; next != NULL; next = next->next)
	{
		last = next;
	}
	// Update last node and increment size
	last->next = node;
	++(list->size);
}

/*
 * Function: cleanList
 * Purpose: Frees the memory used by a list
 *      in: List to deallocate
 */
void cleanList(ListType *list)
{
	NodeType *next = NULL;
	for(NodeType *node = list->head; node != NULL; node = next)
	{
		// If the next node is not saved here, it will be lost in the call to free()
		next = node->next;
		free(node);
	}
	free(list);
}

/*
 * Function: initList
 * Purpose: Initializes a list structure
 *      in: List to initialize
 */
void initList(ListType **list)
{
	(*list) = (ListType *) malloc(sizeof(ListType));
	(*list)->size = 0;
	(*list)->head = NULL;
}

/*
 * Function: initNode
 * Purpose: Initializes a NodeType
 *      in: AI Note for node
 *      in: Node ID
 *     out: Node
 */
void initNode(AINoteType note, int id, NodeType **node)
{
	(*node) = (NodeType *) malloc(sizeof(NodeType));
	(*node)->next = NULL;
	(*node)->id = id;
	(*node)->note = note;
}

/*
 * Function: removeNode
 * Purpose: Removes the node with the given id, if it exists
 *      in: List to remove node from
 *      in: ID to remove
 * returns: NODE_FOUND or NODE_NOT_FOUND
 */
int removeNode(ListType *list, int id)
{
	// If list is empty, node can't be removed
	if(list->size == 0)
	{
		return NODE_NOT_FOUND;
	}

	// Special check for if removed node is head
	NodeType *next = NULL;
	if(list->head->id == id)
	{
		next = list->head->next;
		free(list->head);
		list->head = next;
		--(list->size);
		return NODE_FOUND;
	}

	// Iterate until id is found, then remove node
	for(NodeType *node = list->head; node != NULL; node = node->next)
	{
		if(node->next != NULL && node->next->id == id)
		{
			next = node->next->next;
			free(node->next);
			node->next = next;
			--(list->size);
			return NODE_FOUND;
		}
	}

	return NODE_NOT_FOUND;
}
