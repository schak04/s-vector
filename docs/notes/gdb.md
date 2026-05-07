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
(gdb) quit # shortcut -> q
```

---

## Running Programs

```bash
(gdb) run # runs program inside gdb (shortcut -> r)
```

Arguments can also be passed:
```bash
(gdb) run file.txt
```

---

## Debugging

```bash
(gdb) layout src # shows source code layout (shortcut for layout -> lay)
(gdb) lay asm # shows assembly code layout
(gdb) lay next # shows next layout based on the current layout
```

## Execution Control

```bash
(gdb) run
(gdb) continue # continues execution after a pause or breakpoint (shortcut -> c)
(gdb) next # steps over function (shprtcut -> n)
(gdb) step # steps into function (shprtcut -> s)
(gdb) finish # exits current function (shprtcut -> fin)
(gdb) start # starts/restarts
```

## Backtrace and Stack Frames

Very useful after crashes (like segfaults):
```bash
(gdb) bt # backtrace (shows call stack) -> used when program crashes
```

### Moving Between Stack Frames

```bash
(gdb) frame 0 # moves to frame 0 (usually where the crash occurred)

(gdb) frame 1 # moves one level higher in the call stack
```

> shortcut -> f

---

## Breakpoints

Breakpoints pause program execution at specific locations.

### Break by Function

```bash
(gdb) break main # or whichever function (shortcut -> b)
```

### Break by Line Number

```bash
(gdb) break main.c:25 # 25th line in main.c file (not func)
```

### Deleting Breakpoints

```bash
(gdb) delete breakpoints # all
(gdb) delete 1 # specific (1)
```

---

## Inspecting Variables

### Regular (Non-Pointer) Variables

```bash
(gdb) print varname # shortcut -> p
```

### Pointers

```bash
# address
(gdb) print ptr # Example O/P: $1 = (int *) 0x0

# value (by dereferencing the pointer)
(gdb) print *ptr
```

### View Local Variables

```bash
(gdb) info locals # local vars in the current function
```

### View Function Arguments

```bash
(gdb) info args # args passed to the current function
```

---

## Viewing Source Code

```bash
(gdb) list # source code near the current execution point

(gdb) list main # listing a specific function (say, main)

(gdb) list 20,40 # specific line ranges (20,40)
```

---

## Examining Memory

```bash
(gdb) examine ptr # examines memory at the given address (shortcut -> x)
```

Example:

```bash
(gdb) x/4x ptr

# Meaning:
# examine 4 values, and
# display them in hexadecimal.
```

### Common formats
- x → hexadecimal
- d → decimal
- c → character
- i → instruction
- s → string

---

## Segmentation Fault Debugging

A segmentation fault (SIGSEGV) usually means:
- dereferencing an invalid pointer
- dereferencing NULL
- accessing memory out of bounds
- use-after-free
- stack corruption

### Typical Debugging Process:

```bash
(gdb) run
```
and BOOM.  
Program crashes -> signal `SIGSEGV`.

Now what?

**Inspect call stack:**
```bash
(gdb) bt
```

**Inspect variables:**
```bash
(gdb) info locals
(gdb) print ptr
```

**Move through stack frames if needed:**
```bash
(gdb) frame 1
```

---

## Core Dumps

[Written Here](core-dump.md)

---