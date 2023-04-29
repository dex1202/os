#include<mpi.h>
#include<stdio.h>
#include<string.h>

const int MAX_STRING=1000;
int main(int argc,char**argv)
{
	char greeting[MAX_STRING];
	int comm_size;
	int sum=0,a[1000];
	int comm_rank;
	int i;
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,& comm_size);
	MPI_Comm_rank(MPI_COMM_WORLD,& comm_rank);
	if(comm_rank!=0)
	{
		for(i=0;i<1000;i++)
		{
			a[i]=rand()%10;
		}
		for(i=0;i<1000;i++)
		{
			sum=sum+a[i];
		}
		sprintf(greeting,"Sum of the random 1000 number from process %d of %d is equals to %d!",comm_rank,comm_size,sum);
		MPI_Send(greeting,strlen(greeting)+1,MPI_CHAR,0,0,MPI_COMM_WORLD);
	}
		else
		{
			printf("\nGreetings from process %d of %d\n",comm_rank,comm_size);
			for(i=1;i<comm_size;i++)
			{
				MPI_Recv(greeting,MAX_STRING,MPI_CHAR,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				printf("\n%s\n",greeting);
			}
		}
		MPI_Finalize();
	
}
