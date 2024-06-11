/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhil <adhil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:45:06 by adshafee          #+#    #+#             */
/*   Updated: 2023/12/12 22:37:46 by adhil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_check(char type, va_list arg)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, const char *)));
	else if (type == 'p')
		return (pointers(va_arg(arg, unsigned long long)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (type == 'u')
		return (unsigned_nbr(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (ft_hexaconvert(va_arg(arg, unsigned int), 0));
	else if (type == 'X')
		return (ft_hexaconvert(va_arg(arg, unsigned int), 1));
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(type));
}

int	ft_printf(const char *type, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, type);
	while (*type != '\0')
	{
		if (*type == '%')
		{
			type++;
			i += ft_type_check(*type, arg);
		}
		else
			i += ft_putchar(*type);
		type++;
	}
	va_end(arg);
	return (i);
}
