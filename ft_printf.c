/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:28:48 by ljonas            #+#    #+#             */
/*   Updated: 2020/03/13 11:44:37 by ljonas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void    ft_putfloat(float num)
{
	
}
*/
int     ft_printf(char *spec, ...)
{
	va_list params;
	char    *step;
	t_specs specs;
	
	va_start(params, spec);
	while (*spec)
	{
		if (*spec != '%')
			ft_putchar(*spec);
		else
		{
			spec++;
			if (*spec == 'd' || *spec == 'i')
			{
				specs.d = va_arg(params, int);
				ft_putnbr(specs.d);
			}
			if (*spec == 'c')
			{
				specs.c = va_arg(params, int);
				ft_putchar(specs.c);
			}
			/*if (*spec == 'f')
			{
			    specs.f = va_arg(params, float);
				ft_printf(floatnum(specs.c));
			}*/
		}
		spec++;
	}
	return (1);
}