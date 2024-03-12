/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:56:36 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/12 12:20:15 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

void	pipex(int f1, int f2, char **argv, char **env);
int		child_process(int f1, int fd[2], char **argv, char **env);
void	parent_process(int f2, int fd[2], char **argv, char **env);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
void	ft_strcpy(char	*final_path, char *cmd, int nb);
int		ft_strncmp(char *str, char *str2, int n);
int		ft_strlen(const char *str);
char	**ft_getenv(char **env);
char	*ft_create_cmd_path(char *path, char *cmd);
char	*check_all_paths(char	**path, char	**cmd);
void	free_all_str(char **res);
char	**ft_split(char const *str, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	error_handler(char **argv);
void	command_error(char *cmd);

#endif