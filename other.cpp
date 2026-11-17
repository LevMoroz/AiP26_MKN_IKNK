#include <climits>

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
	if (len <= 0 || !a)
		return INT_MAX; // Для обозначения ошибки... Нужна ли проверка?

	int m = a[0];

	for (int i = 1; i < len; ++i)
		if (a[i] < m)
			m = a[i];

	return m;
}

int min(const int* const* a, int rows, int cols)
{
	if (rows <= 0 || cols <= 0 || !a)
		return INT_MAX;
	
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
