#include <stdio.h>

int addEnd(int array[], int *size, int newElement)
{
    array[*size] = newElement;
    return *size += 1;
}

int addFront(int array[], int *size, int newElement)
{
    int i = *size - 1;
    while (i >= 0)
    {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = newElement;

    return *size += 1;
}

int deleteEnd(int array[], int *size)
{
    return *size -= 1;
}

int deleteFront(int array[], int *size)
{
    int i = 0;
    while (i < *size - 1)
    {
        array[i] = array[i + 1];
        i++;
    }
    return *size -= 1;
}

void show(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {1, 3, 4, 2};
    int sz = 4;

    show(arr, sz);

    addEnd(arr, &sz, 9);
    show(arr, sz);

    addFront(arr, &sz, 0);
    show(arr, sz);

    deleteEnd(arr, &sz);
    show(arr, sz);

    deleteFront(arr, &sz);
    show(arr, sz);

    return 0;
}