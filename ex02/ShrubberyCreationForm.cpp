/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:13 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 17:12:13 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("none") {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm assignation operator called." << std::endl;
	this->_target = rhs._target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() && executor.getGrade() <= this->getRequiredGradeToExecute())
	{

		std::ifstream infile("./ascii_tree");
		std::ofstream outfile(this->_target + "_shrubbery");
		std::string line;

		while (std::getline(infile, line))
			outfile << line << std::endl;

		outfile.close();
		infile.close();

		std::cout << "Shrubbery planted at " << this->_target << "." << std::endl;

	}
	else
		throw AForm::GradeTooLowException();
}
