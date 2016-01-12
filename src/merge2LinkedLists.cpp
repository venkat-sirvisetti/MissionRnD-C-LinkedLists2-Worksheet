/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *temp1, *temp2, *f = NULL, *temp = NULL;
	temp1 = head1;
	temp2 = head2;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->num < temp2->num)
		{
			if (temp == NULL)
			{
				temp = temp1;
				f = temp;
			}
			else
			{
				temp->next = temp1;
				temp = temp->next;
			}
			temp1 = temp1->next;

		}
		else if (temp1->num>temp2->num)
		{
			if (temp == NULL)
			{
				temp = temp2;
				f = temp;
			}
			else
			{
				temp->next = temp2;
				temp = temp->next;
			}
			temp2 = temp2->next;
		}
		else
		{
			if (temp == NULL)
			{
				temp = temp1;
				f = temp;
			}
			else
			{
				temp->next = temp1;
				temp = temp->next;
			}
			temp1 = temp1->next;
			temp->next = temp2;
			temp2 = temp2->next;
			temp = temp->next;
		}
	}
	while (temp1 != NULL)
	{
		temp->next = temp1;
		temp1 = temp1->next;
		temp = temp->next;
	}
	while (temp2 != NULL)
	{
		temp->next = temp2;
		temp2 = temp2->next;
		temp = temp->next;
	}
	temp->next = NULL;
	return f;
}
