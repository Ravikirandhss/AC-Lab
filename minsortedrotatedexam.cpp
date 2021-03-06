//Min element in a sorted rotated array
#include<stdio.h>
int main()
{
	int a[8]={14,16,18,19,1,2,3,4},i=0;
	while(i<7)
	{
		if(a[i]>a[i+1])
            {
			printf("%d is the min element",a[i+1]);
            break;
			}
			i++;
	}
	
}


