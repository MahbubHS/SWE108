#include <stdio.h>

#define CAPACITY 10

int addEnd(int array[], int *size, int newElement)
{
    if (*size >= CAPACITY)
    {
        printf("Array is full!\n");
        return *size;
    }
    array[*size] = newElement;
    return ++(*size);
}

int addFront(int array[], int *size, int newElement)
{
    if (*size >= CAPACITY)
    {
        printf("Array is full!\n");
        return *size;
    }
    for (int i = *size - 1; i >= 0; i--)
    {
        array[i + 1] = array[i];
    }
    array[0] = newElement;
    return ++(*size);
}

int deleteEnd(int array[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty!\n");
        return *size;
    }
    return --(*size);
}

int deleteFront(int array[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty!\n");
        return *size;
    }
    for (int i = 0; i < *size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    return --(*size);
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
    int arr[CAPACITY] = {1, 3, 4, 2};
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