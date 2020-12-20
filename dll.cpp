#include <iostream>
#include <string.h>
using namespace std;
struct Node
{
    int rolln;
    char name[10];
    Node *next,*prev;
};
struct Node *head,*newnode,*temp,*trans = NULL;

void create()  //Creating Node
{
	head=0;
	int ch;
	do
	{
		newnode=new Node[sizeof(Node *)];
		cout<<"Enter the Name : ";
		cin>>newnode->name;
		cout<<"Enter the roll no : ";
		cin>>newnode->rolln;
		newnode->prev=0;
		newnode->next=0;
		if(head==0)
		{
			head=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		cout<<"1.New node\n0.Stop\nEnter :";
		cin>>ch;
	}while(ch);
}

void display()
{
    struct Node*  ptr;
    ptr=head;
    cout<<"-----------Student Data-------------"<<endl;
    while(ptr!=NULL){
    cout<<"roll number : "<<ptr->rolln<<endl;
    cout<<"name : "<<ptr->name<<endl;
    ptr=ptr->next;}
}

void modify()
{
    Node * mod;
    mod=head;
    char str[10];
    cout<<"enter the name to be modified"<<endl;
    cin>>str;
    while(mod != NULL)
    {
        if(strcmp(mod->name,str)==0)
        {
            char str2[10];
            cout<<"enter modified string"<<endl;
            cin>>str2;
            strcpy(mod->name,str2);
        }mod=mod->next;
    }
}

void search()
{
    Node * mod;
    mod=head;
    char str[10];
    cout<<"enter the name to be searched"<<endl;
    cin>>str;

    while(mod != NULL)
    {
        if(strcmp(mod->name,str)==0)
        {
            cout<<"name found at roll number "<<mod->rolln<<endl;
            return;
        }
        mod=mod->next;
    }
    cout<<"name not found in the list"<<endl;
}

void start_insert()  //Start Insert Function
{
    newnode = (struct Node*) malloc(sizeof(struct Node));
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->rolln;
	newnode->next=head;
	head->prev=newnode;
	newnode->prev=NULL;
	head=newnode;
}

void between_insert() //Inbetween Insert Function
{
	int ch,i=1,p;
	newnode = (struct Node*) malloc(sizeof(struct Node));
	temp=head;
	cout<<"1.Before Position\n2.After Position\nEnter choice:";
	cin>>ch;
	cout<<"Enter Position:";
	cin>>p;
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->rolln;
	while(temp->next !=NULL)
	{
		if(p==1)
		{
			if(ch==1)
			{
				newnode->prev=NULL;
				newnode->next=temp;
				temp->prev=newnode;
				head=newnode;
				break;
			}
			else
			{
			    newnode->next=temp->next;
			    newnode->prev=temp;
			    (temp->next)->prev=newnode;
				temp->next=newnode;
				break;
			}
		}
		if(p==i)
		{
			if(ch==1)
			{
                temp=temp->prev;
				newnode->next=temp->next;
				newnode->prev=temp;
				(temp->next)->prev=newnode;
				temp->next=newnode;
				break;
			}
			else
			{
				newnode->next=temp->next;
			    newnode->prev=temp;
			    (temp->next)->prev=newnode;
				temp->next=newnode;
				break;
			}
		}
		temp=temp->next;
		i++;
	}
}

void last_insert()  //Last Insert Function or Append
{
	temp=head;
	newnode = (struct Node*) malloc(sizeof(struct Node));
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->rolln;
	newnode->next=0;
	while(1)
	{
		if(temp->next==0)
		{
			temp->next=newnode;
			newnode->prev=temp;
			break;
		}
		temp=temp->next;
	}
}

void start_delete()  //Start Delete Function
{
	temp=head;
    (temp->next)->prev=NULL;
	head=temp->next;
	delete(temp);
}

void last_delete()  //Last Delete Function
{
	temp=head;
	while(temp->next!=0)
	{
		temp=temp->next;
	}
	(temp->prev)->next=0;
	delete(temp);

}

void between_delete()  //Inbetween Delete Function
{
	int ch,i=1,p;
	temp=head;
	cout<<"1.Before Position\n2.After Position\nEnter choice:";
	cin>>ch;
	cout<<"Enter Position:";
	cin>>p;
	while(temp!=0)
	{
		if(p==1)
		{
			if(ch==1)
			{
				cout<<"Invalid choice"<<endl;
				cout<<"Node Deletion Error"<<endl;
				break;
			}
		}
		if(p==i)
		{
			if(ch==1)
			{
				temp=temp->prev;
				(temp->prev)->next=temp->next;
				(temp->next)->prev=temp->prev;
				delete(temp);
			}
			else if(ch==2)
			{
                temp=temp->next;
                if((temp->next)==NULL)
                    last_delete();
                else
                {
                    (temp->prev)->next=temp->next;
                    (temp->next)->prev=temp->prev;
                    delete(temp);
                }


			}
		}
		temp=temp->next;
		i++;
	}
}


void reverse() //Reverse print function
{
	cout<<"Reversed List-"<<endl;
	temp=head;
	while(temp->next!=NULL){temp=temp->next;}
	while(temp!=head)
	{
		cout<<"roll number : "<<temp->rolln<<endl;
        cout<<"name : "<<temp->name<<endl;
		temp=temp->prev;
	}
	cout<<"roll number : "<<temp->rolln<<endl;
    cout<<"name : "<<temp->name<<endl;
}

int main()
{
    int ch,i,d;
    char ans;
    do
    {
        cout<<"1.Create\n2.Display\n3.Modify\n4.Search\n5.Insertion\n6.Deletion\n7.Reverse\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                create();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                modify();
                break;
            }
            case 4:
            {
                search();
                break;
            }
            case 5:
			{
			    cout<<"\n1.Insert at First\n2.Insert Between\n3.Insert at Last\nEnter choice : ";
			    cin>>i;
			    if(i==1)
			    {
			        start_insert();
			    	cout<<"Node Inserted At Start"<<endl;
			    }
			    else if(i==2)
			    {
			        between_insert();
				    cout<<"Node Insertion Successful"<<endl;
			    }
			    else if(i==3)
			    {
			        last_insert();
		    		cout<<"Node Inserted At Last"<<endl;
			    }
			    else
			    {
			        cout<<"Please enter valid choice\n";
			    }
			    break;
			}
			case 6:
			{
			    cout<<"\n1.Delete First\n2.Delete Between\n3.Delete Last\nEnter choice : ";
			    cin>>d;

			    if(d==1)
			    {
			        start_delete();
		    		cout<<"First Node Deleted"<<endl;
			    }
			    else if(d==2)
			    {
			        between_delete();
			        cout<<"Node Deleted"<<endl;
			    }
			    else if(d==3)
			    {
			        last_delete();
			    	cout<<"Last Node Deleted"<<endl;
			    }
			    else
			    {
			        cout<<"Please enter valid choice\n";
			    }
			    break;
			}
			case 7:
			{
			    reverse();
			    break;
			}
            default:
                cout<<"Please enter valid choice\n";
        };
        cout<<"\n\nDo you want to continue?\nYes or No(y/n) : ";
        cin>>ans;
        cout<<endl;
    }while(ans=='y'|| ans=='Y');
    return 0;
}












