#include<iostream>
using namespace std;
#include<stack>

class Node
{
public:
	int data;
	Node* left, * right;
	Node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(int v)
	{
		data = v;
		left = NULL;
		right = NULL;
	}
};

class bt
{
public:
	Node* root;
	bt()
	{
		root = NULL;
	}
	bool isempty();
	Node* insert(Node*, Node*);
	void Preorder(Node*);
	void Inorder(Node*);
	void Postorder(Node*);
	void nrecPreorder();
	void nrecInorder();
	int countnodes(Node*);
	void nrecPostorder();
};
int bt :: countnodes(Node *root)
{
	static int count=0;
	if (root == NULL)
	{
		++count;
		countnodes(root->right);
		countnodes(root->left);
		
	}
	return count;
}
bool bt::isempty()
{
	return(root == NULL);
}

Node* bt::insert(Node* r, Node* n)
{
	Node* temp = r;
	if (isempty())
	{
		root = n;
		cout << "Node Inserted as ROOT Node\n";
		return(root);
	}
	if (temp->data == n->data)
	{
		cout << "Value already exist, same values are not allowed\n";
		return(temp);
	}
	cout << "We are at Node whose value is : " << temp->data << "\n\nWhere would you like to insert Data , left or right of current Node ? enter 'l' for left and 'r' for right\n";
	char opt;
	cin >> opt;
	if (opt == 'l')
	{
		if (temp->left == NULL)
		{
			temp->left = n;
			cout << "Node inserted successfully\n";
			return(temp);
		}
		else
		{
			temp->left = insert(temp->left, n);
		}

	}
	else
	{
		if (temp->right == NULL)
		{
			temp->right = n;
			cout << "Node inserted successfully\n";
			return(temp);
		}
		else
		{
			temp->right = insert(temp->right, n);
		}
	}
}

void bt::Preorder(Node *n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		cout << n->data << " ";
		Preorder(n->left);
		Preorder(n->right);
	}
}

void bt::Inorder(Node *n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		Inorder(n->left);
		cout << n->data << " ";
		Inorder(n->right);
	}
}

void bt::Postorder(Node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		Postorder(n->left);
		Postorder(n->right);
		cout << n->data << " ";

	}
}

void bt::nrecPreorder()
{
	if (root == NULL)
	{
		cout << "Tree is Empty\n";
		return;
	}
	stack<Node *> s; // creating a stack which will store pointer to the node and with name s 
	s.push(root); // pushing value of root to stack 
	while (!s.empty())
	{
		Node* temp = s.top(); // temp point to TOP node 
		s.pop(); 
		cout << temp->data << " "; // ABDC
		if (temp->right != NULL) 
			s.push(temp->right);
		if (temp->left != NULL) 
			s.push(temp->left);
	}
	cout << "\n";
	return;
}

void bt::nrecInorder()
{

	if (root == NULL)
	{
		cout << "Tree is Empty\n";
		return;
	}
	stack<Node*> s; // creating a stack which will store pointer to the node and with name s
	Node* temp = root; 
	
	while (temp != NULL || s.empty() == false) 
	{
		
		while (temp != NULL)
		{
			s.push(temp); // pushing to stack 
			temp = temp->left; // temp->NULL
		}


		temp = s.top(); 
		s.pop();

		cout << temp->data << " ";
		temp = temp->right;

	}
	cout << "\n";
	return;
}

void bt::nrecPostorder()
{

	if (root == NULL)
	{
		cout << "Tree is Empty\n";
		return;
	}
	stack<Node*> s; // creating a stack which will store pointers to the Node and named s
	stack<int> out; // stack is data type which will store integer value and named as out
	s.push(root); // A
	while (!s.empty()) // checking whether the stack is empty or not
	{ 
		Node * temp = s.top(); 
		s.pop(); //empty stack s

		out.push(temp->data); 
		if (temp->left!=NULL) 
			s.push(temp->left);
		
		if (temp->right!=NULL) 
			s.push(temp->right); 
		
	}
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
	cout << "\n";
	return;
}

int main()
{
	bt b;
	int c, val, ans = 0;

	do {
		cout << "ENTER : \n" << "1. Insert Node\n" << "2. Print/Traversal BST values\n";
		Node* n = new Node;
		int a;
		cin >> c;
		Node* k;
		switch (c)
		{
		case 1:
			cout << "Enter the Value\n";
			cin >> a;
			n->data = a;
			k = b.insert(b.root, n);
			break;
			
		case 2:
			cout<<b.countnodes(b.root);
			if (b.root == NULL )
			{
				cout<<"\n TREE IS EMPTY. ";
			}
			else
			{
				cout <<"\n Traversals :-\n";
			cout <<"--------------------------------------------------DFS---------------------------------------" << "\n";
			cout <<"\n PREORDER : \n";
			cout <<"\n Recursive : ";
			b.Preorder(b.root);
			cout <<"\n Non Recursive: ";
			b.nrecPreorder();
			
			cout <<"\n INORDER : \n";
			cout <<"\n Recursive : ";
			b.Inorder(b.root);
			cout <<"\n Non Recursive: ";
			b.nrecInorder();
			
			cout<<"\n POSTORDER : \n";
			cout<<"\n Recursive : ";
			b.Postorder(b.root);
			cout << "\n Non Recursive: ";
			b.nrecPostorder();
			}
			break;
			
		default:
			cout << "Invalid choice\n";
		}
		cout << "\nWould u like to continue ?\nEnter '0' to exit : ";
		cin >> ans;
	} while (ans != 0);

}
