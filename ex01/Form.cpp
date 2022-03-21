/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:17:41 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 15:23:46 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("unnamed"), _signed(false), _required_grade_to_sign(150), _required_grade_to_execute(150) {
	std::cout 	<< "Form default constructor called." << std::endl 
				<< "`name` has been set to \"unnamed\" and the required grades have been set to 150 by default." << std::endl
				<< *this << std::endl;
	return ;
}

Form::Form(std::string name, int required_grade_to_sign, int required_grade_to_execute) :
	_name(name),
	_signed(false),
	_required_grade_to_sign(required_grade_to_sign),
	_required_grade_to_execute(required_grade_to_execute)
{
	std::cout 	<< "Form constructor called with `name`: \"" << name << "\"," << std::endl
				<< "and a `required grade to sign`: " << required_grade_to_sign << "," << std::endl
				<< "and a `required grade to execute`: " << required_grade_to_execute << "." << std::endl
				<< *this << std::endl;
	if (required_grade_to_sign < 1 || required_grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (required_grade_to_sign > 150 || required_grade_to_execute > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form(Form const &src) :
	_name(src._name),
	_signed(src._signed),
	_required_grade_to_sign(src._required_grade_to_sign),
	_required_grade_to_execute(src._required_grade_to_execute)
{
	std::cout 	<< "Form copy constructor called." << std::endl
				<< "`name` has been set to: \"" << src._name << "\"." << std::endl
				<< "`signed` has been set to: " << (src._signed ? "True" : "False") << "." << std::endl
				<< "`required grade to sign` has been set to: " << src._required_grade_to_sign << "." << std::endl
				<< "`required grade to execute` has been set to " << src._required_grade_to_execute << "." << std::endl
				<< *this << std::endl;
	return ;
}

Form::~Form(void) {
	std::string name = this->_name;
	name[0] = std::toupper(name[0]);
	std::cout << "Form destructor called." << std::endl
			  << "Form " << name << " has been destroyed." << std::endl;
	return ;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_required_grade_to_sign)
		throw Form::GradeTooLowException();
	this->_signed = true;
	std::cout << "Form " << this->_name << " has been signed by " << bureaucrat.getName() << "." << std::endl;
	return ;
}

const char * Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char * Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::string Form::getName(void) const {
	return this->_name;
}

bool Form::getSigned(void) const {
	return this->_signed;
}

int Form::getRequiredGradeToSign(void) const {
	return this->_required_grade_to_sign;
}

int Form::getRequiredGradeToExecute(void) const {
	return this->_required_grade_to_execute;
}

Form & Form::operator=(Form const & rhs) {
	std::cout << "Form assignment operator called." << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	std::cout << *this << std::endl;
	return *this;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	std::string name = rhs.getName();
	name[0] = std::toupper(name[0]);
	o 	<< GREEN << "Form " << PURPLE << name << GREEN << " is ";
	if (rhs.getSigned())
		o << BOLD_GREEN << "signed" << GREEN;
	else
		o << BOLD_RED << "not signed" << GREEN;
	o 	<< " and requires a grade of " << rhs.getRequiredGradeToSign()
		<< " to sign and a grade of " << rhs.getRequiredGradeToExecute() << " to execute."
		<< RESET << std::endl;
	return o;
}

