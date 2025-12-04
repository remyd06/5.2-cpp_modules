/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:57:20 by rdedola           #+#    #+#             */
/*   Updated: 2025/12/04 15:44:37 by rdedola          ###   ########.fr       */
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
	getline(file, buffer);
	while (getline(file, buffer))
		this->_map[buffer.substr(0, buffer.find(' '))]=buffer.substr(12);

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
	
	// Skip the "date | value" line
	getline(file, buffer);
	if (buffer != "date | value")
		throw (std::runtime_error("First line must be \"date | value\"."));
	
	// Getline loop
	while (getline(file, buffer))
	{
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
		if (year % 4 == 0|| year % 100 == 0)
			isLeapYear = true;
		if (month == 2 && day == 29 && !isLeapYear)
			throw (std::runtime_error("Error: your month can contain only 28 days." + std::string(" line: ") + to_string98(linePos)));
		
		// 30 || 31 days/month handler
		if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		{
			if (month == 2 && !isLeapYear)
				throw (std::runtime_error("Error: your month can contain only 28 days." + std::string(" line: ") + to_string98(linePos)));
			else if (month == 2)
				throw (std::runtime_error("Error: your month can contain only 29 days." + std::string(" line: ") + to_string98(linePos)));
			else
				throw (std::runtime_error("Error: your month can contain only 30 days." + std::string(" line: ") + to_string98(linePos)));
		}

		// Separator parsing
		if (buffer[10] != ' ' || buffer[11] != '|' || buffer[12] != ' ')
			throw (std::runtime_error("Error: incorrect separator, it must be ' | '." + std::string(" line: ") + to_string98(linePos)));
		
		// Numbers of Bitcoins parsing
		std::string	strValue;
		int			iValue = 0;
		float		fValue = 0;
		int			dot = 0;
		bool		isNeg = 0;
		strValue = buffer.substr(13, (buffer.size() - 13));
		for (unsigned int i = 0; i < strValue.size(); ++i)
		{
			if (strValue[i] == '.')
				dot++;
			else if (strValue[i] == '-')
				isNeg = 1;
			else if (!std::isdigit(strValue[i]))
				throw (std::runtime_error("Error: your Bitcoin amount must be a number." + std::string(" line: ") + to_string98(linePos)));
		}
		if (dot > 1)
			throw (std::runtime_error("Error: your Bitcoin amount is invalid." + std::string(" line: ") + to_string98(linePos)));
		if (dot == 1)
			fValue = std::atof(strValue.c_str());
		else
			iValue = std::atoi(strValue.c_str());
		if ((iValue < 0 || iValue > 1000) || (fValue < 0 || fValue > 1000))
			throw (std::runtime_error("Error: your Bitcoin is out of limits." + std::string(" line: ") + to_string98(linePos)));

		// Line position iterator
		++linePos;
	}
}

Bitcoin::~Bitcoin()
{
	
}
