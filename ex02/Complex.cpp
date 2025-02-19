/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:52:04 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/19 13:33:35 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Complex.hpp"

int Complex::counter = 1;

Complex::Complex() : id(counter++), name(""), value(0)
{
	std::cout << "[Default Constructor] Created Complex ID " << id << std::endl;
}

Complex::Complex(const std::string& n, int v) : id(counter++), name(n), value(v)
{
	std::cout << "[Parameterized Constructor] Created Complex ID " << id << " (" << name << ")" << std::endl;
}

Complex::Complex(const Complex& other) : id(counter++), name(other.name), value(other.value)
{
	std::cout << "[Copy Constructor] Copied Complex ID " << other.id << " to new ID " << id << std::endl;
}

Complex::Complex(Complex&& other) noexcept : id(other.id), name(std::move(other.name)), value(other.value)
{
	std::cout << "[Move Constructor] Moved Complex ID " << id << std::endl;
	other.value = 0;
}

Complex& Complex::operator=(const Complex& other)
{
	if (this != &other)
	{
		name = other.name;
		value = other.value;
		std::cout << "[Copy Assignment] Complex ID " << id << " copied from ID " << other.id << std::endl;
	}
	return *this;
}

Complex& Complex::operator=(Complex&& other) noexcept
{
	if (this != &other)
	{
		name = std::move(other.name);
		value = other.value;
		std::cout << "[Move Assignment] Complex ID " << id << " took ownership from ID " << other.id << std::endl;
		other.value = 0;
	}
	return *this;
}

void Complex::display() const
{
	std::cout << "[ID: " << id << "] " << name << ": " << value;
}
