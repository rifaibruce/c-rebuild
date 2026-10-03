# c-rebuild

Systems programming fundamentals in C, built from scratch. Each project starts
from a blank file: no frameworks, no generated code, and a test for every
function before it counts as done.

## Build

Every program is compiled with warnings and AddressSanitizer on:

```
gcc -Wall -Wextra -fsanitize=address -g <file>.c -o <name> && ./<name>
```

`-fsanitize=address` catches out-of-bounds reads and writes at runtime, which
in C often run silently without it.

## Contents

| Folder | What's in it | Status |
| --- | --- | --- |
| `week01/` | `strlen` (index and pointer versions), `strcpy`, assert-based tests | Done |

### week01: strings

- `my_strlen_idx` and `my_strlen_p`: string length by indexing and by walking a pointer.
- `my_strcpy`: single-pass copy using the copy-until-terminator idiom.
- Tests cover empty strings, single characters, a buffer sized exactly to fit,
  and a pre-filled buffer so a missing `'\0'` can't hide behind leftover data.
- A deliberate stack-buffer-overflow demo, off by default. Compile with
  `-DDEMO_OVERFLOW` to see the AddressSanitizer report.

## Planned

- `strtok`, structs, and Makefiles
- Dynamic array and hash table
- Unix shell: `fork`, `exec`, pipes, and redirection
- HTTP server on raw sockets
- A `malloc`/`free` allocator
- Bytecode virtual machine (*Crafting Interpreters*, Part II)

## Conventions

- One concept per folder, with notes in comments on what each piece taught me.
- Every function has tests in `main` using `assert`.
- A clean run under AddressSanitizer is part of "done."
