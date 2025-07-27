// doubly linear linkedlist

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

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

void InsertFirst(PPNODE first, int no)
{
  PNODE newn = NULL;

  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  if (*first == NULL)
  {
    *first = newn;
  }
  else
  {
    newn->next = *first;
    (*first)->prev = newn;
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
  newn->prev = NULL;

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
    newn->prev = temp;
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
    (*first)->prev = NULL;
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

void InsertAtPOs(PPNODE first, int no, int pos)
{
  PNODE temp = NULL;
  PNODE newn = NULL;
  int i = 0;
  int iCount = 0;

  newn = (PNODE)malloc(sizeof(NODE));
  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  iCount = Count(*first);

  if (pos < 1 || pos > iCount + 1)
  {
    printf("Invalid position\n");
    return;
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

    for (i = 1; i < pos - 1; i++)
    {
      temp = temp->next;
    }
    newn->next = temp->next;
    newn->next->prev = newn;
    temp->next = newn;
    newn->prev = temp;
  }
}

void DeleteAtPOs(PPNODE first, int pos)
{
  PNODE temp = NULL;
  PNODE target = NULL;
  int i = 0;
  int iCount = 0;

  iCount = Count(*first);

  if (pos < 1 || pos > iCount)
  {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1)
  {
    DeleteFirst(first);
  }
  else if (pos == iCount)
  {
    DeleteLast(first);
  }
  else
  {
    temp = *first;

    for (i = 1; i < pos - 1; i++)
    {
      temp = temp->next;
    }
    target = temp->next;

    temp->next = target->next;

    target->next->prev = temp;

    free(target);
  }
}
void Display(PNODE first)
{
  printf("NULL <=>");

  while (first != NULL)
  {
    printf("|%d| <=>", first->data);
    first = first->next;
  }
  printf("NULL\n");
}

int main()
{
  PNODE head = NULL;
  int iret = 0;

  InsertFirst(&head, 51);
  InsertFirst(&head, 21);
  InsertFirst(&head, 11);

  Display(head);
  iret = Count(head);
  printf("NUmber of linklist are:%d\n", iret);

  InsertLast(&head, 101);
  InsertLast(&head, 111);
  InsertLast(&head, 121);

  Display(head);
  iret = Count(head);
  printf("NUmber of linklist are:%d\n", iret);

  DeleteFirst(&head);
  Display(head);
  iret = Count(head);
  printf("NUmber of linklist are:%d\n", iret);

  DeleteLast(&head);
  Display(head);
  iret = Count(head);
  printf("NUmber of linklist are:%d\n", iret);

  InsertAtPOs(&head, 181, 5);
  Display(head);
  iret = Count(head);
  printf("NUmber of linklist are:%d\n", iret);

  DeleteAtPOs(&head, 5);
  Display(head);
  iret = Count(head);
  printf("NUmber of linklist are:%d\n", iret);
}
