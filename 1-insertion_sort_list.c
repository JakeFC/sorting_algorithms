#include "sort.h"

/**
 * swap - Swaps two nodes in a listint_t list
 * @node1: listint_t node;
 * @node2: listint_t node;
 */
void swap(listint_t *node1, listint_t *node2)
{
	node2->prev = node1->prev;
	if (node2->prev)
		node2->prev->next = node2;
	node1->prev = node2;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node2->next = node1;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using insertion sort algorithm.
 * @list: doubly linked list input
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list;
	listint_t *tmp = node->next;
	listint_t *prev;

	while (tmp)
	{
		if (node->n > tmp->n)
		{
			swap(node, tmp);
			if (!tmp->prev)
				*list = tmp;
			print_list(*list);
			prev = tmp->prev;
			while (prev && prev->n > tmp->n)
			{
				swap(prev, tmp);
				if (!tmp->prev)
					*list = tmp;
				print_list(*list);
				prev = tmp->prev;
			}
		}
		else
			node = tmp;
		tmp = node->next;
	}
}
