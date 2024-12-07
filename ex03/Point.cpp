/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:13:59 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/07 14:51:57 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include "Point.hpp"
Point::Point() : x(0), y(0), m_name("unamed")
{
	std::cout<<"point created initilized to 0"<<std::endl;
}
std::string Point::getName() {return m_name;}
Point::Point(const float initX, const float initY, std::string name) : x(initX), y(initY), m_name(name)
{
	std::cout<<"point "<<name<<" initilized x = "<<initX<<" and y = "<<initY<<std::endl;
}

Fixed Point::getX() const {return x;}
Fixed Point::getY() const {return y;}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		getX() = other.x;
		getY() = other.y;
	}
	return *this;
}
Point::~Point() { std::cout<<"point destroyed"<<std::endl;}