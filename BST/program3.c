#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Insert(PPNODE first,int no)
{
  PNODE newn = NULL;
  PNODE temp = NULL;

  newn = (PNODE)malloc(sizeof(NODE));

  newn->data = no;
  newn->lchild = NULL;
  newn->rchild = NULL;

  if(*first == NULL)
  {
    *first = newn;
  }
  else
  {
    temp = *first;

    while(1)
    {
      if(no == temp->data)
      {
        printf("Duplicate element : Unable to insert node\n");
        free(newn);
         break;
      }
      else if(no > temp->data)
      {
        if(temp->rchild == NULL)
        {
        temp->rchild = newn;
        break;
      }
      temp = temp->rchild;
      }
      else if(no < temp->data)
      {
        if(temp->lchild == NULL)
        {
          temp->lchild = newn;
          break;
        }
        temp = temp->lchild;
      }
   }
  }
}
  void Inorder(PNODE first)
  {
    if(first != NULL)
    {
      Inorder(first->lchild);
      printf("%d\t",first->data);
      Inorder(first->rchild);
    }
  }
  
  void preorder(PNODE first)
  {
    if(first != NULL)
    {
    printf("%d\t",first->data);
    preorder(first->lchild);
    preorder(first->rchild);
    }
  }

  void Postorder(PNODE first)
  {
    if(first != NULL)
    {
      Postorder(first->lchild);
      Postorder(first->rchild);
      printf("%d\t",first->data);
    }
  }

  bool Search(PNODE first,int no)
  {
    bool bflag = false;

     while (first  != NULL)
     {
       if(first->data == no)
       {
         bflag = true;
         break;
       }
       else if(no > first->data)
       {
        first = first->rchild;
       }
       else if(no < first->data)
       {
        first = first->lchild;
       }
     }
     return bflag;
  }

  int Count(PNODE first)
  {
    static int icount = 0;
    if(first != NULL)
    {
      icount++;
      Count(first->lchild);
      Count(first->rchild);
    }
    return icount;
  }



int main()
{
  PNODE head = NULL;
  bool bret = false;
  int iret = 0;

  Insert(&head,11);
  Insert(&head,9);
  Insert(&head,17);
  Insert(&head,21);
  Insert(&head,39);
  Insert(&head,28);

  bret = Search(head,21);

  if(bret == true)
  {
    printf("Element is present\n");
  }
  else
  {
    printf("Element is not present\n");
  }
 
  iret = Count(head);
  printf("Number of nodes are:%d\n",iret);

  return 0;

}