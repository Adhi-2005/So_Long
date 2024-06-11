/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhil <adhil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:41:05 by adshafee          #+#    #+#             */
/*   Updated: 2023/12/12 22:39:28 by adhil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
		i += ft_putchar(*str++);
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		i++;
		nbr = -nbr;
	}
	if (nbr < 0)
		i += unsigned_nbr((unsigned int)-nbr);
	else
		i += unsigned_nbr((unsigned int)nbr);
	return (i);
}

int	unsigned_nbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
		i += unsigned_nbr(nbr / 10);
	i++;
	ft_putchar(nbr % 10 + 48);
	return (i);
}
