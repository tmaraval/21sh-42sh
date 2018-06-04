/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:00:31 by tmaraval          #+#    #+#             */
/*   Updated: 2018/06/02 04:13:53 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"
#include "../../includes/parser.h"

enum e_tkn_type		type[][8] =
{
	{ CHR_WORD, CHR_NULL },
	{ CHR_IO_NUMBER, CHR_WORD, CHR_NULL },
	{ CHR_IO_NUMBER, CHR_WORD, CHR_NULL },
	{ CHR_IO_NUMBER, CHR_WORD, CHR_DASH, CHR_NULL },
	{ CHR_IO_NUMBER, CHR_WORD, CHR_NULL },
	{ CHR_IO_NUMBER, CHR_WORD, CHR_DASH, CHR_NULL }, // GREATAND
	{ CHR_IO_NUMBER, CHR_WORD, CHR_NULL },
	{ CHR_GREAT, CHR_CLOBBER, CHR_LESS, CHR_LESSAND, CHR_DGREAT, CHR_GREATAND,
		CHR_LESSGREAT, CHR_NULL },
	{ CHR_WORD, CHR_NEWLINE, CHR_DASH, CHR_ASSIGNMENT_WORD, CHR_NULL },
	{ CHR_IO_NUMBER, CHR_WORD, CHR_NULL },  // DLESS
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_WORD, CHR_ASSIGNMENT_WORD, CHR_NEWLINE, CHR_NULL }, // SEMI
	{ CHR_NULL },
	{ CHR_WORD, CHR_ASSIGNMENT_WORD, CHR_NULL },
	{ CHR_WORD, CHR_ASSIGNMENT_WORD, CHR_NULL },
	{ CHR_WORD, CHR_ASSIGNMENT_WORD, CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL },
	{ CHR_NULL }
};

static int		valid_tkn_type(t_tkn *tkn)
{
	int		i;

	i = 0;
	while (type[tkn->type][i] != CHR_NULL)
	{
		if (tkn->next->type == type[tkn->type][i])
			return (1);
		else
			i++;
	}
	return (0);
}

int				parse(t_tkn *tkn)
{
	int		i;

	i = 0;
	tkn = tkn->next;
	free(tkn->prev->data);
	free(tkn->prev);
	tkn->prev = NULL;
	while (tkn->next)
	{
		if (tkn->type == CHR_WORD || tkn->type == CHR_ASSIGNMENT_WORD)
			tkn = tkn->next;
		else
		{
			if (!valid_tkn_type(tkn))
			{
				ft_putstr("Syntax error : unexpected token ");
				ft_putendl(tkn->next->data);
				return (0);
			}
			else
				tkn = tkn->next;
		}
	}
	return (1);
}
