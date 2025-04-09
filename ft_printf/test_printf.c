#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int original;
	int custom;
	char *str = "Hello, world!";
	int num = 42;
	void *ptr = &num;

	// Test %c
	printf("\n--- Testing %%c ---\n");
	original = printf("Original: %c\n", 'A');
	custom = ft_printf("Custom  : %c\n", 'A');
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test %s
	printf("\n--- Testing %%s ---\n");
	original = printf("Original: %s\n", str);
	custom = ft_printf("Custom  : %s\n", str);
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test NULL string
	original = printf("Original NULL: %s\n", NULL);
	custom = ft_printf("Custom NULL  : %s\n", NULL);
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test %p
	printf("\n--- Testing %%p ---\n");
	original = printf("Original: %p\n", ptr);
	custom = ft_printf("Custom  : %p\n", ptr);
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test %d and %i
	printf("\n--- Testing %%d and %%i ---\n");
	original = printf("Original: %d, %i\n", num, -num);
	custom = ft_printf("Custom  : %d, %i\n", num, -num);
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test %u
	printf("\n--- Testing %%u ---\n");
	original = printf("Original: %u\n", 4294967295);
	custom = ft_printf("Custom  : %u\n", 4294967295);
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test %x and %X
	printf("\n--- Testing %%x and %%X ---\n");
	original = printf("Original: %x, %X\n", 255, 255);
	custom = ft_printf("Custom  : %x, %X\n", 255, 255);
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test %%
	printf("\n--- Testing %%%% ---\n");
	original = printf("Original: %%\n");
	custom = ft_printf("Custom  : %%\n");
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	// Test multiple conversions
	printf("\n--- Testing multiple conversions ---\n");
	original = printf("Original: %c %s %p %d %i %u %x %X %%\n", 'Z', "test", ptr, 42, -42, 42, 42, 42);
	custom = ft_printf("Custom  : %c %s %p %d %i %u %x %X %%\n", 'Z', "test", ptr, 42, -42, 42, 42, 42);
	printf("Return values - Original: %d, Custom: %d\n", original, custom);

	return (0);
}
