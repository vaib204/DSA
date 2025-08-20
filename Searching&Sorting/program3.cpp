#include<iostream>
using namespace std;

class Arrayx
{
  public:
    int *Arr;
    int isize;

    Arrayx(int no)
    {
       isize = no;
       Arr = new int [isize];
    }
    ~Arrayx()
    {
      delete[]Arr;
    }

    void Accepct()
    {
      cout<<"Enter the elements:\n";

      int i = 0;

      for(i = 0;i<isize;i++)
      {
        cin>>Arr[i];
      }
    }

    void Display()
    {
      cout<<"Elements from the array\n";

      int i = 0;

      for(i = 0; i<isize;i++)
      {
        cout<<Arr[i]<<"\t";
      }
      cout<<"\n";
    }

    bool LinearSearch(int no)
    {
      int i = 0;
      bool bflag = false;

      for(i = 0;i<isize;i++)
      {
        if(Arr[i] == no)
        {
          bflag = true;
          break;
        }
      }
      return bflag;

    }

    bool bidirectionalSearch(int no)
    {
      int istart = 0;
      int iend = 0;

      bool bflag = false;

      for(istart = 0,iend = isize-1; istart<=iend;istart++,iend++)
      {
        if(Arr[istart] == no || Arr[iend] == no)
        {
          bflag = true;
          break;
        }
      }
      
       return bflag;
    }

    bool BinarySearch(int no)
    {
      int istart = 0,iend = 0,imid = 0;
      bool bflag = false;

      istart = 0;
      iend = isize - 1;

      while (istart <= iend)
      {
        imid = istart + ((iend - istart)/2);

        if(no < Arr[imid])
        {
          iend = imid-1;
        }
        else if(no > Arr[imid])
        {
          istart = imid + 1;
        }
      }
      return bflag;
    }

    bool BinarySearchEfficient(int no)
    {
      int istart = 0,iend = 0,imid = 0;
      bool bflag = false;

      istart = 0;
      iend = isize - 1;

      while (istart <= iend)
      {
        imid = istart + ((iend - istart)/2);

        if(Arr[imid] == no || Arr[istart] == no || Arr[iend] == no) //change
        {
          bflag = true;
          break;
        }
        else if(no < Arr[imid])
        {
          iend = imid-1;
        }
        else if(no > Arr[imid])
        {
          istart = imid + 1;
        }
      }
      return bflag;
    }
};

int main()
{
  int ilength = 0;
  int ivalue = 0;

  cout<<"Enter the element:\n";
  cin>>ilength;

  Arrayx *aobj = new Arrayx(ilength);

  bool bret = false;

  aobj->Accepct();

  aobj->Display();

  cout<<"Enter the number that you want to search:\n";
  cin>>ivalue;

  bret = aobj->LinearSearch(ivalue);

  if(bret == true)
  {
    cout<<"Element is present:";
  }
  else
  {
    cout<<"Element is not present:";
  }

  return 0;
}