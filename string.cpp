#include<iostream>
#include<string.h>
using namespace std;

int main ()
{
    char a[10];
    int ch; 
    char k;
    cout<<"Enter the string to be work with:";
    cin>>a;
    do
    {
        
        cout<<"(1) String copy"<<endl;
        cout<<"(2) String reverse"<<endl;
        cout<<"(3) String compare"<<endl;
        cout<<"(4) String concatenate"<<endl;
        cout<<"(5) String palindrome"<<endl;
        cout<<"\nEnter your choice:\t";   
        cin>>ch;
        
        switch(ch)
        {
            case 1:  //case for string copy.
            {
                cout<<"\n\tOperation string COPY:"<<endl;
                int i;
                char b[10], *p;
                p = &a[0];
                for (i = 0; a[i] != '\0'; i++)
                {
                    b[i] = *p;
                    p++;
                }
                b[i] = '\0';
                cout<<"\n\tCopied string:\t"<<b; 
                cout<<"\n";
                break;
            }
            case 2:   //case for string reverse.
            {
                cout<<"\n\tOperation string REVERSE:"<<endl;
                int i, len;
                char b[10], *p;
                p = &a[0];
                len = strlen (a);
                for (i = (len - 1); i >= 0; i--)
                {
                    b[i] = *p;
                    p++;
                }
                cout<<"\n\tReversed string:\t"<<b; 
                cout<<"\n";
                break;
            }
            case 3: //case for string compare.
            {
                cout<<"\n\tOperation string COMPARE:"<<endl;
                int i, lena, lenb, l = 0;
                char b[10], *p, *q;
                p = &a[0];
                q = &b[0];

                cout<<"\n\tEnter string to be compared:\t";
                cin>>b;

                lena = strlen (a);
                lenb = strlen (b);
                if (lena == lenb)
                {
                    for (i = 0; a[i] != '\0'; i++, p++, q++ )
    	            {
    	                if ( *p != *q )
    	                {
    	                    l = 1;
    	                    break;
    	                }
    	            }
    	
                    if (l == 0)
                        cout<<"\n\tStrings are similar";
                    else
	                    cout<<"\n\tStrings are not similar";
                }
                else
                    cout<<"\n\tStrings are not similar"; 
                cout<<"\n";    
                break;
            }
            case 4:   //case for string concatinate.
            {
                cout<<"\n\tOperation string CONCATENATION:"<<endl;
                char b[10],*p,*q;
                int lena;
    
                p = &a[0];
                q = &b[0];
    
                cout<<"\n\tEnter string to be concatinate:\t";
                cin>>b;
    
                lena = strlen(a);
                while( *p != '\0' )
                {
                    p++;
                }
                while( *q != '\0' )
                {
                    *p = *q;
                    p++;
                    q++;
                }
                cout<<"\n\tConcatinated string:\t"<<a; 
                cout<<"\n";
                break;
            }
            case 5: //case for check whether string is palindrom or not.
            {
                cout<<"\n\tOperation checking string for PALINDROME:"<<endl;
                int len;  
                char *p,*q; 
   
                len = strlen(a);
                p = &a[0];
                q = &a[( len - 1 )];
  
                while (*p++ == *q--);
                {
                    if(p > q)
                    {
                        cout<<"\n\tString is PALINDROME";
                    }
                    else
                        cout<<"\n\tString is not PALINDROME";
                } 
                cout<<"\n";
                break;
            }
            default:
            {
                cout<<"\n\tWrong choice please enter appropriated choice:\t";
                break;
            }
        }    
        cout<<"\nYou want to do further operations ?\t";
        cout<<"Press 1 for yes and 0 for no\t";
        cin>>k;
    } while(k == '1');
    
  return 0;
  
}