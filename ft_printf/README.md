# ft_printf

A custom implementation of the printf function in C, as required by the 42 school curriculum.

## Description

This project recreates the functionality of the standard C library's printf function, supporting the following conversions:

- `%c`: Prints a single character
- `%s`: Prints a string (as defined by the common C convention)
- `%p`: Prints a void * pointer in hexadecimal format
- `%d`: Prints a decimal (base 10) number
- `%i`: Prints an integer in base 10
- `%u`: Prints an unsigned decimal (base 10) number
- `%x`: Prints a number in hexadecimal (base 16) lowercase format
- `%X`: Prints a number in hexadecimal (base 16) uppercase format
- `%%`: Prints a percent sign

## Compilation

To compile the library, run:

```bash
make
```

This will create a static library called `libftprintf.a` that you can link with your projects.

## Usage

Include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
gcc your_program.c -L. -lftprintf
```

Use ft_printf just like you would use the standard printf function:

```c
ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
```

## Testing

A test program is included in the repository. To compile and run it:

```bash
gcc test_printf.c -L. -lftprintf -o test_printf
./test_printf
```

This will compare the output and return values of the original printf function with your ft_printf implementation.
