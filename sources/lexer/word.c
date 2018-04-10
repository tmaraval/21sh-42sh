/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 05:15:34 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/31 04:18:43 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

static char	*esc_strncpy(char *dst, char *src, int len)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < len && src[i])
	{
		if ((src[i] != CHR_ESCAPE) || (i != 0 && src[i - 1] == CHR_ESCAPE))
		{
			dst[j] = src[i];
			if ((dst[j] = src[i]) == 0)
			{
				while (i < len)
				{
					dst[j] = '\0';
					i++;
				}
			}
			j++;
		}
		i++;
	}
	return (dst);
}

static int	is_word_type(int c)
{
	int		i;

	i = 0;
	if (c == CHR_ESCAPE)
		return (1);
	while (tkn_fun[i].type)
	{
		if (tkn_fun[i].type == c)
			return (0);
		i++;
	}
	return (1);
}

t_tkn		*tkn_word(char **str)
{
	t_tkn	*tkn;
	int		len;
	int		i;
	char	*line;
	int		is_esc;

	is_esc = 0;
	line = *str;
	len = 0;
	i = 0;
	while (line[i] != '\0' && is_word_type(line[i]))
	{
		if (line[i] == CHR_ESCAPE && !is_esc)
			is_esc = 1;
		else
		{
			is_esc = 0;
			len++;
		}
		i++;
	}
	tkn = tkn_init(len);
	tkn->data = esc_strncpy(tkn->data, line, len);
	tkn->type = CHR_WORD;
	line += i;
	*str = line;
	return (tkn);
}