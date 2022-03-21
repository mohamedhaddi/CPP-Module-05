/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:55:15 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 17:57:22 by mhaddi           ###   ########.fr       */
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

		Bureaucrat b1("mhaddi", 150);

		ShrubberyCreationForm f1("home");

		b1.signForm(f1);
		b1.executeForm(f1);

		RobotomyRequestForm f2(b1.getName());

		b1.signForm(f2);
		b1.executeForm(f2);

		PresidentialPardonForm f3(b1.getName());

		b1.signForm(f3);
		b1.executeForm(f3);

	}
	catch (std::exception &e) {

		std::cerr << RED << e.what() << RESET << std::endl;

	}
}
