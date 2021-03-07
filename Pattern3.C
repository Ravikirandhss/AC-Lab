//pattern-3
#include<stdio.h>
int main()
{
	int i,j,n;
	printf("Enter n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=97;j<=96+i;j++)
		{
			printf("%c",j);
		}
		printf("\n");
		
	}
	return 0;
}
