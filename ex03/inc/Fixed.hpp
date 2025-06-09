/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:40:46 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/03 15:32:24 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>

class Fixed {

public:

// ------------------------------------------------------------ member functions

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

// ----------------------------------------------------- static member functions

	static Fixed		&min( Fixed &f1, Fixed &f2 );
	static Fixed		&max( Fixed &f1, Fixed &f2 );
	static Fixed const	&min( Fixed const &f1, Fixed const &f2 );
	static Fixed const	&max( Fixed const &f1, Fixed const &f2 );

// ---------------------------------------------------------------- constructors

	// Default constructor
	Fixed( void );
	// Copy constructor
	Fixed( Fixed const	&fixed );

	Fixed( int const	integer );
	Fixed( float const	float_num );

// ------------------------------------------------------------------ destructor
	~Fixed( void );
// --------------------------------------------------- member operator overloads

	// Assignment operator
	Fixed	&operator =  ( Fixed const &fixed );

	// Increment and decrement
	Fixed	&operator ++ ( void );
	Fixed	&operator -- ( void );
	Fixed	operator  ++ ( int );
	Fixed	operator  -- ( int );
	
	// Comparison operators
	bool	operator  >  ( Fixed const &fixed ) const;
	bool	operator  <  ( Fixed const &fixed ) const;
	bool	operator  >= ( Fixed const &fixed ) const;
	bool	operator  <= ( Fixed const &fixed ) const;
	bool	operator  == ( Fixed const &fixed ) const;
	bool	operator  != ( Fixed const &fixed ) const;

	// Arithmetic operators
	Fixed	operator  +  ( Fixed const &fixed ) const;
	Fixed	operator  -  ( Fixed const &fixed ) const;
	Fixed	operator  *  ( Fixed const &fixed ) const;
	Fixed	operator  /  ( Fixed const &fixed ) const;

private:
	int						_value;
	static unsigned const	_fractional_bits = 8;
	static constexpr float	_power_of_two_float = ( 1 << _fractional_bits );
};

// ----------------------------------------------- non member operator overloads

std::ostream	&operator << ( std::ostream &os, Fixed const &fixed );
