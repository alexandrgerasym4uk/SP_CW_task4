#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <string.h>

static inline void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(char** arr, size_t length) {
    if (length <= 1) {
        return;
    }

    size_t pivot_index = length - 1;
    char* pivot_value = arr[pivot_index];
    size_t left = 0;

    for (size_t i = 0; i < pivot_index; i++) {
        if (strcmp(arr[i], pivot_value) < 0) {
            swap(&arr[i], &arr[left]);
            left++;
        }
    }

    swap(&arr[left], &arr[pivot_index]);

    quick_sort(arr, left);
    quick_sort(arr + left + 1, length - left - 1);
}

#endif // !SORT
