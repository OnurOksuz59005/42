#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int len;

	if (!str)
		return (ft_putstr("(null)"));
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}
