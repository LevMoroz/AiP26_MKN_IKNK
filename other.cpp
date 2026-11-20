#include <cassert>
#include <iostream>

#include "other.h"

int inc_by_value(int v)
{
	return v + 1;
}

void inc_by_pointer(int* pv)
{
	++*pv;
}

void inc_by_reference(int& v)
{
	++v;
}

void swap(int* xp, int* yp)
{
	int t = *xp;
	*xp = *yp;
	*yp = t;
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int min(const int* a, int len)
{
	assert(len > 0 && a);

	int m = a[0];

	for (int i = 1; i < len; ++i)
		if (a[i] < m)
			m = a[i];

	return m;
}

int min(const int* const* a, int rows, int cols) //
{
	assert(rows > 0 && cols > 0 && a);
	
	int m = a[0][0];

	for (int i = 0; i < rows; ++i)
	{
		int m_r = min(a[i], cols);
		if (m_r < m)
			m = m_r;
	}

	return m;
}

int my_str_cmp(const char* str1, const char* str2)
{
	while (*str1 && *str1 == *str2)
	{
		++str1;
		++str2;
	}

	return (unsigned char)*str1 - (unsigned char)*str2; // Для корректной работы с русским алфавитом, например
}

int day_of_year(int day, int month, int year, const int (*part)[2][12])
{
	int type = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 1 : 0;

	assert(part && 1 <= month && month <= 12 && 1 <= day && day <= (*part)[type][month - 1]);
	
	int num = 0;
	for (int i = 0; i < month - 1; ++i)
		num += (*part)[type][i];

	return num + day;
}

void day_of_month(int num, int year, int& day, int& month, const int (*part)[2][12])
{
	int type = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 1 : 0;

	assert(1 <= num && num <= 365 + type && part);

	int i = 0;
	for (; num > (*part)[type][i]; ++i)
		num -= (*part)[type][i];

	day = num;
	month = i + 1;
}

void print_array(const int* a, int len)
{
	assert(a && len >= 0);
	for (int i = 0; i < len; ++i)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

int add_unique(int*& arr, int& len, int new_value)
{
	assert(arr && len >= 0);
	for (int i = 0; i < len; ++i)
		if (arr[i] == new_value)
			return 1;

	int* arr2 = new int[len + 1];
	for (int i = 0; i < len; ++i)
		arr2[i] = arr[i];

	arr2[len++] = new_value;
	delete[] arr;
	arr = arr2;

	return 0;
}

int sumN(int n)
{
	assert(n > 0);
	return n != 1 ? n + sumN(n - 1) : 1;
}
