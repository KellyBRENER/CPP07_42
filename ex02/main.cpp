/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:39:26 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/27 11:37:42 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.tpp"
#include <ctime>
#include <cstdlib>

int	main() {
	try {
	Array<int>	int_array(5);
	for (int i = 0; i < 5; ++i) {
		srand(time(0));//initialise le générateur de rand avec l'heure actuelle
		int_array[i] = rand();
	}
	std::cout<<"int_array contain : \n"<<int_array<<std::endl;
	}
	catch (std::exception & e) {
		std::cout<<"error : "<<e.what()<<std::endl;
	}
	try {
	Array<std::string>	empty_string_array;
	std::cout<<"empty_string_array size = "<<empty_string_array.size()<<std::endl;

	Array<std::string>	string_array(3);
	string_array[0] = "bonjour";
	string_array[1] = "monsieur";
	string_array[2] = "martin";
	Array<std::string> string_array_copy(string_array);
	std::cout<<"string_array = \n"<<string_array<<std::endl;
	std::cout<<"string_array_copy = \n"<<string_array<<std::endl;
	string_array[2] = "Paul";
	std::cout<<"string_array[2] = "<<string_array[2]<<std::endl;
	std::cout<<"string_array_copy[2] = "<<string_array_copy[2]<<std::endl;
	string_array[3] = "Paul";
	}
	catch (std::exception & e) {
		std::cout<<"error : "<<e.what()<<std::endl;
	}
}
