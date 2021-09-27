/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:18:49 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/23 09:43:22 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sub_len;

	i = 0;
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	sub_len = ft_strlen(&s[start]);
	if (len > sub_len)
		len = sub_len;
	sub = malloc((len + 1) * sizeof(char));
	if (! sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);

}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	join = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (! join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (join);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	if (! src || ! dst)
		return (0);
	src_len = ft_strlen(src);
	if (! dstsize)
		return (src_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total = dst_len + src_len;
	if (! (dstsize))
		return (src_len);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	while (dst_len < dstsize - 1 && *src)
	{
		dst[dst_len++] = *src;
		src++;
	}
	dst[dst_len] = '\0';
	if (dst_len < total)
		return (total);
	return (dst_len);
}


size_t	ft_strlen(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux] != '\0')
	{
		aux++;
	}
	return (aux);
}


char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	ptr = malloc(s_len * sizeof(char));
	if (! ptr)
		return (NULL);
	return (ft_memcpy(ptr, s, s_len));
}


void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}


char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	char	*ptr;

	ptr = (char *)s;
	s_len = ft_strlen(ptr) + 1;
	while (s_len--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
