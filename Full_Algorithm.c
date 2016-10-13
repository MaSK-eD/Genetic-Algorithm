#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define n 4
#define m 6
#define probability 0.002
#define G 5
//CROSSOVER PROBABILITY 1
// MUTATION PROBABILITY 1/64

int main()
{
	void clscr();
	int i,j;
	int r[n][m];
	float integer[100];
	float fit[100];
	int a; 
	int time_random;
/*	time_random = time(NULL);  //seeding rand. time
	if ( time_random%2 == 0 )
			time_random = time_random+1;
	srand(time_random);*/
	srand(time(NULL));
		
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0 ; j < m ; j++ )
		{
			r[i][j] = rand() % 2 ;
		}
	}
	printf( "First Data : \n" ) ;
	
	for ( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < m ; j++ )
		{
			printf("%d " , r[i][j]) ;
		}
		printf("\n") ;
	}

	//for ( a = 1 ; a < G ; a++ ) // NUMBER OF GENERATIONS TO BE CALCULATED
	//{
		// Calculating Integer Value of the binary number
	
		for ( i = 0 ; i < n ; i++ )
		{
			integer[i] = 0 ;
			for ( j = m-3 ; j > 0 ; j-- )
			{
				integer[i] = integer[i] + ( r[i][j] * ( 2 ^ ( m - 3 - j ) ) ) ;
			}
			//FOR POSITIVE AND NEGATIVE CASE. FIRST DIGIT IS TAKEN AS SIGN BIT
			if ( r[i][0] == 1 )
			{
				integer[i] = -integer[i] ;
			}
			//LAST 2 DIGITS ARE TAKEN AS DECIMAL. CONVERTING THIS INTO INTEGER WAS DONE. (MAY FIND SOMETHING EASIER)
			if ( r[i][m-2] == 0 && r[i][m-1] == 0 )
				integer[i] = integer[i] ;
			if ( r[i][m-2] == 0 && r[i][m-1] == 1 )
				integer[i] = integer[i] + 0.25 ;
			if ( r[i][m-2] == 1 && r[i][m-1] == 0 )
				integer[i] = integer[i] + 0.50 ;
			if ( r[i][m-2] == 1 && r[i][m-1] == 1 )
				integer[i] = integer[i] + 0.75 ;

		printf("%f\n",integer[i]);
		}

		// Assigning a fitness function

		int total = 0 ;
		for( i = 0 ; i < n ; i++ )
		{
			fit[i] = pow(integer[i],4) + integer[i] ;
			total = total + fit[i] ;
		}

		// Defining range of values for checking fitness
		printf("\nThe fitness values are: \n");
		float fitness[100] ;
		for(i = 0; i < n; i++)
		{
			fitness[i] = ( fit[i] / total ) * 1000000 ; //FOR CHECKING WITH RANDOM VALUES. CANT LIMIT RANGE OF RANDOM VALUES?? 
			printf("%f\n",fit[i]);
			//printf("%f\n",fitness[i]);
		}
		
		//Generating random number for parent selection
	//	printf("\nThe random values are: \n");
		
		int ran ;
		float random[n] ;
		for( ran = 0 ; ran < n ; ran++ )
		{
		//	srand(time(NULL)) ;
			random[ran] = rand() % 100000 * 10 ;
			//printf("%f\n",random[ran]);
		}

		//Parent Selection
	//	printf("\nThe parent values are: \n");
		
		float fitness_range[n] ;
		float temp ;
		//float parent[n];
		//int parent1[n];
		int parent[n][m] ;
		int k ;

		for( j = 0 ; j < n ; j++ )
		{
			temp = 0;
			for ( i = 0 ; i < n ; i++ )
			{
				fitness_range[i] = temp + fitness[i] ;
				if ( fitness_range[i] > random[j] && random[j] >= temp)
				{
					//parent[j] = temp; // PARENTS RANGE SELECTED FROM RANDOM VALUE
					//parent1[j] = i;
					for ( k = 0 ; k < m ; k++ )
					{
						parent[j][k] = r[i][k] ;
	//					printf("%d",parent[j][k]); // PARENTS SELECTED AND PRINTED
					}

			
				}
				temp = fitness_range[i] ;
	 		}
			//printf("\n%f\n %d\n",parent[j],parent1[j]); //PARENTS RANGE PRINTED
			//printf("\n");
			
		}
		
		// CROSS OVER POINTS

		//Generation of random number for crossover
		int random1[n] ;
		for( ran = 0 ; ran < n ; ran = ran + 2 )
		{
			//srand(time(NULL));
			random1[ran] = rand()%7+1; //To avoid 0 added 1
		//	printf("\n%d\n",random1[ran]);
		}
		
	/*	temp = parent[1][k];
		parent[1][k] = parent[2][k];
		parent[2][k] = temp;
		*/


		// CROSSOVER
		int temp1;
		for ( i = 0 ; i < n ; i = i + 2 )
		{
			for ( j = random1[i] ; j < m ; j++)
			{
				temp1 = parent[i][j] ;
				parent[i][j] = parent[i+1][j] ;
				parent[i+1][j] = temp1 ;
			}
			
		}

		//MUTATION. DIRECTLY DONE OF 1 VALUE FROM THE FIRST PARENT
	/*	int random_m;
		int random_n;
	//	srand(time(NULL));
		random_m = rand()%(m-1);
		random_n = rand()%(n-1);
		if ( parent[random_n][random_m] == 0 )
			parent[random_n][random_m] = 1;
		else if ( parent[random_n][random_m] ==1)
			parent[random_n][random_m] = 0;
		printf("R %d %d",random_m,r[random_n][random_m]);
*/
		int random_2;
		
		for( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; j < m ; j++ )
			{
				random_2 = rand()%10000;
				if ( random_2 < probability*10000)
				{
					if ( parent[i][j] == 0 )
						parent[i][j] = 1;
					else if ( parent[i][j] ==1)
						parent[i][j] = 0;
				}
			}
		}




		//GENERATION FINAL
		printf("\nGeneration %d : \n",a) ;
		for ( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; j < m ; j++ )
			{
				r[i][j] = parent[i][j] ;
				printf("%d",r[i][j]) ;
			}
			printf("\n") ;
		}
	//}

}
		
