/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:05:38 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/29 16:21:14 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char	**buffer_backup, char	*ptr_n)
{
	char	*tmp_free;
	char	*line_return;
	int	i;
	//while ((*buffer_backup)[i] != '\n' && (*buffer_backup)[i] != '\0')
	//	i++;
	/*if (*buffer_backup[i] == 0)
	{
		line_return = *buffer_backup;
		*buffer_backup = NULL;
		return (line_return);
	}*/
	if (!ptr_n)
	{
		if (**buffer_backup == '\0')
		{
			free(*buffer_backup);
			*buffer_backup = NULL;
			return (NULL);
		}
		line_return = *buffer_backup;
		*buffer_backup = NULL;
		return (line_return);
	}
	tmp_free = *buffer_backup;
	i =  ptr_n - tmp_free + 1;
	line_return = ft_substr(tmp_free, 0, i);
	*buffer_backup = ft_strdup(&tmp_free[i]);
	free(tmp_free);
	tmp_free = NULL;
	return (line_return);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*buffer_backup;
	int		bytes_read;
	char	*tmp_free;
	char	*line;
	char	*ptr_nl;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ptr_nl = ft_strchr(buffer_backup, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
		{
			free(buffer);
			buffer = NULL;
			return (get_line(&buffer_backup, 0));
		}
		buffer[bytes_read] = '\0';
		tmp_free = buffer_backup;
		buffer_backup = ft_strjoin(tmp_free, buffer);
		free(tmp_free);
		tmp_free = NULL;
	}
	line = get_line(&buffer_backup, ptr_nl);
	free(buffer);
	buffer = NULL;
	return (line);
}
