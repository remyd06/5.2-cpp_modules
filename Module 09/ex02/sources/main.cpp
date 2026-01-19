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

	clock_t start = clock();
	try
	{	std::cout << std::endl << GREEN3 << "VECTOR SORTED LIST: " << RESET;
		PmergeMe<std::vector<unsigned int> >	pm(argv);
	}
	catch (const std::exception& e)
    {
        std::cerr << RED2 << e.what() << RESET << '\n';
    }
	const double duration1 = (clock() - start) / double(CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(6) << std::endl;

	start = clock();
	try
	{	
		std::cout << GREEN3 << "DEQUE SORTED LIST: " << RESET;
		PmergeMe<std::deque<unsigned int> >	pm(argv);
	}
	catch (const std::exception& e)
    {
        std::cerr << RED2 << e.what() << RESET << '\n';
    }
	const double duration = (clock() - start) / double(CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(6) << std::endl;

	std::cout << YELLOW3 << std::endl << "Vector sort took: " << duration1 << " seconds" << RESET << std::endl;
    std::cout << YELLOW3 << "Deque sort took: " << duration << " seconds" << RESET << std::endl << std::endl;
}
