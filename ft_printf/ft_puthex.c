#include "ft_printf.h"

int	ft_puthex(unsigned long n, int uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_puthex(n / 16, uppercase);
		count += ft_puthex(n % 16, uppercase);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}
