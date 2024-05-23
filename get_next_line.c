/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:10:55 by htrindad          #+#    #+#             */
/*   Updated: 2024/05/22 18:37:06 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_str(int fd)
{
	char	*s[BUFFER_SIZE + 1];
	char	*ret;
	int		b_read;
	
	b_read = read(fd, s, BUFFER_SIZE);
	if (b_read < 0)
		return (NULL);
	while (b_read)
	{
		b_read = read(fd, s, BUFFER_SIZE);
		if (b_read < 0)
			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 1 || BUFFER_SIZE < 1 || read(fd, 0, 0))
		return (NULL);
	str = get_str(fd);
}
