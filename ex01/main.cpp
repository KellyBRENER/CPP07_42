/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:05:55 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/27 11:22:26 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "iter.tpp"

int	main() {
	int	int_array[3] = {5, 13, -8};
	char	char_array[] = "hello world";
	std::string	string_array[3] = {"bonjour", "monsieur", "martin"};
	Random_class	class_array[3] = {Random_class(3), Random_class(8), Random_class(16)};

	std::cout<<"int_array = ";
	::iter(int_array, 3, &print_array<int>);
	std::cout<<"char_array = ";
	::iter(char_array, 12, &print_array<char>);
	std::cout<<"string_array = ";
	::iter(string_array, 3, &print_array<std::string>);
	std::cout<<"class_array = ";
	::iter(class_array, 3, &print_array<Random_class>);

	std::cout<<"*****double function*****"<<std::endl;
	::iter(int_array, 3, &ft_double<int>);
	::iter(char_array, 12, &ft_double<char>);
	::iter(string_array, 3, &ft_double<std::string>);
	::iter(class_array, 3, &ft_double<Random_class>);

	std::cout<<"int_array = ";
	::iter(int_array, 3, &print_array<int>);
	std::cout<<"char_array = ";
	::iter(char_array, 12, &print_array<char>);
	std::cout<<"string_array = ";
	::iter(string_array, 3, &print_array<std::string>);
	std::cout<<"class_array = ";
	::iter(class_array, 3, &print_array<Random_class>);
}
