/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_u_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:18:21 by mmondad           #+#    #+#             */
/*   Updated: 2023/11/29 11:53:41 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_u_i(unsigned int nb, int i)
{
	if (i == -1)
		return (-1);
	if (nb < 10)
	{
		if (ft_putchar(nb + 48) < 0)
			return (-1);
	}
	else
	{
		i = ft_putnbr_u_i(nb / 10, i);
		i = ft_putnbr_u_i(nb % 10, i);
	}
	if (i == -1)
		return (-1);
	return (nbr_len(nb));
}
