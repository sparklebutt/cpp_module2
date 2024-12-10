/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:48:18 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/10 11:20:33 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed:: fractionalBits = 8;

Fixed::Fixed() : rawValue(0)
{ /*std::cout<<"Default constructor called"<<std::endl;*/ };
Fixed::Fixed(const Fixed &other)
{
	*this = other;
	//std::cout<<"copy constructor called"<<std::endl;
}
Fixed& Fixed::operator=(const Fixed &other)
{
	//std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
		rawValue = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int number)
{ 
	rawValue = number << fractionalBits;
}

Fixed::Fixed(const float floatingNumber)
{
	 rawValue = static_cast<int>(roundf(floatingNumber * (1 << fractionalBits)));
}

Fixed::~Fixed()
{ /*std::cout<<"Destructor called"<<std::endl;*/ }

int	Fixed::getRawBits( void ) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return rawValue;
}

void Fixed::setRawBits(int const raw)
{
	rawValue = raw;
}

float Fixed::toFloat( void ) const 
{ return static_cast<float>(rawValue) / (1 << fractionalBits); }

int Fixed::toInt( void ) const
{ return rawValue >> fractionalBits; }


std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{ 
	return out << fixed.toFloat();
}