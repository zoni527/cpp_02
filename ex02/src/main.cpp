/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/05 22:53:09 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#define YELLOW	"\033[0;93m\001"
#define RESET	"\033[0m\002"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main( void ) {

	print_test_name( "Subject's main (with better formatting)" );
	// -------------------------------------------------------------------------
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << "\n\n";
		std::cout << ++a << "\n";
		std::cout << a << "\n\n";;
		std::cout << a++ << "\n";;
		std::cout << a << "\n\n";;
		std::cout << b << "\n\n";;
		std::cout << Fixed::max( a, b ) << "\n";
	}
	// -------------------------------------------------------------------------
	print_test_name( "Additional testing: division" );
	{
		Fixed a( 4 );
		Fixed b( 2 );
		Fixed c = a / b;
		std::cout << c << "\n";
	}
	std::cout << std::endl;
	return 0;
}

static void print_test_name( std::string str ) {

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" YELLOW << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << RESET "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
