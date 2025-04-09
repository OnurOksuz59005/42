#include "ft_printf.h"

static int handle_conversion(const char *format, va_list args)
{
	int count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (*format == '%')
		count += ft_putpercent();
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += handle_conversion(format, args);
		}
		else if (*format != '%')
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
