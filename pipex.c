/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:07:33 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/12 12:21:42 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int f1, int fd[2], char **argv, char **env)
{
	char	**cmd1;
	char	*final_path;
	char	**path;

	path = ft_getenv(env);
	cmd1 = ft_split(argv[2], ' ');
	if (access(cmd1[0], X_OK) == 0)
		final_path = cmd1[0];
	else
		final_path = check_all_paths(path, cmd1);
	if (!final_path)
	{
		command_error(cmd1[0]);
		free_all_str(path);
		free_all_str(cmd1);
		return (1);
	}
	dup2(f1, STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(f1);
	free_all_str(path);
	execve(final_path, cmd1, NULL);
	return (0);
}

void	parent_process(int f2, int fd[2], char **argv, char **env)
{
	char	**cmd2;
	char	*final_path;
	char	**path;

	path = ft_getenv(env);
	cmd2 = ft_split(argv[3], ' ');
	if (access(cmd2[0], X_OK) == 0)
		final_path = cmd2[0];
	else
		final_path = check_all_paths(path, cmd2);
	if (!final_path)
	{
		command_error(cmd2[0]);
		free_all_str(path);
		free_all_str(cmd2);
		exit(127);
	}
	close(fd[1]);
	dup2(f2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(f2);
	close(fd[0]);
	free_all_str(path);
	execve(final_path, cmd2, NULL);
}

void	pipex(int f1, int f2, char **argv, char **env)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
	{
		f1 = open(argv[1], O_RDONLY);
		if (f1 < 0)
			error_handler(argv);
		child_process(f1, fd, argv, env);
	}
	else
	{
		f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f2 < 0)
			exit (1);
		wait(NULL);
		parent_process(f2, fd, argv, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	f1;
	int	f2;

	f1 = 0;
	f2 = 0;
	if (argc != 5)
	{
		perror("wrong number of args");
		return (1);
	}
	pipex(f1, f2, argv, env);
	return (0);
}
