#include<stdio.h>
#include<stdlib.h>
int alloc[10][10],pr[10],need[10][10],a[10],max[10][10],r,p,i,j;
void allocation();
void NEED();
void MAX();
void avai();
int main()
{
	printf("Enter number of process:");
	scanf("%d",&p);
	printf("\nEnter number of resources:");
	scanf("%d",&r);
	printf("\nEnter avilable:");
	for(i=0;i<r;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter allocation");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("Enter allocation for alloc[%d][%d]:\t",i,j);
			scanf("%d",&alloc[i][j]);
		}
	}

	printf("Enter MAX");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("Enter MAX values for max[%d][%d]:\t",i,j);
			scanf("%d",&max[i][j]);
		}
	}
	int c;
	while(1)
	{
	printf("                MENU              \n1.Display allocation\n2.Display max\n3.Display need\n4.Available\n5.exit\n");
	printf("Enter your choice:");
	scanf("%d",&c);
	
		switch(c)
		{
			case 1:allocation();
				break;
		
			case 2:MAX();
				break;
		
			case 3:NEED();
				break;

			case 4:avai();
			       break;
		
			case 5:exit(0);
			       break;
		}

	}
}

void MAX()
{
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",max[i][j]);
		}
		printf("\n");
	}
}

void allocation()
{
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",alloc[i][j]);
		}
		printf("\n");
	}
}

void display()
{
	printf("Process\t\tAllocation\t Max\n");
	
	
	for(i=0;i<p;i++)
	{
		printf("P%d\t\t",i);

		for(j=0;j<r;j++)
		{
			printf("%d ",alloc[i][j]);
		}
		printf("\t\t");
		for(j=0;j<r;j++)
		{
			printf("%d ",max[i][j]);
		}
		printf("\n");

	}
}

void NEED()
{
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("Need Matrix\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
}

void avai()
{
	for(i=0;i<r;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
