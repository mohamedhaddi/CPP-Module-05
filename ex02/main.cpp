/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:55:15 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 17:18:41 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {

		ShrubberyCreationForm f1("home");
		RobotomyRequestForm f2("foo");
		PresidentialPardonForm f3("bar");
		PresidentialPardonForm f4(f3);
		PresidentialPardonForm f5;

		Bureaucrat b1("mhaddi", 6);

		b1.signForm(f4);
		b1.executeForm(f4);

	}
	catch (std::exception &e) {

		std::cerr << RED << e.what() << RESET << std::endl;

	}
}
