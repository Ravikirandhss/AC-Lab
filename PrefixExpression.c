#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
int stack[MAX];
int top=-1;
int isFull()
{
	return top==MAX-1;
}
int isEmpty()
{
	return top==-1;
}
int isOperator(char ch)
{
	return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
}
int power(int a,int b)
{
	if(b==0)
	return 1;
	return a*power(a,b-1);
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
int pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	return stack[top--];
}
int main()
{
	char s[MAX];
	printf("Enter Prefix Expression:");
	gets(s);
	int i,j,k,op1,op2,res;
	i=strlen(s)-1;
	while(i>=0)
	{
		if(isalnum(s[i]))
		{
			push(s[i]-'0');
		}
		else if(isOperator(s[i]))
		{
			switch(s[i])
			{
				case '+':
					op1=pop();
					op2=pop();
					res=op1+op2;
					break;
				case '-':
					op1=pop();
					op2=pop();
					res=op1-op2;
					break;
				case '*':
					op1=pop();
					op2=pop();
					res=op1*op2;
					break;
				case '/':
					op1=pop();
					op2=pop();
					res=op1/op2;
					break;
				case '^':
					op1=pop();
					op2=pop();
					res=power(op1,op2);
					break;	
			}
			push(res);
		}
		else
		{
			printf("Invalid Expression\n");
			break;
		}
		i--;
	}
	if(top!=0)
	{
		printf("Invalid Prefix Expression");
	}
	else
	{
		printf("Result = %d",pop());
	}
}
