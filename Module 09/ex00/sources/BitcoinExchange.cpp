/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:57:20 by rdedola           #+#    #+#             */
/*   Updated: 2025/12/03 22:17:46 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	
}

Bitcoin::Bitcoin(const std::string &input)
{
	std::ifstream	file(input.c_str());
	std::string		buffer;

	parseInput(input);

	// while (getline(file, buffer))
	// {
	// 	this->_map["toto"]="tata";
	// }

	for (std::map<std::string, std::string>::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
	{
		std::cout << it->first << it->second << std::endl;
	}
}

std::string	to_string98(unsigned long value)
{
	std::ostringstream oss;
	oss << value;
	return (oss.str());
}

void	Bitcoin::parseInput(const std::string &input)
{
	std::ifstream	file(input.c_str());
	std::string		buffer;
	unsigned int	linePos = 2;
	char			*endPtr;
	bool			isLeapYear = false;
	
	getline(file, buffer);
	if (buffer != "date | value")
		throw (std::runtime_error("First line must be \"date | value\"."));
	
	while (getline(file, buffer))
	{
		std::cout << buffer << std::endl;
		if (buffer.size() < 14)
			throw (std::runtime_error("Error: wrong display -> line: " + to_string98(linePos) + '.'));

		// Year parsing
		std::string yearStr = buffer.substr(0, 4);
		long year = std::strtol(yearStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error: bad input -> " + to_string98(year) + std::string(" line: ") + to_string98(linePos)));
		if (year < 2009 || year > 2100)
			throw (std::runtime_error("Error: wrong year -> " + to_string98(year) + std::string(" line: ") + to_string98(linePos)));
		if (buffer[4] != '-')
			throw (std::runtime_error("Error: bad input -> " + std::string(1, buffer[4]) + std::string(" line: ") + to_string98(linePos)));
		
		// Month parsing
		std::string monthStr = buffer.substr(5, 2);
		long month = std::strtol(monthStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error: bad input -> " + monthStr + std::string(" line: ") + to_string98(linePos)));
		if (month < 1 || month > 12)
			throw (std::runtime_error("Error: wrong month -> " + monthStr + std::string(" line: ") + to_string98(linePos)));
		if (buffer[7] != '-')
			throw (std::runtime_error("Error: bad input -> " + std::string(1, buffer[7]) + std::string(" line: ") + to_string98(linePos)));

		// Day parsing
		std::string dayStr = buffer.substr(8, 2);
		long day = std::strtol(dayStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error: bad input -> " + to_string98(day) + std::string(" line: ") + to_string98(linePos)));
		if (day < 1 || day > 31)
			throw (std::runtime_error("Error: wrong day -> " + to_string98(day) + std::string(" line: ") + to_string98(linePos)));

		// Leap year handler
		if (year % 4 || year % 100)
			isLeapYear = true;
		if (month == 2 && day == 29 && !isLeapYear)
			throw (std::runtime_error("Error: your month can contain only 28" + std::string(" line: ") + to_string98(linePos)));

		// 30 || 31 days/month handler
		if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		{
			if (month == 2 && !isLeapYear)
				throw (std::runtime_error("Error: your month can contain only 28" + std::string(" line: ") + to_string98(linePos)));
			else if (month == 2)
				throw (std::runtime_error("Error: your month can contain only 29" + std::string(" line: ") + to_string98(linePos)));
			else
				throw (std::runtime_error("Error: your month can contain only 30" + std::string(" line: ") + to_string98(linePos)));
		}
			++linePos;
	}
}

Bitcoin::~Bitcoin()
{
	
}
