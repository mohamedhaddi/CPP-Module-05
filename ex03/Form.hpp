/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:14:03 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/22 18:25:38 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdexcept>
# include <iostream>
# include "Bureaucrat.hpp"

class AForm {
	
	private:

		std::string const 	_name;
		bool 				_signed;
		int const			_requiredGradeToSign;
		int const			_requiredGradeToExecute;

	public:

		AForm(void);
		AForm(AForm const & src);
		AForm(std::string const name, int const requiredGradeToSign, int const requiredGradeToExecute);
		virtual ~AForm(void);

		AForm &		operator=(AForm const & rhs);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getRequiredGradeToSign(void) const;
		int				getRequiredGradeToExecute(void) const;
		void 			beSigned(Bureaucrat const & bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		virtual void	execute(Bureaucrat const & executor) const = 0;

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif
