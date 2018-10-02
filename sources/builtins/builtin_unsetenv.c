/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:00:15 by tomlulu           #+#    #+#             */
/*   Updated: 2018/10/02 14:56:55 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "env.h"
#include "error.h"

int		builtin_unsetenv(char **cmd, char ***myenv)
{
	int i;
	int ret;

	i = 0;
	while (cmd[i])
		i++;
	if (i < 2)
	{
		error_print(TOOFEWARG, "unsetenv", "\0");
		return (-1);
	}
	i = 0;
	while (cmd[i])
	{
		ret = env_delete_var(cmd[i], myenv);
		remove_global(cmd[i]);
		i++;
	}
	return (ret);
}
