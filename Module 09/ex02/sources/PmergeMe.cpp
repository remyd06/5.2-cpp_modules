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
void PmergeMe<C>::printContainer()
{
	for (unsigned int i = 0; i < _container.size(); ++i)
		std::cout << _container[i] << std::endl;
}

template <typename C>
void PmergeMe<C>::parser(const char **argv)
{
	for (unsigned int i = 1; argv[i]; ++i)
	{
		unsigned int x = 0;
		if (!argv[i][0])
			throw(std::runtime_error("Error: Invalid input."));

		while (argv[i][x])
		{
			if (!std::isdigit(argv[i][x++]))
				throw(std::runtime_error("Error: Invalid input."));
		}

		unsigned long nb = std::atol(argv[i]);
		if (nb >= 4294967296)
			throw(std::runtime_error("Error: input over flo."));
		else if (std::strlen(argv[i]) > 10)
			throw(std::runtime_error("Error: input over flo."));

		_container.push_back(nb);
	}
}

template <typename C>
PmergeMe<C>::PmergeMe(const char **argv)
{
	parser(argv);

	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::vector<C> lowlist;
	int rest = -1;

	while (_container.size() > 1)
	{
		if (rest != -1)
		{
			typename C::iterator it = std::lower_bound(_container.begin(), _container.end(), rest);
			_container.insert(it, rest);
			rest = -1;
		}
		if (_container.size() % 2 != 0)
		{
			rest = _container.back();
			_container.pop_back();
		}
		for (unsigned int i = 0; i < _container.size(); i += 2)
		{
			unsigned int first = _container[i];
			unsigned int second = _container[i + 1];
			
			if (first < second)
			pairs.push_back(std::make_pair(first, second));
			else
			pairs.push_back(std::make_pair(second, first));
		}

		C high;
		C low;
		for (unsigned int i = 0; i < pairs.size(); ++i)
		{
			high.push_back(pairs[i].second);
			low.push_back(pairs[i].first);
		}
		
		pairs.clear();
		_container = high;
		lowlist.push_back(low);

	}
	for (unsigned int i = 0; i < lowlist.size(); ++i)
	{
		for (unsigned int y = 0; y < lowlist[i].size(); ++y)
		{
			typename C::iterator it = std::lower_bound(_container.begin(), _container.end(), lowlist[i][y]);
			_container.insert(it, lowlist[i][y]);
		}
		
	}

	if (rest != -1)
	{
		typename C::iterator it = std::lower_bound(_container.begin(), _container.end(), rest);
		_container.insert(it, rest);
		rest = -1;
	}

	for (unsigned int i = 0; i < _container.size(); ++i)
		std::cout << _container[i] << " ";
}

template <typename C>
PmergeMe<C>::PmergeMe(const PmergeMe &copy)
{
	this->_container = copy._container;
}

template <typename C>
PmergeMe<C> &PmergeMe<C>::operator=(const PmergeMe<C> &copy)
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
