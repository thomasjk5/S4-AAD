#include<stdio.h>
#include<time.h>
#include<malloc.h>
int m;
struct node
{
	int data;
	struct node *next;
}*top=NULL,*temp,*head,*n;
void ins()
{
	int a;
	//printf("Enter data:");
	//scanf("%d",&a);
	temp=(struct node*)malloc(sizeof(struct node));
	for(int i=0;i<9999;i++)
	{
		temp->data=i;
		temp->next=NULL;
		if(top==NULL)
		{
			top=temp;
			head=top;
		}
		else
			top->next=temp;
		top=top->next;
	}
}
void del()
{
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==m)
		{
			temp=temp->next;
			free(temp);
			break;
		}
		else
			temp=temp->next;
	}
}
void check()
{
	int l;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==m)
		{
			l=temp->data;
			temp=temp->next;
			n=temp->data;
			if(n>l)
			{
				l=n;
				break;
			}
		}
	}
}
void disp()
{
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}
void main()
{
	int ch;
	ins();
	printf("1.delete\n2.check large no\nEnter the choice:");
	scanf("%d",&ch);
	printf("Enter the no:");
	scanf("%d",&m);
	switch(ch)
	{
		case 1:	del();
			break;
		case 2:	check();
			break;
	}
	disp();
}	
