#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int Count(PNODE first, PNODE last)
{
  int iCount = 0;

  if (first == NULL && last == NULL)
  {
    return iCount;
  }

  do
  {
    iCount++;
    first = first->next;
  } while (first != last->next);

  return iCount;
}


void InsertFirst(PPNODE first,PPNODE last,int no)
{
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  if(*first == NULL && *last == NULL)
  {
    *first = newn;
    *last = newn;
  }
  else
  {
    newn->next = *first;
    (*first)->prev = newn;

    *first = newn;

    (*last)->next = *first;

    (*first)->prev = *last;
  }
}

void InsertLast(PPNODE first,PPNODE last,int no)
{
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  if(*first == NULL && *last == NULL)
  {
    *first = newn;
    *last = newn;
  }
  else
  {
    (*last)->next = newn;
    newn->prev = *last;

    *last = newn;
  }
  (*last)->next = *first;
  (*first)->prev = *last;
}

void  DeleteFirst(PPNODE first,PPNODE last)
{
  if(*first == NULL && *last == NULL)
  {
    return;
  }
  else if(*first == *last)
  {
    free(*first);
    *first = NULL;
    *last = NULL;
  }
  else
  {
    *first = (*first)->next;
     
      free((*last)->next);

    (*last)->next = *first;
    (*first)->prev = *last;
  }
}

void  DeleteLast(PPNODE first,PPNODE last)
{
  if(*first == NULL && *last == NULL)
  {
    return;
  }
  else if(*first == *last)
  {
    free(*first);
    *first = NULL;
    *last = NULL;
  }
  else
  {
   *last = (*last)->prev;

   free((*last)->next);

   (*last)->next = *first;
   (*first)->prev  = *last;

  }
}

void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
  int icnt = 0;
  int iCount = 0;
  
  PNODE temp = NULL;
  PNODE newn = NULL;

 newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;
  newn->prev = NULL;

  iCount = Count(*first,*last);

  if(*first == NULL && *last == NULL )
  {
    printf("Invalid statement");
    return;
  }

  if(pos == 1)
  {
    InsertFirst(first,last,no);
  }
  else if(pos == iCount+1)
  {
    InsertLast(first,last,no);
  }
  else
  {
     temp = *first;

     for(icnt = 1;icnt<pos-1;icnt++)
     {
      temp = temp->next;
     }
    newn->next = temp->next;
    temp->next = newn;

  }
}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
  int icnt = 0;
  int iCount = 0;
  PNODE temp = NULL;
  PNODE target = NULL;
  
  iCount = Count(*first,*last);

  if(*first == NULL && *last == NULL )
  {
    printf("Invalid statement");
    return;
  }

  if(pos == 1)
  {
    DeleteFirst(first,last);
  }
  else if(pos == iCount)
  {
    DeleteLast(first,last);
  }
  else
  {
     temp = *first;

     for(icnt = 1;icnt<pos-1;icnt++)
     {
      temp = temp->next;
     }
      target = temp->next;
      temp->next = target->next;
      free(target);

  }
}
void Display(PNODE first,PNODE last)
{
   PNODE temp = NULL;
  printf( "Elements of the LinkedList are : \n");

  temp = first;

  if (first == NULL && last == NULL)
  {
    printf( "LinkedList is empty\n");
    return;
  }

  do
  {
    printf( "| %d |<=> ",temp->data );
    temp = temp->next;
  } while (temp != first);
 printf("NULL\n");
}

int main()
{
  PNODE head = NULL;
  PNODE tail = NULL;

  int iret = 0;

  InsertFirst(&head,&tail,51);
   InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,121);
    InsertLast(&head,&tail,131);
    InsertLast(&head,&tail,151);

    iret = Count(head,tail);
    Display(head,tail);
    printf("number of ll are:%d",iret);

    DeleteFirst(&head,&tail);
    Display(head,tail);

    DeleteLast(&head,&tail);
     Display(head,tail);

     InsertAtPos(&head,&tail,125,5);
     iret = Count(head,tail);
    Display(head,tail);
    printf("number of ll are:%d",iret);

    DeleteAtPos(&head,&tail,5);
     iret = Count(head,tail);
    Display(head,tail);
    printf("number of ll are:%d",iret);
}
