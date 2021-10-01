/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:05:38 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/30 23:53:50 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char	**buffer_backup, char	*ptr_n)
{
	char	*tmp_free;
	char	*line_return;
	size_t	i;

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
	i = ptr_n - tmp_free + 1;
	line_return = ft_substr(tmp_free, 0, i);
	*buffer_backup = ft_strdup(&tmp_free[i]);
	free(tmp_free);
	tmp_free = NULL;
	return (line_return);
}

char	*read_file(int fd, char	*buffer, char **buffer_backup)
{
	ssize_t	bytes_read;
	char	*tmp_free;

	while (!ft_strchr(*buffer_backup, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
		{
			return (get_line(buffer_backup, 0));
		}
		buffer[bytes_read] = '\0';
		tmp_free = *buffer_backup;
		*buffer_backup = ft_strjoin(tmp_free, buffer);
		free(tmp_free);
		tmp_free = NULL;
	}
	return (get_line(buffer_backup, ft_strchr(*buffer_backup, '\n')));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_file(fd, buffer, &buffer_backup);
	free(buffer);
	buffer = NULL;
	return (line);
}
