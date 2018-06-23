/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:36:01 by cormarti          #+#    #+#             */
/*   Updated: 2018/06/23 15:35:31 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "astree.h"
#include "exec.h"
#include "ext_node_fun.h"

int		check_exec_exception(t_exec *exec)
{
	return (exec->parent == NT_PIPE ? 1 : 0);
}

int		node_ret(t_astree *astree)
{
	if (astree->type == NT_AND_IF
		|| astree->type == NT_PIPE)	
		return (0);
	else
		return (1);
}

int				exec_node(t_astree *astree, char **env, t_exec *exec)
{
	int		i;
	int		last_exec;

	i = 0;
	if (astree->left->type != NT_CMD)
	{
	//	exec->nodeact--;
		if (astree->left->type != NT_CMD)
			exec->parent = astree->type;
		last_exec = exec_node(astree->left, env, exec);
	}
	// while (node_fun[i].type)// ne parcourt pas...
	while (i < 1)
	{
		if (node_fun[i].type == astree->type)
			return (node_fun[i].fun(astree, env, exec));
		i++;
	}
	exit(1);
	return (0);
}
