/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:47:46 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/07 14:20:46 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <cmath> //roundf
//#include "Point.hpp"
/**
 * @brief pre and post incremenation use parameters only to signal to 
 * compiler if we are dealing with pre or post.
 * 
 */
class Fixed
{
	private:
		int	rawValue;
		static const int fractionalBits;
	public:
	//default constructor
		Fixed();
	//copy constructor 
		Fixed(const Fixed& other);
	//copy aissignment operator
		Fixed& operator=(const Fixed& other);

		Fixed(const int number);
		Fixed(const float floatingNumber);
	//destructor
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator-(const Fixed& other);
		Fixed operator+(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);

		Fixed operator++(int);
		Fixed operator++();
		Fixed operator--(int);
		Fixed operator--();

		static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
		static Fixed& max(Fixed& obj1, Fixed& obj2);

		static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
		static Fixed& min(Fixed& obj1, Fixed& obj2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);
