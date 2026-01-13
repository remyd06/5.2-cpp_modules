/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:55:47 by rdedola           #+#    #+#             */
/*   Updated: 2026/01/12 13:55:47 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ansi.hpp"
# include <iostream>
# include <cstdlib>
# include <stack>

class RPN
{
    public:
        RPN();
        RPN(const std::string &input);
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();
        
    private:
        std::stack<int> st;
};
