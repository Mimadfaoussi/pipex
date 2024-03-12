/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:50:51 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/12 12:15:34 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
*ft_strncmp- will compare between two strings
* @str:first string to compare with , will represent a PATH dir
* @str2: will represent second string in our case "PATH="
* n = 5 "PATH=5
* Return: 1 if we find the match other wise 0
*/

int	ft_strncmp(char *str, char *str2, int n)
{
	int	i;

	i = 0;
	if (str == NULL || str2 == NULL)
		return (1);
	while (str[i] == str2[i] && i < n && str[i] && str2[i])
	{
		i++;
	}
	if (i == n)
		return (1);
	return (0);
}

void	ft_strcpy(char	*final_path, char *cmd, int nb)
{
	int	i;

	i = 0;
	while (cmd[i] && i < nb)
	{
		final_path[i] = cmd[i];
		i++;
	}
	final_path[i] = '\0';
}

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (!src || !dst)
		return (0);
	if (destsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && (i < destsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_length);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
