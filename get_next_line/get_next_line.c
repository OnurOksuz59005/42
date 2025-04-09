/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cascade                                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:41:15 by cascade           #+#    #+#             */
/*   Updated: 2025/04/09 13:41:15 by cascade          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Extracts a line from the static buffer
 * @param buffer The static buffer containing data read from fd
 * @return The extracted line (including \n) or the remaining buffer if no \n
 */
static void	process_buffer_with_newline(char **buffer, char *newline_pos,
	char **line)
{
	char	*temp;

	*line = ft_substr(*buffer, 0, newline_pos - *buffer + 1);
	temp = ft_strdup(newline_pos + 1);
	free(*buffer);
	*buffer = temp;
	if (**buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_pos;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
		process_buffer_with_newline(buffer, newline_pos, &line);
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

/**
 * @brief Reads from fd and appends to the static buffer until a newline is found
 * @param fd The file descriptor to read from
 * @param buffer The static buffer to store read data
 * @return 1 if read was successful, 0 if EOF or error
 */
static int	append_to_buffer(char **buffer, char *read_buf)
{
	char	*temp;

	if (!*buffer)
		*buffer = ft_strdup(read_buf);
	else
	{
		temp = ft_strjoin(*buffer, read_buf);
		free(*buffer);
		*buffer = temp;
	}
	return (1);
}

static int	read_to_buffer(int fd, char **buffer)
{
	char	*read_buf;
	ssize_t	bytes_read;

	read_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buf)
		return (0);
	bytes_read = 1;
	while (bytes_read > 0 && (!*buffer || !ft_strchr(*buffer, '\n')))
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(read_buf);
			return (0);
		}
		read_buf[bytes_read] = '\0';
		append_to_buffer(buffer, read_buf);
	}
	free(read_buf);
	return (1);
}

/**
 * @brief Reads a line from a file descriptor
 * @param fd The file descriptor to read from
 * @return The line read from fd (including \n), or NULL if there's nothing 
 *         else to read or if an error occurred
 */
char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_to_buffer(fd, &buffer))
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	return (extract_line(&buffer));
}
