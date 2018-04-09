/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:41:10 by tmaraval          #+#    #+#             */
/*   Updated: 2018/03/29 17:44:50 by tmaraval         ###   ########.fr       */
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
	fptr = malloc(sizeof(void (*)(t_buffer *, char *)) * 3);
	fptr[0] = input_arrow_left;
	fptr[1] = input_arrow_right;
	fptr[2] = NULL;
	return (fptr);
}

char	*readline(t_cmd_hist **head, t_term_cap *cur_termcap)
{
	t_buffer	tbuffer;
	char		*read_buf;
	void		(**fptr)(t_buffer *, char *);
	int			i;

	i = 0;
	tbuffer.cnt = 0;
	tbuffer.index = 0;
	tbuffer.line = 1;
	tbuffer.cutstart = 0;
	tbuffer.cutend = 0;
	tbuffer.state = READ_NORMAL;
	tbuffer.buffer = malloc(sizeof(char) * BUFFER_SIZE);
	read_buf = malloc(sizeof(char) * MAX_KEYCODE_SIZE);	
	ft_bzero(tbuffer.buffer, BUFFER_SIZE);
	ft_bzero(tbuffer.cutbuffer, BUFFER_SIZE);
	ft_bzero(read_buf, MAX_KEYCODE_SIZE);
	fptr = readline_get_func_array();
	tbuffer.termcap = cur_termcap;
	while (tbuffer.state == READ_NORMAL)
	{
		i = 0;
		read(0, read_buf, MAX_KEYCODE_SIZE);
		while (fptr[i])
		{
			(fptr[i])(&tbuffer, read_buf);
			i++;
		}
		ft_bzero(read_buf, MAX_KEYCODE_SIZE);
	}
	if (head)
		;
	return (tbuffer.buffer);
}

int		main(void)
{
	t_term_cap		*cur_termcap;
	char			*line;
	t_cmd_hist		*head;
	t_token			*root_token;

	root_token = NULL;
	cur_termcap = term_init();
	while (1)
	{	
		line = readline(&head, cur_termcap);
	}
}
