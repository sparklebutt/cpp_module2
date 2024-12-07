/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:13:00 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/07 14:52:59 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <stdio.h>
/**
 * @brief 
 * we first normalize the and validate the triangle with fixed denominator, 
 * by normalizing the denominator we get a single value representing the triangle 
 * we will use to normalize u and v . dividing by the denominator will give us a value 
 * between 0 and 1 which gives us a simple number for comparison. a number outside 0 or 1 will be considered
 * outside the triangle 
 * 
 * @param a point of trinagle 
 * @param b point of triangle
 * @param c point of triangle
 * @param point the point we are trying to evaluate, if it is inside the triangle
 * formed by point a b and c.
 * @return true if point is in triangle
 * @return false if point is not in trinagle
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed denominator((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
    if (denominator == 0)
	{
		std::cerr<<"a b and c do not form a valid triangle"<<std::endl;
		return false; //handle this differebntly 
	}
    Fixed u = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed v = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed w = Fixed(1) - u - v;
    return (u >= Fixed(0)) && (u <= Fixed(1)) &&
           (v >= Fixed(0)) && (v <= Fixed(1)) &&
           (w >= Fixed(0)) && (w <= Fixed(1));
}
