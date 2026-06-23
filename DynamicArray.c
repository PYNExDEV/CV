#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *arrPointer;
    size_t size;
    size_t capacity;
} DynamicArray;
void InitializeArr(DynamicArray *arr, size_t initale_cap)
{
    arr->arrPointer = malloc(initale_cap * sizeof(int));
    if (arr->arrPointer == NULL)
    {
        fprintf(stderr, "FAILED TO INITAILIZE THE ARRAY!\n");
        arr->capacity = 0;
        arr->size = 0;
        return;
    }
    else
    {
        arr->capacity = initale_cap;
        arr->size = 0;
    }
}
void AddValue(DynamicArray *arr, int value)
{
    if (arr->size == arr->capacity)
    {
        size_t new_cap = (arr->capacity == 0) ? 1 : (arr->capacity * 2);

        int *temp = realloc(arr->arrPointer, new_cap * sizeof(int));
        if (temp == NULL)
        {
            fprintf(stderr, "FAILED TO ADD THE VALUE!\n");
            return;
        }
        arr->arrPointer = temp;
        arr->capacity = new_cap;
    }
    *(arr->arrPointer + arr->size) = value;
    arr->size++;
}

void FreeArr(DynamicArray *arr)
{
    if (arr->arrPointer != NULL)
    {
        free(arr->arrPointer);
        arr->arrPointer = NULL;
    }
    arr->capacity = 0;
    arr->size = 0;
}

int main()
{
    DynamicArray arr;
    size_t size = 0;
    int value;
    InitializeArr(&arr, 2);
    printf("enter the amount of values you want to enter : ");
    scanf("%zu", &size);
    printf("Please enter the values you want : ");
    for (size_t i = 0; i < size; i++)
    {
        scanf("%d", &value);
        AddValue(&arr, value);
        printf("value added:%d ,current size: %zu , current capacity: %zu \n", value, arr.size, arr.capacity);
    }
    FreeArr(&arr);
    printf("current size: %zu , current capacity: %zu \n", arr.size, arr.capacity);

    return 0;
}