#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *llink,*rlink;
};
typedef struct node *cpt;
cpt insertend(cpt root,int x)
{
	cpt p=(cpt)malloc(sizeof(struct node));
	p->data=x;
	if(root==NULL)
	{
		p->llink=p->rlink=p;
		return p;
	}
	cpt t=root;
	p->rlink=root;
	while(t->rlink!=root)
	{
		t=t->rlink;
	}
	t->rlink=p;
	p->llink=t;
	root->llink=p;
	return root;
}
cpt deletefront(cpt root)
{
	cpt t=root,t2;
	root=root->rlink;
	t2=root;
	while(t2->rlink!=t)
	{
		t2=t2->rlink;
	}
	t2->rlink=root;
	root->llink=t2;
	free(t);
	return root;
}
void displaymain(cpt root)
{
	cpt t=root;
	while(t->rlink!=root)
	{
		printf("%d ",t->data);
		t=t->rlink;
	}
	printf("%d\n",t->data);
}
void displayreverse(cpt root)
{
	cpt t=root->llink;
	while(t->llink!=root->llink)
	{
		printf("%d ",t->data);
		t=t->llink;
	}
	printf("%d\n",t->data);
}
int main()
{
	cpt root=NULL;
	root=insertend(root,1);
	root=insertend(root,2);
	root=insertend(root,3);
	root=insertend(root,4);
	displaymain(root);
	displayreverse(root);
	root=deletefront(root);
	displaymain(root);
	displayreverse(root);
}
