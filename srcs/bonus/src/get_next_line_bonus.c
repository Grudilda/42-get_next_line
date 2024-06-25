/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudilda <grudilda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:58:15 by grudilda          #+#    #+#             */
/*   Updated: 2024/06/22 23:23:47 by grudilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

/* 
** This function browses the complete read (stash + buf) to find if a '\n'
** is in the string. 
** It also put a terminator character just after the '\n' character to set
** the final return of the __get_next_line__ function.
**
** @brief __stock_in_stash__ is a function that return the rest of the string 
** (after the '\n' previously read in the function __read_line__.
** This rest is stock in a static variable to be used at the next call
** of __get_next_line__. It also put the terminator character at the end
** of the 'line' which is the final return the __get_next_line__ function
** @param line the complete read from __read_line__ (stash + buf)
** @return a string with the rest of the string read (after the '\n') 
*/

static char	*stock_in_stash(char *line)
{
	char	*stash;
	size_t	index;
	size_t	start;
	size_t	len;

	index = 0;
	while (line[index] != '\n' && line[index] != '\0')
		index++;
	if (line[index] == 0 || line[1] == 0)
		return (NULL);
	start = index + 1;
	len = ft_strlen(line) + 1;
	stash = ft_substr(line, start, len);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line[index + 1] = 0;
	return (stash);
}

/* 
** This function reads the file descriptor while there is no newline find in
** the buf (what the read(2) function has read). 
** If the read(2) function return a -1 the function free(3) the stash and
** return NULL.
** If the read(2) function reach the end of file it breaks the loop and
** returns what read(2) read in its entirety.
** If the function __ft_strchr__ finds a newline character ('\n') in buf
** it breaks the loop and returns what read(2) read in its entirety.
**
** @brief __read_line__ reads a line with the read(2) function. It reads 
** while there is no newline character ('\n') found in what it read.
** @param fd the file descriptor from which to read
** @param stash the rest of the previous call of the function __get_next_line__
** @param buf the string in which read(2) stocks what it has read
** @return a string with the complete read (stash + buf)
*/

static char	*read_line(int fd, char *stash, char *buf)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == READ_ERROR)
		{
			free(stash);
			return (NULL);
		}
		else if (bytes_read == EOF_REACHED)
			break ;
		buf[bytes_read] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

/* 
** This function set the variable stash[fd] so that the __get_next_line__
** function can read from several files descriptor without overwrite
** one another. So it will read on the current fd (the one on INPUT) and 
** not another one.
** The function starts by allocates buf with the size of BUFFER_SIZE + 1
** (for the terminator character) and does the the security checks -> if
** file descriptor is valid, if the BUFFER_SIZE is valid and if read(2)
** fails. If one of them is true, then the function free(3) and set at
** NULL stash[fd] and buf and then return [NULL].
** Then it use __read_line__ fill the 'line' variable with what read(2)
** read in its entirety.
** It then free(3) and set at NULL buf.
** If line is NULL then the function return NULL and if not it continues
** the setting of the rest (stash) and the final return with the
** __stock_in_stack__ function.
** The it returns 'line'.
*/

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		free(buf);
		stash[fd] = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = read_line(fd, stash[fd], buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stash[fd] = stock_in_stash(line);
	return (line);
}
