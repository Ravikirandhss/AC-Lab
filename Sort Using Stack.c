#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
int stack[MAX],temp[MAX];
int top=-1,top2=-1;
int isFull()
{
	return top==MAX-1;
}
int isFull2()
{
	return top2==MAX-1;
}
int isEmpty()
{
	return top==-1;
}
int isEmpty2()
{
	return top2==-1;
}
void push(int x)
{
	if(isFull())
	{
		printf("Stack OverFlow\n");
		exit(0);
	}
	top++;
	stack[top]=x;
}
void push2(int x)
{
	if(isFull2())
	{
		printf("Stack 2 OverFlow\n");
		exit(0);
	}
	top2++;
	temp[top2]=x;
}
int pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	return stack[top--];
}
int pop2()
{
	if(isEmpty2())
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	return temp[top2--];
}
int peek()
{
	return stack[top];
}
void Sortpush(int x)
{
	int n;
	while(!isEmpty() && peek()>=x)
	{
		n=pop();
		push2(n);
	}
	push(x);
	while(!isEmpty2())
	{
		n=pop2();
		push(n);
	}
}
int main()
{
	int n;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	int arr[n],i;
	printf("Enter Elements to Array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		Sortpush(arr[i]);
	}
	for(i=n-1;i>=0;i--)
	{
		arr[i]=pop();
	}
	printf("Sorted Order:");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}
