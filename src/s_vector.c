/*
s-vector
Author: Saptaparno Chakraborty
*/

#include "s_vector.h"

#include <stdio.h>
#include <stdlib.h>

/*
--- mem mgmt ---
*/

void sv_init(struct s_vector* vec) {
    vec->size = 0;
    vec->capacity = 5;
    vec->data = (int*)malloc(vec->capacity * sizeof(int));

    if (!vec->data) {
        fprintf(stderr, "Failed to allocate memory.\n");
        vec->capacity = 0;
    }
}

void sv_free(struct s_vector* vec) {
    vec->size = 0;
    vec->capacity = 0;
    free(vec->data);
    vec->data = NULL;
}

/*
--- main s_vector functions ---
*/

void sv_push_back(struct s_vector* vec, int val) {
    if (vec->size >= vec->capacity) {
        size_t new_capacity = vec->capacity + 5;

        int* tmp = (int*)realloc(vec->data, new_capacity * sizeof(int));
        if (!tmp) {
            fprintf(stderr, "Failed to reallocate memory.\n");
            return;
        }

        vec->data = tmp;
        vec->capacity = new_capacity;
    }

    vec->data[vec->size] = val;
    vec->size++;
}

void sv_pop_back(struct s_vector* vec) {
    if (vec->size == 0) return;

    vec->size--;

    if (vec->capacity > 5 && (vec->capacity - vec->size) >= 5) {
        size_t new_capacity = vec->capacity - 5;

        int* tmp = (int*)realloc(vec->data, new_capacity * sizeof(int));
        if (!tmp) {
            fprintf(stderr, "Failed to reallocate memory.\n");
            return;
        }

        vec->data = tmp;
        vec->capacity = new_capacity;
    }
}
