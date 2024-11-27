/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:53:04 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/27 11:20:46 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>

#ifndef ITER_TPP
#define ITER_TPP

template < typename T >
void	ft_double(T & t) {
	t = t + t;
}

template < typename T >
void	print_array(T & t) {
	std::cout<<t<<std::endl;
}

template < typename T >
void	iter(T* array, size_t	array_size, void (*f)(T&)) {
	for (size_t i = 0; i < array_size; ++i)
		f(array[i]);
}

template < typename T >
void	iter(T* array, size_t	array_size, void (*f)(const T&)) {
	for (size_t i = 0; i < array_size; ++i)
		f(array[i]);
}

class	Random_class {
	public:
		int	_nb;
		Random_class(){}
		Random_class(int nb) : _nb(nb) {}
		~Random_class(){}
		Random_class &	operator+(Random_class const & rhs) {
			_nb += rhs._nb;
			return *this;
		}
};

std::ostream &	operator<<(std::ostream & o, Random_class & rhs) {
	o<<"random class nb = "<<rhs._nb;
	return o;
}

#endif
