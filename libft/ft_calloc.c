/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:05:00 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/01 19:44:57 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (size > SIZE_MAX / count)
		return (NULL);
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc (count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
