/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:48:13 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/01 19:46:54 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	j = dstlen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while ((*(src + i) != '\0') && ((j + 1) < dstsize))
	{
		*((unsigned char *)dst + j) = *((unsigned char *)src + i);
		i++;
		j++;
	}
	*(dst + j) = '\0';
	return (dstlen + srclen);
}
