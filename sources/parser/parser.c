/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:00:31 by tmaraval          #+#    #+#             */
/*   Updated: 2018/03/27 11:38:51 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** complete_command : list separator
 **					 | list
 **					 ;
 **	list			 : list separator_op and_or
 **					 |					 and_or
 **					 ;
 ** and_or			 : pipeline
 **					 ;
 ** pipeline		 : pipe_sequence
 **					 | Bang pipe_sequence
 **					 ;
 ** pipe_sequence	 : command
 ** 				 | pipe_sequence '|' linebreak command
 ** 				 ;
 **	command			 : simple_command
 **					 ;
 ** simple_command	 : cmd_prefix cmd_word cmd_suffix
 **                  | cmd_prefix cmd_word
 **                  | cmd_prefix
 **                  | cmd_name cmd_suffix
 **                  | cmd_name
 ** 				 ;
 ** cmd_name         : WORD                   * Apply rule 7a *
 **                  ;
 ** cmd_word         : WORD                   * Apply rule 7b *
 **                  ;
 ** cmd_prefix       : io_redirect
 **                  | cmd_prefix io_redirect
 **				     | ASSIGNMENT_WORD
 **					 | cmd_prefix ASSIGNMENT_WORD
 **					 ;
 ** cmd_suffix       : io_redirect
 **                  | cmd_suffix io_redirect
 **				     | WORD
 **					 | cmd_suffix WORD
 **					 ;
 ** io_redirect      :           io_file
 **                  | IO_NUMBER io_file
 **	                 |           io_here
 **	                 | IO_NUMBER io_here
 **	                 ;
 ** io_file          : '<'       filename
 **                  | LESSAND   filename
 **	                 | '>'       filename
 **	                 | GREATAND  filename
 **	                 | DGREAT    filename
 **	                 | LESSGREAT filename
 **	                 | CLOBBER   filename
 **                  ;
 ** filename         : WORD                      * Apply rule 2 *
 **                  ;
 ** io_here          : DLESS     here_end
 **                  | DLESSDASH here_end
 **                  ;
 ** here_end         : WORD                      * Apply rule 3 *
 **                  ;
 ** separator_op     : ';'
 **                  ;
 ** separator        : separator_op
 **				     ;
 ** sequential_sep   : ';'
 **                  ;
 **
 */
