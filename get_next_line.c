/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:05:38 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/28 10:16:45 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char	**buffer_backup)
{
	size_t	i;
	char	*tmp_free;
	char	*line_return;

	i = 0;
	while ((*buffer_backup)[i] != '\n' && (*buffer_backup)[i] != '\0')
		i++;
	tmp_free = *buffer_backup;
	line_return = ft_substr(tmp_free, 0, i + 1);
	*buffer_backup = ft_strdup(&tmp_free[i + 1]);
	free(tmp_free);
	return (line_return);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*buffer_backup;
	int		bytes_read;
	char	*tmp_free;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer_backup, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		tmp_free = buffer_backup;
		buffer_backup = ft_strjoin(tmp_free, buffer);
		free(tmp_free);
	}
	line = get_line(&buffer_backup);
	free(buffer);
	return (line);
}
