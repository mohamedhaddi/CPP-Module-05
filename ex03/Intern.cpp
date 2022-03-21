/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:01:57 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 20:04:56 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor called." << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
	return ;
}

Intern &Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern assignment operator called." << std::endl;
	(void)rhs;
	return *this;
}

std::string const toLower(std::string str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = tolower(str[i]);
        i++;
    }
    return (str);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	size_t formCode = forms->find(toLower(formName));

	switch (formCode)
	{
		case 0: case 1: case 2:
			std::cout << "Intern creates " << formName << std::endl;
		default:
			throw Intern::FormNotFoundException();
	}

	switch (formCode)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
	}
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found.");
}

