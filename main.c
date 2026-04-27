/*
s-vector
Author: Saptaparno Chakraborty
*/

#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 0

// components: data (ptr) + size + capacity
struct s_vector {
    int* data; // changes whenever the array needs resizing
    size_t size;
    size_t capacity;
};

/*
design decision for s_vector's cap and size:
    initially size -> 0
    capacity -> 5
every time,
    until size == capacity, capacity doesn't change.
    as soon as size == capacity -> cap = size + 5 again.
*/

void init(struct s_vector* vec) {
    vec->size = INITIAL_SIZE;
    vec->capacity = 5;
    vec->data = (int*)malloc(vec->capacity * sizeof(int));
}

int main() {
    return 0;
}