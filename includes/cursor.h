/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:08:16 by tmaraval          #+#    #+#             */
/*   Updated: 2018/03/02 11:31:31 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

#include "readline.h"


void	cursor_delete_line(int linebr);
void	cursor_move_left_upd_tbuffer(int count, t_buffer *tbuffer);
void	cursor_move_left(int count);
void	cursor_move_right_upd_tbuffer(int count, t_buffer *tbuffer);
void	cursor_move_right(int count);
void	cursor_save_pos(void);
void	cursor_reload_pos(void);
void	cursor_up_line(int linenbr);
#endif
