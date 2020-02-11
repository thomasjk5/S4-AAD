#include<stdio.h>
#include<time.h>
void main()
{
	clock_t t1,t2;
	t1=clock();
	int a[100000],i,c,p,max;
        double n,m;
	printf("Enter the Number of Elements :");
	scanf("%d",&n);
	n=99999;
	for(i=0;i<n;i++)
	  a[i]=rand()%10000;
	printf("The arrays is :");
	for(i=0;i<n;i++)
	  printf("%d ",a[i]); 
	while(1)
	{
		printf("\n**** MENU ****");
		printf("\n1.Remove i\n2.Next i\n3.Exit\nEnter Your Choice :");
		scanf("%d",&c); 
		if(c==1)
		{
			printf("Enter the Index position :");
			scanf("%d",&p);
			for(i=p;i<n;i++)
			 a[i]=a[i+1];
			n--;
			printf("Now the array is :");
			for(i=0;i<n;i++)
			  printf("%d ",a[i]);
                        printf("\n");
		}
		if(c==2)
		{
			
			printf("Enter the Index position :");
			scanf("%d",&p);
                        max=a[p];
		 	for(i=p;i<n;i++)
                            if(max<a[i])
                              max=a[i];
			 printf("Largest element is :%d",max);
			
		}
		if(c==3)
		 break;
	
	}
	
	t2=clock();
	
	m=t2-t1;
        m=m/(double)CLOCKS_PER_SEC;
	printf("Time taken=%f",m);
}
	
	
	
	
	
	  

