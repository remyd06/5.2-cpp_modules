/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:47:25 by rdedola           #+#    #+#             */
/*   Updated: 2025/12/05 15:27:51 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ansi.hpp"
# include <iostream>
# include <fstream>
# include <sstream>
# include <climits>
# include <cstdlib>
# include <exception>
# include <map>

class	Bitcoin
{
	public:
		Bitcoin();
		Bitcoin(const std::string &input);
		Bitcoin(const Bitcoin &copy);
		Bitcoin	&operator=(const Bitcoin &copy);
		~Bitcoin();

		void	parseInput(const std::string &input);
		void	parseDb();
		
	private:
		std::map<std::string, std::string>	_map_csv;
};
