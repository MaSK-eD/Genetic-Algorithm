#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main ()
{
	int n, m ;
	printf ("Enter the size of parents: \n") ;
	scanf ("%d\t%d", &n, &m) ;
	int a[n][m], b[n][m];		//defining parents
	int temp1[n][m], temp2[n][m], swap[n][m], real[n][m], sum[n][m];		//storing the value of parents in temporary variables
	int temp ;
	int i, j, k, l ;		//here assuming k is row and i is column
	int x, y, z ;
     int random[m] ;		//defining variable for random value generation
    srand(time(NULL));
//defining the size of parents
//GENERATING RANDOM PARENTS A
// putting numbers from 1 to 10 into the 'numbers' array
    for(i = 0; i < m; i++)
        random[i] = i + 1;
// shuffling using Fisher-Yates shuffle algorithm
	for(k = 0; k < n; k++)
	{	
		for(i = m-1; i >= 0; i--)
		{
			// very important: pick a random number from 1 to i
			j = rand() % (i+1);
			// swapping two random
			temp = random[i];
			random[i] = random[j];
			random[j] = temp;
			a[k][i] = random [i];
		}
	}
	printf ("THE VALUE OF PARENT A IS: \n") ;
	for(k = 0; k < n; k++)
	{	
		for(i = 0; i < m; i++)
		{	
			printf("%d ", a[k][i]);
		}
	}
	printf ("\n") ;
//temporarily storing values of parents A
	for(k = 0; k < n; k++)
	{	
		for(i = 0; i< m; i++)
		{	
			temp1[k][i] = a[k][i];
		}
	}	
//GENERATING RANDOM PARENTS B	
	for(i = 0; i < m; i++)
    	random[i] = i + 1;
	for(k = 0; k < n; k++)
	{	
		for(i = m-1; i >= 0; i--)
		{
			j = rand() % (i+1);
			temp = random[i];
			random[i] = random[j];
			random[j] = temp;
			b[k][i] = random [i];
		}
	}
	printf ("THE VALUE OF PARENT B IS: \n") ;
	for(k = 0; k < n; k++)
	{	
		for(i = 0; i < m; i++)
		{	
			printf("%d ", b[k][i]);
		}
	}	
	printf ("\n") ;
//temporarily storing values of parents A
	for(k = 0; k < n; k++)
	{	
		for(i = 0; i < m; i++)
		{	
			temp2[k][i] = b[k][i];
		}
	}	

//BEGINING OF PMA
//selecting the point for crossover
	printf ("Enter the starting and ending point for crossover: \n") ;
	scanf ("%d\t %d", &x, &y) ;
//swapping the values for pma
	for (k = 0; k < n; k++)
	{
		for (i = x; i < y; i++)
		{
			swap[k][i] = a[k][i] ;
			a[k][i] = b[k][i] ;
			b[k][i] = swap[k][i] ;
		}
	}
	printf ("\n") ;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < m; i++)
		{
			printf ("%d ", a[k][i]) ;
		}
	}
	printf ("\n") ;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < m; i++)
		{
			printf ("%d ", b[k][i]) ;
		}
	}
	printf ("\n") ;
	
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < m; i++)
		{
		

	for (i = 0; i < m; i++)
	{
		for (k = 0; k < n; k++)
		{
			if (a[k][i] == a[1][3] || a[1][4] || a[1][5]|| a[1][6])
				{
					if (b[k][i] == a[1][3] || a[1][4] || a[1][5]|| a[1][6])
						{
							
		}
	}		
}
	
