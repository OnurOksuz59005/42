#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int			count;
	unsigned long	addr;

	count = 0;
	addr = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(addr, 0);
	return (count);
}
