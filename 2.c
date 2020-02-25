
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double h;
struct node
{
    int data;
    struct node* next;
}*list=NULL,*temp,*p,*back;

typedef struct node NODE;

void insert(int item)
{
temp=(NODE*)malloc(sizeof(NODE));
temp->data=item;
if(list==NULL)
{
temp->next=NULL;
list=temp;
}
else
{
p=list;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
temp->next=NULL;
}
}

void remove()
{
int item,search;
printf("Enter the Element: ");
scanf("%d",&search);
back=list;
p=list->next;
if(list->data==search)
{
   temp=list;
   list=list->next;
   free(temp);
}
else
{
   while(p->next!=NULL&&p->data!=search)
     {
       back=back->next;
       p=p->next;
     }
       back->next=p->next;
       free(p);
}
}


void display()
{
if(list==NULL)
    printf("List is empty");
else
{
for(p=list;p!=NULL;p=p->next)
    printf("%d\t",p->data);
}
}


int main()
{
int i,c,n,k,item,m;
clock_t t1,t2;
printf("Enter the Number of Elements :");
scanf("%d",&n);
for(i=0;i<n;i++)   
{

insert(rand()%100);
}
printf("THe Elements are:\n");
display();
while(1)
{
t1=clock();
printf("\n****MENU****\n1.Remove\n2.Next largest\n3.Exit\nEnter Your Choice :");
scanf("%d",&c);
   
if(c==1)
{       
remove();
printf("AFTER REMOVING:\n");
display();
}
if(c==2)
{
  p=list;
  printf("Enter the Element :");
  scanf("%d",&item);
  while(p->next!=NULL&&p->data!=item)
    p=p->next;
        if(p->next!=NULL)
        {
        while(p->data<=item)
            p=p->next;
        printf("%d is largest element",p->data);
        }
        else
            printf("No larger element");
    }
if(c==3)
break;


}
t2=clock();
h=(t2-t1)/(double)CLOCKS_PER_SEC;
printf("\nTime:%f\n",h);

}

