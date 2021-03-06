#include<iostream>
#define MAX 10000
using namespace std;
template<class T>
class stack
{
	int top;
	T arr[MAX];
	public:
		stack()
		{
			top=-1;
		}
		int isFull()
		{
			return top==MAX-1;
		}
		int isEmpty()
		{
			return top==-1;
		}
		void push(T x)
		{
			if(!isFull())
			 arr[++top]=x;
		}
		T pop()
		{
			if(!isEmpty())
			   return arr[top--];
		}
};
int main()
{
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<"Elements in integer stack are:\n";
	while(!s.isEmpty())
	      cout<<s.pop()<<endl;
	stack<float>f;
	f.push(1.5);
	f.push(1.3);
	f.push(2.5);
	cout<<"Elements in float stack are:\n";
	while(!f.isEmpty())
	      cout<<f.pop()<<endl;
	
}
