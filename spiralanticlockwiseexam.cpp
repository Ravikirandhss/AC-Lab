#include<stdio.h>
int main()
{
int top=0,bottom,left=0,right,n,i,j,dir=0,a[10][10];
printf("Enter n:");
scanf("%d",&n);
right=n-1;
bottom=n-1;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		scanf("%d",&a[i][j]);
	}
}
printf("Matrix of numbers inn spiral anticlockwiswe:\n");
while(top<=bottom&&left<=right)
{
if(dir==0)
{
for(i=top;i<=bottom;i++)
{
	printf("%d\t",a[i][left]);
}
left++;
}	
else if(dir==1)
{
for(i=left;i<=right;i++)
{
	printf("%d\t",a[bottom][i]);
}	
bottom--;	
}

else if(dir==2)
{
for(i=bottom;i>=top;i--)
{
	printf("%d\t",a[i][right]);
}	
right--;	
}	
else if(dir==3)
{
for(i=right;i>=left;i--)
{
	printf("%d\t",a[top][i]);
}	
top++;	
}
dir= (dir+1)%4;	
}
}
