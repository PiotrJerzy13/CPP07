/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:03:30 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/17 17:49:39 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> arr(5);
    arr[0] = 10;
    arr[1] = 20;
    arr.emplace(2, 30);

    std::cout << "Array: " << arr << std::endl;

    Array<int> arr2 = arr; // Copy constructor
    Array<int> arr3 = std::move(arr); // Move constructor

    std::cout << "Copied Array: " << arr2 << std::endl;
    std::cout << "Moved Array: " << arr3 << std::endl;

    return 0;
}
