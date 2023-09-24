#include "sort.h"
/**
* insertion_sort_list - function that sorts a doubly linked list of
* integers in ascending order using the Insertion sort algorithm
* @list: Pointer to the list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *outer, *inner, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	outer = (*list)->next;
	while (outer)
	{
		temp = outer;
		while (temp->prev && temp->n < temp->prev->n)
		{
			inner = temp->prev;
			if (inner->prev)
				inner->prev->next = temp;
			else
				*list = temp;
			if (temp->next)
				temp->next->prev = inner;
			inner->next = temp->next;
			temp->prev = inner->prev;
			temp->next = inner;
			inner->prev = temp;
			print_list(*list);
		}
		outer = outer->next;
	}
}
