#include<iostream>
using namespace std;

class Node
{
	public:
		int data,cnt;
		Node *next;
};

class List : public Node
{
	Node *listptr, *listptr2, *temp; 
    public:
    List() 
	{
        listptr = NULL;
        temp = NULL;
    }
    void Create(int );
    void Display();
    void Insert();
    void Delete();
    void Reverse();
    void Concatenate();
    
    void Insert_start();
    void Insert_intermediate();
    void Insert_end();
    
    void Delete_from_start();
    void Delete_from_intermediate();
    void Delete_from_end();
    
    void empty();
};

void List :: empty()
{
	int x;
	if(listptr==NULL)
	{
		cout<<"\n THE LIST IS EMPTY .. CREATING A LIST....";
		cout<<"Enter no. of nodes: ";
        cin>>cnt; 
        cout<<"Enter the numbers: ";
        while(cnt !=0) 
        {
        	cin>>x;
        	Create(x);
        	cnt --;
		}
	}
}

void List :: Create(int x)
{
	Node *newnode = new Node();
	newnode->data=x; 
	newnode -> next = NULL;
	if (listptr == NULL)
	{
		listptr = temp = newnode;
		newnode->next=listptr;
	}
	else
	{
		temp->next=newnode;
		newnode->next=listptr;
		temp=temp->next;
	}
}

void List :: Display()
{
	cout<<"\n Result: "<<endl;
    if (listptr == NULL) 
        cout<<"\n List empty. ";
    else
    {
    	temp=listptr;
    	do
    	{
    		cout<<temp->data<<" -> ";
    		temp=temp->next;
		}while(temp!=listptr);
		cout<<"\b\b ";
	}
}

void List :: Insert()
{
	int ichoice;
	cout<<"\n Select from following. ";
	cout<<"\n 1. Insert at start. ";
	cout<<"\n 2. Insert at intermediate. ";
	cout<<"\n 3. Insert at end. ";
	cout<<"\n Enter choice: ";
	cin>>ichoice;
	switch(ichoice)
	{
		case 1:
			Insert_start();
			break;
			
		case 2:
			Insert_intermediate();
			break;
			 
	    case 3:
	    	Insert_end();
	    	break;
	}
}

void List :: Insert_start()
{
	int x;
	Node *newnode = new Node;
	cout<<"\n Enter value: ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	newnode->next=listptr;
	temp=listptr;
	// traversing temp to last node
	while(temp->next!=listptr)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	listptr=newnode; // connecting of the noew node with the original start node
	
	Display();
}

void List :: Insert_intermediate()
{
	empty();                                  
	int n,x,i=0;
	temp = listptr;   
	Node *newnode = new Node;
	cout<<"\n\n  Enter value to insert: ";
	cin>>x;  
	newnode->data=x;  
	newnode->next=NULL; 
	cout<<"\n Where to insert: ";
	cin>>n; 
	if(n<0)
	{
		cout<<"enter correct postion to insert: ";
		cin>>n;
	}
		while(i!=(n-1))     // traversing statement   
    	{
	    	temp = temp->next;   
		    i++;
	    }
	    newnode->next= temp->next; 
	    temp->next=newnode; 
	    
    cout<<"\n The node is inserted at "<<n<<" position.";
	Display();
}

void List :: Insert_end()
{
	empty(); 
	int x;
	Node *newnode = new Node;
	cout<<"\n\n  Enter value to insert: ";
	cin>>x;
	newnode->data=x;   
	newnode->next=NULL;
	temp = listptr;
	while(temp->next!= listptr)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	// the value will be pointed to the last node
	newnode->next=listptr;
	
	Display();
}

void List :: Delete()
{
	if(listptr==NULL)
	    cout<<"\n The list is empty and cannot delete any element.";
	else
	{
		int dchoice;
	    cout<<"\n Select from following. ";
    	cout<<"\n 1. Delete from start. ";
	    cout<<"\n 2. Delete from intermediate. ";
    	cout<<"\n 3. Delete from end. ";
    	cin>>dchoice;
    	switch(dchoice)
    	{
	    	case 1:
	    		Delete_from_start();
		    	break;
			
	    	case 2:
	    		Delete_from_intermediate();
	    		break;
			 
	        case 3:
	        	Delete_from_end();
	        	break;
	    }
	}
}

void List :: Delete_from_start()
{
	if(listptr==NULL)
	{
		cout<<"\n List is empty! ";
		return;
	}
	if(listptr->next==listptr)
	{
		delete(listptr);
		listptr=NULL;
		return;
	}
	temp=listptr;
	while(temp->next!=listptr)
	{
		temp=temp->next;
	}
	temp->next=listptr->next;
	temp=listptr;
	listptr=listptr->next;
	delete(temp);
	
	Display();
}

void List :: Delete_from_intermediate()
{
    Node *q;         
	int n,i;
	if(listptr==NULL)
	{
		cout<<"\n List empty!!";
		return;
	}
	else
	{
		cout<<"\n Enter position to delete: ";
		cin>>n;
		if(n<0)
		{
			cout<<"\n enter correct position: ";
			cin>>n;
		}
		temp=listptr;
		for(i=0;i<n-1;i++) 
		{
			temp=temp->next;
			if(temp->next ==listptr)
			{
				cout<<"the element is not present there";
		    }
		}
		q=temp->next;
		temp->next = q->next;
		delete(q);
	}
	
	Display();
}

void List :: Delete_from_end()   
{
	Node *current,*prev; 
	current = listptr; 
	temp = listptr; 
	if(current->next==listptr) 
	{
		delete(current);
		listptr=temp=NULL;
        return;				
	}
                                  
    while(current->next!=listptr) 
	{
		prev = current;   
        current=current->next; 
    }
    prev->next=current->next;
    delete(current);
    
	Display();
}

void List :: Reverse()
{
	if(listptr==NULL)
	{
		cout<<"\n The list is empty. ";
	}
	Node *forward,*back,*current; 
	forward = listptr;
	current = listptr;
	do
	{
		back = current; 
		current = forward; 
		forward = forward->next;
		current->next=back;
	}while(forward!=listptr);
	forward->next=current;
	listptr = current;
	
}

void List :: Concatenate() {
	if(listptr==NULL)
	{
		cout<<"The list is empty...  ";
	}
	else
	{
		int n;
		listptr2=NULL;
    	cout<<"Enter no. of nodes of second list : ";
    	cin>>n;
    	if(n<0)
    	{
    		cout<<" enter correct number of nodes: ";
    		cin>>n;
		}
    	cout<<"Enter the numbers: ";
    	for(int i=0;i<n;i++)
    	{
    		Node *newNode=new Node();
    	    cin>>newNode->data;  
    	    if(listptr2==NULL)
		    {
    	    	listptr2=newNode;
    	    }
    	    else 
		    {
    	    	temp->next=newNode;
    	    }
			temp=newNode;
		}
		temp->next = listptr;
		temp=listptr;
		while(temp->next!=listptr)
		{
		    temp = temp->next;
		}
		temp->next = listptr2;

		Display();
	}
}

int main () 
{
    int ch, cnt,x;
    char c;
    List l;   
    do
	{
        cout<<"\n Select from following. ";
        cout<<"\n 1. Create.";
        cout<<"\n 2. Display.";
        cout<<"\n 3. Insert. ";
        cout<<"\n 4. Delete. ";
        cout<<"\n 5. Reverse. ";
        cout<<"\n 6. Concatenate. ";
        cout<<"\n \n Enter choice: ";
        cin>>ch;
        
        switch (ch) 
		{
            case 1:
            	cout<<"\n Enter no. of nodes: ";
                cin>>cnt;
                if(cnt<0)
                {
                	cout<<"Enter correct number of nodes. ";
					cin>>cnt;       	
				}
                cout<<"\n Enter the numbers: ";
                for(int i=0;i<cnt;i++)
				{
					cin>>x;
                    l.Create(x); 
                }
				break;
				
            case 2:
                l.Display();
                break;
                
            case 3:
            	l.Insert();
            	break;
			
			case 4:
				l.Delete();
				break;
				
			case 5:
			    l.Reverse();
			    l.Display();
			    l.Reverse();
			    cout<<"\n\n Original list:  ";
			    l.Display();
			    break;
			    
			case 6:
			    l.Concatenate();
				break;    
			
            default:
			    cout<<"\n WRONG CHOICE. ";    
			
        }
        cout<<"\n \n Press Y Continue."<<endl;
        cin>>c;
    } while (c == 'Y');
    
    return 0;
}
