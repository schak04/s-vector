# GCC Optimisation Flags

- `-O0` -> No optimisation. Best for debugging (default).
- `-O1` -> Basic optimisations with faster compile times.
- `-O2` -> Recommended optimisation level for release builds. Improves performance without overly aggressive transformations.
- `-O3` -> More aggressive optimisations (e.g. loop unrolling, vectorisation). Can increase binary size and isn't always faster.
- `-Os` -> Optimise for smaller binary size.
- `-Ofast` -> Enables `-O3` plus optimisations that may violate strict C standard behaviour. Use only when maximum performance matters more than strict correctness.

**Typical usage:**

- Development:

```sh
-Wall -Wextra -Wpedantic -fsanitize=address,undefined -g
```

- Release:

```sh
-Wall -Wextra -Wpedantic -O2
```
