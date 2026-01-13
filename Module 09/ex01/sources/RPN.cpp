/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:55:54 by rdedola           #+#    #+#             */
/*   Updated: 2026/01/12 13:55:54 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

bool    isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return (true);
    return (false);
}

RPN::RPN(const std::string &input)
{
    for (unsigned int i = 0; i < input.size(); ++i)
    {
        while (input[i] == ' ' && i < input.size() - 1)
            i++;

        if (std::isdigit(input[i]))
        {
            if (input[i + 1] != '\0' && std::isdigit(input[i + 1]))
                throw (std::runtime_error("Error: invalid input1."));
            else
                st.push(input[i] - '0');
        }
     
        else if (isOperator(input[i]))
        {
            if (st.size() >= 2)
            {
                int    int1 = st.top();
                st.pop();
                int    int2 = st.top();
                st.pop();

                int res;
                switch(input[i])
                {
                    case '+':
                        res = int2 + int1; break;
                    case '-':
                        res = int2 - int1; break;
                    case '*':
                        res = int2 * int1; break;
                    case '/':
                    {
                        if (int1 == 0)
                            throw (std::runtime_error("Error: divison by 0."));
                        res = int2 / int1; break;
                    }
                    
                }
                st.push(res);
            }
            else
                throw (std::runtime_error("Error: invalid input.2"));
        }
        else
        {
            throw (std::runtime_error("Error: invalid input.3"));
        }
    }
    if (st.size() != 1)
        throw (std::runtime_error("Error: invalid input.4"));
    else
        std::cout << st.top() << std::endl;
}

RPN::RPN(const RPN &copy)
    :   st(copy.st)
{

}

RPN &RPN::operator=(const RPN &copy)
{
    st = copy.st;
    return (*this);
}

RPN::~RPN()
{

}