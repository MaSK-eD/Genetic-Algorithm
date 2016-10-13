#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

#define n 7		//defining the  bit size of population
#define probability 0.5

int main ()
{
	int p[n], r[2][n];
	int i, x, j;
	int z [n];
	
	srand(time(NULL));
	for( i = 0 ; i < n ; i++)
	{
		p[i] = 32;
		printf("%d ",p[i]) ;
	}
	
	printf("\n");
	for( i = 0 ; i < n ; i++)
	{
		for (j = 0; j < 2; j++)
		{
			r[i][j] = rand()%63 ;
			
			printf("%d ",r[i][j]);
		}
	}

	for (i=0; i<n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (p[i] >= r[i][j])
			{
				z [i][j] = 1 ;

			}

			if (p[i] < r[i][j])
			{
				z [i][j] = 0 ;
			}
				printf ("%d ", z[i][j]) ;
		}
	}
}





