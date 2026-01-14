/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:05 by rdedola           #+#    #+#             */
/*   Updated: 2026/01/14 14:51:05 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename C>
PmergeMe<C>::PmergeMe()
{
	
}

template <typename C>
void	PmergeMe<C>::printContainer()
{
	for (unsigned int i = 0; i < _container.size(); ++i)
		std::cout << _container[i] << std::endl;
}

template <typename C>
PmergeMe<C>::PmergeMe(const char **argv)
{
	for (unsigned int i = 1; argv[i]; ++i)
	{
		unsigned int x = 0;
		if (!argv[i][0])
			throw (std::runtime_error("Error: Invalid input."));
			
		while (argv[i][x])
		{
			if (!std::isdigit(argv[i][x++]))
				throw (std::runtime_error("Error: Invalid input."));
		}

		unsigned int	nb = std::atol(argv[i]);
		if (nb > 4294967295)
			throw (std::runtime_error("Error: input over flo."));
		else if (std::strlen(argv[i]) > 10)
			throw (std::runtime_error("Error: input over flo."));

		_container.push_back(nb);
	}

	while (_container.size() > 1)
	{
		if (_container.size() % 2 != 0)
		{
			unsigned int	rest = 0;
			rest = _container.back();
			_container.pop_back();
		}

		std::vector<std::pair<unsigned int, unsigned int>> pairs;
		for (unsigned int i = 0; i < _container.size(); i += 2)
		{
			unsigned int first = _container[i];
			unsigned int second = _container[i + 1];

			if (first < second)
				pairs.push_back(std::make_pair(first, second));
			else
				pairs.push_back(std::make_pair(second, first));
		}

		std::vector<unsigned int> high;
		std::vector<unsigned int> low;
		for (unsigned int i = 0; i < pairs; ++i)
		{
			high.push_back(pairs[i].second)
			low.push_back(pairs[i].first)
		}
		pairs.clear;
	}

	printContainer();
}

template <typename C>
PmergeMe<C>::PmergeMe(const PmergeMe &copy)
{
	this->_container = copy._container;
}

template <typename C>
PmergeMe<C>	&PmergeMe<C>::operator=(const PmergeMe<C> &copy)
{
	this->_container = copy._container;
	return (*this);
}

template <typename C>
PmergeMe<C>::~PmergeMe()
{

}

template class PmergeMe<std::vector<unsigned int> >;
template class PmergeMe<std::deque<unsigned int> >;
