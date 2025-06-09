/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:08:00 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 17:15:56 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:

// ------------------------------------------------------------ member functions

// ---------------------------------------------------------------- constructors

	Point( void );
	Point( Point const &src );

	Point ( float const flt1, float const flt2 );

// ------------------------------------------------------------------ destructor
	~Point( void );
// ---------------------------------------------------------- operator overloads

	Point	&operator = ( Point const &src );

private:
	Fixed const	x;
	Fixed const	y;
};
#endif
