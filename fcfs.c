#include<stdio.h>
#include<stdlib.h>

int req[20],n,head,b,i,thm=0;
void accept()
{

	printf("\nEnter total number of cylinder = ");
	scanf("%d",&b);
	
	printf("\nEnter Current Head Position = ");
	scanf("%d",&head);
	
	printf("\nEnter Number of Request = ");
	scanf("%d",&n);
	
	printf("\nEnter Request in Sequence :");
	for(i=0;i<n;i++)
	{
		printf("\n%d=",i);
		scanf("%d",&req[i]);
	}
}
void display()
{
	printf("\nTotal head movements:\n %d",thm);
}
void fcfs()
{
	int m,i;
	for(int i=0;i<n;i++)
	{
		if(head<req[i])
		{
			m=req[i]-head;
			thm=thm+m;
			head=req[i];
		}
		else
		{
			m=head-req[i];
			thm=thm+m;
			head=req[i];
		}
	}
}

void main()
{
	accept();
	fcfs();
	display();
}

