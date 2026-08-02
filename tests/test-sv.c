#include <assert.h>
#include <stdio.h>

#include "s_vector.h"

static void test_init(void) {
    struct s_vector v;
    sv_init(&v);

    assert(v.size == 0);
    assert(v.capacity == 5);
    assert(v.data != NULL);

    sv_free(&v);
}

static void test_push_and_resize(void) {
    struct s_vector v;
    sv_init(&v);

    for (int i = 0; i < 6; i++) sv_push_back(&v, i);

    assert(v.size == 6);
    assert(v.capacity == 10);

    for (int i = 0; i < 6; i++) assert(v.data[i] == i);

    sv_free(&v);
}

static void test_pop_and_shrink(void) {
    struct s_vector v;
    sv_init(&v);

    for (int i = 0; i < 11; i++) sv_push_back(&v, i);

    assert(v.capacity == 15);

    for (int i = 0; i < 6; i++) sv_pop_back(&v);

    assert(v.size == 5);
    assert(v.capacity == 5);

    for (int i = 0; i < 5; i++) assert(v.data[i] == i);

    sv_free(&v);
}

static void test_pop_empty(void) {
    struct s_vector v;
    sv_init(&v);

    sv_pop_back(&v);

    assert(v.size == 0);
    assert(v.capacity == 5);

    sv_free(&v);
}

int main(void) {
    test_init();
    test_push_and_resize();
    test_pop_and_shrink();
    test_pop_empty();

    printf("All tests passed!\n");
    return 0;
}
