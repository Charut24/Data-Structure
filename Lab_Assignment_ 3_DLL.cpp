#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node *next, *prev;
};

class list : public node
{
	public:
		node *head,*temp; 
		list()
		{
			head=NULL;
			temp=NULL;
		}
		void cre(int );
		void ins();
		void del();
		void disp();
		void con();
		void rev();
};

void list::cre(int x)
{
		node *newnode=new node;
		newnode->data=x;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL)
		{
			head=newnode;
			temp=newnode;
		} 
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
}

void list::disp()
{
	temp=head;
	cout<<"\n LINKED LIST:\n";
	cout<<" NULL <=> ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		cout<<" <=> ";
		temp=temp->next;
	}
	cout<<"NULL";
}

void list::ins()
{
	int opt;
	cout<<"\n Select from following. ";
	cout<<"\n 1. Insert at start. ";
	cout<<"\n 2. Insert at end. ";
	cout<<"\n 3. Insert at intermediate. ";
	cout<<"\n Enter choice: ";
	cin>>opt;
	switch(opt)
	{
		case 1: 
		{
			int x;
	        node *newnode=new node;
	        cout<<"\n ENTER DATA:";
	        cin>>x;
	        cout<<"\n DATA INSERTED AT BEGINNING.";
			newnode->data=x;
			newnode->prev=NULL;
			newnode->next=NULL;
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
			disp();
			
			break;	
		}
		case 2: 
		{
			int x;
	        node *newnode=new node;
	        cout<<"\n ENTER DATA:";
	        cin>>x;
	        cout<<"\n DATA INSERTED AT END.";
			newnode->data=x;
			newnode->next=NULL;
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;	
			newnode->prev=temp;	
			disp();
			
			break;
		
		}
		case 3: 
		{
			int x,pos,i;
			temp=head;
	        node *newnode=new node;
	        cout<<"\n ENTER DATA:";
	        cin>>x;
			newnode->data=x;
			newnode->prev=NULL;
			newnode->next=NULL;
			cout<<"\n WHERE TO INSERT DATA? (nodes starting from 0):";
			cin>>pos;
			if(pos<0)
        	{
	        	cout<<" enter correct postion to insert: ";
	        	cin>>pos;
        	}
			i=0;
			while(i!=pos-1)
			{
				temp=temp->next;
				i++;				
			}
			newnode->next=temp->next;
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next->prev=newnode;
			cout<<"\n DATA INSERTED AT POSITION:"<<pos;
			
			disp();
			break;
		}
		default:
		{
			cout<<"\n WRONG CHOICE!";
		}	
	}
}

void list::del()
{
	if(head==NULL)
	{
		cout<<"\n List is empty. ";
	}
	else
	{
		int opt;
	cout<<"\n Select from following. ";
    cout<<"\n 1. Delete from start. ";
    cout<<"\n 2. Delete from end. ";
	cout<<"\n 3. Delete from intermediate. ";
	cout<<"\n Enter choice: ";
	cin>>opt;
	switch(opt)
	{
		case 1: 
		{
		    temp=head;
			head=temp->next;
			head->prev=NULL;
	        delete(temp);
	        cout<<"\n DATA DELETED FROM BEGINNING.";
	        
	        disp();
	        break;
	        
		}
		case 2:
		{
			temp=head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete(temp->next); 
			temp->next=NULL;
			cout<<"\n DATA DELETED FROM END.";
			
	        disp();
			break;
		}
		case 3:
		{
			int pos,i=0;
			temp=head; //temp traverses and stands on one position before the user entered position
			cout<<"\n WHERE TO DELETE DATA FROM? (nodes starting from 0):";
			cin>>pos; 
			if(pos<0)
        	{
	        	cout<<" enter correct postion to insert: ";
	        	cin>>pos;
        	}
			for(i=0;i<pos;i++) 
			{
				temp=temp->next;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			delete(temp);
			cout<<"\n DATA DELETED FROM POSITION:"<<pos;
			
			disp();
			break;
			
		}	
	}
	
    }
}

void list::rev() 
{
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	cout<<"\n DATA REVERSED.";
	cout<<"\n NULL <=> ";
	cout<<temp->data<<" <=> ";
	while(temp->prev!=NULL)
	{
		temp=temp->prev;
		cout<<temp->data;
		cout<<" <=> ";
    }
    cout<<"NULL";
    
    disp();
}

void list::con()
{
	int x,n;
	cout<<"\n ENTER NUMBER OF NODES:";
	cin>>n;
	if(n<0)
	{
		cout<<" enter correct number of nodes: ";
		cin>>n;
	}
	node *head2,*temp2;
	head2=NULL;
	temp2=NULL;
	cout<<"\n Enter numbers: ";
	for(int i=0;i<n;i++)
	{
		node *newnode=new node;
		cin>>x;
		newnode->data=x;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head2==NULL)
		{
			head2=newnode;
			temp2=newnode;
		} 
		else
		{
			temp2->next=newnode;
			newnode->prev=temp2;
			temp2=temp2->next;
		}
	}
	temp2=head2;
	cout<<"\n\n SECOND LINKED LIST:\n";
	cout<<" NULL <=> ";
	while(temp2!=NULL)
	{
		cout<<temp2->data;
		cout<<" <=> ";
		temp2=temp2->next;
	}
	cout<<"NULL";
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
	cout<<"\n\n CONCATENATED.";
	disp();	
}

int main()
{
	int d, option, n, x;
	list l;
	do
	{
		cout<<"\n____________________________________DOUBLY LINKED LIST OPERATIONS____________________________________\n\n";
		cout<<"\n Select from following. ";
        cout<<"\n 1. Create.";
        cout<<"\n 2. Insert. ";
        cout<<"\n 3. Delete. ";
        cout<<"\n 4. Reverse. ";
        cout<<"\n 5. Concatenate. ";
        cout<<"\n 6. Display.";
        cout<<"\n \n Enter choice: ";
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"\n ENTER NUMBER OF NODES:";
	            cin>>n;
	            if(n<0)
                {
                	cout<<"\n Enter correct number of nodes. ";
	            	cin>>n;       	
            	}
            	cout<<"\n Enter the numbers: ";
                for(int i=0;i<n;i++)
                {
                	cin>>x;
                	l.cre(x);
				}
				break;
				
			case 2:
				l.ins();
				break;
				
			case 3:
				l.del();
				break;
				
			case 4:
				l.rev();
				break;
				
			case 5:
				l.con();
				break;
				
			case 6:
				l.disp();
				break;
				
			default:
				cout<<"\n WRONG CHOICE!";	
		}
		cout<<"\n Enter 1 to continue: ";
		cin>>d;
	}
	while(d==1);
	return 0;
}
