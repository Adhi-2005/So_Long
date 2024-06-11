/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:18:14 by adshafee          #+#    #+#             */
/*   Updated: 2023/12/11 14:30:48 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_hexaconvert(unsigned long long int nbr, int uc);
int	pointers(unsigned long long ptr);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int nbr);
int	unsigned_nbr(unsigned int nbr);
int	ft_printf(const char *type, ...);

#endif