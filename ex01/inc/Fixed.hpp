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

// Welcome to Orthodoc Canonical Form!

class Fixed {

public:

// ------------------------------------------------------------ member functions

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

// ---------------------------------------------------------------- constructors

	// Default constructor
	Fixed( void );
	// Copy constructor
	Fixed( Fixed const	&fixed );

	Fixed( int const	integer );
	Fixed( float const	ifloat_num );

// ------------------------------------------------------------------ destructor

	~Fixed( void );

// ---------------------------------------------------------- operator overloads

	Fixed			&operator  = ( Fixed const &fixed );

private:
	int						_value;
	static unsigned const	_fractional_bits = 8;

	static constexpr float	_power_of_two_float = (1 << _fractional_bits);
	static constexpr int	_power_of_two_int = (1 << _fractional_bits);
};

std::ostream	&operator<<( std::ostream &os, Fixed const &fixed);
