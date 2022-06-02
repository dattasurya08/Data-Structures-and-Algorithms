/**
 * @file stacks.c
 * @brief Abstraction file for stack operations
 * 
 * This implementation file provides an abstaction for stack
 * and its operations.
 * 
 * @author Sree Suryadatta M Vadhoolas
 * @date May 22 2022
 * 
 */

#include "stacks.h"
#include <stdio.h>

STYPE isEmpty(STACK * st)
{
    return (st->top <= STACK_TOP);
}

STYPE isFull(STACK * st)
{
    return (st->top >= STACK_SIZE);
}

void push(STACK * st, STYPE data)
{
    if(isFull(st))
        ;// printf("Stack overflow\n");
    else
        st->stck[++(st->top)] = data;
}

STYPE pop(STACK * st)
{
    if(isEmpty(st))
        ;// printf("Stack underflow\n");
    else
        return st->stck[(st->top)--];
}

void displayStack(STACK * st)
{
    for(int i = 0; i <= st->top; i++)
        printf("%d ", st->stck[i]);
}

void clearStack(STACK * st)
{
    while (!isEmpty(st))
        pop(st);
}