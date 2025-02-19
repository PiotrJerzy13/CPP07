/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:49:38 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/19 13:34:33 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>

class Complex
{
private:
	static int counter;
	int id;
	std::string name;
	int value;

public:
	Complex();
	Complex(const std::string& n, int v);
	Complex(const Complex& other);
	Complex(Complex&& other) noexcept;
	Complex& operator=(const Complex& other);
	Complex& operator=(Complex&& other) noexcept;
	void display() const;
};

#endif

