/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_s_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:19:46 by mmondad           #+#    #+#             */
/*   Updated: 2023/11/29 13:52:48 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		count++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_s_i(long int nb, int i)
{
	if (i == -1)
		return (-1);
	if (nb >= 0 && nb <= 9)
	{
		if (ft_putchar(nb + 48) < 0)
			return (-1);
	}
	else if (nb < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		i = ft_putnbr_s_i(-nb, i);
	}
	else
	{
		i = ft_putnbr_s_i(nb / 10, i);
		i = ft_putnbr_s_i(nb % 10, i);
	}
	if (i == -1)
		return (-1);
	return (num_len(nb));
}
