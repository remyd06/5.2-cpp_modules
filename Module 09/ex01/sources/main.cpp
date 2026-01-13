/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:55:23 by rdedola           #+#    #+#             */
/*   Updated: 2026/01/12 13:55:23 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED2 << "Error: Invalid argument. Don't forget to use \"...\" ." << RESET << std::endl;
        return (1);
    }

    try
    {
        RPN rpn(argv[1]);
    }

    catch (const std::exception& e)
    {
        std::cerr << RED2 << e.what() << RESET << '\n';
    }
    
}