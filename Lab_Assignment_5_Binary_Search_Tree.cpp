//INPUT: 8 3 10 1 6 14
//PRE-ORDER RECURSIVE:    8  3  1  6  10  14  
//IN-ORDER RECURSIVE:     1  3  6  8  10  14  
//POST-ORDER RECURSIVE:   1  6  3  14  10  8

#include<iostream>
using namespace std;
#define COUNT 10

class Node
{
	public:
		int data;
		Node *left, *right;
		Node()
		{
			data=0;
			left=NULL;
			right=NULL;
		}		
};

class BST
{
	public:
		Node *root;
		BST()
		{
			root=NULL;
		}

		void Insert(int);
		bool Search(int,Node*);
		void Delete(int);
		void Display();
		
		void print2DUtil(Node *, int );
		void print2D(Node*);
		void Preorder(Node*);
	    void Inorder(Node*);
	    void Postorder(Node*);
};


void BST :: Insert(int num)
{
	Node *temp, *newnode;
	newnode= new Node();
	newnode->data = num;
	if (root == NULL)
	{
		root = newnode;
		cout<<"\n Node inserted. ";
	}
	else
	{
		temp = root;
		while (1) 
		{
			if (num < temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = newnode;
					cout<<"\n Node Inserted.";
					break;
				}
				else
					temp = temp->left;
			}
			else
			{
				if (temp->right == NULL)
				{
					temp->right = newnode;
					cout<<"\n Node Inserted.";
					break;
				}
				else
					temp = temp->right;
			}
		}
	}
}

bool BST :: Search(int value,Node *temp)
{
	if (root == NULL)
		return (false);
	else
	{
		if (temp == NULL)
	    	return (false);
		
	    if (temp->data == value)
	    	return (true);
		
    	if (temp->data > value)
    		return (Search(value,temp->left));
		
    	else if (temp->data < value )
    		return (Search(value,temp->right));
	}
	return (NULL);
}

void BST :: Delete(int del) //INPUT: 8 3 10 1 6 14 // DEL =  // 8  3  1  6  10  14 
{
	Node *temp, *parent=NULL, *father, *r, *son;
	temp = root;// 8
	while ((temp->data != del) && (temp!=NULL))
	{
		if(del <temp->data)
		{
			parent = temp;
			temp = temp->left;
		}
		else
		{
			parent = temp;
			temp = temp->right;
		}
	}
	if(temp == NULL)
	{
		cout<<"\nNumber Not Found";
		return;
	}
	if(temp->left == NULL)
	{
		r=temp->right;
	}
	else
	{
		if (temp->right == NULL){
			r=temp->left;
		}
		else {
			father = temp;
			r=temp->right;
			son = r->left;
			while (son != NULL)
			{
				father =r;
				r = son;
				son = r->left;
			}
			if(father != temp)
			{
				father->left = r->right;
				r->right = temp->right;
			}
			r->left = temp->left;
		}
	}
	
	if(parent == NULL)
	{
		root = r;
	}
	else
	{
		if (temp == parent->left)
		{
			parent->left = r;
		}
		else
		{
			parent->right = r;
		}
	}
	delete(temp);
	return;
}

void BST::print2DUtil(Node *root, int space) 
{ 
    if (root == NULL) 
        return; 
    space += COUNT; 
    // Process right child first 
    print2DUtil(root->right, space); 
    // Print current node after space 
    // count
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
	cout<<root->data<<"\n"; 
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void BST::print2D(Node *root) { 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
}

void BST :: Display()
{
	int c;
	cout<<"\n 1. Display in Preorder. ";
	cout<<"\n 2. Display in Inorder. ";
	cout<<"\n 3. Display in Postorder. ";
	cout<<"\n Enter choice: ";
	cin>>c;
	switch(c)
	{
		case 1:
			print2D(root);
			
			cout<<"\n**************** Preorder Display ***************\n";
			Preorder(root);
			break;
			
		case 2:
			print2D(root);
			cout<<"\n**************** Inorder Display ***************\n ";
			Inorder(root);
			break;
			
		case 3:
			print2D(root);
			cout<<"\n**************** Postorder Display ***************\n ";
			Postorder(root);
			break;
	}
}

void BST :: Preorder(Node *root)
{
	if (this->root == NULL) {
        cout<<"! - TREE IS EMPTY - !"<<endl;
        return;
    }
    else if (root == NULL)
        return;
    cout<<root->data<<"  ";
    Preorder(root->left);
    Preorder(root->right);
}

void BST :: Inorder(Node *root)
{
	if (this->root == NULL) {
        cout<<"! - TREE IS EMPTY - !"<<endl;
        return;
    }
    else if (root == NULL)
        return;
	Inorder(root->left);
    cout<<root->data<<"  ";
    Inorder(root->right);
}

void BST :: Postorder(Node *root)
{
	if (this->root == NULL) {
        cout<<"! - TREE IS EMPTY - !"<<endl;
        return;
    }
    else if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
	cout<<root->data<<"  ";
}

main()
{
	BST b;
	int choice, num, value, del;
	char ch;
	do
	{
		cout<<"\n Select from following... ";
	    cout<<"\n 1. Insert.";
	    cout<<"\n 2. Search.";
	    cout<<"\n 3. Delete.";
	    cout<<"\n 4. Display.";
	    cout<<"\n Enter choice: ";
	    cin>>choice;
	
	    switch(choice)
	    {
	    	case 1:
		    	cout<<"\n \n Enter the value: ";
	    		cin>>num;
	    		b.Insert(num);
	    		break;
			
	    	case 2:
	    		if(b.root == NULL)
	    		{
	    			cout<<"\n Empty Tree. ";
				}
				else
				{
					cout<<"\n Enter value To search: ";
	    		    cin>>value;
	    		    if (b.Search(value,b.root))
	    		    {
	    			    cout<<"\n Element present. ";
				    }
				    else
				    {
				    	cout<<"\n Element not present.";
				    }
				}
	    		break;
			 
	    	case 3:
	    		if(b.root == NULL)
	    		{
	    			cout<<"\n Empty Tree. ";
				}
				else
				{
					cout<<"\n Enter the value to Delete: ";
		    	    cin>>del;
	    		    if (b.Search(del,b.root))
	    	    	{
	    	    		b.Delete(del);
	    	    		cout<<"\n Element Deleted. ";
			    	}
			    	else
		    		{
		    			cout<<"\n Element not present, delete operation cannot be performed.";
			    	}
				}
	    		break;
			
	    	case 4:
	    		if(b.root == NULL)
	    		{
	    			cout<<"\n TREE IS EMPTY.";
				}
				else
				{
					b.Display();
				}
	    	    break;
        	
        	default:
        		cout<<"\n WRONG CHOICE. ";
        		
		}
		cout<<"\n\n Enter 'Y' to continue: ";
		cin>>ch;
		
	}while(ch=='Y');
	
	return(0);
}
