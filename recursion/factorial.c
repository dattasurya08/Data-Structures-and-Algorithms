/**
 * @file factorial.c
 * @brief Factorial of an integer. 
 * 
 * This code implements calculation of factorial
 * of a natural number using recursion.
 * 
 * @author Sree Suryadatta M Vadhoolas
 * @date June 02 2022
 * 
 */

#include <stdio.h>

/**
 * @brief Factorial function
 * 
 * - Function computes factorial of a
 * number recursively.
 * 
 * @param num input integer
 * 
 * @return factorial of num
 * 
 */
int fact(int num);

int main()
{
    int num, num_fact;
    printf("Enter the number: ");
    scanf("%d", &num);
    num_fact = fact(num);
    printf("Factorial of %d = %d\n", num, num_fact);
    return 0;
}

int fact(int num)
{
    if((num == 1)|(num == 0))
        return 1;
    else
        return num*fact(num - 1);
}
