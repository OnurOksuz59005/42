#include "ft_printf.h"

int	ft_putpercent(void)
{
	return (write(1, "%", 1));
}
