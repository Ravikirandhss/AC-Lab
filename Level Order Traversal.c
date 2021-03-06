#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
int queue[MAX];
struct tree
{
	int data;
	struct tree *left, *right;	
};
int q[10];
int first=0,last=0;
typedef struct tree *bst;
bst insertdata(bst root,int x)
{
	bst p=(bst)malloc(sizeof(struct tree));
	p->data=x;
	p->left=p->right=NULL;
	if(root==NULL)
	return p;
	bst current,parent;
	parent=current=root;
	while(current!=NULL)
	{
		parent=current;
		if(current->data>x)
		current=current->left;
		else if(x>current->data)
		current=current->right;
		else
		return root;
	}
	if(x<parent->data)
	parent->left=p;
	else if(parent->data<x)
	parent->right=p;
	return root;
}
void inorder(bst root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void qIn(int x)
{
	q[last++]=x;
}
int qPop()
{
	if(first==last)
	{
		return 0;
	}
	return q[first++];
}
void lvlOrder(bst root)
{
	if(root==NULL)
	{
 		return;
 	}
	if(root->left!=NULL)
 	{	
 		qIn(root->left->data);
 	}
	if(root->right!=NULL)
 	{
 		qIn(root->right->data);
 	}
	lvlOrder(root->left);
	lvlOrder(root->right);
}
void dispLvlOrder()
{
	int x;
	printf("\n Level Order: \n");
	while(1)
 	{
 		x=qPop();
 		if(x==0)
 		{
 			break;
 		}
 		else
 		{
 			printf("%d ",x);
 		}
	}
}
int main()
{
	bst root=NULL;
	root=insertdata(root,6);
	root=insertdata(root,3);
	root=insertdata(root,4);
	root=insertdata(root,2);
	root=insertdata(root,8);
	root=insertdata(root,7);
	root=insertdata(root,9);
	inorder(root);
	printf("\n");
	qIn(root->data);
	lvlOrder(root);
	dispLvlOrder();

}

