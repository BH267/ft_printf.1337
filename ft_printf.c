/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:58:37 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/13 12:07:40 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *f, ...)
{
	va_list	list;
	char	**sp;

	va_start(list, f);
	sp = ft_split(f, '%');
	while(sp)
	{
		if (ft_strlen(*sp) == 1)
		{
			if (*sp == 's')
				ft_putstr_fd(va_arg(list, char *), 1);
			if (*sp == 'd' || *sp == 'i')
				ft_putnbr_fd(va_arg(list, int), 1);
			if (*sp == 'c')
				ft_putchar_fd(va_arg(list, char), 1);
			if (*sp == '%')
				ft_putchar_fd('%', 1);
			if (*sp == 'x' || *sp == 'X')
				ft_puthexa(va_arg(list, long), *sp);
			if (*sp == 'p')
				ft_puthexa(&(va_arg(list, int)), 'x');
			if (*sp == 'u')
				ft_putunbr(va_arg(list, unsigned int));
		}
		ft_putstr_fd(*sp, 1);
		sp++;
	}
	va_end(list);
}
