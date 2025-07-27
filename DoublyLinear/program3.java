class node
{
  public int data;
  public node next;
  public node prev;
}

class DoublyLL
{
  private node first;
  private int icount;

  public DoublyLL()
  {
    first = null;
    icount = 0;
  }
  
  public void InsertFirst(int no)
  {
    node newn = new node();

    newn.data = no;
    newn.next = null;
    newn.prev = null;

    if(first == null)
    {
      first = newn;
    }
    else
    {
      newn.next = first;
      newn.next.prev = newn;
      first = newn;
    }
    icount++;
  }

  public void InsertLast(int no)
  {
    node newn = new node();
    node temp = null;

    newn.data = no;
    newn.next = null;
    newn.prev = null;

    if(first == null)
    {
      first = newn;
    }
    else
    {
      temp = first;

      while(temp.next!=null)
      {
        temp= temp.next;
      }
      temp.next = newn;
      newn.next = null;
      
    }
    icount++;
  }

  public void DeleteFirst()
  {
    node temp = null;

    if(first == null)
    {
      return;
    }
    else if(first.next==null)
    {
      first = null;
    }
    else
    {
       first = first.next;
       first.prev = null;
    }
    icount--;
  }

  public void DeleteLast()
  {
    node temp = null;

    if(first == null)
    {
      return;
    }
    else if(first.next==null)
    {
      first = null;
    }
    else
    {
       temp = first;

       while(temp.next.next!=null)
       {
        temp = temp.next;
       }
       temp.next  = null;
    }
    icount--;
  }

  void InsertAtPos(int no,int pos)
  {
    node newn = new node();
    node temp = null;
    int icnt = 0;

    newn.data = no;
    newn.next = null;
    newn.prev = null;
 
    if((pos<1) || (pos>icount+1))
    {
      System.out.println("Invalid statement\n");
      return;
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
        temp = temp.next;
      }
      newn.next = temp.next;
      newn.next.prev = newn;
      temp.next = newn;
      newn.prev = temp;
    }
    icount++;
  }

   void InsertAtPos(int pos)
  {
    node temp = null;
    int icnt = 0;
 
    if((pos<1) || (pos>icount))
    {
      System.out.println("Invalid statement\n");
      return;
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
        temp = temp.next;
      }
      temp.next = temp.next.next;
      temp.next.prev = temp;
    }
    icount--;
  }


  public void Display()
  {
    node temp = null;

    temp = first;

    System.out.print("null<=>");
    while(temp != null)
    {
      System.out.print("|"+temp.data+" |<=>");
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
  public static void main(String a[])
  {
   int iret = 0;
   DoublyLL dobj = new DoublyLL();
   dobj.InsertFirst(51);
   dobj.InsertFirst(21);
   dobj.InsertFirst(11);

   dobj.InsertLast(101);
   dobj.InsertLast(121);
   dobj.InsertLast(151);

   iret = dobj.Count();
   dobj.Display();
   System.out.println("Total linked list are:"+iret);

   dobj.DeleteFirst();
   iret = dobj.Count();
   dobj.Display();
   System.out.println("Total linked list are:"+iret);

   dobj.DeleteLast();
   iret = dobj.Count();
   dobj.Display();
   System.out.println("Total linked list are:"+iret);

   dobj.InsertAtPos(700, 5);
   iret = dobj.Count();
   dobj.Display();
   System.out.println("Total linked list are:"+iret);

    dobj.InsertAtPos(5);
   iret = dobj.Count();
   dobj.Display();
   System.out.println("Total linked list are:"+iret);
  }
}