# ft_printf - 42 Barcelona

ft_printf is an essential systems programming project from the 42 Barcelona curriculum. The goal is to recreate the functionality of the standard C library printf function. Using variadic functions (va_list, va_start, va_arg, va_end), ft_printf parses formatted strings and prints characters, strings, memory addresses, signed integers, unsigned integers, and hexadecimal numbers to standard output while accurately tracking the total number of printed characters. The bonus implementation extends this engine with a comprehensive flag parser supporting field width, precision, padding, sign prefixes, and alignment.

# Prerequisites

To compile and link ft_printf, ensure you have:

- A C compiler: gcc or clang
- GNU Make
- Standard C library headers
- POSIX-compliant operating system (Linux or macOS)

# Configuration

1. Clone the repository:
```bash
git clone https://github.com/adrmarqu/printf.git
cd printf
```

No external dependencies are necessary. The project bundles its own Libft helper library and compiles into a single self-contained archive libftprintf.a.

# Execution

### Compilation

Compile the mandatory version:
```bash
make
```
This generates the static library libftprintf.a.

Compile the bonus version with full flag support:
```bash
make bonus
```

### Linking with Your Own Programs

Include ft_printf.h and link against libftprintf.a:

```c
// Example: main.c
#include "include/ft_printf.h"

int main(void)
{
    int count = ft_printf("Hello %s, score: %d (hex: 0x%x)\n", "42 Barcelona", 100, 100);
    ft_printf("Total printed bytes: %d\n", count);
    return (0);
}
```

Compile and run:
```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -Iinclude -o test_program
./test_program
```

### Running Included Test Suites

The repository contains automated test suites for both mandatory and bonus features:

Test mandatory conversions:
```bash
make
gcc -Wall -Wextra -Werror test_main.c -L. -lftprintf -Iinclude -o test_mandatory
./test_mandatory
```

Test bonus flags, widths, and precisions:
```bash
make bonus
gcc -Wall -Wextra -Werror test_main_bonus.c -L. -lftprintf -Iinclude -o test_bonus
./test_bonus
```

# Project Structure

```
printf/
├── Makefile                 # Library compilation and archive generation
├── test_main.c              # Test runner for standard conversions
├── test_main_bonus.c        # Test runner for bonus flags and precision
├── include/                 # Header files
│   ├── ft_printf.h          # Mandatory prototypes and declarations
│   └── ft_printf_bonus.h    # Bonus flag structs, masks, and prototypes
├── libft/                   # Bundled custom C utility library
├── src/                     # Mandatory implementation
│   ├── ft_printf.c          # Format string parser and specifier dispatcher
│   ├── ft_putchar.c         # Character and string rendering (%c, %s, %%)
│   ├── ft_putnbr.c          # Signed and unsigned integer output (%d, %i, %u)
│   └── ft_num.c             # Hexadecimal and pointer address output (%x, %X, %p)
└── bonus/                   # Bonus flag engine
    ├── ft_printf_bonus.c    # Flag-aware dispatcher loop
    ├── init_bonus.c         # State and flag struct initialization
    ├── ft_flags_bonus.c     # Flag parsing (- 0 . # + space and width)
    ├── ft_putflags_bonus.c  # Padding, alignment, and sign insertion
    ├── ft_putchar_bonus.c   # Padded character and string writing
    ├── ft_putnbr_bonus.c    # Padded numeric formatting
    └── ft_num_bonus.c       # Padded hex and memory pointer output
```

# Commands and Makefile Targets

- make or make all: Compiles libft and the mandatory ft_printf implementation into libftprintf.a
- make bonus: Compiles libft and the bonus flag formatting engine into libftprintf.a
- make clean: Deletes compiled object files (.o) in both printf and libft
- make fclean: Runs clean and deletes libftprintf.a and libft.a
- make re: Completely recompiles the library from scratch

# Conversions and Formatting Flags

### Mandatory Specifiers

- %c: Single character
- %s: String of characters
- %p: Pointer address in hexadecimal format (prefixed with 0x)
- %d / %i: Signed base 10 integer
- %u: Unsigned base 10 integer
- %x: Unsigned hexadecimal integer (lowercase)
- %X: Unsigned hexadecimal integer (uppercase)
- %%: Literal percent character

### Bonus Formatting Flags

- - : Left-align output within the specified field width
- 0 : Pad numeric output with leading zeros instead of spaces
- . : Precision modifier (controls minimum digits for numbers, maximum characters for strings)
- # : Alternative form for hexadecimal output (prepends 0x for %x and 0X for %X)
- + : Forces a leading sign (+ or -) for signed numbers
- space : Prepends a space before positive signed numbers if no sign is written
- Width: Minimum field width padding with whitespace

# Author Details

Author: Adrià Márquez Nebot
Github: https://github.com/adrmarqu
LinkedIn: https://www.linkedin.com/in/adria-marquez
Portfolio: https://adrmarqu.github.io
