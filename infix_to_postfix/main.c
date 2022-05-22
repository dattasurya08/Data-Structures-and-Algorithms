/**
 * @file main.c
 * @brief Infix to postfix convertion
 * 
 * This code implements infix to postfix conversion
 * of expression using stacks.
 * 
 * @author Sree Suryadatta M Vadhoolas
 * @date May 19 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define STACK_TOP  -1

struct stack {
    int top;
    char stck[STACK_SIZE];
};
typedef struct stack STACK;

STACK operator = {STACK_TOP};
STACK noperand = {STACK_TOP};

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
char isEmpty(STACK * st);

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
char isFull(STACK * st);

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
void push(STACK * st, char data);

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
char pop(STACK * st);
/**
 * @brief Operator check
 * 
 * - Function checks if character is a mathematical
 * operator
 * 
 * @param c Input character
 * 
 * @return Logic indicating if operator
 * 
 */
char isOperator(char c);

/**
 * @brief Precedence to operators
 * 
 * - Function assigns priority to mathematical
 * operators
 * 
 * @param op Input operator character
 * 
 * @return Precedence value
 * 
 */
char precedence(char op);

/**
 * @brief Infix to postfix conversion 
 * 
 * - Function converts input expression from
 * infix to postfix and displays on console
 * 
 * @param expression Input expression string
 * 
 * @return void
 * 
 */
void prefixToPostfix(char * expression);

int main()
{
    char expression[100];
    printf("Enter the algebraic expression: ");
    scanf("%s", expression);
    prefixToPostfix(expression);
}

char isEmpty(STACK * st)
{
    return (st->top <= STACK_TOP);
}

char isFull(STACK * st)
{
    return (st->top >= STACK_SIZE);
}

void push(STACK * st, char data)
{
    if(isFull(st))
        ;// printf("Stack overflow\n");
    else
        st->stck[++(st->top)] = data;
}

char pop(STACK * st)
{
    if(isEmpty(st))
        ;// printf("Stack underflow\n");
    else
        return st->stck[(st->top)--];
}

char isOperator(char c)
{
    char isop = 0;
    switch (c)
    {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        isop = 1;
        break;
    default:
        isop = 0;
        break;
    }
    return isop;
}

char precedence(char op)
{
    char prec;
    switch (op)
    {
    case '(':
        prec = 0;
        break;
    case '+':
    case '-':
        prec = 1;
        break;
    case '*':
    case '/':
        prec = 2;
        break;
    case '^':
        prec = 3;
        break;
    default:
        prec = 0;
        break;
    }
    return prec;
}

void prefixToPostfix(char * expression)
{
    int i = 0;
    char exp;
    char prev = 0, curr = 0;
    printf("Post-fix algebraic expression : ");
    while(expression[i] != '\0')
    {
        exp = expression[i];
        if(isOperator(exp))
        {
            if(exp == ')')
            {
                char top = pop(&operator);
                while(top != '(')
                {
                    printf("%c", top);
                    top = pop(&operator);
                }
                // printf("%c", pop(&operator));
            }
            else if(exp == '(')
                push(&operator, exp);
            else
            {
                curr = precedence(exp);
                if(i == 0)
                    prev = 0;
                else
                    prev = precedence(operator.stck[operator.top]);
                if(curr <= prev)
                {
                    while(curr <= prev)
                    {
                        printf("%c", pop(&operator));
                        prev = precedence(operator.stck[operator.top]);
                    }
                    push(&operator, exp);
                }
                else
                    push(&operator, exp);
            }
        }
        else
        {
            printf("%c", exp);
        }
        i++;
    }
    while(!isEmpty(&operator))
        printf("%c", pop(&operator));
    printf("\n");
}
