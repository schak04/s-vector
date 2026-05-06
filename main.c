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

void free_s_vector(struct s_vector* vec) {
    vec->size = 0;
    vec->capacity = 0;
    free(vec);
}

void s_push_back(struct s_vector* vec, int val) {
    vec->size += 1;
    if (vec->size >= vec->capacity) {
        vec->capacity = vec->size + 5;
    }
    /*
    vec->size at index 0 = 1
    vec->size at index x = x+1
    so while pushing back,
    idx = vec->size - 1 
    */
    *(vec->data + (vec->size - 1)) = val;
}

int main() {
    struct s_vector* v = malloc(sizeof(struct s_vector));
    init(v);

    s_push_back(v, 4);

    printf("%d\n", v->data[0]);

    free_s_vector(v);
 
    return 0;
}