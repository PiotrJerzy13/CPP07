/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:28:07 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/17 13:34:49 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstddef>

template <typename T, typename F>
void iter(T* arr, size_t len, F func)
{
	T* end = arr + len;
	for (T* p = arr; p < end; ++p)
	{
		func(*p);
	}
}
