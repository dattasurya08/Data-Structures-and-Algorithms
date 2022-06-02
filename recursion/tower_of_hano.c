/**
 * @file tower_of_hano.c
 * @brief Tower of Hano. 
 * 
 * This code implements solution to tower
 * of hano problem for n element tower.
 * 
 * @author Sree Suryadatta M Vadhoolas
 * @date June 02 2022
 * 
 */

#include <stdio.h>
#include "stacks.h"

#define SRC 1
#define ITR 2
#define DST 3
#define STACKTYPE int
STACK source, inter, dest;

/**
 * @brief Create source tower
 * 
 * - Function creates a source tower
 * stack for hano problem.
 * 
 * @param n elements in tower
 * @param srcstk pointer to source stack
 * 
 * @return pointer to source stack
 * 
 */
STACK * makeSourceTower(int n, STACK * srcstk);

/**
 * @brief Tower of hano function
 * 
 * - Function computes and displays the
 * required shift of elements to solve
 * tower of hano problem recursively.
 * 
 * @param n elements in tower
 * @param A source
 * @param B intermediate
 * @param C destination
 * @param srcst stack pointer to problem source
 * @param itrst stack pointer to problem intermediate
 * @param dstst stack pointer to problem destination
 * 
 * @return void
 * 
 */
void toh(int n, int A, int B, int C, STACK * srcst, STACK * itrst, STACK * dstst);

/**
 * @brief Move disk
 * 
 * - Function moves disk on top of source point
 * to destination point.
 * 
 * @param s source point
 * @param d destination point
 * @param srcst stack pointer to problem source
 * @param itrst stack pointer to problem intermediate
 * @param dstst stack pointer to problem destination
 * 
 * @return void
 * 
 */
void moveDisk(int s, int d, STACK * srcst, STACK * itrst, STACK * dstst);

/**
 * @brief Display 3 towers
 * 
 * - Function displays all elements in the
 * 3 towers (stacks) in order.
 * 
 * @param srcst stack pointer to problem source
 * @param itrst stack pointer to problem intermediate
 * @param dstst stack pointer to problem destination
 * 
 * @return void
 * 
 */
void showTowers(STACK * srcst, STACK * itrst, STACK * dstst);


int main()
{
    int n;
    printf("Enter the tower length: ");
    scanf("%d", &n);
    clearStack(&source);
    clearStack(&inter);
    clearStack(&dest);
    makeSourceTower(n, &source);
    printf("\n");
    showTowers(&source, &inter, &dest);
    printf("\n");
    printf("Solution to tower of hanoi for %d element tower from %d to %d:\n", n, SRC, DST);
    toh(n, SRC, ITR, DST, &source, &inter, &dest);
    return 0;
}

STACK * makeSourceTower(int n, STACK * srcstk)
{
    for(int i = n; i > 0; i--)
        push(srcstk, i);
    return srcstk;
}

void toh(int n, int A, int B, int C, STACK * srcst, STACK * itrst, STACK * dstst)
{
    if(n > 0)
    {
        toh(n - 1, A, C, B, srcst, itrst, dstst);
        // printf(" - Move disk %d from %d to %d\n", n, A, C);
        printf("------------------------ New Move ------------------------\n");
        moveDisk(A, C, srcst, itrst, dstst);
        showTowers(srcst, itrst, dstst);
        toh(n - 1, B, A, C, srcst, itrst, dstst);
    }
}

void moveDisk(int s, int d, STACK * srcst, STACK * itrst, STACK * dstst)
{
    int disk;
    if(s == 1)
    {
        disk = pop(srcst);
        if(d == 2)
            push(itrst, disk);
        else if(d == 3)
            push(dstst, disk);
        else
            push(srcst, disk);
    }
    else if(s == 2)
    {
        disk = pop(itrst);
        if(d == 1)
            push(srcst, disk);
        else if(d == 3)
            push(dstst, disk);
        else
            push(itrst, disk);
    }
    else if(s == 3)
    {
        disk = pop(dstst);
        if(d == 1)
            push(srcst, disk);
        else if(d == 2)
            push(itrst, disk);
        else
            push(dstst, disk);
    } 
}

void showTowers(STACK * srcst, STACK * itrst, STACK * dstst)
{
    printf("    Source tower      : ");
    displayStack(srcst);
    printf("\n");
    printf("    Intermediate tower: ");
    displayStack(itrst);
    printf("\n");
    printf("    Destination tower : ");
    displayStack(dstst);
    printf("\n");
}
