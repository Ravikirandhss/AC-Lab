#include<stdio.h>
int main()
{
int m,n,i,j,t;
printf("Enter row and columns of matrix: ");
scanf("%d%d",&m,&n);
int a[m][n],b[m][n];
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=i*n+j+1;
b[i][j]=i*n+j+1;
}
}
printf("Matrix after 270 degrees Rotation \n");
for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
 {
 if(i<=j)
 {
 t=a[i][j];
 a[i][j]=a[j][i];
 a[j][i]=t;
 }
 }
}
for(i=0;i<m/2;i++)
{
 for(j=0;j<n;j++)
 {
 t=a[i][j];
 a[i][j]=a[m-i-1][j];
 a[m-i-1][j]=t;
 }
}
 for(i=0;i<m;i++)
 {
 for(j=0;j<n;j++)
 {
 printf("%d\t",a[i][j]);
 }

 printf("\n");
 }
 printf("Matrix after 90 degrees Anti-Rotation \n");
 for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
 {
 if(i<=j)
 {
 t=b[i][j];
 b[i][j]=b[j][i];
 b[j][i]=t;
 }
 }
}
for(i=0;i<m/2;i++)
{
 for(j=0;j<n;j++)
 {
 t=b[i][j];
 b[i][j]=b[m-i-1][j];
 b[m-i-1][j]=t;
 }
}
 for(i=0;i<m;i++)
 {
 for(j=0;j<n;j++)
 {
 printf("%d\t",b[i][j]);
 }

 printf("\n");
 }
 for(i=0;i<m;i++)
 {
 for(j=0;j<n;j++)
 {
 if(a[i][j]==b[i][j])
 {
 continue;
 }
 else
 {
 printf("NO\n");
 }
 }
 }
 printf("EQUIVALENT\n");
return 0;
}
