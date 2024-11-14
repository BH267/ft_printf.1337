/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:05:28 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/14 17:14:16 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_puthexa(long n, char x);
int	ft_putunbr(unsigned int n);
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);

#endif
