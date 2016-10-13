#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	int j,k,l;
	int s=1;
	int st=4;
	float m[100],large=0;
	
	for (l=1;l<100;l++)
	{
		m[l]=rand()%100;
		printf("%f \n",m[l]);
	}
	
	//m[0]=0;
	j=rand()%100;

	for (k=1;k<100;k++)
	{
		
		if(m[j]>=m[j+s])
		{
			j=j+s;
			s=s+st;
			large=m[j];
		}
		else if(m[j]<m[j-s])
		{
			j=j-s;
			s=s-st;
			large=m[j];
		}
	}
	printf("Final Value is %f",large);
}