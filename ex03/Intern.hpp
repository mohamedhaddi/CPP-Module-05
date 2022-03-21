/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:59:28 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 20:01:56 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

class Intern
{

	public:

		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern &operator=(Intern const &rhs);

		AForm *makeForm(std::string form, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif
