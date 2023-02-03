/* Implement a Circular Link list using C. The link list should have traverse, insert, delete, search and sort operations. */

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node* next;
};

// Add node to an empty circular list
struct Node* pushToEmpty(struct Node* last, int data) 
{
  if (last != NULL) return last;

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  last = newNode;
  last->next = last;
  return last;
}

// Add node to the front of the list
struct Node* pushFront(struct Node* last, int data) 
{
  
  if (last == NULL) return pushToEmpty(last, data);

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;
  return last;
}

// Add node to the end the list
struct Node* pushEnd(struct Node* last, int data) 
{

  if (last == NULL) return pushToEmpty(last, data);

  
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;
  last = newNode;
  return last;
}

// Insert node after a node
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
  printf("\n The given node is not in the list");
  return last;
}

// Delete a node from the list
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

//Sort the linked list
void sortList(struct Node* last) 
{    
  struct Node *current = last, *index = NULL;  
  int temp;  
    
  if(last == NULL) 
  {  
    printf("List is empty");  
  }  

  else 
  {
    do
    {    
      index = current->next;  
      while(index != last) 
      {    
        if(current->data > index->data) 
        {  
          temp =current->data;  
          current->data= index->data;  
          index->data = temp;  
        }  
        index= index->next;  
      }  
      current =current->next;  
    } 
  while(current->next != last);   
  }  
}

// Search for node in list
int search(struct Node* last, int key)
{
  int index = 0; 
  struct Node* current = last;

  do
  {
    if(current = NULL)
    {
      return;
    }

    if(current->data == key)
    {
      return index;
    }
    current = current->next;
    index++;
  } while(current != last);

  return -1;
}

int main() 
{
  struct Node* last = NULL;

  last = pushToEmpty(last, 6);
  last = pushFront(last, 2);
  last = pushAfter(last, 10, 2);
  last = pushAfter(last, 7, 10);
  last = pushAfter(last, 4, 7);
  last = pushEnd(last, 8);

  printf("The Circular linked list is: ");
  traverse(last);

  printf("\n");

  printf("The Circular linked list after DELETION is: ");  
  deleteNode(&last, 2);
  traverse(last);

  printf("\n");

  printf("The SORTED Circular linked list is: ");
  sortList(last);
  traverse(last);

  int key = 10;
  if(search(&last, key))
  {
    printf("\n%d is found", key);
  }
  else
  {
    printf("\n%d is not found", key);
  }
  
  return 0;
}



