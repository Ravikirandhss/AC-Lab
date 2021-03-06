#include<stdio.h>
#define MAX 15
int q[20],s[20];
int top=-1,front=-1,rear=-1;
int isqempty()
{
	if(front==rear) return 1;
    else return 0;
}
int issempty()
{
	if(top==-1) return 1;
	else return 0;
}
void push(int x)
{
	s[++top]=x;
}
int pop()
{
	return s[top--];
}
void enq(int x)
{
	q[++rear]=x;
}
int deq()
{
	return q[++front];
}
int main()
{
	int n,i,x;
	printf("Enter size:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		enq(x);
	}
	while(!isqempty())
	   push(deq());
    front=-1,rear=-1;
    while(!issempty())
        enq(pop());
    printf("\nElements after reversing queue:");
    while(!isqempty())
	   printf("\n%d",deq());
    
}
