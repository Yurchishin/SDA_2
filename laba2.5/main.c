#include <stdlib.h>
#include <stdio.h>

void enter(int*,int);

void print(int*,int);

int CheckPaired(int*,int);

int SumNotPaired(int*,int);

void Solution(int);

int main()
{
    Solution(19);
    Solution(17);
    Solution(23);
    return 0;
}

void enter(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 20 - 7;
    }
}

void print(int* array,int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int CheckPaired(int* array,int size)
{
    int paired = 0;
    for(int i = 1; i < size; i += 2)
    {
        if(array[i] > 0) paired++;
    }
    return paired;
}

int SumNotPaired(int* array, int size)
{
    int sum = 0;
    for(int i = 0; i < size; i += 2)
    {
        sum += array[i];
    }
    return sum;
}

void Solution(int size)
{
    int* ar = malloc(size * sizeof(int));
    enter(ar,size);
    print(ar, size);
    int paired = CheckPaired(ar, size);
    printf("Kilkist na parnuh: %i \n", paired);
    int sum = SumNotPaired(ar, size);
    printf("Suma ne parnuh: %i \n\n", sum);
    free(ar);
}