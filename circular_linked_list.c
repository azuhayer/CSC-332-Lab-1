/* Implement a Circular Link list using C. The link list should have traverse, insert, delete, search and sort operations. */

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node* next;
};

struct Node* pushToEmpty(struct Node* last, int data) 
{
  if (last != NULL) return last;

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  last = newNode;
  last->next = last;
  return last;
}

// Add node to the front
struct Node* pushFront(struct Node* last, int data) 
{
  
  if (last == NULL) return addToEmpty(last, data);

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;
  return last;
}

// Add node to the end
struct Node* pushEnd(struct Node* last, int data) 
{

  if (last == NULL) return addToEmpty(last, data);

  
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;
  last = newNode;
  return last;
}

// Insert node after a specific node
struct Node* pushAfter(struct Node* last, int data, int item) 
{
  
  if (last == NULL) return NULL;

  struct Node *newNode, *p;

  p = last->next;
  do 
  {
    if (p->data == item) 
    {
        
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = data;
        newNode->next = p->next;
        p->next = newNode;

        if (p == last) 
            last = newNode;
        return last;
    }
    p = p->next;
  } 

  while (p != last->next);
  printf("\nThe given node is not in the list");
  return last;
}

// Delete a node
void deleteNode(struct Node** last, int key) 
{
  
  if (*last == NULL) return;

  if ((*last)->data == key && (*last)->next == *last) 
  {
    free(*last);
    *last = NULL;
    return;
  }

  struct Node *temp = *last, *d;

  if ((*last)->data == key) 
  {
    while (temp->next != *last) temp = temp->next;
    temp->next = (*last)->next;
    free(*last);
    *last = temp->next;
  }

  while (temp->next != *last && temp->next->data != key) 
  {
    temp = temp->next;
  }

  if (temp->next->data == key) 
  {
    d = temp->next;
    temp->next = d->next;
    free(d);
  }
}

// Traverse Circular linked list
void traverse(struct Node* last) 
{
  struct Node* p;

  if (last == NULL) 
  {
    printf("The list is empty");
    return;
  }

  p = last->next;

  do 
  {
    printf("%d ", p->data);
    p = p->next;
  } while (p != last->next);
}

int main() 
{
  struct Node* last = NULL;

  last = pushToEmpty(last, 6);
  last = pushFront(last, 2);
  last = addAfter(last, 10, 2);
  last = pushEnd(last, 8);

  traverse(last);

  deleteNode(&last, 8);

  printf("\n");

  traverse(last);

  return 0;
}



