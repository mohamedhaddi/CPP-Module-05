/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:17:41 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/24 18:15:04 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("unnamed"), _signed(false), _requiredGradeToSign(150), _requiredGradeToExecute(150) {
	std::cout 	<< MAGENTA << "Form default constructor called." << std::endl 
				<< "`name` has been set to \"unnamed\" and the required grades have been set to 150 by default."
				<< RESET << std::endl
				<< *this << std::endl;
	return ;
}

AForm::AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute) :
	_name(name),
	_signed(false),
	_requiredGradeToSign(requiredGradeToSign),
	_requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout 	<< MAGENTA << "Form constructor called with `name`: \"" << name << "\"," << std::endl
				<< "and a `required grade to sign`: " << requiredGradeToSign << "," << std::endl
				<< "and a `required grade to execute`: " << requiredGradeToExecute << "."
				<< RESET << std::endl
				<< *this << std::endl;
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::AForm(AForm const &src) :
	_name(src._name),
	_signed(src._signed),
	_requiredGradeToSign(src._requiredGradeToSign),
	_requiredGradeToExecute(src._requiredGradeToExecute)
{
	std::cout 	<< MAGENTA << "Form copy constructor called." << std::endl
				<< "`name` has been set to: \"" << src._name << "\"." << std::endl
				<< "`signed` has been set to: " << (src._signed ? "True" : "False") << "." << std::endl
				<< "`required grade to sign` has been set to: " << src._requiredGradeToSign << "." << std::endl
				<< "`required grade to execute` has been set to " << src._requiredGradeToExecute << "."
				<< RESET << std::endl
				<< *this << std::endl;
	return ;
}

AForm::~AForm(void) {
	std::string name = this->_name;
	name[0] = std::toupper(name[0]);
	std::cout << MAGENTA << "Form destructor called." << RESET << std::endl;
	return ;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requiredGradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
	std::cout << "Form " << this->_name << " has been signed by " << bureaucrat.getName() << "." << std::endl;
	return ;
}

const char * AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::string AForm::getName(void) const {
	return this->_name;
}

bool AForm::getSigned(void) const {
	return this->_signed;
}

int AForm::getRequiredGradeToSign(void) const {
	return this->_requiredGradeToSign;
}

int AForm::getRequiredGradeToExecute(void) const {
	return this->_requiredGradeToExecute;
}

AForm & AForm::operator=(AForm const & rhs) {
	std::cout << MAGENTA << "Form assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	std::cout << *this << std::endl;
	return *this;
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
	std::string name = rhs.getName();
	name[0] = std::toupper(name[0]);
	o 	<< GREEN << "Form " << MAGENTA << name << GREEN << " is ";
	if (rhs.getSigned())
		o << BOLD_GREEN << "signed" << GREEN;
	else
		o << BOLD_RED << "not signed" << GREEN;
	o 	<< " and requires a grade of " << rhs.getRequiredGradeToSign()
		<< " to sign and a grade of " << rhs.getRequiredGradeToExecute() << " to execute."
		<< RESET << std::endl;
	return o;
}

