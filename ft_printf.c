/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:28:48 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/10 14:28:50 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.a"

int ft_printf(char *spec, ...)
{
	va_list params;
	char    *step;
	int     d;
	char    c;
	
	va_start(params, spec);
	while (*spec)
	{
		if (*spec == '%')
			ft_putchar(*spec);
		else
		{
			spec++;
			if (*spec == 'd')
			{
				d = va_arg(params, int);
				ft_putnbr(d);
			}
			if (*spec == 'c')
			{
				c = va_arg(params, char);
				ft_putchar(c);
			}
			spec++;
		}
	}
}