#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertion(int a[],int n)
{
	
    	int j,t;
    	for(int i=0;i<=n;i++)
    	{
    		j=i;
    		while(j>0&&a[j-1]>a[j])
    		{
    			t=a[j];
    			a[j]=a[j-1];
    			a[j-1]=t;
    			j--;
    		}
    	}
    	for(int i=1;i<=n;i++)
    	{
     		printf("%d ",a[i]);
        	
    	}
}
void main()
{
	FILE *fp;
	fp=fopen("ins.dat","a");
	int a[10000],n,i;
	clock_t t1,t2;
	double m;
	printf("\nEnter the number of elements :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	t1=clock();	
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
	insertion(a,n);
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\nThe time taken is %f",m);
	fprintf(fp,"%d\t%f\n",n,m);
	fclose(fp);
	printf("\n");
}
