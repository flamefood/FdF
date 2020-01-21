/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:55:26 by ffood             #+#    #+#             */
/*   Updated: 2019/12/12 14:03:05 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			error_out(void)
{
	ft_putendl("Error!");
	exit(1);
}

int key_hook(int keycode,void *param)
{
    if (keycode == 53)
        exit(1);
    return(0);
}

int main(int argc, char **argv)
{
    void    *mlx_ptr; // идентификатор подключения к графическому серверу
    void    *win_ptr; // идентификатор окна
    void    *img_ptr;
    int     bpp;
    int     size_line;
    int     end;
    int     *image_pix;
    int     i;
    int     x;
    int     y;
    int     **map;
    
    //if (argc != 2)
    //    error_out();
    //map = read_file(argv[1]);
    mlx_ptr = mlx_init(); //создает соединение с графической системой
    win_ptr = mlx_new_window(mlx_ptr, SIZE_WIN, SIZE_WIN, "mlx");  // открывает окно
    
    img_ptr = mlx_new_image(mlx_ptr, SIZE_WIN, SIZE_WIN);
    image_pix = (int *)mlx_get_data_addr (img_ptr, &bpp, &size_line, &end);

    draw_line(0, 0, 500, 500, image_pix);
    
    mlx_put_image_to_window (mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_key_hook(win_ptr, key_hook, (void*)0);
    mlx_loop(mlx_ptr); // получение событий
}
