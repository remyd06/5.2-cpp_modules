/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:45:05 by rdedola           #+#    #+#             */
/*   Updated: 2026/01/14 13:29:59 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, const char **argv)
{
	if (argc == 1)
	{
		std::cerr << RED2 << "Error: Invalid argument." << RESET << std::endl;
        return (1);
	}

	try
	{
		PmergeMe<std::vector<unsigned int> >	pm(argv);
	}
	catch (const std::exception& e)
    {
        std::cerr << RED2 << e.what() << RESET << '\n';
    }
}
