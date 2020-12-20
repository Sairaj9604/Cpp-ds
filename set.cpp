#include <iostream>
using namespace std;
int c[100];
void uni(int a[],int b[],int s1,int s2)
{
  int i=0,j,k=0;
  for(i=0;i<s1;++i){
    c[k]=a[i];
    k++;
  }
  
  for(i=0;i<s2;++i){
  int  flag=1;
    for(j=0;j<s1;++j){
      if(b[i]==a[j]){
        flag=0;
        break;
      }
    }
    if(flag){
      c[k]=b[i];
      k++;
    }
  }
 
  cout<<"\nUnion of two arrays is:\n";
  for(i=0;i<k;++i){
    cout<<c[i]<<" ";
  }
}
void intersection(int a[],int b[],int s1,int s2)
{
  int i=0,j,k;
  for(j=0;j<s1;j++)
    {
      for(k=0;k<s2;k++)
      {
        if(a[j]==b[k])
        {
          c[i++]=a[j];
        }
      }
    }
    if(i!=0)
    {
      cout<<"\n Intersection is\n";
      for(k=0;k<i;k++)
      {
        cout<<c[k]<<"  ";
      }
    }
    else
    {
      cout<<"\nno common elements\n";
    }
}
void diff(int a[],int b[],int s1,int s2)
{
  int i=0,j,k;
  for(j=0;j<s1;j++)
    {
      for(k=0;k<s2;k++)
      {
        if(a[j]==b[k])
        {
          break;
        }
        if(k==s1)
        {
          c[i++]=a[j];
        }
      }
    }
    if(i!=0)
    {
      cout<<"\n Difference is\n";
      for(k=0;k<i;k++)
      {
        cout<<c[k]<<"  ";
      }
    }
    else
    {
      cout<<"\nNo Difference found\n";
    }
}

void symdif(int a[],int b[],int s1,int s2)
{
  int i = 0,j,k,p; 
  for(j=0;j<s1;j++)
  {
    p=0;
    for(k=0;k<s2;k++)
    {
      if(a[j]==b[k])
      {
        p=1;
        break;
      }
    }
    if(p==0)
    {
      c[i]=a[j];
      i++;
    }
  }
  for(j=0;j<s2;j++)
  {
    p=0;
    for(k=0;k<s1;k++)
    {
      if(b[j]==a[k])
      {
        p=1;
        break;
      }
    }
    if(p==0)
    {
      c[i]=b[j];
      i++;
    }
  }
  if(i!=0)
    {
      cout<<"\n Symmertric Difference is\n";
      for(k=0;k<i;k++)
      {
        cout<<c[k]<<"  ";
      }
    }
    else
    {
      cout<<"\nNo Symmertric Difference found\n";
    }
}
int main()
{
    char ch;
    int s1,s2,n;
    cout<<"enter size of array 1:  ";
    cin>>s1;
    cout<<"enter size of array 2:  ";
    cin>>s2;
    int a[s1],b[s2];
    cout<<"Enter array 1  ";
    for(int i=0;i<s1;i++){cin>>a[i];}
    cout<<"Enter array 2  ";
    for(int i=0;i<s2;i++){cin>>b[i];}
    cout<<"\n\t OPERATIONS";
    cout<<"\n1.Union";
    cout<<"\n2.Intersection";
    cout<<"\n3.Difference";
    cout<<"\n4.Symmertric Difference \n";
    do
    {
    cout<<"\nEnter operation to be performed :";
    cin>>n;
    switch(n)
    {
      case 1:
        uni(a,b,s1,s2);
        break;
      case 2:
        intersection(a,b,s1,s2);
        break;
      case 3:
        diff(a,b,s1,s2);
        break;
      case 4:symdif(a,b,s1,s2);
        break;
      default:
      cout<<"\nInvalid";
    } 
    cout<<"\nDo you want to continue (y/n):";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}