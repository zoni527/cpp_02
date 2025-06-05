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

	// Assignment operator
	Fixed &operator  =( Fixed const &fixed );
	Fixed &operator <<( Fixed const &fixed );

private:
	int						_value;
	static unsigned const	_fractional_bits = 8;
};
