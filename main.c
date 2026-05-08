/*
s-vector
Author: Saptaparno Chakraborty
*/

#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 0

struct s_vector {
    int* data;
    size_t size;
    size_t capacity;
};

/*
--- mem mgmt ---
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

/*
--- main s_vector functions ---
*/

void s_push_back(struct s_vector* vec, int val) {
    vec->size += 1;
    if (vec->size >= vec->capacity) {
        vec->capacity = vec->size + 5;
    }
    *(vec->data + (vec->size - 1)) = val; // vec->size at index x = x+1
}

void s_pop_back(struct s_vector* vec) {
    vec->size -= 1;
    if (vec->capacity - vec->size >= 5) {
        vec->capacity -= 5;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    // at this point, vec->data still has the element to be removed
    // removing it...
    // yet to write the logic for removal    
}

int main() {
    struct s_vector* v = malloc(sizeof(struct s_vector));
    init(v);

    s_push_back(v, 4);
    printf("%d\n", v->data[0]); // 4
    s_push_back(v, 22);
    printf("%d\n", v->data[1]); // 4, 22
    
    s_pop_back(v);
    printf("%d\n", v->data[0]); // 4
    printf("%d\n", v->data[1]); // nothing
    
    free_s_vector(v);
 
    return 0;
}