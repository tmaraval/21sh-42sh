/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 02:41:50 by cormarti          #+#    #+#             */
/*   Updated: 2018/03/31 02:42:35 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

t_tkn	*tkn_dollar(char **str)
{
	t_tkn	*tkn;
	char	*line;

	line = *str;
	tkn = tkn_init(1);
	tkn->data[0] = CHR_DOLLAR;
	tkn->type = CHR_DOLLAR;
	line++;
	*str = line;
	return (tkn);
}
