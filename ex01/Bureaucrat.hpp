/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:13:41 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/21 15:07:42 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

# include <string>
# include <stdexcept>
# include <iostream>

class Form;

class Bureaucrat {

	private:

		std::string const	_name;
		int					_grade;

	public: 

		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);

		Bureaucrat &		operator=(Bureaucrat const & rhs);

		std::string			getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void  				signForm(Form & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
