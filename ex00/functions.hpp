/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:27 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/22 14:48:03 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template < typename T>
void	swap(T & lhs, T & rhs) {
	T	temp;
	temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template < typename T >
T const &	min(T const & lhs, T const & rhs) {
	return ((lhs < rhs) ? lhs : rhs);
}

template < typename T >
T const &	max(T const & lhs, T const & rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}

#endif
