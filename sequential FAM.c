#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void show_bitvector();
int search(char *);
void show_directory();
void create_file();
void delete_file();
struct FAT
{
	char fname[20];
	int ib;
	int nob;
	struct FAT *next;
}*head=NULL;

int *bitvector,total_block;

int main()
{
	int i,ch;
	printf("\n Enter no of blocks: ");
	scanf("%d",&total_block);

	bitvector=(int *)malloc(total_block*(sizeof(int)));
	for(i=0;i<total_block;i++)
	{
		bitvector[i]=0;
	}

	while(1)
	{
		printf("\n*************MENU***********\n");
		printf("\n1.Show bit vector\n2.Create new file\n3.Show directory\n4.Delete the file\n5.Exit\n");
		printf("\nEnter the choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				show_bitvector();
				break;
			case 2:
				create_file();
				break;
			case 3:
				show_directory();
				break;
			case 4:
				delete_file();
				break;
			case 5:
				exit(0);
			default:
				printf("wrong choice\n");
		}
	}
}
void show_bitvector()
{
	int i;
	for(i=0;i<total_block;i++)
	{
		printf("%d\t",bitvector[i]);
	}
}
int search(char f[20])
{
	int c=1;
	struct FAT*temp;
	for(temp=head;temp!=NULL;temp=temp->next,c++)
	{
		if(strcmp(f,temp->fname)==0)
		{
			return c;
		}
	}
	return -1;
}
void create_file()
{
	struct FAT*temp,*NN;
	char f[20];
	int size,x,i,j,k,free=0;
	printf("Enter the file name: \n");
	scanf("%s",f);
	printf("Enter the size of file : \n");
	scanf("%d",&size);

	x=search(f);
	if(x!=-1)
	{
		printf("~The file already exists~\n");
		return;
	}

	for(i=0;i<total_block;i++)
	{
		free=0;
		for(j=i;j<total_block;j++)
		{
			if(bitvector[j]==1)
			{
				break;
			}
			free++;
		}
		if(free>=size)
		{
			break;
		}
	}
	if(i==total_block)
	{
		printf("Insufficient memory to add the file\n");
		return;
	}
	for(k=i;k<size+i;k++)
	{
		bitvector[k]=1;
	}
	NN=(struct FAT*)malloc(sizeof(struct FAT));
	strcpy(NN->fname,f);
	NN->nob=size;
	NN->ib=i;
	NN->next=NULL;

	if(head==NULL)
	{
		head=NN;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=NN;
	}
	printf("File created successfully ! \n");
	show_bitvector();
}
void show_directory()
{
	struct FAT*temp;
	printf("\n***filee allocation table***\n");
	printf("\nFile name \tinitial block \tNo.of blocks allocated\n");

	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp==NULL)
		{
			printf("Directory is empty\n");
			return;
		}
		printf("\n%s\t\t %d \t\t %d\n",temp->fname,temp->ib,temp->nob);
	}
}
void delete_file()
{
	struct FAT*temp,*prev;
	char f[20];
	printf("enter the file name to be deleted\n");
	scanf("%s",f);
	int x,i,size,initial;
	x=search(f);
	if(x==-1)
	{
		printf("file not found\n");
		return;
	}
if(x==1)
{
	size=head->nob;
	initial=head->ib;
	temp=head;
	head=head->next;
	temp->next=NULL;
	free(temp);
}
else
{
	for(prev=head,i=1;i<x-1;i++,prev=prev->next);
	temp=prev->next;
	prev->next=temp->next;
	temp->next=NULL;
	size=temp->nob;
	initial=temp->ib;
	free(temp);

}
for(i=initial;i<size+initial;i++)
{
	bitvector[i]=0;
}
printf("File deleted successfully");
show_bitvector();
}

