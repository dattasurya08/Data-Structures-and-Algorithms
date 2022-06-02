/**
 * @file fibonacci.c
 * @brief Fibonacci sequence. 
 * 
 * This code displays n fibonacci elements
 * using recursion.
 * 
 * @author Sree Suryadatta M Vadhoolas
 * @date June 02 2022
 * 
 */

#include <stdio.h>

/**
 * @brief Fibonacci function
 * 
 * - Function computes the nth element of
 * fibonacci series recursively.
 * 
 * @param n element
 * 
 * @return nth element of series
 * 
 */
int fib(int n);

int main()
{
    int n;
    printf("Enter the fibonacci series length: ");
    scanf("%d", &n);
    printf("The fibonacci series of length %d: ", n);
    for(int i = 0; i < n; i++)
        printf("%d ", fib(i));
    printf("\n");
    return 0;
}

int fib(int n)
{
    if(n <= 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
