     /**********************************************************************
     * Name: Renn Jervis                                                   *
     * Box: 3762                                                           *
     * Supplememntal Problem 6: Defective, Perfect,                        *  
     * , and Superperfect Numbers                                          *
     * Assignment for ...                                                  *
     ***********************************************************************/

     /**********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *                                                                     *
     *       checked :                                                     *
     *     http://stackoverflow.com/questions/1496313/                     *
     *                           returning-c-string-from-a-function        *
     *    for info on how to return a sting from a funct                   *
     *   Help obtained                                                     *
     *     [none]                                                          *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:   Rj                                                     *
     ***********************************************************************/


/* Supplemental problem 6, a program to print the numbers 1 to n, where n *
 * is a number entered by the user, along with its non-trivial factors,   *
 * the sum of the factors, and the classification of the number */

#include <stdio.h>


void sum_funct(int number, int* sum);
char* classification (int number, int factor_sum);


// pre-conditions: Number entered is positive, 
//post-conditions: Program correctly prints number, factors, sum, 
//                     and classification 


int main()
{
  //read and print a max number
  int max;
  printf("This prgram will list certain requrements for numbers 1 to n\n");
  printf("Please enter a integer number n: ");
  scanf("%d", &max);          //store entered number in max
  printf("The number you entered for n was: %d\n\n", max);

 //title table of numbers
  printf("The classification of numbers:\n");
  printf("n : classification : sum of proper factors: non-trivial factors\n");

 //create these data for numbers 1 to n and print in table form
  int i, j, factor, sum=1;
  for(i=1; i<=max; i++)          //first loop to go 1 to n
    {

      printf("%4d : " , i);            //print n :
      if (i==1)	sum=0; 
      else sum =1;
      sum_funct(i, &sum);
      printf("%s:", classification(i, sum));
      printf(" %d:", sum);     
     
      if ((i % j)== 0 && j !=1)          //j a factor if j divides i exactly
	  {
	    printf(" %d,", j);      //print nontrivial factor
	  }
      printf("\n");
    }
  return 0;
}

void sum_funct(int number, int *sum)
{
  
  int j ;
  for (j=1; j<number; j++)            //second loop to test each factor 1 to n-1
    {                          
      if ((number % j)== 0 && j !=1)        //j a factor if j divides i exactly
	{
	 *sum+=j;  //add each non-trivial factor to sum
	}
    }
}

//pre-conditions: number is positive
//post-conditions: program returns correct number classification
char *classification (int number, int factor_sum)
{char* type;
  //unit type
  if (number == 1)
    type="Unit";
  //prime if not a unit and all factors trivial
  else if (factor_sum == 1)  //no factors -> sum = 1
    type="Prime";
  //defective if not unit or prime and sum < n
  else if(factor_sum < number)
    type="Defective";
  //prefect if sum divisors is n
  else if(factor_sum == number)
    type="Perfect";
  //super perfect if sum > n
  else if(factor_sum > number)
    type="Super Perfect";
  return type;
}
