/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:33:09 by ffood             #+#    #+#             */
/*   Updated: 2019/12/15 16:22:18 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_el(char *el)
{
	int			i;

	i = 0;
	while (el[i] >= '0' && el[i] <= '9')
		i++;
	if (el[i] == ',')
	{
		if (el[i + 1] != '0' && el[i + 2] != 'x')
			error_out();
		i += 2;
		while ((el[i] >= '0' && el[i] <= '9') || (el[i] >= 'a' && el[i] <= 'f'))
			i++;
		if (el[i] != '\0')
			error_out();
	}
	if (el[i] != '\0')
		error_out();
}

static int		count_size(char *line)
{
	int			size;
	char		**tmp;

	tmp = ft_strsplit((const char*)line, ' ');
	size = 0;
	while (tmp[size])
	{
		check_el(tmp[size]);
		free(tmp[size]);
		size++;
	}
	free(tmp);
	return (size);
}

static void		check_file(char *file_name)
{
	if (ft_strstr(file_name, ".fdf") == 0)
		error_out();
}

void			check_valid(char *file_name)
{
	char		*line;
	int			size;
	int			next_size;
	int			fd;

	check_file(file_name);
	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	size = count_size(line);
	while (get_next_line(fd, &line) > 0)
	{
		next_size = count_size(line);
		if (next_size != size)
			error_out();
	}
}
