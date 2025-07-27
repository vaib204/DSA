#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first,PPNODE last,int no)
{
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;

  if(*first == NULL && *last == NULL)
  {
    *first = newn;
    *last = newn;

    (*last)->next = *first;
  }
  else
  {
    newn->next = *first;
    *first = newn;

    (*last)->next = *first;
  }
}
void InsertLast(PPNODE first,PPNODE last,int no)
{
  
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->next = NULL;

  if(*first == NULL && *last == NULL)
  {
    *first = newn;
    *last = newn;

    (*last)->next = *first;
  }
  else
  {
    (*last)->next = newn;
    *last = newn;
   (*last)->next = *first;
  }
}
void DeleteFirst(PPNODE first,PPNODE last)
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
  }
}
void DeleteLast(PPNODE first,PPNODE last)
{
  PNODE temp = NULL;
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
    temp = *first;

    while (temp->next!=*last)
    {
    temp = temp->next;
    }
    free(*last);
    *last = temp;

    (*last)->next = *first;
  }
}
void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
  int icnt = 0;
  int iCount = 0;
  PNODE newn = NULL;
  PNODE temp = NULL;
  newn = (PNODE)malloc(sizeof(NODE));

  iCount = Count(*first,*last);
 
  newn->data = no;
  newn->next = NULL;

  if((pos<1) || (pos>iCount+1))
  {
    printf("Invalid Position");
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
void DeleteAtPos(PPNODE first,PPNODE last,int no,int pos)
{
  int iCount = 0;
  int icnt = 0;

  iCount = Count(*first,*last);
 
  if((pos<1) || (pos>iCount))
  {
    printf("Invalid Position");
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
    PNODE temp = NULL;
    PNODE target = NULL;

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
void Display(PNODE first, PNODE last)
{
  if (first == NULL && last == NULL)
  {
    return;
  }

  do
  {
    printf("| %d | -> ", first->data);
    first = first->next;
  } while (first != last->next);

  printf("\n");
}

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


int main()
{
  PNODE head = NULL;
  PNODE tail = NULL;
  int iret = 0;

  InsertFirst(&head,&tail,51);
  InsertFirst(&head,&tail,21);
  InsertFirst(&head,&tail,11);
  Display(head,tail);
  iret = Count(head,tail);
  printf("Total numbers of ll are:%d\n",iret);

  InsertLast(&head,&tail,111);
  InsertLast(&head,&tail,121);
  InsertLast(&head,&tail,131);
  Display(head,tail);
  iret = Count(head,tail);
  printf("Total numbers of ll are:%d\n",iret);

  DeleteFirst(&head,&tail);
  Display(head,tail);
  iret = Count(head,tail);
  printf("Total numbers of ll are:%d\n",iret);

  DeleteLast(&head,&tail);
  Display(head,tail);
  iret = Count(head,tail);
  printf("Total numbers of ll are:%d\n",iret);

  InsertAtPos(&head,&tail,180,5);
  Display(head,tail);
  iret = Count(head,tail);
  printf("Total numbers of ll are:%d\n",iret);

  DeleteAtPos(&head,&tail,180,5);
  Display(head,tail);
  iret = Count(head,tail);
  printf("Total numbers of ll are:%d\n",iret);


}
