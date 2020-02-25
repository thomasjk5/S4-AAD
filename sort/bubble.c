#include<stdio.h>
#include<time.h>
#include<stdlib.h>
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
void main()
{
	FILE *fp;
	fp=fopen("bubble.dat","a");
	int a[10000],n,i;
	clock_t t1,t2;
	double m;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		//scanf("%d",&a[i]);
		a[i]=rand()%1000;
	}
	t1=clock();	
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
	bubble(a,n);
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\nThe time taken is %f",m);
	fprintf(fp,"%d\t%f\n",n,m);
	fclose(fp);
}
