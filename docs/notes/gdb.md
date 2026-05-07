# GDB (GNU Debugger)

> **Reference:** https://web.eecs.umich.edu/~sugih/pointers/summary.html

It is a debugger for C (and C++).

It allows us to:
- run the program up to a certain point then stop and print out the values of certain variables at that point
- step through the program one line at a time and print out the values of each variable after executing each line

---

## Compiling

While compiling the program that needs debugging, the `-g` flag needs to be used.

So for a program file `main.c`:

```bash
gcc -g main.c -o main
```

---

## Starting and Quitting

### Starting

To start GDB, we simply type `gdb`. That gives a prompt that looks like this: `(gdb)`.

Alternatively, we can start gdb and give it the name of the program executable that needs debugging:

```bash
gdb main # or whatever the name of the executable is
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
```

---
