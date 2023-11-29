/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:06:36 by mmondad           #+#    #+#             */
/*   Updated: 2023/11/29 11:57:22 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb == 1)
		return (1);
	while (nb)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

int	ft_put_add(unsigned long nb, char *base, int i)
{
	if (i == -1)
		return (-1);
	if (nb == 0)
	{
		if (ft_putchar('0') < 0)
			return (-1);
		return (1);
	}
	if (nb >= 0 && nb < 16)
	{
		if (ft_putchar(base[nb]) < 0)
			return (-1);
	}
	else
	{
		i = ft_put_add(nb / 16, base, i);
		i = ft_put_add(nb % 16, base, i);
	}
	if (i == -1)
		return (-1);
	return (nbr_len(nb));
}
