/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:01:57 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/22 18:55:39 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void)
{
	std::cout << CYAN << "Intern constructor called." << RESET << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << CYAN << "Intern copy constructor called." << RESET << std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << CYAN << "Intern destructor called." << RESET << std::endl;
	return ;
}

Intern &Intern::operator=(Intern const &rhs)
{
	std::cout << CYAN << "Intern assignment operator called." << RESET << std::endl;
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

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *(Intern::*forms[4])(std::string) =
	{
		NULL,
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	int formNumber = (
		1 * (toLower(formName) == "shrubbery creation") +
		2 * (toLower(formName) == "robotomy request") +
		3 * (toLower(formName) == "presidential pardon")
	);

	if (formNumber == 0)
		throw Intern::FormNotFoundException();

	std::cout << CYAN << "Intern creates " << formName << " for " << target << "." << RESET << std::endl;

	return (this->*forms[formNumber])(target);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found.";
}

