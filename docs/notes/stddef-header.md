# `stddef.h`

Provides fundamental types and macros used by the C standard library.

Commonly used:

- `size_t` -> Unsigned integer type for sizes and array indices.
- `NULL` -> Null pointer constant.
- `ptrdiff_t` -> Signed integer type for pointer differences.
- `offsetof(type, member)` -> Computes the byte offset of a struct member.

Use `#include <stddef.h>` when the code uses these types/macros, especially in header files where we shouldn't rely on other headers to include them indirectly.
