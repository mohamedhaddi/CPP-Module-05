/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:27 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 18:03:49 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("none") {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
	this->_target = rhs._target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() && executor.getGrade() <= this->getRequiredGradeToExecute())
	{

		std::string name = this->_target;
		name[0] = toupper(name[0]);

		std::cout << name << " has been pardoned by Zaphod Beeblebrox." << std::endl;

	}
	else
		throw AForm::GradeTooLowException();
}
