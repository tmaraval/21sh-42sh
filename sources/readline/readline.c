/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:41:10 by tmaraval          #+#    #+#             */
/*   Updated: 2018/04/09 10:46:12 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <termcap.h>
#include <term.h>
#include "cursor.h"
#include "key.h"
#include "lexer.h"

/*
*******************************************************************************
********************************************************************************
** Here is the readline main file.
** It use a tbuffer struct (declared in readline.h)
** which uses three different int to know the cursor position in the shell.
** the colnbr which give us the number of colon in the term
** the index parameter who tell us where we are in the colunm.
** it is reseted whenever we go down a line ex (with 10 colunm) :
**
** $ >   0 1 2 3 4 5 6
** > 0 1 2 3 4 5 6 7 8
** 0 1 2 3 4 5 6 7 8 9
** 0 1 2 3 4 5 6 7 8 9
**
** the cnt parameter give us where we are in the buffer string.
** it isn't reseted. Ex :
** $ >   0 1 2 3 4 5 6
** 7 8 9 10111213141516
** 17181920212223242526
**
** In all function we check if we are in line 1
** if yes we need to take in count the prompt len.
********************************************************************************
********************************************************************************
*/

void	*readline_get_func_array()
{
	void (**fptr)(t_buffer *, char *);
	
	fptr = malloc(sizeof(void (*)(t_buffer *, char *)) * 18);
	fptr[0] = input_arrow_left;
	fptr[1] = input_arrow_right;
	fptr[2] = insert_char;
	fptr[3] = input_arrow_up;
	fptr[4] = input_arrow_down;
	fptr[5] = input_backspace;
	fptr[6] = input_delete;
	fptr[7] = input_home;
	fptr[8] = input_end;
	fptr[9] = input_arrow_shift_updown;
	fptr[10] = input_shift_right_left;
	fptr[11] = input_select_left;
	fptr[12] = input_select_right;
	fptr[13] = input_paste;
	fptr[14] = input_cut;
	fptr[15] = input_copy;
	fptr[16] = input_enter;
	fptr[17] = NULL;
	return (fptr);
}

char	*readline(t_buffer *tbuffer, t_cmd_hist **head)
{
	char		*read_buf;
	void		(**fptr)(t_buffer *, char *);
	int			i;

	i = 0;
	read_buf = malloc(sizeof(char) * MAX_KEYCODE_SIZE);	
	ft_bzero(read_buf, MAX_KEYCODE_SIZE);
	fptr = readline_get_func_array();
	*head = history_read();
	tbuffer->head_hist = head;
	prompt_print(tbuffer);
	while (tbuffer->state == READ_NORMAL || tbuffer->state == READ_IN_QUOTE)
	{
		i = 0;
		read(0, read_buf, MAX_KEYCODE_SIZE);
		while (fptr[i])
		{
			(fptr[i])(tbuffer, read_buf);
			i++;
		}
		ft_bzero(read_buf, MAX_KEYCODE_SIZE);
	}
	free(fptr);
	return (tbuffer->buffer);
}

void	tbuffer_init(t_buffer *tbuffer)
{
	t_term_cap		*cur_termcap;
	
	cur_termcap = term_init();
	tbuffer->cnt = 0;
	tbuffer->index = 0;
	tbuffer->line = 1;
	tbuffer->cutstart = 0;
	tbuffer->cutend = 0;
	tbuffer->state = READ_NORMAL;
	tbuffer->colnbr = tgetnum("co");
	tbuffer->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	ft_bzero(tbuffer->buffer, BUFFER_SIZE);
	ft_bzero(tbuffer->cutbuffer, BUFFER_SIZE);
	tbuffer->termcap = cur_termcap;
}

int		main(void)
{
	char			*line;
	t_cmd_hist		*head;
	t_buffer		tbuffer;

	tbuffer_init(&tbuffer);
	while (1)
	{	
		line = readline(&tbuffer, &head);
		ft_putstr("\n");
		//tbuffer.state = READ_IN_QUOTE;
		// go lexer parse etc..
	}
}
