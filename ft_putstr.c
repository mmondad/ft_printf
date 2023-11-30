/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:24:03 by mmondad           #+#    #+#             */
/*   Updated: 2023/11/30 12:10:04 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (ft_putstr("(null)") < 0)
			return (-1);
		return (6);
	}
	while (str[i])
		if (ft_putchar(str[i++]) < 0)
			return (-1);
	return (i);
}
