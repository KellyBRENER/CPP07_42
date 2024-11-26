/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:45:48 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/26 15:44:25 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
			_array = new T[n];
			_size = n;
			for (unsigned int i = 0; i < n; ++i)
				_array[i] = T();//pour initialiser à null ou 0
		}
		else {
			_array = NULL;
			_size = 0;
		}
	}
	Array<T>(Array<T> const & src) {
		_size = src._size;
		if (src._size == 0)
			_array = NULL;
		else {
			_array = new T[_size];
			for (unsigned int i = 0; i < src._size; ++i) {
				_array[i] = src._array[i];
			}
		}
	}
	Array<T> &	operator=(Array<T> const & src) {
		if (this == &src)
			return *this;
		if (_size > 0)
			delete[] _array;
		_size = src._size;
		if (src._size == 0)
			_array = NULL;
		else {
			_array = new T[_size];
			for (unsigned int i = 0; i < src._size; ++i) {
				_array[i] = src._array[i];
			}
		}
		return *this;
	}

	T&	operator[](unsigned int i) {
		if (i >= _size)
			throw IndexOutOfBoundExeption("index out of bound");
		return (_array[i]);
	}
	unsigned int	size() const {
		return _size;
	}


	~Array() {}

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
template <typename T>
std::ostream&	operator<<(std::ostream & o, Array<T> & src) {
	for (unsigned int i = 0; i < src.size(); ++i)
		o << "array["<<i<<"] = "<<src[i]<<"; ";
	return o;
}
#endif
