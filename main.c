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

/*
design decision for s_vector's cap and size while pushing back elements:
    initially size -> 0
    capacity -> 5
every time,
    until size == capacity, capacity doesn't change.
    as soon as size == capacity -> cap = size + 5 again.
*/

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

/*
design decision (popping from the back/end):
    
rambling... (deciding what to do as I type)
say,
    vec->data = {5, 6, 3, 2, 8, 4}
    s_pop_back(vec) should remove 4
    then again it should remove 8
    and so on.
    size -= 1, each time.
    
but how about capacity?
    when vec = {5, 6, 3, 2, 8, 4}
    size = 6, cap = 10 (say)

then,
    s_pop_back(vec) -> {5, 6, 3, 2, 8} => size -= 1 => size = 5.
    if the diff between cap and size is >=5 then capacity -= 5, otherwise cap remains the same.
    why? to reverse the pushing back logic for cap changes.
*/
void s_pop_back(struct s_vector* vec) {
    vec->size -= 1;
    if (vec->capacity - vec->size >= 5) {
        vec->capacity -= 5;
    }
    // at this point, vec->data still has the element to be removed
    // to remove it: maybe reallocation of memory?
    // will try tomorrow
}

int main() {
    struct s_vector* v = malloc(sizeof(struct s_vector));
    init(v);

    s_push_back(v, 4);
    printf("%d\n", v->data[0]);
    
    s_pop_back(v);
    printf("%d\n", v->data[0]);
    
    free_s_vector(v);
 
    return 0;
}