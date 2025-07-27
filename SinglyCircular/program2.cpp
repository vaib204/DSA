// singly LL inc cpp

#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyLL
{
private:
  PNODE first;
  int icount;

public:
  SinglyLL()
  {
    cout << "Inside default constructor\n";
    first = NULL;
    icount = 0;
  }

  int Count()
  {
    return icount;
  }

  void InsertFirst(int no)
  {
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
      first = newn;
    }
    else
    {
      newn->next = first;
      first = newn;
    }

    icount++;
  }

  void InsertLast(int no)
  {
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
      first = newn;
    }
    else
    {
      PNODE temp = first;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newn;
    }
    icount++;
  }

  void DeleteFirst()
  {
    if (first == NULL)
    {
      return;
    }
    else if (first->next == NULL)
    {
      free(first);
      first = NULL;
    }
    else
    {
      PNODE temp = first;
      first = first->next;
      delete temp;
    }
    icount--;
  }

  void DeleteLast()
  {
    if (first == NULL)
    {
      return;
    }
    else if (first->next == NULL)
    {
      free(first);
      first = NULL;
    }
    else
    {
      PNODE temp = first;

      while (temp->next->next != NULL)
      {
        temp = temp->next;
      }
      free(temp->next);
      temp->next = NULL;
    }
    icount--;
  }

  void InsertAtPos(int no, int pos)
  {

    PNODE temp = NULL;
    temp = first;
    PNODE newn = new node;

    newn->data = no;
    newn->next = NULL;

    int i = 0;

    if (pos < 1 || pos > icount + 1)
    {
      cout << "Invalid position\n";
      return;
    }
    if (pos == 1)
    {
      InsertFirst(no);
    }
    else if (pos == icount + 1)
    {
      InsertLast(no);
    }
    else
    {
      for (i = 1; i <= pos - 2; i++)
      {
        temp = temp->next;
      }
      newn->next = temp->next;
      temp->next = newn;

      icount++;
    }
  }

  void DeleteAtPos(int pos)
  {
    if (pos < 1 || pos > icount)
    {
      cout << "Invalid position\n";
      return;
    }

    if (pos == 1)
    {
      DeleteFirst();
    }
    else if (pos == icount)
    {
      DeleteLast();
    }
    else
    {
      PNODE temp = first;
      for (int i = 1; i < pos - 1; i++)
      {
        temp = temp->next;
      }

      PNODE target = temp->next;
      temp->next = target->next;
      delete target;

      icount--;
    }
  }

  void Display()
  {
    PNODE temp = first;
    while (temp != NULL)
    {
      cout << "|" << temp->data << "|->";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
};

int main()
{
  SinglyLL sobj;
  int iret = 0;

  sobj.InsertFirst(51);
  sobj.InsertFirst(21);
  sobj.InsertFirst(11);

  sobj.InsertLast(111);
  sobj.InsertLast(121);
  sobj.InsertLast(151);

  sobj.Display();
  iret = sobj.Count();
  cout << "Total number of nodes: " << iret << "\n";

  /*sobj.DeleteFirst();
  sobj.Display();
  iret = sobj.Count();
  cout << "Total number of nodes after deletion: " << iret << "\n";

  sobj.DeleteLast();
  sobj.Display();
  iret = sobj.Count();
  cout << "Total number of nodes after deletion: " << iret << "\n";*/

  sobj.InsertAtPos(181, 5);
  sobj.Display();
  iret = sobj.Count();
  cout << "Total number of nodes after : " << iret << "\n";

  sobj.DeleteAtPos(5);
  sobj.Display();
  iret = sobj.Count();
  cout << "Total number of nodes after : " << iret << "\n";

  return 0;
}