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
    int TimeComplexity = 0;

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
       TimeComplexity++;
     }
     printf("Time complexity of search is : %d\n",TimeComplexity);
     
     return bflag;
  }

  int CountLeafNode(PNODE first)
  {
    static int icount = 0;
    if(first != NULL)
    {
       if(first->lchild == NULL && first->rchild == NULL)
       {
        icount++;
       }
       CountLeafNode(first->lchild);
       CountLeafNode(first->rchild);
    }
    return icount;
  }

  int CountParentNode(PNODE first)
  {
    static int icount = 0;
    if(first != NULL)
    {
      if(first->lchild != NULL && first->lchild != NULL)
      {
        icount++;
      }
      CountParentNode(first->lchild);
      CountParentNode(first->rchild);
    }
    return icount;
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
    Insert(&head,25);
    Insert(&head,7);
    Insert(&head,35);
    Insert(&head,10);
    Insert(&head,15);
    Insert(&head,21);
    Insert(&head,26);
    Insert(&head,37);
    Insert(&head,89);
    Insert(&head,91);
    Insert(&head,65);
    Insert(&head,12);
    Insert(&head,20);
    Insert(&head,44);
    Insert(&head,66);
    Insert(&head,90);
    Insert(&head,88);

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

  iret = CountLeafNode(head);
  printf("Number of leaf nodes are: %d\n",iret);

  iret = CountParentNode(head);
  printf("number of parent nodes are:%d\n",iret);

  return 0;

}