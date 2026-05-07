# Core Dump

A core dump is a file produced by the OS that captures a snapshot of a program's memory and execution state at the exact moment it crashes.

In other words, it is the memory image of a process at that point in time when it was terminated.

---

## While Debugging Using GDB

**Enable core dumps:**

```bash
ulimit -c unlimited
```

**Run the program:**

```bash
./main
```

If a crash occurs, a core dump may be generated.

### Open it using GDB:

```bash
gdb ./main core
```
On many modern Linux systems, systemd-coredump is used instead:

```bash
coredumpctl list
```

Open crash directly in GDB:
```bash
coredumpctl gdb <pid>
```

---