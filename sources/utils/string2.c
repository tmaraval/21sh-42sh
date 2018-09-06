/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:52:45 by tmaraval          #+#    #+#             */
/*   Updated: 2018/09/06 12:06:26 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	string_insert_substring(char **string, char *substring, int offset)
{
	int i;

	i = 0;
	if (string[offset] == 0)
	{
		ft_printf("here ??\n");
		ft_strncpy(string[0], substring, ft_strlen(substring));
	}
	else
	{
		while (substring[i])
		{
			string_shift_right(string, offset + i);
			string[0][offset + i] = substring[i];
			i++;
		}
	}
}
