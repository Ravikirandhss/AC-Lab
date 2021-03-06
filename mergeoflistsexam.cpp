#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node *npt;
npt insertend(npt root,int x)
{   
	npt t=(npt)malloc(sizeof(struct node));
	npt temp;
	t->next=NULL;
	t->data=x;
	if(root==NULL)
    	return t;
    temp=root;
    while(temp->next!=NULL)
    	temp=temp->next;
    temp->next=t;
    return root;
}
npt findmid(npt root)
{
	npt fast=root,slow=root;
	while(fast->next!=NULL &&((fast->next)->next)!=NULL)
	{
		fast=fast->next;
		fast=fast->next;
		slow=slow->next;	
	}
	return slow;
}
npt merge(npt l1,npt l2)
{
	npt newlist=NULL,temp;
	
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
    if(l1->data<=l2->data)
    {
    	temp=l1;
    	l1=l1->next;
	}
	else
	{
		temp=l2;
		l2=l2->next;
	}
	newlist=temp;
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->data<l2->data)
		{
			temp->next=l1;
			temp=l1;
			l1=l1->next;
		}
		else
		{
			temp->next=l2;
			temp=l2;
			l2=l2->next;
		}
	}
	if(l1==NULL) temp->next=l2;
	if(l2==NULL) temp->next=l1;
	return newlist;
}
npt mergesort(npt root)
{   npt mid,l1,l2,first,second;
	if(root==NULL||root->next==NULL)
		return root;
	mid=findmid(root);	
	l2=mid->next;
	mid->next=NULL;
	l1=root;
	first=mergesort(l1);
	second=mergesort(l2);
	return merge(first,second);		
}
void display(npt root)
{ npt temp=root;
	while(temp->next!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
	printf("\n%d",temp->data);
}
int main()
{
	int x,n,i;
	npt root=NULL;
	printf("Enter size:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		root=insertend(root,x);
	}	
	root=mergesort(root);
	printf("\nAfter sorting:");
	display(root);
}
