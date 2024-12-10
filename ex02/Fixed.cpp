/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:48:18 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/10 11:44:46 by araveala         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed& other) const
{
	return this->rawValue > other.rawValue;	
}
bool Fixed::operator<(const Fixed& other) const
{
	return this->rawValue < other.rawValue;	
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->rawValue >= other.rawValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->rawValue <= other.rawValue;
}
bool Fixed::operator==(const Fixed& other) const
{
	return this->rawValue == other.rawValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->rawValue != other.rawValue;	
}

/**
 * @brief when the operator overload is called the object infront
 * of the operator is considered the caller therefor it shall be handled 
 * as *this, the object after operator will be considered the parameter thus
 * will be referred to as &other, return value is sent to object waiting for
 * a value , which will be used to call the copy constructor once value has
 * been calculated. returning an int would lead to more bitshifting and potentailly
 * loosing the encapsulation of the class.
 * 
 * @param other the object after the operator is consdiered the parameter 
 * @return new object with new value that will be the initilization value 
 * of the product or in other terms result variable 
 */
Fixed Fixed::operator*(const Fixed& other)
{
	Fixed value;
	value.rawValue = static_cast<int>((static_cast<long long>(this->rawValue) * other.rawValue) >> fractionalBits);
	return value;
}
Fixed Fixed::operator/(const Fixed& other)
{
	Fixed value;
	long long div = static_cast<long long>((this->rawValue) << fractionalBits);
	value.rawValue = static_cast<int>(div / other.rawValue);
	return value;
}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed value;
	value.rawValue = this->rawValue + other.rawValue;
	return value;
}
Fixed Fixed::operator-(const Fixed& other)
{
	Fixed value;
	value.rawValue = this->rawValue - other.rawValue;
	return value;
}

/*pre and post incrementatioń*/
/**
 * @brief our incremenation is happenig on a fixed point value
 * using "epsilon" 1 is the smallest possible bit value we can assign
 * when we convert back to float it takes the smallest bit value and turns it
 * into a decimal number with bitshifting.n kind of like packing and unpacking a zip file 
 * 
 * @return Fixed 
 */
Fixed Fixed::operator++() {
	rawValue += 1;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed dummy = *this;
	rawValue += 1;
	return dummy;
}
Fixed Fixed::operator--() {
	rawValue -= 1;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed dummy = *this;
	rawValue -= 1;
	return dummy;
}



const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	return obj1 > obj2 ? obj1 : obj2;
}
Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	return obj1 > obj2 ? obj1 : obj2;
}
const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	return obj1 < obj2 ? obj1 : obj2;
}
Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	return obj1 < obj2 ? obj1 : obj2;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{ 
	return out << fixed.toFloat();
}