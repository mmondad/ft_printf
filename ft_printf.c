/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:14:01 by mmondad           #+#    #+#             */
/*   Updated: 2023/11/29 16:58:01 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cheker(char c, va_list format, int count)
{
	if (c == 'd' || c == 'i')
		count = ft_putnbr_s_i(va_arg(format, int), 0);
	if (c == 'u')
		count = ft_putnbr_u_i(va_arg(format, unsigned int), 0);
	if (c == 'x')
		count = ft_put_add(va_arg(format, unsigned int), "0123456789abcdef", 0);
	if (c == 'X')
		count = ft_put_add(va_arg(format, unsigned int), "0123456789ABCDEF", 0);
	if (c == 'c')
		count = ft_putchar(va_arg(format, int));
	if (c == 's')
		count = ft_putstr(va_arg(format, char *));
	if (c == 'p')
	{
		if (ft_putstr("0x") < 0)
			return (-1);
		count = ft_put_add(va_arg(format, unsigned long),
				"0123456789abcdef", 0);
		if (count >= 0)
			return (count + 2);
	}
	if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ff(const char *format, int i, int count, va_list args)
{
	int	temp;

	temp = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == 0)
				return (count);
			temp = cheker(format[i], args, 0);
			if (temp < 0)
				return (-1);
			count += temp;
			i++;
		}
		else
		{
			temp = ft_putchar(format[i]);
			if (temp == -1)
				return (-1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		s;

	s = 0;
	i = 0;
	count = 0;
	va_start(args, format);
	s = ff(format, i, count, args);
	va_end(args);
	return (s);
}
