/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_tbuffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:47:52 by tmaraval          #+#    #+#             */
/*   Updated: 2018/03/13 09:08:51 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termcap.h>
#include <term.h>
#include <cursor.h>

void	cursor_move_left_upd_tbuffer(int count, t_buffer *tbuffer)
{
	int		lastcol;
	int		prompt_len;

	lastcol = 0;
	//ft_printf("\n|cnt = %d index = %d line = %d colnbr = %d|\n", tbuffer->cnt, tbuffer->index, tbuffer->line, tbuffer->colnbr);
	prompt_len = readline_print_prompt(FALSE);
	while (count > 0 && tbuffer->cnt > -3)
	{
		if (tbuffer->line != 1 && tbuffer->cnt != 1 && tbuffer->index == 0)	
		{
	//	ft_printf("\n\n\n\n??f.e.fpflefpelfpelpfelpefl");
			tbuffer->line--;
			tputs(tbuffer->termcap->up, 0, ft_putcc);
			cursor_move_right(tbuffer->colnbr + 1);
			if (tbuffer->line == 1)
				tbuffer->colnbr -= prompt_len;
			tbuffer->index = tbuffer->colnbr;
			tbuffer->index--;
		}
		else
		{
			tbuffer->index--;
			tputs(tbuffer->termcap->le, 0, ft_putcc);
		}
		tbuffer->cnt--;
		count--;
	}
//	ft_printf("\n|cnt = %d index = %d line = %d colnbr = %d|\n", tbuffer->cnt, tbuffer->index, tbuffer->line, tbuffer->colnbr);
}

void	cursor_move_right_upd_tbuffer(int count, t_buffer *tbuffer)
{
	int		prompt_len;

	//ft_printf("\n\n%d|%d\n\n", tbuffer->index, tbuffer->colnbr);
	prompt_len = readline_print_prompt(FALSE);
	while (count && tbuffer->cnt < (int)ft_strlen(tbuffer->buffer))
	{
		if (tbuffer->index == tbuffer->colnbr - 1)
		{
		//	temp = tgetstr("sf", NULL);
			tputs(tbuffer->termcap->sf, 0, ft_putcc);
			tbuffer->index = 0;
			tbuffer->line++;
			if (tbuffer->line == 2)
				tbuffer->colnbr += prompt_len;
		}
		else
		{
			tbuffer->index++;
			//temp = tgetstr("nd", NULL);
			tputs(tbuffer->termcap->nd, 0, ft_putcc);
		}
		count--;
		tbuffer->cnt++;
	}
}
