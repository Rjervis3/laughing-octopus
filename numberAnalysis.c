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
     *     [include textbook(s), CSC 161 labs or readings;                 *
     *       complete citations for Web or other written sources           *
     *      write "none" if no sources used]                               *
     *   Help obtained                                                     *
     *     [indicate names of instructor, class mentors                    *
     *      or evening tutors, consulted according to class policy;        *
     *      write "none" if none of these sources used]                    *
     *     ["none" required for Supplemental Problems                      *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/


/* Supplemental problem 6 */





#include <stdio.h>



int main()
{
  //read and print a max number
  int max;
  printf("This prgram will list certain requrements for numbers 1 to n\n");
  printf("Please enter a integer number n:");
  scanf("%d", &max);          //store entered number in max
  printf("The number you entered for n was: %d\n", max);

  //print the table of numbers
  printf("The classification of numbers:\n\n");
  printf("n : non-trivial factors : sum of proper factors : classification\n");

  //create these data for numbers 1 to n and print in table form
  int i, j, sum;
  int factors[max];  //array to hold factors
  for(i=1; i<=max; i++)          //first loop to go 1 to n
    { printf(" %d :" , i);
      for (j=1; j<i; j++)            //second loop to test each factor 1 to n
      {
	if ((i % j)==0 && j!=1)              //factor if j divides i evenly
	  {
	    factors[j-1]=j;
	    printf("%d,", factors[j-1]);
	    sum+=factors[j-1];
	  }
      }
      printf("\n");
    }
}
