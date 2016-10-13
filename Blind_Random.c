#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int k,l; 
	float p=0;
	float n[100];
	
	/*printf("Enter number of data to be entered");
	scanf("%d",&i);
	
	printf("Enter dat a");

	for(j=1;j<=i;j++)
	{
		scanf("%f",&m[j]);
	}
	*/
	/* SAVING RANDOM NUMBER TO AN ARRAY */
	for (l=1;l<100;l++)
	{
		n[l]=rand()%100;
		printf("%f \n",n[l]);
	}

	/* SELECTING RANDOM NUMBER FROM DATA */
	
	for(k=1;k<100;k++)
	{
		int x = rand()%10;
		if(n[x]>p)
		{
			p=n[x];
		}
	}
	printf("The maximum number from the data with blind random number is %f",p);
	
}

	
