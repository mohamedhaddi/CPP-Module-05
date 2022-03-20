/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:55:15 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/20 16:55:19 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {

		Bureaucrat a;
		Bureaucrat b("mhaddi", 147);
		Bureaucrat c(b);
		a = b;

		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();

	}
	catch (std::exception &e) {

		std::cout << RED << e.what() << RESET << std::endl;

	}
}
