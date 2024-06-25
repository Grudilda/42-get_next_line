/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudilda <grudilda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:27:32 by grudilda          #+#    #+#             */
/*   Updated: 2024/06/22 23:32:29 by grudilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ************************************************************************** */
/*                                INCLUDES                                    */
/* ************************************************************************** */

/*********************/
/*     LIBRARIES     */
/*********************/
# include <unistd.h>
# include <stdlib.h>

/*******************/
/*     DEFINES     */
/*******************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define READ_ERROR -1
# define EOF_REACHED 0

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/*****************************/
/*     GET_NEXT_LINE FILE    */
/*****************************/

/*
** @brief __get_next_line__ is a function that returns a
** line read from a file descriptor.
** @param fd the file descriptor to read from
** @return Read line: correct behavior || 
** [NULL]: there is nothing else to read, or an error occurred
*/
char	*get_next_line(int fd);

/***********************************/
/*     GET_NEXT_LINE_UTILS FILE    */
/***********************************/

/*
** @brief __ft_strlen__ calculates the length of the string
**pointed to by s, excluding the terminating null byte ('\0').
** @param s string to calculate the length 
** @return the length of the string
*/
size_t	ft_strlen(const char *s);

/*
** @brief __ft_strchr__ return a pointer to the matched character or NULL if
** the character is not found. The terminating null byte is
** considered part of the string, so that if c is
** specified as '\0', these functions return a pointer to
** the terminator.
** @param s the string in which to locate the character
** @param c the string in which to locate the character
** @return A pointer to the first occurrence of c 
*/
char	*ft_strchr(char *s, int c);

/*
** @brief __ft_strdup__  returns a pointer to a new string which is a
** duplicate of the string s. Memory for the new string is obtained
** with malloc(3), and can be freed with free(3).
** @param s1 the string to duplicate
** @return A pointer to the duplicated string || [NULL] if allocation failed
*/
char	*ft_strdup(const char *s1);

/*
** @brief __ft_strjoin__ allocates (with malloc(3)) and returns a substring
** from the string ’s’. The substring begins at index ’start’ and is of
** maximum size ’len’.
** @param s1 the prefix string
** @param s2 the suffix string
** @return the new string || [NULL] if the allocation failed
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
** @brief __ft_substr__ allocates and returns a sub-string from the string 's'.
** this new string starts at the 'start' index and has 'len' as max length.
** @param s the original string from which the sub-string is extract
** @param start start index of the sub-string
** @param len the maximum length of the sub-string
** @return the sub-string || [NULL] if the allocation failed
*/
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif