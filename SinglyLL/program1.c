// singly LL in c

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first, int no)
{
  PNODE newn = NULL;

  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;

  if (*first == NULL)
  {
    *first = newn;
  }
  else
  {
    newn->next = *first;
    *first = newn;
  }
}

void InsertLast(PPNODE first, int no)
{
  PNODE newn = NULL;
  PNODE temp = NULL;

  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;

  if (*first == NULL)
  {
    *first = newn;
  }
  else
  {
    temp = *first;

    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newn;
  }
}

void DeleteFirst(PPNODE first)
{
  PNODE temp = NULL;

  if (*first == NULL)
  {
    return;
  }
  else if ((*first)->next == NULL)
  {
    free(*first);
    *first = NULL;
  }
  else
  {
    temp = *first;
    *first = (*first)->next;
    free(temp);
  }
}

void DeleteLast(PPNODE first)
{
  PNODE temp = NULL;

  if (*first == NULL)
  {
    return;
  }
  else if ((*first)->next == NULL)
  {
    free(*first);
    *first = NULL;
  }
  else
  {
    temp = *first;

    while (temp->next->next != NULL)
    {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
  }
}
void display(PNODE first)
{
  while (first != NULL)
  {
    printf("|%d|->", first->data);
    first = first->next;
  }
  printf("NULL\n");
}

int Count(PNODE first)
{
  int iCount = 0;

  while (first != NULL)
  {
    iCount++;
    first = first->next;
  }

  return iCount;
}

void InsertAtFirst(PPNODE first, int no, int pos)
{
  PNODE temp = NULL;
  PNODE newn = NULL;
  int iCount = 0, i = 0;

  iCount = Count(*first);

  if (pos < 1 || pos > iCount + 1)
  {
    printf("Invalid postion");
  }

  if (pos == 1)
  {
    InsertFirst(first, no);
  }
  else if (pos == iCount + 1)
  {
    InsertLast(first, no);
  }
  else
  {
    temp = *first;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    for (i = 1; i <= pos - 2; i++)
    {
      temp = temp->next;
    }
    newn->next = temp->next;
    temp->next = newn;
  }
}

void DeleteAtpos(PPNODE first, int pos)
{
  PNODE temp = NULL;
  PNODE newn = NULL;
  PNODE target = NULL;

  int iCount = 0, i = 0;

  iCount = Count(*first);

  if (pos < 1 || pos > iCount + 1)
  {
    printf("Invalid postion");
  }

  if (pos == 1)
  {
    DeleteFirst(first);
  }
  else if (pos == iCount + 1)
  {
    DeleteLast(first);
  }
  else
  {
    temp = *first;

    for (i = 1; i <= pos - 2; i++)
    {
      temp = temp->next;
    }
    target = temp->next;

    temp->next = target->next;
    free(target);
  }
}

int main()
{
  PNODE head = NULL;
  int iret = 0;
  printf("Inside insert first:\n");
  InsertFirst(&head, 51);
  InsertFirst(&head, 21);
  InsertFirst(&head, 11);
  display(head);
  iret = Count(head);
  printf("number of ll are:%d\n", iret);

  printf(".....................................................................................\n");

  printf("Inside insert last:\n");
  InsertLast(&head, 151);
  InsertLast(&head, 121);
  InsertLast(&head, 111);
  display(head);
  iret = Count(head);
  printf("number of ll are:%d\n", iret);

  /*printf(".....................................................................................\n");

  printf("Inside delete first:\n");
  DeleteFirst(&head);
  display(head);
  iret = Count(head);
  printf("number of ll are:%d\n", iret);

  printf(".....................................................................................\n");

  printf("inside delete last:\n");
  DeleteLast(&head);
  display(head);
  iret = Count(head);
  printf("number of ll are:%d\n", iret);*/

  printf(".....................................................................................\n");

  printf("Inside insert AtPOS\n");
  InsertAtFirst(&head, 116, 5);
  display(head);
  iret = Count(head);
  printf("number of ll are:%d\n", iret);

  printf(".....................................................................................\n");

  printf("Delete At POS");
  DeleteAtpos(&head, 5);
  display(head);
  iret = Count(head);
  printf("number of ll are:%d\n", iret);
}
