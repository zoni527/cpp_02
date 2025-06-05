/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:28:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/03 15:59:35 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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

	// Found this clever trick to make bit masks on reddit:
	// if _fractional_bits = 8:
	// -> 1				= 0000 0000 0000 0001
	// -> 1 << 8		= 0000 0001 0000 0000
	// -> (1 << 8) - 1	= 0000 0000 1111 1111
	int fractional_bits = ( ( 1 << _fractional_bits ) - 1 ) & _value;

	float fractional_part = static_cast<float>(fractional_bits);
	for ( int i = 0; i < _fractional_bits; ++i )
		fractional_part /= 10;

	int whole_bits = _value >> _fractional_bits;
	float whole_part = static_cast<float>(whole_bits);
	
	return whole_part + fractional_part;
}

int Fixed:: toInt( void ) const {
	return _value >> _fractional_bits;
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

Fixed:: Fixed( int const integer ) {
	std::cout << "Int constructor called" << std::endl;

	int shift_left_and_back = ( ( integer << _fractional_bits ) >> _fractional_bits );
	if ( shift_left_and_back != integer )
		std::cout << "WARNING! Number can't be simply shifted without corruption" << std::endl;
	_value = ( integer << _fractional_bits );
}

Fixed:: Fixed( float const float_num ) {
	std::cout << "Float constructor called" << std::endl;

	_value = ( float_num * ( 1 << _fractional_bits ) );

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

// Assignment operator
Fixed &Fixed:: operator =( Fixed const &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &fixed )
		_value = fixed.getRawBits();
	return *this;
}
