#include<stdio.h>
#include<stdlib.h>

int req[20],n,head,b,i,thm,flag[10]={0};
void accept()
{

	printf("\nEnter total number of cylinder = ");
	scanf("%d",&b);
	
	printf("\nEnter Current Head Position = ");
	scanf("%d",&head);
	
	printf("\nEnter Number of Request = ");
	scanf("%d",&n);
	
	printf("\nEnter Request in Sequence :");
	for(i=1;i<n+1;i++)
	{
		printf("\n%d=",i);
		scanf("%d",&req[i]);
	}
}
void display()
{
	printf("\nTotal head movements:\n %d",thm);
}
int diff()
{
	int i,d[20]={-1},min=32546,index,indexd,cnt=0;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			if(req[i]>head)
				d[i]=req[i]-head;
		}
	}
	for(i=0;i<n;i++){
		if(d[i]<min && flag[i]==0)
		{
			min=d[i];
			index=i;
		}
	}
	for(i=0;i<n;i++)
	{
		if(d[i]==min)
		{
			cnt++;
			indexd=i;
		}
	}
	if(cnt==1)
		return index;
	else{
		if(req[index]>req[indexd])
			return index;

		else 
			return indexd;
	}
}

int sstf()
{
	int i,index,m;
	for(i=0;i<n;i++)
	{
		index=diff(head);
		if(head>req[index])
		{
			m=head-req[index];
			thm=thm+m;
		}
		else
		{
			m=req[index]-head;
			thm=thm+m;
		}
		head=req[index];
		flag[index]=1;
	}
	printf("\n");
	printf("Total Head Movement = %d ",thm);
}

void main()
{
	accept();
	sstf();
	display();
}
