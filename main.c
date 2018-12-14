#include<stdlib.h>
#include<stdio.h>


int main()
{
	int i;
	int j;
	/**********/
	
	for(j=0;j<=9;j++)
	{
		printf("  %d",j);
	}
	printf("\n");
	

	for(i=9;i>=0;i--)
	{	printf("%d ",i);
		
		
		if(i==4 || i==5)
			for(j=0;j<=9;j++)
			{
				if((j+i)%2==0)
					printf("   ");
				else
					printf(".  ");
			
			}
			
		if(i==0 || i==1 || i==2 || i==3)
			for(j=0;j<=9;j++)
			{
				if((j+i)%2==0)
				{
					printf("   ");
				}
				else
				{
					printf("P  ");
				}
		
			}
			
		if(i==6 || i==7 || i==8 || i==9)
			for(j=0;j<=9;j++)
			{	
				if((j+i)%2==0)
				{
					printf("   ");
				}
				else 
				{
					printf("p  ");
				}	
		
			}
		
		printf("\n");
	}
}

