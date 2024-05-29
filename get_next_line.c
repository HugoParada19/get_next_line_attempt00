/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:10:55 by htrindad          #+#    #+#             */
/*   Updated: 2024/05/29 13:24:23 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_append(t_list **lst, char *buf)
{
	t_list	*n;
	t_list	*last_n;

	last_n = ft_fln(*lst);
	n = malloc(sizeof(t_list));
	if (!n)
		return ;
	if (!last_n)
		*lst = n;
	else
		last_n->next = n;
	n->content = buf;
	n->next = NULL;
}

// cl stands for "create list"
static void	ft_cl(t_list **lst, int fd)
{
	int		c_read;
	char	*buff;

	while (!ft_found_new_line(lst))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return ;
		c_read = read(fd, buff, BUFFER_SIZE);
		if (!c_read)
		{
			free(buff);
			return ;
		}
		buff[c_read] = 0;
		ft_append(lst, buff);
	}
}

static char	*ft_get_line(t_list *lst)
{
	int		strlen;
	char	*n_str;
	if (lst == NULL)
		return (lst);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*nl;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
}
