/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:38:49 by bcolossu          #+#    #+#             */
/*   Updated: 2019/09/11 21:13:15 by bcolossu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *a;

	a = (char *)s;
	while (n > 0)
	{
		*a = 0;
		a++;
		n--;
	}
}
