/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:37:48 by tmaraval          #+#    #+#             */
/*   Updated: 2018/07/30 16:05:12 by tomux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_update_var_cat(char **newvalue, char *name, char *value)
{
	if (!(*newvalue = (char *)malloc(sizeof(char) *
	(ft_strlen(name) + 1 + ft_strlen(value) + 1))))
		error_malloc_err();
	ft_strcpy(*newvalue, name);
	ft_strcat(*newvalue, "=");
	ft_strcat(*newvalue, value);
}

int		env_update_var(char *name, char *value, char **myenv)
{
	char		*newvalue;
	char		*temp;
	int			i;

	i = 0;
	newvalue = NULL;
	if (name == NULL || value == NULL)
		return (0);
	env_update_var_cat(&newvalue, name, value);
	while (myenv[i])
	{
		temp = ft_strsub(myenv[i], 0, ft_strlen(name));
		if (ft_strcmp(temp, name) == 0)
		{
			free(temp);
			temp = myenv[i];
			myenv[i] = newvalue;
			free(temp);
			return (1);
		}
		free(temp);
		i++;
	}
	free(newvalue);
	return (0);
}

char	**env_add_var(char *name, char *value, char **myenv)
{
	int		i;
	char	**newenv;

	i = 0;
	while (myenv[i])
		i++;
	if (!((newenv = (char **)malloc(sizeof(char *) * (i + 2)))))
		error_malloc_err();
	i = -1;
	while (myenv[++i])
		newenv[i] = myenv[i];
	env_update_var_cat(&newenv[i], name, value);
	newenv[i + 1] = NULL;
	printf("before free : |%p|\n", myenv);
	free(myenv);
	printf("newenv : |%p|\n", newenv);
	myenv = newenv;
	return (newenv);
}

int		env_delete_var(char *name, char ***myenv)
{
	int			i;
	char		*temp;

	i = 0;
	if (name == NULL)
		return (0);
	while (myenv[0][i])
	{
		temp = ft_strsub(myenv[0][i], 0, ft_strlen(name));
		if (ft_strcmp(temp, name) == 0)
		{
			free(temp);
			utils_delete_in_2darray(myenv[0], i);
			return (1);
		}
		free(temp);
		i++;
	}
	return (0);
}
