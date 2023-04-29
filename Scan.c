#include<stdio.h> 
#include<stdlib.h>
#define MAX 200
int i,head,n,req[MAX],thm,c,j,k,move,max[MAX],min[MAX]; 

void accept() 
{ 
	printf("Enter move value either Left or Right:  ");
	scanf("%c",&move);
	printf("Enter the total_cylinder\n");
	scanf("%d",&c); 
	printf("Enter the head of the cylinder\n"); 
	scanf("%d",&head); 
	printf("Enter the no.of request do you have\n"); 
	scanf("%d",&n); 
	for(i=0;i<n;i++) 
	{
		printf("Enter the %d th request\n",i+1); 
		scanf("%d",&req[i]); 
	}
} 
void sort()
{
	int l;
	for(i=0;i<n;i++)
	{
		if(req[i]>=head)
		{
			max[j++]=req[i];
		}
		else
		{
			min[k++]=req[i];
		}
	}
	for(i=0;i<j;i++)
	{
		for(int l=0;l<=j-i-1;l++)
		{
			if(max[l]>max[l+1])
			{
				int temp;
				temp=max[l];
				max[l]=max[l+1];
				max[l+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(int m=0;m<=k-i-1;m++)
		{
			if(min[m]<min[m+1])
			{
				int temp;
				temp=min[m];
				min[m]=min[m+1];
				min[m]=temp;
			}
		}
	}
}
void thmcal()
{
	int thm1;
	sort();
	if(move=='l')
	{
		thm1=head;
		thm=thm1+max[k-1];
	}
	else if(move=='r')
	{
		thm1=199-head;
		thm=thm1+(199-min[0]);
	}
	/*else
 		printf("\n invalid input");*/
	printf("***thm= %d",thm);
}
void display()
{
	printf("The Maximum is=");
	for(i=0;i<n;i++)
	{
		printf("%d\t",max[i]);
	}
	printf("The Minimum is=");
	for(i=0;i<n;i++)
	{
		printf("%d\t",min[i]);
	}
}
int main() 
{ 
	accept();
	thmcal();
	display();
	return 0; 
} 
