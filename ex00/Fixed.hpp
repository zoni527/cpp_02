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

// ---------------------------------------------------------------- constructors

	// Default constructor
	Fixed( void );
	// Copy constructor
	Fixed( Fixed const &fixed );
	// Destructor
	~Fixed( void );

// ---------------------------------------------------------- operator overloads

	// Assignment operator
	Fixed &operator =( Fixed const &fixed );

private:
	int					_value;
	static int const	_fractional_bits = 8;

};
