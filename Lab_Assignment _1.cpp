#include <stdlib.h>
#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *next;
};

class List:public Node 
{
    Node *listptr, *temp;
    public:
    List() 
	{
        listptr = NULL;
        temp = NULL;
    }
    void create();
    void display();
};

void List::create()
 {
    Node *nextNode = new Node();
    cout<<"\n Enter Data: ";
    cin>>nextNode -> data;
    nextNode->next = NULL;
    
    if(listptr == NULL)
	{
        listptr = nextNode;
        temp = nextNode;
    }
    else {
        temp->next=nextNode;
        temp = nextNode;
    }
}

void List::display() 
{
    cout<<"Result: "<<endl;
    if (listptr == NULL)
        cout<<"List empty. ";
    else 
	{
        temp = listptr;
        while (temp != NULL)
		{
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
}

int main () 
{
    int ch, cnt;
    char c;
    List ll;
    do
	{
        cout<<"Select from following. ";
        cout<<"\n 1 Create.";
        cout<<"\n 2. Display.";
        cout<<"\n Enter choice: ";
        cin>>ch;
        switch (ch) 
		{
            case 1:
                cout<<"Enter no. of nodes: ";
                cin>>cnt;
                while(cnt != 0)
				{
                    ll.create();
                    cnt--;
                }
				break;
				
            case 2:
                ll.display();
                break;
                
            default:
			    cout<<"\n WRONG CHOICE. ";    
			
        }
        cout<<"Press Y Continue."<<endl;
        cin>>c;
    } while (c == 'Y');
    
    return 0;
}
