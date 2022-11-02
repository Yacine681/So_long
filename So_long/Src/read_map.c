/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:19:37 by yabed             #+#    #+#             */
/*   Updated: 2022/07/20 13:18:35 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

char	**read_map(char **argv)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	i = 0;
	fd = open(*argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Map does not exist!\n");
		exit (0);
	}
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	return (map);
}
