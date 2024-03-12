/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:16:18 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/12 12:20:31 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_error(char *cmd)
{
	ft_putstr("zsh: command not found: ");
	ft_putstr(cmd);
	ft_putchar('\n');
}

void	error_handler(char **argv)
{
	if (errno == ENOENT)
	{
		ft_putstr("zsh: no such file or directory: ");
		ft_putstr(argv[1]);
		ft_putchar('\n');
	}
	else if (errno == EACCES)
	{
		ft_putstr("Permission denied for file: ");
		ft_putstr(argv[1]);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("Failed to open the file: ");
		ft_putstr(argv[1]);
		ft_putchar('\n');
	}
	exit (1);
}
