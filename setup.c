/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:50:16 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/11 06:54:14 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
* validate_args-will check the args if they ok
* @argc:nb of arguments.
* @argv:the arguments.
* Return: 1 if all good or 0 if not.
**/

char	**ft_getenv(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 1 && env[i])
		i++;
	path = ft_split(env[i] + 5, ':');
	return (path);
}

/**
* ft_create_cmd_path-create the final command path
* @path:the path where the excutable is found.
* @cmd: the command to join with the path PATH + / + CMD
* Return: the final command with full path
**/

char	*ft_create_cmd_path(char *path, char *cmd)
{
	int		i;
	int		j;
	char	*final_path;

	if (path == NULL || cmd == NULL)
		return (NULL);
	i = 0;
	while (path[i])
		i++;
	j = 0;
	while (cmd[j])
		j++;
	final_path = malloc(i + j + 2);
	if (!final_path)
		return (NULL);
	ft_strcpy(final_path, path, i);
	ft_strcpy(final_path + i, "/", 1);
	ft_strcpy(final_path + i + 1, cmd, i + j + 1);
	return (final_path);
}
/**
*check_all_paths-will create each possible path and check if its valid
* @path: enviroment variable
* @cmd: the command to check which is a list containt cmd and args end with null
* Return: the final path of the command or NULL in case didn't find it 
**/

char	*check_all_paths(char	**path, char	**cmd)
{
	int		i;
	char	*final_path;

	i = 0;
	while (path[i])
	{
		final_path = ft_create_cmd_path(path[i], cmd[0]);
		if (access(final_path, X_OK) == 0)
		{
			return (final_path);
		}
		free(final_path);
		i++;
	}
	return (NULL);
}

void	free_all_str(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
