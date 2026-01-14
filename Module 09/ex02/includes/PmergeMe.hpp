/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:52:55 by rdedola           #+#    #+#             */
/*   Updated: 2026/01/14 13:38:55 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ansi.hpp"
# include <iostream>
# include <cstdlib>
# include <climits>
# include <cstring>
# include <vector>
# include <deque>

template <typename C>
class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const char **argv);
		PmergeMe(const PmergeMe &copy);
		PmergeMe	&operator=(const PmergeMe &copy);
		~PmergeMe();

		void	printContainer();

	private:
		C	_container;
};
