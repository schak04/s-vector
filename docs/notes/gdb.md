# GDB (GNU Debugger)

> **Reference:** https://web.eecs.umich.edu/~sugih/pointers/summary.html

It is a debugger for C (and C++).

It allows us to:
- pause program execution at specific points
- inspect variables and memory
- step through execution line by line
- inspect the call stack after crashes
- understand why bugs like segmentation faults occur

---

## Compiling

While compiling the program that needs debugging, the `-g` flag needs to be used.

So for a program file `main.c`:

```bash
gcc -g main.c -o main
```

Useful additonal flags:

```bash
gcc -g -Wall -Wextra main.c -o main
```

- `-Wall` enables common warnings
- `-Wextra` enables additional warnings

For memory-related bugs, AddressSanitizer is extremely useful:

```bash
gcc -g -fsanitize=address main.c -o main
```

---

## Starting and Quitting

### Starting

To start GDB normally, we simply type `gdb`.

```bash
gdb
```

That opens up the GDB prompt:

```bash
(gdb)
```

We can also directly provide the executable:

```bash
gdb ./main # or whatever the name of the executable is
```

> Once (gdb) appears, every time a command is used, it can be reused simply by hitting `Enter`.

### Quitting

Simply type `quit` or just `q`.

```bash
(gdb) quit
```
**or**

```bash
(gdb) q
```

---

## Debugging

```bash
(gdb) lay src # shows source code

(gdb) lay asm # shows assembly code

(gdb) lay next # shows next layout based on what we're currently seeing

(gdb) run # runs program inside gdb

(gdb) bt # backtrace (shows call stack) -> used when program crashes

(gdb) next # steps over function
(gdb) step # steps into function
(gdb) finish # exits current function
```

---
