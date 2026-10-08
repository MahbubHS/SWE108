#include <stdio.h>

#define CAPACITY 10

int addEnd(int array[], int *size, int newElement) {
    if (*size >= CAPACITY) {
        printf("Array is Full!\n");
        return *size;
    }
    array[*size] = newElement;
    return ++(*size);
}

int addFront(int array[], int *size, int newElement) {
    if (*size >= CAPACITY) {
        printf("Array is Full!\n");
        return *size;
    }
    for (int i = *size - 1; i >= 0; i--) {
        array[i + 1] = array[i];
    }
    array[0] = newElement;
    return ++(*size);
}

int deleteEnd(int array[], int *size) {
    if (*size <= 0) {
        printf("Array is Empty!\n");
        return *size;
    }
    array[*size - 1] = 0;
    return --(*size);
}

int deleteFront(int array[], int *size) {
    if (*size <= 0) {
        printf("Array is Empty!\n");
        return *size;
    }
    for (int i = 0; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[*size - 1] = 0;
    return --(*size);
}

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arr[CAPACITY] = {2, 3, 4, 5, 6, 8};
    int s = 6;

    display(arr, s);

    display(arr, addEnd(arr, &s, 1));

    display(arr, addFront(arr, &s, 0));

    display(arr, deleteEnd(arr, &s));

    display(arr, deleteFront(arr, &s));

    return 0;
}
