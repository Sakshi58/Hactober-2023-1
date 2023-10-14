#include<iostream>
#include<malloc.h>
using namespace std;
struct Tree
{
	int data;
	Tree *left , *right ;        //inter-referential pointer
};
Tree *root , *temp , *ttemp , *p;
//initialization
void init()
{
	root=temp=ttemp=p=NULL;
}

//creating the first node
void create_first(int x)
{
	root=(Tree *)malloc(sizeof(Tree));
	root->data = x;
	root->left=NULL;
	root->right=NULL;
}

///adding other nodes
void addnodes(int x)
{
	temp=root;
	while(temp!=NULL)
	{
		ttemp=temp;
		if(temp->data > x)
		  temp=temp->left;
		else
		  temp=temp->right;
	}
	p=(Tree *)malloc(sizeof(Tree));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	
	///joining the nodes
	if(ttemp->data > x)
	  ttemp->left = p;
	else
	  ttemp->right = p;
}

////level of the node
void level(int x)
{
	temp=root;
	int v=0;         ///counting the visit i.e. level
	while(temp->data!=x)
	{
		if(temp->data > x)
		 {
		 	temp=temp->left;
		 	v++;
		} 
		  else
		  {
		  	temp=temp->right;
		  	v++;
		  }
		  
	}
	cout<<"\n\nlevel of "<<x<<" is "<<v;
	
}
//void display using preorder
void preorder(Tree *p)
{
	if(p!=NULL)
	{
		cout<<"\n"<<p->data;
		preorder(p->left);
		preorder(p->right);
	}
}

////display using inorder
void inorder(Tree *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<"\n"<<p->data;
		inorder(p->right);
	}
}

///Postorder traversal
void postorder(Tree *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<"\n"<<p->data;
	}
}
///driver code
int main()
{
	init();
	create_first(50);
	addnodes(30);
	addnodes(35);
	addnodes(70);
	addnodes(60);
	addnodes(32);
	addnodes(20);
	addnodes(90);
	addnodes(100);
	addnodes(55);
	addnodes(25);
	addnodes(33);
	addnodes(95);
	addnodes(96);
	//cout<<" Preorder Traversal\n";
	//preorder(root);
	cout<<"\n Inorder Traversal\n";
	inorder(root);
	//cout<<"\n Postorder Traversal\n";
	//postorder(root);
	level(96);
}
