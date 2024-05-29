/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:23:27 by htrindad          #+#    #+#             */
/*   Updated: 2024/05/29 13:40:48 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_new_line(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

//fln stands for "find last node"
t_list	*ft_fln(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// nl stands for "new line"
int	ft_len_to_nl(t_list *lst)
{
	int	i;
	int	len;

	if (lst == NULL)
		return (lst);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (++len);
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

void	ft_copy_buff(t_list *lst, char *buff)
{
	int	i;
	int	j;

	if (lst == NULL)
		return (lst);
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				buff[j++] = '\n';
				buff[j] = 0;
				return ;
			}
			buff[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	buff[j] = 0;
}
