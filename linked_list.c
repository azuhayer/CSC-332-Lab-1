/* Implement a Link list using C. The link list should have traverse, insert, delete, search and sort operations. Sort operations are both ascending and descending. */

#include <stdio.h>
#include <stdlib.h>

//Creating a node
struct Node 
{
    int data;
    struct Node* next;
};

//Insert at the beginning of list
void pushBeginning(struct Node** head_ref, int new_data) 
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

//Insert a node after another node
void pushAfter(struct Node* prev_node, int new_data) 
{
  if (prev_node == NULL) 
  {
    printf("The previous node is NULL, please insert starting node.");
    return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert at the end of a list
void pushAtEnd(struct Node** head_ref, int new_data) 
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) 
  {
    *head_ref = new_node;
    return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

//Delete a node from list
void deleteNode(struct Node** head_ref, int key) 
{
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) 
  {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  
  while (temp != NULL && temp->data != key) 
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) return;
  prev->next = temp->next;

  free(temp);
}

//Search Function
int searchForNode(struct Node** head_ref, int key) 
{
  struct Node* current = *head_ref;

  while (current != NULL) 
  {
    if (current->data == key) 
    return 1;
    current = current->next;
  }
  return 0;
}

//Sort Function
void sortLinkedList(struct Node** head_ref) 
{
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) 
  {
    return;
  } 
  else 
  {
    while (current != NULL) 
    {
      index = current->next;

      while (index != NULL) 
      {
        if (current->data > index->data) 
        {
          temp = current->data;
          current->data = index->data;
          index->data = temp;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
}