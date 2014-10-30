     /**********************************************************************
     * Name: Renn Jervis                                                   *
     * Box: 3762                                                           *
     * Supplemental Problem 6 (ex cred): Defective, Perfect,               *  
     * and Superperfect Numbers                                            *
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
     *   Signature:                                                        *
     ***********************************************************************/


/* Supplemental problem 6, a program to print the numbers 1 to n, where n *
 * is a number entered by the user, along with its non-trivial factors,   *
 * the sum of the factors, and the classification of the number */



#include <stdio.h>

char* classification (int number, int factor_sum);

// pre-conditions: Number entered is positive, 
//post-conditions: Program correctly prints number, factors, sum, 
//                     and classification 
int main()
{
  //read and print a max number
  int max;
  printf("This program will list certain requrements for numbers 1 to n\n");
  printf("Please enter a integer number n: ");
  scanf("%d", &max);          //store entered number in max
  printf("The number you entered for n was: %d\n\n", max);

  //print the table of numbers
  printf("The classification of numbers:\n");
  printf("n : non-trivial factors : sum of proper factors : classification\n");

  //create these data for numbers 1 to n and print in table form
  int i, j, factor, sum=1;
  char leading=0;
  for(i=1; i<=max; i++)          //first loop to go 1 to n
    {
     

      printf("%2d :" , i);            //print n :
      if (i==1)	sum=0; 
      else sum =1;
      printf("%c", leading);
      for (j=1; j<i; j++)            //second loop to test each factor 1 to n-1
	{                          
	if ((i % j)== 0 && j !=1)          //j a factor if j divides i exactly
	  { leading=',';
	    factor=j;
	    printf("%2d", factor);      //print nontrivial factor
	    // printf(" ");
	    sum+=factor;  //add each non-trivial factor to sum
            printf("%c", leading);
	  } 
        leading = 0;

	}
      // printf("\b ");      //delete comma after last factor
        
      printf(": %d ", sum);     
      printf(": %s", classification(i, sum));     
      printf("\n");
    }
  return 0;
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
