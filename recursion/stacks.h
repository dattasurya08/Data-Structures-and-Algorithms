/**
 * @file stacks.h
 * @brief Abstraction for stack operations
 * 
 * This header file provides an abstaction for stack
 * and its operations
 * 
 * @author Sree Suryadatta M Vadhoolas
 * @date May 22 2022
 * 
 */

#ifndef __STACKS_H__
#define __STACKS_H__

#define STACK_SIZE 100
#define STACK_TOP  -1
#ifndef STACKTYPE
typedef char STYPE;
#else
typedef STACKTYPE STYPE;
#endif

typedef struct stack {
    int top;
    STYPE stck[STACK_SIZE];
} STACK;

/**
 * @brief Stack empty check
 * 
 * - Function checks whether stack is empty
 * 
 * @param st Pointer to the stack
 * 
 * @return logic indicating stack empty
 * 
 */
STYPE isEmpty(STACK * st);

/**
 * @brief Stack full check
 * 
 * - Function checks whether stack is full
 * 
 * @param st Pointer to the stack
 * 
 * @return logic indicating stack full
 * 
 */
STYPE isFull(STACK * st);

/**
 * @brief Stack push
 * 
 * - Function puts data on top of the stack
 * 
 * @param st Pointer to the stack
 * @param data Data to put on stack
 * 
 * @return void
 * 
 */
void push(STACK * st, STYPE data);

/**
 * @brief Stack pop
 * 
 * - Function remove data on top of stack
 * 
 * @param st Pointer to the stack
 * 
 * @return Popped value
 * 
 */
STYPE pop(STACK * st);

/**
 * @brief Stack Display
 * 
 * - Function displays all elements of stack
 * 
 * @param st Pointer to the stack
 * 
 * @return void
 * 
 */
void displayStack(STACK * st);

/**
 * @brief CLear stack
 * 
 * - Function clears all elements from stack
 * 
 * @param st Pointer to the stack
 * 
 * @return void
 * 
 */
void clearStack(STACK * st);

#endif