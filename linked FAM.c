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
	struct FAT *next;
}*head=NULL;
int *bitvector,total_block;
int main()
{
	int i,ch;
	printf("Enter no of blocks:");
	scanf("%d",&total_block);
	bitvector=(int *)malloc(total_block*(sizeof(int)));
	for(i=0;i<total_block;i++)
	{
		bitvector[i]=0;
	}
	while(1)
	{
		printf("\n***************MENU****************");
		printf("\n1. Show Bit\n2. Create new file\n3. Show Directory\n4. Delete File\n5. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: show_bitvector();
				break;
			case 2: create_file();
				break;
			case 3: show_directory();
				break;
			case 4: delete_file();
				break;
			case 5: exit(0);
			default: printf("Wrong choice\n");
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
	int size,x,i,j,k,initial,free1=0;
	printf("Enter the file name you want to create:\n");
	scanf("%s",f);
	printf("Enter the size of the file:\n");
	scanf("%d",&size);
	x=search(f);
	if(x!=-1)
	{
		printf("The file already exists\n");
		return;
	}
	for(i=0;i<total_block;i++)
	{
		if(bitvector[i]==0)
		{
			free1++;
		}
	}
	printf("\nFree size=%d",free1);
	if(free1<size+1)
	{
		printf("Insufficient memory to allocate the file\n");
		return;
	}
	for(i=0;i<total_block;i++)
	{
		if(bitvector[i]==0)
		{
			break;
		}
	}
	initial=i;
	for(j=i+1;j<total_block;j++)
	{
		if(bitvector[j]==0)
		{
			bitvector[i]=j;
			i=j;
			size--;
		}
		if(size==0)
		{
			bitvector[j]=-1;
			break;
		}
	}
	
	NN=(struct FAT*)malloc(sizeof(struct FAT));
	strcpy(NN->fname,f);
	NN->ib=initial;
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
	printf("File created Successfully\n");
	show_bitvector();
}
void show_directory()
{
	struct FAT*temp;
	printf("\n*****File Allocation Table*****\n");
	printf("\nFile name\tInitial Block");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp==NULL)
		{
			printf("Directory is empty\n");
			return;
		}
		printf("\n%s\t\t%d\n",temp->fname,temp->ib);
	}
}
void delete_file()
{
	struct FAT*temp,*prev;
	char f[20];
	printf("Enter the file name to delete:\n");
	scanf("%s",f);
	int x,i,initial;
	x=search(f);
	if(x==-1)
	{
		printf("File not found\n");
		return;
	}
	if(x==1)
	{;
		initial=head->ib;
		temp=head;
		head=head->next;
		temp->next=NULL;
		free(temp);
	}
	else
	{
		for(prev=head;i=1;i<x-1,i++,prev=prev->next);
		temp=prev->next;
		prev->next=temp->next;
		temp->next=NULL;
		initial=temp->ib;
		free(temp);
	}
	for(i=initial;i<total_block;)
	{
		x=bitvector[i];
		bitvector[i]=0;
		i=x;
		if(bitvector[i]==-1)
		{
			bitvector[i]=0;
			break;
		}
	}
	printf("File Deleted Successfully\n");
	show_bitvector();
}
