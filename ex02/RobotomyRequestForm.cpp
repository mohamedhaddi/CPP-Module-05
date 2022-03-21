/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:25:58 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 17:12:34 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("none") {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm assignation operator called." << std::endl;
	this->_target = rhs._target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() && executor.getGrade() <= this->getRequiredGradeToExecute())
	{

		std::string name = this->_target;
		name[0] = toupper(name[0]);

		std::cout << "* Drilling noises *" << std::endl;

		if (rand() % 2)
			std::cout << name << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy failed." << std::endl;

	}
	else
		throw AForm::GradeTooLowException();
}
