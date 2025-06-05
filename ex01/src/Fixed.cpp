/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:28:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/05 22:48:29 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

unsigned const	Fixed:: _fractional_bits;
constexpr float	Fixed:: _power_of_two_float;
constexpr int	Fixed:: _power_of_two_int;

// ------------------------------------------------------------ member functions

int Fixed:: getRawBits( void ) const {
	std::cout << "getRawBits member funtion called" << std::endl;
	return _value;
}

void Fixed:: setRawBits( int const raw ) {
	std::cout << "setRawBits member funtion called" << std::endl;
	_value = raw;
}

float Fixed:: toFloat( void ) const {

	return ( _value / _power_of_two_float );

	/**
	 * At one point I thought of constructing the float by using base 10, but
	 * that would have caused some bad wrangling of bytes, which would have
	 * been difficult and unnecessary. I would like to leave these comments here
	 * as a reminder of my mistakes, but I don't know if someone will complain
	 * during an eval... maybe this is a risk I could dare to take.
	 * -------------------------------------------------------------------------
	 *
	 * Found this clever trick to make bit masks on reddit:
	 * if _fractional_bits = 8:
	 * -> 1				= 0b 0000 0000 0000 0001 = 1
	 * -> 1 << 8		= 0b 0000 0001 0000 0000 = 256
	 * -> (1 << 8) - 1	= 0b 0000 0000 1111 1111 = 255
	 */

	/**
	 * int fractional_bits = value & ( ( 1 << _fractional_bits ) - 1 );
	 *
	 * float fractional_part = static_cast<float>(fractional_bits);
	 * for ( int i = 0; i < _fractional_bits; ++i )
	 * 	fractional_part /= 10;
	 *
	 * int whole_bits = _value >> _fractional_bits;
	 * float whole_part = static_cast<float>(whole_bits);
	 * 
	 * return whole_part + fractional_part;
	 */
}

int Fixed:: toInt( void ) const {
	return ( _value / _power_of_two_int );
}

// ---------------------------------------------------------------- constructors

// Default constructor
Fixed:: Fixed( void ) : _value( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed:: Fixed( Fixed const &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// Int constructor
Fixed:: Fixed( int const integer ) {
	std::cout << "Int constructor called" << std::endl;

	// This portion of code I used to have for checking if the original integer
	// would fit in the int type in the system when shifted fractional bits to
	// the left. The division is done instead of shifting back due to the
	// undefined behaviour of right shifting signed integers (division isn't
	// UB). After discussions with peers I agree that the type should be fast.
	// (The subject forces us to write messages, I realise those are slow)
	/**
	 * int shift_left = ( ( integer << _fractional_bits ) );
	 * if ( shift_left / _power_of_two_int != integer )
	 * 	std::cout << "WARNING! Number can't be simply shifted without corruption" << std::endl;
	*/
	 _value = ( integer << _fractional_bits );
}

// Float constructor
Fixed:: Fixed( float const float_num ) {
	std::cout << "Float constructor called" << std::endl;

	_value = roundf( float_num * _power_of_two_float );

	// 123.456...
	// Whole part = 123
	// int whole_part = static_cast<int>( float_num );
	// if ( ( ( whole_part << _fractional_bits ) >> _fractional_bits ) != whole_part )
	// 	std::cout << "WARNING! Number can't be simply shifted without corruption" << std::endl;
	// Float part = .456...
	// Get _fractional_bits real bytes
	// float temp = float_num;
	// for ( int i = 0; i < _fractional_bits; ++i )
	// 	temp *= 10;
	// temp = 4567 8901.234...
	// int fractional_part = static_cast<int>(temp);
	// _value = whole_part | fractional_part;
}

// ------------------------------------------------------------------ destructor

Fixed:: ~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

Fixed &Fixed:: operator =( Fixed const &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &fixed )
		_value = fixed._value;
	return *this;
}

std::ostream &operator << ( std::ostream &os, Fixed const &fixed ) {
	return ( os << fixed.toFloat() );
}
