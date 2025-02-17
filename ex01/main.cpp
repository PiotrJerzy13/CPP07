/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:30:06 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/17 13:34:38 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int numbers[5] = { 10, 20, 30, 40, 50 };
	
	std::cout << "Original numbers: ";
	iter(numbers, 5, [](const int &n)
	{
		std::cout << n << " ";
	});
	std::cout << "\n";
	
	iter(numbers, 5, [](int &n)
	{
		n /= 10;
	});
	
	std::cout << "Modified numbers: ";
	iter(numbers, 5, [](int n)
	{
		std::cout << n << " ";
	});
	std::cout << "\n\n";
	
	std::string words[3] = {"apple", "banana", "cherry"};
	
	std::cout << "Original words:\n";
	iter(words, 3, [](const std::string &s)
	{
		std::cout << s << "\n";
	});
	std::cout << "\n";
	
	iter(words, 3, [](std::string &s)
	{
		s += " pie";
	});
	
	std::cout << "Modified words:\n";
	iter(words, 3, [](const std::string &s)
	{
		std::cout << s << "\n";
	});
	
	return 0;
}
