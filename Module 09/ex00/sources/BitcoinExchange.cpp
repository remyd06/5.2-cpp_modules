/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:57:20 by rdedola           #+#    #+#             */
/*   Updated: 2025/12/05 15:47:32 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	
}

Bitcoin::Bitcoin(const std::string &input)
{
	std::ifstream	file(input.c_str());
	std::ifstream	file_csv;
	std::string		buffer;

	// Input & data.csv parsing
	parseInput(input);
	parseDb();

	// Opening .csv file
	file_csv.open("./data.csv");
	if (!file_csv.is_open())
		throw (std::runtime_error("Error.csv: the file could not be opened"));

	// Store the parsed data.csv file in std::map container
	getline(file_csv, buffer);
	while (getline(file_csv, buffer))
		this->_map_csv[buffer.substr(0, buffer.find(','))]=buffer.substr(11);
	
		
	// Iterator declaration for std::map
	// std::map<std::string, std::string>::iterator it_csv = this->_map_csv.begin();
			
	while (getline(file, buffer))
	{
		std::string	date = buffer.substr(0, 10);
	}

	// while (it_csv != this->_map_csv.end())
	// {
	// 	if (it->first > it_csv->first)
	// 	{
	// 		while (it_csv != _map_csv.end() && it_csv->first < it->first)
	// 			it_csv++;
	// 		if (it_csv == _map_csv.end())
	// 			it_csv--;
	// 		if (it_csv != _map_csv.end() && it_csv->first > it->first)
	// 			it_csv--;
	// 	}
	// 	else if (it_csv->first > it->first)
	// 	{
	// 		while (it != _map.end() && it->first < it_csv->first)
	// 			it++;
	// 		if (it == _map.end())
	// 			it--;
	// 		if (it != _map.end() && it->first > it_csv->first)
	// 			it--;
	// 	}
	// 	double result = std::atof(it->second.c_str()) * std::atof(it_csv->second.c_str());
	// 	std::cout << it->first << " -> " << it->second << " -> " << GREEN4 << result << RESET << std::endl;

	// 	it++;
	// }
}

std::string	to_string98(unsigned long value)
{
	std::ostringstream oss;std::string a("2025-12-20");
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
	
	// Opening file security
	if (!file.is_open())
		throw (std::runtime_error("Error.input: the file could not be opened."));

	// Skip the "date | value" line
	getline(file, buffer);
	if (buffer != "date | value")
		throw (std::runtime_error("Error.input: First line must be \"date | value\"."));
	
	// Getline loop
	while (getline(file, buffer))
	{
		// Size of date parsing
		if (buffer.size() < 14)
			throw (std::runtime_error("Error.input: wrong display -> line: " + to_string98(linePos) + '.'));

		// Year parsing
		std::string yearStr = buffer.substr(0, 4);
		long year = std::strtol(yearStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error.input: bad input -> " + to_string98(year) + std::string(" line: ") + to_string98(linePos)));
		if (year < 2009 || year > 2100)
			throw (std::runtime_error("Error.input: wrong year -> " + to_string98(year) + std::string(" line: ") + to_string98(linePos)));
		if (buffer[4] != '-')
			throw (std::runtime_error("Error.input: bad input -> " + std::string(1, buffer[4]) + std::string(" line: ") + to_string98(linePos)));
		
		// Month parsing
		std::string monthStr = buffer.substr(5, 2);
		long month = std::strtol(monthStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error.input: bad input -> " + monthStr + std::string(" line: ") + to_string98(linePos)));
		if (month < 1 || month > 12)
			throw (std::runtime_error("Error.input: wrong month -> " + monthStr + std::string(" line: ") + to_string98(linePos)));
		if (buffer[7] != '-')
			throw (std::runtime_error("Error.input: bad input -> " + std::string(1, buffer[7]) + std::string(" line: ") + to_string98(linePos)));

		// Day parsing
		std::string dayStr = buffer.substr(8, 2);
		long day = std::strtol(dayStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error.input: bad input -> " + to_string98(day) + std::string(" line: ") + to_string98(linePos)));
		if (day < 1 || day > 31)
			throw (std::runtime_error("Error.input: wrong day -> " + to_string98(day) + std::string(" line: ") + to_string98(linePos)));

		// Error handler for too early date
		unsigned int date = year * 10000 + month * 100 + day;
		if (date < 20090102)
			throw (std::runtime_error("Error.input: the date must not be earlier than 2009-01-02"));

		// Leap year handler
		if (year % 4 == 0|| year % 100 == 0)
			isLeapYear = true;
		if (month == 2 && day == 29 && !isLeapYear)
			throw (std::runtime_error("Error.input: your month can contain only 28 days." + std::string(" line: ") + to_string98(linePos)));
		
		// 30 || 31 days/month handler
		if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		{
			if (month == 2 && !isLeapYear)
				throw (std::runtime_error("Error.input: your month can contain only 28 days." + std::string(" line: ") + to_string98(linePos)));
			else if (month == 2)
				throw (std::runtime_error("Error.input: your month can contain only 29 days." + std::string(" line: ") + to_string98(linePos)));
			else
				throw (std::runtime_error("Error.input: your month can contain only 30 days." + std::string(" line: ") + to_string98(linePos)));
		}

		// Separator parsing
		if (buffer[10] != ' ' || buffer[11] != '|' || buffer[12] != ' ')
			throw (std::runtime_error("Error.input: incorrect separator, it must be ' | '." + std::string(" line: ") + to_string98(linePos)));
		
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
				throw (std::runtime_error("Error.input: your Bitcoin amount must be a number." + std::string(" line: ") + to_string98(linePos)));
		}
		if (dot > 1)
			throw (std::runtime_error("Error.input: your Bitcoin amount is invalid." + std::string(" line: ") + to_string98(linePos)));
		if (dot == 1)
			fValue = std::atof(strValue.c_str());
		else
			iValue = std::atoi(strValue.c_str());
		if ((iValue < 0 || iValue > 1000) || (fValue < 0 || fValue > 1000))
			throw (std::runtime_error("Error.input: your Bitcoin is out of limits." + std::string(" line: ") + to_string98(linePos)));

		// Line position iterator
		++linePos;
	}
}

void	Bitcoin::parseDb()
{
	std::ifstream	file;
	std::string		buffer;
	unsigned int	linePos = 2;
	char			*endPtr;
	bool			isLeapYear = false;
	
	// Opening .csv file
	file.open("./data.csv");
	if (!file.is_open())
		throw (std::runtime_error("Error.csv: the file could not be opened"));

	// Skip the "date,exchange_rate" line
	getline(file, buffer);
	if (buffer != "date,exchange_rate")
		throw (std::runtime_error("Error.csv: First line must be \"date,exchange_rate\"."));
	
	// Getline loop
	while (getline(file, buffer))
	{
		if (buffer.size() < 12)
			throw (std::runtime_error("Error.csv: wrong display -> line: " + to_string98(linePos)));

		// Year parsing
		std::string yearStr = buffer.substr(0, 4);
		long year = std::strtol(yearStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error.csv: bad input -> " + to_string98(year) + std::string(" line: ") + to_string98(linePos)));
		if (year < 2009 || year > 2100)
			throw (std::runtime_error("Error.csv: wrong year -> " + to_string98(year) + std::string(" line: ") + to_string98(linePos)));
		if (buffer[4] != '-')
			throw (std::runtime_error("Error.csv: bad input -> " + std::string(1, buffer[4]) + std::string(" line: ") + to_string98(linePos)));
		
		// Month parsing
		std::string monthStr = buffer.substr(5, 2);
		long month = std::strtol(monthStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error.csv: bad input -> " + monthStr + std::string(" line: ") + to_string98(linePos)));
		if (month < 1 || month > 12)
			throw (std::runtime_error("Error.csv: wrong month -> " + monthStr + std::string(" line: ") + to_string98(linePos)));
		if (buffer[7] != '-')
			throw (std::runtime_error("Error.csv: bad input -> " + std::string(1, buffer[7]) + std::string(" line: ") + to_string98(linePos)));

		// Day parsing
		std::string dayStr = buffer.substr(8, 2);
		long day = std::strtol(dayStr.c_str(), &endPtr, 10);
		if (*endPtr != '\0')
			throw (std::runtime_error("Error.csv.csv: bad input -> " + to_string98(day) + std::string(" line: ") + to_string98(linePos)));
		if (day < 1 || day > 31)
			throw (std::runtime_error("Error.csv.csv: wrong day -> " + to_string98(day) + std::string(" line: ") + to_string98(linePos)));
		
		// Error handler for too early date
		unsigned int date = year * 10000 + month * 100 + day;
		if (date < 20090102)
			throw (std::runtime_error("Error_csv: the date must not be earlier than 2009-01-02"));

		// Leap year handler
		if (year % 4 == 0|| year % 100 == 0)
			isLeapYear = true;
		if (month == 2 && day == 29 && !isLeapYear)
			throw (std::runtime_error("Error.csv.csv: your month can contain only 28 days." + std::string(" line: ") + to_string98(linePos)));
		
		// 30 || 31 days/month handler
		if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		{
			if (month == 2 && !isLeapYear)
				throw (std::runtime_error("Error.csv.csv: your month can contain only 28 days." + std::string(" line: ") + to_string98(linePos)));
			else if (month == 2)
				throw (std::runtime_error("Error.csv.csv: your month can contain only 29 days." + std::string(" line: ") + to_string98(linePos)));
			else
				throw (std::runtime_error("Error.csv.csv: your month can contain only 30 days." + std::string(" line: ") + to_string98(linePos)));
		}

		// Separator parsing
		if (buffer[10] != ',')
			throw (std::runtime_error("Error.csv.csv: incorrect separator, it must be ','." + std::string(" line: ") + to_string98(linePos)));
		
		// Exchange value parsing
		std::string	strValue;
		int			iValue = 0;
		float		fValue = 0;
		int			dot = 0;
		bool		isNeg = 0;
		strValue = buffer.substr(11, (buffer.size() - 11));
		for (unsigned int i = 0; i < strValue.size(); ++i)
		{
			if (strValue[i] == '.')
				dot++;
			else if (strValue[i] == '-')
				isNeg = 1;
			else if (!std::isdigit(strValue[i]))
				throw (std::runtime_error("Error.csv: your Bitcoin exchange value must be a number." + std::string(" line: ") + to_string98(linePos)));
		}
		if (dot > 1)
			throw (std::runtime_error("Error.csv: your Bitcoin amount is invalid." + std::string(" line: ") + to_string98(linePos)));
		if (dot == 1)
			fValue = std::atof(strValue.c_str());
		else
			iValue = std::atoi(strValue.c_str());
		if ((iValue < 0 || iValue > 1000000000) || (fValue < 0 || fValue > 1000000000))
			throw (std::runtime_error("Error.csv: your Bitcoin is out of limits." + std::string(" line: ") + to_string98(linePos)));

		// Line position iterator
		++linePos;
	}
}

Bitcoin::~Bitcoin()
{
	
}
