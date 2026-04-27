/*
s-vector
Author: Saptaparno Chakraborty
*/

#include <stdio.h>
#define INITIAL_SIZE 0

// components: data (ptr) + size + capacity
struct s_vector {
    int* data; // changes whenever the array needs resizing
    size_t size;
    size_t capacity;
};

void init(struct s_vector* vec) {
    vec->data = NULL;
    vec->size = INITIAL_SIZE;
    vec->capacity = vec->size + 5;
    /*
    design decision for s_vector's cap and size:
        initially size -> 0
        capacity -> 5
    every time,
        until size == capacity, capacity doesn't change.
        as soon as size == capacity -> cap = size + 5 again.
    */
}

int main() {
    return 0;
}