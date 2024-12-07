/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:48:43 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/07 14:49:14 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>

/**
 * @brief const Fixed x and y are attributes 
 * 
 */

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		std::string m_name;
	public:
		Point();
		Point(const float initX, const float initY, std::string name);
		Point(const Point& other);
		Point& operator=(const Point& other);

		Fixed	getX() const;
		Fixed 	getY() const;
		std::string getName();
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);