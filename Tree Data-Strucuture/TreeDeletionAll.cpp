#include<iostream>
#include<malloc.h>
using namespace std;
struct Tree
{
	int data;
	Tree *left , *right ;        //inter-referential pointer
};
Tree *root , *temp , *ttemp , *p , *r , *s , *q;
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
 //deletion case 1:
 void del(int x)
 {
 	int t;
 	temp=root;
 	while(temp->data!=x)
 	{
 		ttemp=temp;
		 if(temp->data>x)
		   temp=temp->left;
		 else
		   temp=temp->right;	
	}
	//case 4
	//r=temp;
	if(temp->left!=NULL && temp->right!=NULL)
	{
		p=temp->right;
		while(p->left!=NULL)
		{
			q=p;
			p=p->left;
		}
		t=temp->data;
		temp->data=p->data;
		p->data=t;
		temp=p;
	}
	
	//case 2 
	if(temp->left==NULL && temp->right!=NULL)
	{
//		s=temp->right;
//		q->left =s;
//		temp->right=NULL;
		//free(temp);
		s=temp->right;
		ttemp->left=s;
	}
	//case 3
	if(temp->left!=NULL &&  temp->right==NULL)
	{
		s=temp->left;
	    ttemp->right=s;
		//temp->left=NULL;
	}
	
	if(temp->left==NULL && temp->right==NULL)
	{
		if(ttemp->data >temp->data)
		 ttemp->left=NULL;
		else
		  ttemp->right=NULL;
	}
	free(temp);
	
	
 }
////void display using preorder
//void preorder(Tree *p)
//{
//	if(p!=NULL)
//	{
//		cout<<"\n"<<p->data;
//		preorder(p->left);
//		preorder(p->right);
//	}
//}

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
//void postorder(Tree *p)
//{
//	if(p!=NULL)
//	{
//		postorder(p->left);
//		postorder(p->right);
//		cout<<"\n"<<p->data;
//	}
//}
///driver code
int main()
{
	init();
	create_first(50);
	addnodes(30);
	addnodes(35);
	addnodes(70);
	addnodes(60);
	addnodes(20);
	addnodes(32);
	addnodes(75);
	addnodes(72);
	addnodes(74);
	addnodes(80);
	addnodes(90);
	//cout<<" Preorder Traversal\n";
	//preorder(root);
	cout<<"\n Inorder Traversal\n";
	inorder(root);
	cout<<"\n after deletion \n";
	del(80);
	inorder(root);
	//cout<<"\n Postorder Traversal\n";
	//postorder(root);
}
