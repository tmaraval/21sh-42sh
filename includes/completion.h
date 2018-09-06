/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:23:36 by tmaraval          #+#    #+#             */
/*   Updated: 2018/09/06 10:38:46 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H 
int		completion_in_first_word(char *userinput, int pos);
t_list *completion_read(char **dirs);
t_list *completion_cmp_userinput_filelist(char *userinput, t_list *filelist);
void	completion_print(t_buffer *tbuffer, t_list *filelist);

#endif
