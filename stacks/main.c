#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 50

unsigned char stack[STACK_SIZE];
int top = -1;

void push(unsigned char data);
unsigned char pop(void);
void displayStack(void);

int main(void)
{
    int value;
    push(37);
    push(55);
    push(8);
    push(45);
    push(10);
    push(128);
    displayStack();
    value = pop();
    displayStack();
    printf("Popped value: %d\n", value);
    value = pop();
    displayStack();
    printf("Popped value: %d\n", value);
}

void push(unsigned char data)
{
    if(top > STACK_SIZE)
        printf("Stack Overflow!!\n");
    else
    {
        top++;
        stack[top] = data;
    }
}

unsigned char pop(void)
{
    unsigned char val = 0;
    if(top < 0)
        printf("Stack Underflow!!\n");
    else
    {
        val = stack[top];
        top--;
    }
    return val;
}

void displayStack(void)
{
    if(top < 0)
        printf("Stack empty!\n");
    else
    {
        printf("Stack Contents:\n");
        for(int i = 0; i <= top; i++)
        {
            printf("    %d\n", stack[i]);
        }
    }
}
