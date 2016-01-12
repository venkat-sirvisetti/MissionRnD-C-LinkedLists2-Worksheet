/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *temp, *temp1;
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp1 = head;
	while (temp1 != temp)
	{
		head = head->next;
		temp1->next = temp->next;
		temp->next = temp1;
		temp1 = head;
	}
	return head;
}
