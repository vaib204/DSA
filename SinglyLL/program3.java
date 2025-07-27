
class node

{
  public int data;
  public node next;
}

class SinglyLL

{

  private node first;
  private int icount;

  public SinglyLL()

  {
    System.out.println("Inside constructor");

    first = null;
    icount = 0;
  }

  public void InsertFirst(int no)

  {
    node newn = null;
    newn = new node();

    newn.data = no;
    newn.next = null;

    if (first == null) {
      first = newn;
    } else {
      newn.next = first;
      first = newn;
    }
    icount++;
  }

  public void InsertLast(int no)

  {
    node newn = null;
    node temp = null;
    newn = new node();

    newn.data = no;
    newn.next = null;

    if (first == null)

    {
      first = newn;
    } else {
      temp = first;

      while (temp.next != null)

      {
        temp = temp.next;
      }
      temp.next = newn;
      newn.next = null;
    }
    icount++;
  }

  public void DeleteFirst()

  {
    if (first == null)

    {
      return;
    }

    else if (first.next == null)

    {
      first = null;
    } else

    {
      first = first.next;
    }
    icount--;
  }

  public void DeletLast()

  {
    node temp = null;

    if (first == null)

    {
      return;
    }

    else if (first.next == null)

    {
      first = null;
    }

    else

    {
      temp = first;

      while (temp.next.next != null) {
        temp = temp.next;
      }
      temp.next = null;
    }
    icount--;
  }

  public void InsertAtPos(int no, int pos) {
    node newn = null;
    node temp = null;
    int icnt = 0;
    newn = new node();

    newn.data = no;
    newn.next = null;

    if (pos < 1 || pos > icount + 1) {
      System.out.println("Invalid syntax:");
      return;
    }

    if (pos == 1) {
      InsertFirst(no);
    } else if (pos == icount + 1) {
      InsertLast(no);
    } else {
      temp = first;

      for (icnt = 1; icnt < pos - 1; icnt++) {
        temp = temp.next;
      }
      newn.next = temp.next;
      temp.next = newn;

      icount++;
    }
  }

  public void DeleteAtPos(int pos) {

    int icnt = 0;
    node temp = null;

    if (pos < 1 || pos > icount + 1) {
      System.out.println("Invalid syntax:");
      return;
    }

    if (pos == 1) {
      DeleteFirst();
    } else if (pos == icount + 1) {
      DeletLast();
    } else {
      temp = first;
      for (icnt = 1; icnt < pos - 1; icnt++) {
        temp = temp.next;
      }
      temp.next = temp.next.next;
      icount--;
    }
  }

  public void Disply()

  {
    node temp = null;
    temp = first;

    while (temp != null)

    {
      System.out.print("| " + temp.data + " |-> ");
      temp = temp.next;
    }
    System.out.println("null");
  }

  public int Count()

  {
    return icount;
  }
}

class program3

{
  public static void main(String[] args)

  {

    int iret = 0;
    SinglyLL sobj = new SinglyLL();

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(100);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Disply();
    iret = sobj.Count();
    System.out.println("Total linkedlist are :" + iret);

    
      sobj.DeleteFirst();
      sobj.Disply();
      iret = sobj.Count();
      System.out.println("Total linkedlist are :" + iret);
      
      sobj.DeletLast();
      sobj.Disply();
      iret = sobj.Count();
      System.out.println("Total linkedlist are :" + iret);
     

    sobj.InsertAtPos(800, 5);
    sobj.Disply();
    iret = sobj.Count();
    System.out.println("Total linkedlist are :" + iret);

    sobj.DeleteAtPos(5);
    sobj.Disply();
    iret = sobj.Count();
    System.out.println("Total linkedlist are :" + iret);

  }
}
