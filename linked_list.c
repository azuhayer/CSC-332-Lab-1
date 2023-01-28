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