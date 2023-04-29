#include<stdio.h>
#include<stdlib.h>
int alloc[10][10],pr[10],need[10][10],max[10][10],r,p,i,j,flag=0;
int proc,n,pno,m,Request[100],work[100],Avail[10],Finish[10],Safe[10];
void allocation();
void NEED();
void MAX();
void accept_req();
int compare_need(int p);
void safety_algo();

int main()
{
	printf("Enter number of process:");
	scanf("%d",&p);
	printf("\nEnter number of resources:");
	scanf("%d",&r);

	printf("Enter Allocations");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("Enter Allocations [%d][%d]",i,j);
			scanf("%d",&alloc[i][j]);
		}
	}

	printf("Enter MAX");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("Enter MAX [%d][%d]",i,j);
			scanf("%d",&max[i][j]);
		}
	}
	int c;
	while(1)
	{
	printf("                MENU              \n1.Display allocation\n2.Display max\n3.Display need\n4.Accept Request\n5.Saftey Algo\n6.Compare_need\n7.Exit\n");
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

			case 4:accept_req();
			       break;

			case 5:safety_algo();
			       break;

			case 6:compare_need(p);
			       break;
		
			case 7:exit(0);
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
	printf("Need Matrix is ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
}

void accept_req()
{
	int i;
	printf("\n Enter number of Process: ");
	scanf("%d",&proc);
	for(i=0;i<m;i++)
	{
		printf("\nEnter Request: ");
		scanf("%d",&Request[i]);
	}
}


int compare_need(int p)
{
	int i,j,flag=0;
	for(j=0;j<r;j++)
	{
		if(need[p][j]>work[j])
		{
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
			return p;
		}
		return -1;
}

void safety_algo()
{
	int over=0,k,l=0;
	for(i=0;i<r;i++)
	{
		work[i]=Avail[i];

		while(!over)
		{
			for(i=0;i<n;i++)
			{
				if(Finish[i]==0)
				{
					flag=0;
					pno=compare_need(i);
					if(pno>-1)
						break;
				}
			}
			if(i==n)
			{
				printf("System is unsafe");
				exit(1);
			}

			if(i<n && pno>=0)
			{
				for(k=0;k<m;k++)
					work[k]+=alloc[pno][k];

				Finish[pno]=1;
				Safe[l++]=pno;

				if(l>=n)
				{
					printf("\n Safe sequence is: ");

					for(l=0;l<n;l++)
						printf("P%d\t",Safe[l]);
					over=1;
				}
			}
		}
	}
}




