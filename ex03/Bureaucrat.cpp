/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:13:37 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/22 18:27:04 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(void) : _name("unnamed"), _grade(150) {
	std::cout 	<< YELLOW << "Bureaucrat default constructor called." << std::endl 
				<< "`name` has been set to \"unnamed\" and `grade` has been set to 150 by default."
				<< RESET << std::endl
				<< *this << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {

	std::cout 	<< YELLOW << "Bureaucrat constructor called with name \"" << name << "\" and grade " << grade << "."
				<< RESET << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	this->_grade = grade;
	std::cout << *this << std::endl;

	return ;

}

Bureaucrat::Bureaucrat(Bureaucrat const & src): _name(src._name), _grade(src._grade)
{
	std::cout 	<< YELLOW << "Bureaucrat copy constructor called." << std::endl
				<< "`name` has been set to \"" << src._name << "\"," << std::endl
				<< "and `grade` has been set to " << src._grade << "." << std::endl
				<< RESET << *this << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << YELLOW << "Bureaucrat destructor called." << RESET << std::endl;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	std::cout << YELLOW << "Bureaucrat assignment operator called." << RESET << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	std::cout << *this << std::endl;
	return *this;
}

std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::incrementGrade(void) {
	std::cout << "Grade will be incremented from " << this->_grade << " to " << this->_grade - 1 << "." << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << *this << std::endl;
}

void Bureaucrat::decrementGrade(void) {
	std::cout << "Grade will be decremented from " << this->_grade << " to " << this->_grade + 1 << "." << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << *this << std::endl;
}

void Bureaucrat::signForm(AForm & form) {

	std::string bureaucratName = this->_name;
	bureaucratName[0] = std::toupper(bureaucratName[0]);

	std::string formName = form.getName();
	formName[0] = std::toupper(formName[0]);

	try {
		form.beSigned(*this);
		std::cout << CYAN << bureaucratName << " signed " << formName << "." << RESET << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cerr 	<< RED << bureaucratName << " couldn't sign " << formName
					<< " because: " << e.what() << RESET << std::endl << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) {

	std::string bureaucratName = this->_name;
	bureaucratName[0] = std::toupper(bureaucratName[0]);

	std::string formName = form.getName();
	formName[0] = std::toupper(formName[0]);

	try {
		form.execute(*this);
		std::cout << CYAN << bureaucratName << " executed " << formName << "." << RESET << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cerr 	<< RED << bureaucratName << " couldn't execute " << formName
					<< " because: " << e.what() << RESET << std::endl << std::endl;
	}

}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high! Range is 1 to 150.";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low! Range is 1 to 150.";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	std::string name = rhs.getName();
	name[0] = std::toupper(name[0]);
	o << GREEN << name << ", bureaucrat grade " << rhs.getGrade() << "." << RESET << std::endl;
	return o;
}

