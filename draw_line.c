/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:32:19 by ffood             #+#    #+#             */
/*   Updated: 2020/01/21 13:53:44 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define MAX(x,y) x > y ? x : y

void set_pixel(int x, int y, int *image_pix)
{
    int i;

    i = SIZE_WIN * y + x;
    image_pix[i] = 0x58c1f5; //с цветом здесь потом надо разобраться
}

void ft_ly(int x, int y, int lx, int ly, int len, int *image_pix, int dx, int dy)
{
    int d = -lx;
    len++;
    while(len--)
    {
        set_pixel(x, y, image_pix);
        x += dx;
        d += 2 * ly;
        if (d > 0)
        {
            d -= 2 * lx;
            y += dy;
        }
    }
}

void ft_lx(int x, int y, int lx, int ly, int len, int *image_pix, int dx, int dy)
{
    int d = -ly;
 
    len++;
    while(len--)
    {
        set_pixel(x, y, image_pix);
        y += dy;
        d += 2 * lx;
        if (d > 0) 
        {
            d -= 2 * ly;
            x += dx;
        }
    }
}

void draw_line(int x1, int y1, int x2, int y2, int *image_pix)
{
    int x;
    int y;
    int dx;
    int dy;
    int lx;
    int ly;
    int length;

    dx = (x2 - x1 >= 0 ? 1 : -1);
    dy = (y2 - y1 >= 0 ? 1 : -1);
    lx = abs(x2 - x1);
    ly = abs(y2 - y1);
    length = MAX(lx, ly);
    if (length == 0)
        set_pixel(x1, y1, image_pix);
    if (ly <= lx)
        ft_ly(x1, y1, lx, ly, length, image_pix, dx, dy);
    else
        ft_lx(x1, y1, lx, ly, length, image_pix, dx, dy);
}