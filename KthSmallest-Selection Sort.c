#include<stdio.h>
int kthSmallest(int arr[],int n,int k)
{
	int i,j,minpos,min,c=0,t;
	for(i=0;i<n&&c<k;i++,c++)
	{
		minpos=i;
		min=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];
				minpos=j;
			}
		}
		t=arr[i];
		arr[i]=arr[minpos];
		arr[minpos]=t;
	}
	return arr[k-1];
}
int main()
{
	int n,i,res,k;
	printf("Enter No of Values:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter Values into Array:");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("Enter value of k:");
	scanf("%d",&k);
	res=kthSmallest(arr,n,k);
	printf("kth smallest is %d\n",res);
}
