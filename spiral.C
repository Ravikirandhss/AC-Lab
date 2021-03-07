//spiral program
#include<stdio.h>
int main()
{
	int m,n,i,j;
	printf("enter no.of rows:");
	scanf("%d",&m);
	printf("enter no.of cols");
	scanf("%d",&n);
	char a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]='Z';
		}
	}
	int top=0,bottom=m-1,left=0,right=n-1,dir=0;
	char val='A';
	
	while(top<=bottom && left<=right)
	{
		if(dir==0)
		{
			for(i=left;i<=right;i++)
			{
				a[top][i]=val;
				val=val+1;
			}
			top=top+1;
		}
		else if(dir==1)
		{
			for(i=top;i<=bottom;i++)
			{
				a[i][right]=val;
				val+=1;
			}
			right=right-1;
		}
		else if(dir==2)
		{
			for(i=right;i>=left;i--)
			{
				a[bottom][i]=val;
				val=val+1;
			}
			bottom=bottom-1;
		}
		else if(dir==3)
		{
			for(i=bottom;i>=top;i--)
			{
				a[i][left]=val;
				val+=1;
			}
			left=left+1;
		}
		dir=(dir+1)%4;
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
		
}
