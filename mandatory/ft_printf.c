/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:25:54 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/17 14:25:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print_str(const char *str, va_list valst);

int	ft_printf(const char *str, ...)
{
	va_list	valst;
	int		count;

	va_start(valst, str);
	count = print_str(str, valst);
	va_end(valst);
	return (count);
}

static int	print_str(const char *str, va_list valst)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			write(1, "%", 1);
			str++;
		}
		else if (*str == '%')
			count = write_spe(++str, valst, count);
		else
			write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}
