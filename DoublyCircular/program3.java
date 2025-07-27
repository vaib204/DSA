class node
{
  public int data;
  public node next;
  public node prev;
}

class DoublyLL
{
  private node first;
  private node last;
  private int icount;

  public DoublyLL()
  {
    first = null;
    last = null;
    icount = 0;
  }
  
  public void InsertFirst(int no)
  {
    node newn = new node();

    newn.data = no;
    newn.next = null;
    newn.prev = null;

    if(first == null && last == null)
    {
      first = newn;
      last = newn;
      
      last.next = first;
    }
   else
   {
    newn.next = first;

    first = newn;
   
     last.next = first;
   }
   icount++;
  }

  public void InsertLast(int no)
  {
     node newn = new node();

    newn.data = no;
    newn.next = null;
    newn.prev = null;

    if(first == null && last == null)
    {
      first = newn;
      last = newn;
      
      last.next = first;
    }
   else
   {
    last.next = newn;

    last  = newn;

    last.next = first;

   }
   icount++;
  }

  public void DeleteFirst()
  {
    if(first == null && last == null)
    {
      return;
    }
    else if(first == last)
    {
     first = null;
     last = null;
    }
    else
    {
      first = first.next;

      last.next = first;

      first.prev = last;
    }
    icount--;
  }

  public void DeleteLast()
  {
    if(first == null && last == null)
    {
      return;
    }
    else if(first == last)
    {
     first = null;
     last = null;
    }
    else
    {
       node temp = null;

       temp = first;

       while (temp.next!= last)
       {
         temp= temp.next;
       }
       first.prev = temp.next;

       temp.next = first;

    }
    icount--;
   
  }

  void InsertAtPos(int no,int pos)
  {
    node newn = new node();

    newn.data = no;
    newn.next = null;
    newn.prev = null;

    if(pos < 1 || pos>icount+1)
    {
      System.out.println("Invalid position");
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
       int icnt = 0;
       node temp = null;
       temp = first;

       for(icnt = 1;icnt<pos-1;icnt++)
       {
        temp = temp.next;
       }
         newn.next = temp.next;
         temp.next = newn;
    }
    icount++;
  }

  void DeleteAtPos(int pos)
  {
    if(pos < 1 || pos>icount)
    {
      System.out.println("Invalid position");
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
       int icnt = 0;
       node temp = null;
       temp = first;

       for(icnt = 1;icnt<pos-1;icnt++)
       {
        temp = temp.next;
       }
        temp.next = temp.next.next;
    }
    icount--;
    
  }

  public void Display()
  {
    if(first == null && last == null)
    {
      return;
    }

   node temp = first;

    do
    {
     System.out.print("|"+temp.data+"| ->");// cout << "| " << temp->data << " | -> ";
      temp = temp.next;
    } while (temp != last.next);

    System.out.println();
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

    dobj.DeleteAtPos(5);
   iret = dobj.Count();
   dobj.Display();
   System.out.println("Total linked list are:"+iret);
  }
}