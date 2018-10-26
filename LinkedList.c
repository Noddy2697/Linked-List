#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *next;
};

struct node *head;  //******head is global******

struct node *createNode(int data) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void insertFirst(int data) 
{
  struct node *temp = createNode(data);
  temp->next = head;
  head = temp;
}

int deleteFirst() 
{
  struct node *temp = head;
  int data = temp->data;
  head = head->next;
  return data;
}

int is_empty() 
{ 
  return !head; 
}

int getFirst()
{ 
  return head->data; 
}

int main()
{
	printf("Testing LinkedList...\n");
	insertFirst(1);
	insertFirst(2);
	insertFirst(3);
	assert(is_empty() == 0);
	assert(getFirst() == 3);
	assert(deleteFirst() == 3);
	assert(deleteFirst() == 2);
	assert(deleteFirst() == 1);
	assert(is_empty() == 1);
	printf("linkedlist : all test cases passed\n");
}
