#include<stdio.h>
void evenoddinsertion(int a[],int n)
{
int i,j,t;
for(i=2;i<n;i++)
{
j=i-2;
t=a[i];
if(i%2==0)
{
while(t<=a[j] && j>=0)
{
a[j+2]=a[j];
j-=2;
}
a[j+2]=t;
}
else
{
while(t>=a[j] && j>=0)
{
a[j+2]=a[j];
j-=2;
}
a[j+2]=t;
}
}
}
int main()
{
int a[183],i,n;
printf("Enter n:\n");
scanf("%d",&n);
printf("Enter elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Array:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
 printf("\n");
 evenoddinsertion(a,n);
 printf("After Performing Operation:\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",a[i]);
 }
}
