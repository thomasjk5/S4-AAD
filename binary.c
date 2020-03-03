#include<stdio.h>
#include<time.h>
void bubble(int a[],int n)
{	
	int temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	printf("\nArray after sorting.\n\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void binary(int a[],int n)
{
int i,l,u,mid,search;
bubble(a,n);
   printf("\nEnter element to find :");
   scanf("%d",&search);
   l=0;
   u=n-1;
   mid=(l+u)/2;
   while(l<=u) 
   {
      if(a[mid]<search)
         l=mid+1;   
      else if(a[mid]==search)
	   {
	 printf("\n****SUCCESSFUL SEARCH****\n");
         printf("\n%d found at location %d\n",search,mid+1);
         break;
      }
      else
         u=mid-1;
         
      mid=(l+u)/2;
   }
   if(l>u)
      printf("\nElement not found\n"); 
}

void main()
{
	FILE *fp;
	fp=fopen("binary.dat","a");
	int a[10000],n,i;
	clock_t t1,t2;
	double m;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%1000;
	}
	t1=clock();	
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
	binary(a,n);
        bubble(a,n);
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\nThe time taken is %f",m);
	fprintf(fp,"%d\t%f\n",n,m);
	fclose(fp);
}
