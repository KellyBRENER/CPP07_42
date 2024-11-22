/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:45:48 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/22 17:30:42 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ARRAY_HPP
#define ARRAY_HPP

template < typename T >
class Array {
private:
	T*	_array;
	unsigned int	_size;
public:
	Array<T>() : _array(NULL), _size(0){}
	Array<T>(unsigned int n) {
		if (n > 0) {
			_array = new T(n);
			_size = n;
			for (int i = 0; i < n; ++i)
				_array[i] = T();
		}
		else {
			_array = NULL;
			_size = 0;
		}
	}
	Array<T>(Array<T> const & src) {
		*this = src;
	}
	Array<T> &	operator=(Array<T> const & src) {
		if (this = &src)
			return *this;
		if (src._size == 0)
			return *this;
		if (_array)
			delete[] _array;
		_size = src._size;
		_array = new T[_size];
		for (int i = 0; i < src._size; ++i) {
			_array[i] = src._array[_size];
		}
		return *this;
	}
	unsigned int &	size() {
		return _size;
	}
	~Array();

	class	IndexOutOfBoundExeption : public std::exception {
		private:
		std::string	_message;
		public:
		IndexOutOfBoundExeption(const std::string & message) : _message(message) {}
		virtual ~IndexOutOfBoundExeption() throw() {}
		virtual const char* what() const throw() {
			return _message.c_str();
		}
	};
};

#endif
