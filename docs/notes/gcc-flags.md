# GCC Flags I Use

- `-Wall` -> Enable common compiler warnings.
- `-Wextra` -> Enable additional useful warnings.
- `-Wpedantic` -> Warn about non-standard C code and compiler extensions.
- `-fsanitize=address` -> Detect memory bugs (buffer overflows, use-after-free, double free, etc.).
- `-fsanitize=undefined` -> Detect undefined behaviour (integer overflow, invalid shifts, divide-by-zero, etc.).
- `-g` -> Generate debug symbols for GDB and sanitiser stack traces.
- `-I<dir>` -> Add a directory to the compiler's header search path (e.g. `-Iheaders`).
