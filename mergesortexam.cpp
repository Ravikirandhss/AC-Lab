#include<stdio.h>
int a[100];
void mergesort(int l,int h);
void merge(int si,int mi,int ei)
{
int i=si,j=mi+1,k=0,c[100];
while(i<=mi&&j<=ei)	
{
	if(a[i]<a[j])
		c[k++]=a[i++];
	else
		c[k++]=a[j++];
}
	while(i<=mi)
		c[k++]=a[i++];	
	while(j<=ei)
		c[k++]=a[j++];
	i=si;
	k=0;
	while(i<=ei)
		a[i++]=c[k++];
}

void mergesort(int l,int h){
    if(l>=h){
        return;
    }
    int m=(l+h)/2;
    mergesort(l,m);
    mergesort(m+1,h);
    merge(l,m,h);
}
int main()
{
	int i,j,n,t;
	printf("Enter size:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nSorted Array:");
	mergesort(0,n-1);
	for(i=0;i<n;i++)
	   printf("\n%d",a[i]);
}
