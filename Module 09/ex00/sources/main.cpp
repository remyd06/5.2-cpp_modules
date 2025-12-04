/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:26:58 by rdedola           #+#    #+#             */
/*   Updated: 2025/12/04 12:00:55 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open the file." << std::endl;
		return (1);
	}

	try
	{
		Bitcoin	bit(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << RED2 << e.what() << RESET << std::endl;
	}
	
}
