/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:55:15 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 15:20:18 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {

		Form f1;
		Form f2("chahadatSsokna", 100, 100);
		Form f3(f2);

		Bureaucrat b1("mhaddi", 100);

		b1.signForm(f3);

		f1 = f3;

	}
	catch (std::exception &e) {

		std::cerr << RED << e.what() << RESET << std::endl;

	}
}
