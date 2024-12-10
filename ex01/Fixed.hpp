/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:35:46 by shaboom           #+#    #+#             */
/*   Updated: 2024/12/10 11:20:20 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <cmath> //roundf

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
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);
