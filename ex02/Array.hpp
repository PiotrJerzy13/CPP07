/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:00:19 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/17 17:56:31 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <utility>

template<typename T>
class Array
{
private:
	T* _data;
	size_t _size;

public:
	Array();
	explicit Array(size_t n);
	Array(const Array& other);
	Array(Array&& other) noexcept;
	~Array();

	Array& operator=(const Array& other);
	Array& operator=(Array&& other) noexcept;

	size_t size() const;

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	class OutOfRangeException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

	template<typename... Args>
	void emplace(size_t index, Args&&... args);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

#include "Array.tpp"

#endif