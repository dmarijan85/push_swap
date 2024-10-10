/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:17:29 by dmarijan          #+#    #+#             */
/*   Updated: 2024/03/28 12:58:53 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!copy)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}
/*
int	main()
{
	char	*s1[5];

	strcpy(s1, "LMAO");
	puts(ft_strdup(s1));
}
*/
