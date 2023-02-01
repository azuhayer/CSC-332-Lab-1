/* Implement a Link list using C. The link list should have traverse, insert, delete, search and sort operations. Sort operations are both ascending and descending. */

#include <stdio.h>
#include <stdlib.h>

//Create a node
struct Node 
{
  int data;
  struct Node* next;
};

//Insert at the beginning
void pushAtBeginning(struct Node** head_ref, int new_data) 
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

//Insert a node after a node
void pushAfter(struct Node* prev_node, int new_data) 
{
  if (prev_node == NULL) 
  {
    printf("the given previous node cant be NULL");
    return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

//Insert the the end
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

//Delete a node
void deleteNode(struct Node** head_ref, int key) 
{
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) 
  {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  //Find the node to be deleted
  while (temp != NULL && temp->data != key) 
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) return;
  prev->next = temp->next;

  free(temp);
}

//Search for a node
int searchForNode(struct Node** head_ref, int key) 
{
  struct Node* current = *head_ref;

  while (current != NULL) 
  {
    if (current->data == key) return 1;
    current = current->next;
  }
  return 0;
}

//Sort the linked list
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

//Traverse the linked list
void printList(struct Node* node) 
{
  while (node != NULL) 
  {
    printf(" %d ", node->data);
    node = node->next;
  }
}

//Driver program
int main() 
{
  struct Node* head = NULL;

  pushAtBeginning(&head, 9);
  pushAtBeginning(&head, 4);
  pushAfter(head->next, 7);
  pushAfter(head->next, 5);
  pushAfter(head->next, 2);
  pushAtEnd(&head, 1);
  pushAtEnd(&head, 3);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 7);                  //delete node
  printList(head);

  int item = 7;
  if (searchForNode(&head, item))       //search for node
  {
    printf("\n%d is found", item);
  } 
  else 
  {
    printf("\n%d is not found", item);
  }

  sortLinkedList(&head);                //sort list
  printf("\n The Sorted List is: ");
  printList(head);                      //traverse list
}
