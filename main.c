/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:11:42 by bdion             #+#    #+#             */
/*   Updated: 2021/12/23 14:12:45 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	void		*ptr;
	int		s;

	puts("-----------------");		
	s = ft_printf("d|%d|\n", 42);
	ft_printf("nchr:%d\n", s);
	s = printf("d|%d|\n", 42);
 	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("u|%u|\n", 42);
	ft_printf("nchr:%d\n", s);
	s = printf("u|%u|\n", 42);
	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("s|%s|\n", "MyLap");
	ft_printf("nchr:%d\n", s);
	s = printf("s|%s|\n", "MyLap");
	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("c|%c|%%\n", '$');
	ft_printf("nchr:%d\n", s);
	s = printf("c|%c|%%\n", '$');
	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("x|%x|%X|\n", 0x8F4F4F, 0xabcde113);
	ft_printf("nchr:%d\n", s);
	s = printf("x|%x|%X|\n", 0x8F4F4F, 0xabcde113);
	ft_printf("nchr:%d\n", s);
	puts("-----------------");
	s = ft_printf("p|%p|\n", &ptr);
	ft_printf("nchr:%d\n", s);
	s = printf("p|%p|\n", &ptr);
	ft_printf("nchr:%d\n", s);
	return (0);
}
