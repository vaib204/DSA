#include<iostream>
#include<stdbool.h>
using namespace std;

class Arrayx
{
  public:
   int *Arr;
   int isize;
   bool sorted;

   Arrayx(int no)
   {
    isize = no;
    Arr = new int[isize];
    sorted = true;
   }

   void Accspt()
   {
     int i = 0;

     for(i = 0;i<isize;i++)
     {
        cout<<"Enter the Elements:"<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (sorted == true))
        {
          sorted = false;
        }
     }
   }

   void Display()
   {
  
    cout<<"Elements from the array:\n";
    int i = 0;

    for(i = 0;i<isize;i++)
    {
      cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
   }

   void BubbleSort()
   {
     int i = 0,j = 0,temp = 0;

     if(sorted == true)
     {
       return;
     }

     for(i = 0; i < isize ; i++)
     {
       for(j = 0; j < isize - 1;j++)
       {
           if(Arr[j] > Arr[j + 1])
           {
             temp = Arr[j];
             Arr[j] = Arr[j+1];
             Arr[j+1] = temp;
           }  
       }
       cout<<"Data after pass:"<<i+1<<"\n";

       Display();
     }
   }

   void BubbleSortEfficient()
   {
     int i = 0,j = 0,temp = 0;
     bool bflag = true;

     if(sorted == true)
     {
       return;
     }

     for(i = 0; ( i < isize && bflag == true ); i++)
     {
       bflag = false;

       for(j = 0; j < isize - 1;j++)
       {
           if(Arr[j] > Arr[j + 1])
           {
             temp = Arr[j];
             Arr[j] = Arr[j+1];
             Arr[j+1] = temp;

             bflag = true;
           }  
       }
       cout<<"Data after pass:"<<i+1<<"\n";

       Display();
     }
   }
};


int main()
{
  int ilength = 0;
  bool bret = false;

  cout<<"Enter the size of Array:\n";
  cin>>ilength;

  Arrayx *aobj = new Arrayx(ilength);

  aobj->Accspt();

  aobj->Display();

  aobj->BubbleSort();

  cout<<"Data after sorted:\n";

  aobj->Display();

  delete aobj;
  
  return 0;
}