/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:01:51 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/19 13:32:27 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

template<typename T>
Array<T>::Array(size_t n) : _data(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other) : _data(new T[other._size]), _size(other._size)
{
	for (size_t i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

template<typename T>
Array<T>::Array(Array&& other) noexcept : _data(nullptr), _size(0)
{
	_data = other._data;
	_size = other._size;

	other._data = nullptr;
	other._size = 0;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* newData = new T[other._size];
		for (size_t i = 0; i < other._size; ++i)
			newData[i] = other._data[i];

		delete[] _data;
		_data = newData;
		_size = other._size;
	}
	return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept
{
	if (this != &other)
	{
		delete[] _data;

		_data = other._data;
		_size = other._size;

		other._data = nullptr;
		other._size = 0;
	}
	return *this;
}

template<typename T>
size_t Array<T>::size() const
{
	return _size;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw OutOfRangeException();
	return _data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw OutOfRangeException();
	return _data[index];
}

template<typename T>
const char* Array<T>::OutOfRangeException::what() const noexcept
{
	return "Array index out of range";
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	os << "[ ";
	for (size_t i = 0; i < arr.size(); ++i)
	{
		os << arr[i];
		if (i + 1 < arr.size())
			os << " | ";
	}
	os << " ]";
	return os;
}

template<typename T>
template<typename... Args>
void Array<T>::emplace(size_t index, Args&&... args)
{
	if (index >= _size)
		throw OutOfRangeException();
	_data[index] = T(std::forward<Args>(args)...);
}
