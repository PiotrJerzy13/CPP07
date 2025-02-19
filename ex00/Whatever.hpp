/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:54:25 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/19 13:19:43 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	if (&a != &b)
	{
		T temp(std::move(a));
		a = std::move(b);
		b = std::move(temp);
	}
}
// template<typename T>
// void swap(T &a, T &b)
// {
// 	if (&a != &b)
// 	{
// 		T temp(a);
// 		a = b;
// 		b = temp;
// 	}
// }

template<typename T>
const T& min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template<typename T>
const T& max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}
