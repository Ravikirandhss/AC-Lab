#include<stdlib.h>
#include<stdio.h>
void transpose(int N,int a[N][N])
{
	int i,j,t;
	
	for(i=0;i<N-1;i++)
		for(j=i+1;j<=N-1;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
}
void swapcolumns90_clockwise(int N,int a[N][N])
{
	int i,j1,j2,k,t;
	j1=0;
	j2=N-1;
	transpose(N,a);
	while(j1<j2)
	{
		for(i=0;i<=N-1;i++)
		{
			t=a[i][j1];
			a[i][j1]=a[i][j2];
			a[i][j2]=t;
		}
		j1++;j2--;
	}
}
void swapcolumns90_anticlockwise(int N,int a[N][N])
{
	int j,i1,i2,k,t;
	transpose(N,a);
	i1=0;
	i2=N-1;
	while(i1<i2)
	{
		for(j=0;j<=N-1;j++)
		{
			t=a[i1][j];
			a[i1][j]=a[i2][j];
			a[i2][j]=t;
		}
		i1++;i2--;
	}
}
void display(int N,int a[N][N])
{
	int i,j;
	for(i = 0; i < N; i++)
	{
	for(j = 0; j < N; j++)
	{
	printf("%d\t",a[i][j]);
	}
	printf("\n");
	}	
}
int check(int n,int a[n][n],int b[n][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=b[i][j])
			return 0;
		}
	}
	return 1;
}
int main()
{
int N;
printf("\nInput the N value for square matrix : ");
scanf("%d",&N);
int a[N][N],b[N][N];
int i,j;
printf("\nInput the matrix \n");
	for(i = 0; i < N; i++)
	{
	for(j = 0; j < N; j++)
	{
	scanf("%d",&a[i][j]);
	b[i][j]=a[i][j];
	}
	}
printf("\nOriginal Matrix:\n");
display(N,a);
printf("\n");
swapcolumns90_clockwise(N,a);
swapcolumns90_clockwise(N,a);
swapcolumns90_clockwise(N,a);
printf("\nMatrix after 270deg rotation clockwise:\n");
display(N,a);
swapcolumns90_anticlockwise(N,b);
printf("\nMatrix after 90deg rotation Anticlockwise:\n");
display(N,b);
int res=check(N,a,b);
if(res==1)
printf("Both are Equal");
else
printf("Both are not equal");
}
