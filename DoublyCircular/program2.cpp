#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
  struct node *next;
  int data;
  struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class DoublyCll
{
  private :
  PNODE first;
  PNODE last;
  int icount;

  public:
  DoublyCll()
  {
    this->first = NULL;
    this->last = NULL;
    this->icount = 0;
  }

  void  InsertFirst(int no)
  {
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next  = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
      first = newn;
      last = newn;

      last->next = first;
    }
    else
    {
      newn->next = first;
      first = newn;

      last->next = first;
    }
    icount++;
  }

  void  InsertLast(int no)
  {
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next  = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
      first = newn;
      last = newn;

      last->next = first;
    }
    else
    {
     last->next = newn;
     last = newn;
     newn->next = first;
    }
    icount++;
  }

  void DeleteFirst()
  {
    if(first == NULL&&last == NULL)
    {
      return;
    }
    else if(first == last)
    {
      first = NULL;
      last = NULL;

      delete first;
    }
    else
    {
      first = first->next;
      delete last->next;
      last->next = first;
    }
    icount--;
  }
 
  void DeleteLast()
  {
    PNODE temp = NULL;

    if(first == NULL&&last == NULL)
    {
      return;
    }
    else if(first == last)
    {
      first = NULL;
      last = NULL;

      delete first;
    }
    else
    {
      temp  = first;

      while (temp->next != last)
      {
        temp = temp->next;
      }
      delete temp->next;
      last = temp;
      last->next = first;
      first->prev = last;
    }
    icount--;
  }

  void InsertAtPos(int no,int pos)
  {
   
    PNODE newn = NULL;
    newn = new NODE;
    int icnt = 0;
    PNODE temp = NULL;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(pos < 1 || pos>icount+1)
    {
      cout<<"Invalid position";
    }
    if(pos == 1)
    {
      InsertFirst(no);
    }
    else if(pos == icount+1)
    {
      InsertLast(no);
    }
    else
    {
      temp = first;

      for(icnt = 1;icnt<pos-1;icnt++)
      {
        temp = temp->next;
      }
      newn->next = temp->next;
      temp->next = newn;
    }
    icount++;
  }

  void DeleteAtPos(int pos)
  {
   
    PNODE newn = NULL;
    int icnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    if(pos < 1 || pos>icount)
    {
      cout<<"Invalid position";
    }
    if(pos == 1)
    {
     DeleteFirst();
    }
    else if(pos == icount)
    {
      DeleteLast();
    }
    else
    {
      temp = first;

      for(icnt = 1;icnt<pos-1;icnt++)
      {
        temp = temp->next;
      }
      target = temp->next;

      temp->next = target->next;

      delete target;
      
    }
    icount--;
  }
 
   void Display()
  {
    if (first == NULL && last == NULL)
    {
      return;
    }

    PNODE temp = first;

    do
    {
      cout << "| " << temp->data << " | -> ";
      temp = temp->next;
    } while (temp != last->next);

     cout << "\n";
  }
  int Count()
  {
    return icount;
  }
};

int main()
{
  PNODE head = NULL;
  PNODE tail = NULL;
  int iret = 0;

DoublyCll dobj;

dobj.InsertFirst(51);
dobj.InsertFirst(21);
dobj.InsertFirst(11);

dobj.InsertLast(111);
dobj.InsertLast(121);
dobj.InsertLast(151);

dobj.Display();
iret = dobj.Count();
cout<<"Total ll are:"<<iret<<"\n";

dobj.DeleteFirst();
dobj.Display();

dobj.DeleteLast();
dobj.Display();

dobj.InsertAtPos(700,5);
iret = dobj.Count();
dobj.Display();
cout<<"Total ll are:"<<iret<<"\n";

dobj.DeleteAtPos(5);
iret = dobj.Count();
dobj.Display();
cout<<"Total ll are:"<<iret<<"\n";

}