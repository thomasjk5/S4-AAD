#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void linear(int a[],int n)
{
  int search,i;
printf("\nEnter the number to be searched :");
scanf("%d",&search);
  for(i=0;i<n;i++)
  {
    if(a[i]==search)
    {
printf("****SUCCESSFUL SEARCH****\n");
printf("%d is present at location %d\n", search,i+1);
    break;
    }
}
  if(i==n)
    printf("Element not found\n");
}			
void main()
{
	FILE *fp;
	fp=fopen("linear.dat","a");
	int a[10000],n,i;
	clock_t t1,t2;
	double m;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	t1=clock();	
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
	linear(a,n);
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\nThe time taken is %f",m);
	fprintf(fp,"%d\t%f\n",n,m);
	fclose(fp);
}
	
