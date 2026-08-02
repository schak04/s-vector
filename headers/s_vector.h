#ifndef S_VECTOR_H
#define S_VECTOR_H

#include <stddef.h>

struct s_vector {
    int* data;
    size_t size;
    size_t capacity;
};

void sv_init(struct s_vector* vec);
void sv_free(struct s_vector* vec);

void sv_push_back(struct s_vector* vec, int val);
void sv_pop_back(struct s_vector* vec);

#endif /* S_VECTOR_H */
