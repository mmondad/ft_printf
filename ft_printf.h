/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:48:00 by mmondad           #+#    #+#             */
/*   Updated: 2023/11/29 13:28:18 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_putnbr_s_i(int nb, int i);
int	ft_putnbr_u_i(unsigned int nb, int i);
int	ft_put_add(unsigned long nb, char *base, int i);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_printf(const char *foramt, ...);

#endif