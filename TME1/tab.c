#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#include "tab.h"

void printMem()
{
    int who = RUSAGE_SELF;
    struct rusage usage;

    getrusage(who, &usage);
    printf("ru_maxrss : %ld\n", usage.ru_maxrss);
}

void initTab(int *tab, int size)
{
    for (int i = 0; i < size; i++)
        tab[i] = rand() % 10;
}

void printTab(int *tab, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", tab[i]);
        if (i + 1 != size)
            printf(", ");
    }
    printf(" ]\n");
}

int minSumTab(int *min, int *tab, int size)
{
    if (!size)
        return 0;

    int sum = *min = tab[0];

    for (int i = 1; i < size; i++)
    {
        sum += tab[i];
        if (*min > tab[i])
            *min = tab[i];
    }

    return sum;
}

int main()
{
    srand(time(NULL));

    printf("Before static allocation ");
    printMem();

    int staTab[NMAX], *dynTab;
    initTab(staTab, NMAX);
    // printTab(staTab, NMAX);

    printf("After static allocation ");
    printMem();

    dynTab = malloc(sizeof(int) * NMAX);
    printf("After malloc allocation ");
    printMem();

    initTab(dynTab, NMAX);
    // printTab(dynTab, NMAX);

    free(dynTab);
    printf("After free : ");
    printMem();

    return 0;
}