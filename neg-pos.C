#include<stdio.h>
#include<stdlib.h>
int main()
{
int a[183],i,j,n,key;
printf("Enter n:");
scanf("%d",&n);
printf("Enter elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
	if(a[i]<0)
	{
		printf("%d",a[i]);
		printf("\n");
	}	
}

for(i=0;i<n;i++)
{
	if(a[i]>0)
	{
		printf("%d",a[i]);
		printf("\n");
	}
}
}
