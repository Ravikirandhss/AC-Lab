#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node *npt;
npt insertfront(npt root,int x)
{
	npt p=(npt)malloc(sizeof(struct node));
	p->data=x;
	p->link=root;
	return p;
}
void display(npt root)
{
	npt t;
	t=root;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->link;
	}
	printf("\n");
}
npt reverse(npt root)
{
	npt prev,next,current;
	prev=next=NULL;
	current=root;
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
	}
	return prev;
}
int main()
{
	npt root=NULL;
	root=insertfront(root,1);
	root=insertfront(root,2);
	root=insertfront(root,3);
	root=insertfront(root,4);
	root=insertfront(root,5);
	display(root);
	root=reverse(root);
	display(root);
}
