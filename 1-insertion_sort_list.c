#include "sort.h"

void insert_node(listint_t **list, listint_t *current);

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *			in ascending order
 * @list: a pointer to the doubly linked list
 *
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insert_node(list, current);
		current = current->next;
	}
}

/**
 * insert_node - functions that inserts a node into the correct position
 * @list: pointed to a doubly linked list
 * @current: pointer to the current nore
 *
 * Return: void
 */

void insert_node(listint_t **list, listint_t *current)
{
	listint_t *temp = current->prev;
	
	if (temp != NULL && temp->n > current->n)
	{
		if (temp == *list)
			*list = current;

		current->prev = temp->prev;
		temp->next = current->next;
		current->next = temp;
		temp->prev = current;

		print_list(*list);
	}
}
