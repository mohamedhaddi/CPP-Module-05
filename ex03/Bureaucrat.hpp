/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:13:41 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/22 18:25:31 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW "\033[0;33m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_RED "\033[1;31m"
# define RESET "\033[0m"

# include <string>
# include <stdexcept>
# include <iostream>

class AForm;

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
		void  				signForm(AForm & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		void 				executeForm(AForm const & form);

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
