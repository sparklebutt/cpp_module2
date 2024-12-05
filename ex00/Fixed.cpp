/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:50:25 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/05 17:48:53 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
const int Fixed:: fractionalBits = 8;

Fixed::Fixed() : rawValue(0) { std::cout<<"Default constructor called"<<std::endl; };
Fixed::Fixed(const Fixed &other)
{
	*this = other;
	std::cout<<"copy constructor called"<<std::endl;
}
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
		rawValue = other.getRawBits();
	return *this;
}
Fixed::~Fixed() { std::cout<<"Destructor called"<<std::endl; }

int	Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return rawValue;
}

void Fixed::setRawBits(int const raw)
{
	rawValue = raw;
	std::cout<<"setRawBits member function called"<<std::endl;	
}