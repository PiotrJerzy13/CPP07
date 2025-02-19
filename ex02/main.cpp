/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:03:30 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/19 13:36:07 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Complex.hpp"

int main()
{
	std::cout << "=== Testing Array<int> ===" << std::endl;
	Array<int> arr(5);
	arr[0] = 10;
	arr[1] = 20;
	arr.emplace(2, 30);

	std::cout << "Array: " << arr << std::endl;

	Array<int> arr2 = arr;
	Array<int> arr3 = std::move(arr);

	std::cout << "Copied Array: " << arr2 << std::endl;
	std::cout << "Moved Array: " << arr3 << std::endl;

	std::cout << "\n=== Testing Array<Complex> ===" << std::endl;
	Array<Complex> complexArr(3);
	complexArr.emplace(0, "First", 100);
	complexArr.emplace(1, "Second", 200);
	complexArr.emplace(2, "Third", 300);

	std::cout << "Complex Array: [ ";
	for (size_t i = 0; i < complexArr.size(); ++i)
	{
		complexArr[i].display();
		if (i + 1 < complexArr.size()) std::cout << " | ";
	}
	std::cout << " ]" << std::endl;

	std::cout << "\nCopying Complex Array..." << std::endl;
	Array<Complex> complexArr2 = complexArr;

	std::cout << "Copied Complex Array: [ ";
	for (size_t i = 0; i < complexArr2.size(); ++i)
	{
		complexArr2[i].display();
		if (i + 1 < complexArr2.size()) std::cout << " | ";
	}
	std::cout << " ]" << std::endl;

	std::cout << "\nMoving Complex Array..." << std::endl;
	Array<Complex> complexArr3 = std::move(complexArr);

	std::cout << "Moved Complex Array: [ ";
	for (size_t i = 0; i < complexArr3.size(); ++i)
	{
		complexArr3[i].display();
		if (i + 1 < complexArr3.size()) std::cout << " | ";
	}
	std::cout << " ]" << std::endl;

	return 0;
}
