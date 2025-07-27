#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyLL
{
private:
  PNODE first = NULL;
  int icount;

public:
  DoublyLL()
  {
    cout << "Inside defualt constructor\n";
    first = NULL;
    icount = 0;
  }

  int count()
  {
    return icount;
  }

  void InsertFirst(int no)
  {
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
      first = newn;
    }
    else
    {
      newn->next = first;
      first->prev = newn;
      first = newn;
    }
    icount++;
  }

  void InserLast(int no)
  {
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
      first = newn;
    }
    else
    {
      PNODE temp = NULL;

      temp = first;

      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newn;
      newn->prev = temp;
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
      temp = first;

      first = first->next;
      delete (temp);
      first->prev = NULL;

      icount--;
    }
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
      temp = first;

      while (temp->next->next != NULL)
      {
        temp = temp->next;
      }
      delete (temp->next);
      temp->next = NULL;

      icount--;
    }
  }

  void InsertAtPos(int no, int pos)
  {
    PNODE temp = NULL;
    int icnt = 0;

    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((pos < 1) || (pos > icount + 1))
    {
      cout << "Invalid position";
      return;
    }

    if (pos == 1)
    {
      InsertFirst(no);
    }
    else if (pos == icount + 1)
    {
      InserLast(no);
    }
    else
    {
      temp = first;

      for (icnt = 1; icnt < pos - 1; icnt++)
      {
        temp = temp->next;
      }
      newn->next = temp->next;
      newn->next->prev = newn;
      temp->next = newn;
      newn->prev = temp;
    }
    icount++;
  }

  void DeleteAtPos(int pos)
  {
    PNODE temp = first;

    if ((pos < 1) || (pos > icount))
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
      for (int i = 1; i < pos; i++)
      {
        temp = temp->next;
      }
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      delete temp;
    }
    icount--;
  }

  void Display()
  {
    PNODE temp = first;
    cout << "NULL <=>";

    while (temp != NULL)
    {
      cout << "|" << temp->data << "|<=>";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
};

int main()
{
  PNODE head = NULL;
  int iret = 0;

  DoublyLL dobj;

  dobj.InsertFirst(51);
  dobj.InsertFirst(21);
  dobj.InsertFirst(11);

  dobj.InserLast(111);
  dobj.InserLast(121);
  dobj.InserLast(151);

  dobj.Display();
  iret = dobj.count();
  cout << "count is:" << iret << "\n";

  dobj.DeleteFirst();
  dobj.Display();
  iret = dobj.count();
  cout << "count is:" << iret << "\n";

  dobj.DeleteLast();
  dobj.Display();
  iret = dobj.count();
  cout << "count is:" << iret << "\n";

  dobj.InsertAtPos(185, 5);
  dobj.Display();
  iret = dobj.count();
  cout << "count is:" << iret << "\n";

  dobj.DeleteAtPos(5);
  dobj.Display();
  iret = dobj.count();
  cout << "count is:" << iret << "\n";
}
