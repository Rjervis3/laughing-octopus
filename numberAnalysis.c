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


/* Supplemental problem 6 */





#include <stdio.h>

char* classification (int number, int factor_sum);

int main()
{
  //read and print a max number
  int max;
  printf("This prgram will list certain requrements for numbers 1 to n\n");
  printf("Please enter a integer number n: ");
  scanf("%d", &max);          //store entered number in max
  printf("The number you entered for n was: %d\n", max);

  //print the table of numbers
  printf("The classification of numbers:\n\n");
  printf("n : non-trivial factors : sum of proper factors : classification\n");

  //create these data for numbers 1 to n and print in table form
  int i, j, factor, sum=1;
  for(i=1; i<=max; i++)          //first loop to go 1 to n
    {
      sum=1;   //reset sum to 0 after each number 1 to n
      printf("%2d : " , i);
      for (j=1; j<i; j++)            //second loop to test each factor 1 to n
	{                            //notice bounds to ignore trivial factors
	if ((i % j)==0 && j!=1)              //factor if j divides i evenly
	  {
	    factor=j;
	    printf("%d ", factor);
	    sum+=factor;
	    }
      }
	if(sum != 0)
	  printf(":%2d", sum);
	printf(" : %s", classification(i, sum));     
	printf("\n");
    }
  return 0;
}


char *classification (int number, int factor_sum)
{char* type;
  //unit type
  if (number == 1)
    type="Unit";
  //prime if not a unit and all factors trivial
  else if (factor_sum == 1)  //no factors = sum = 1
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
