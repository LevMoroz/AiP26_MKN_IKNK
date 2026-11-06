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

int min(int* a, int len)
{
	if (len <= 0)
		return -1; // Классическое обозначение ошибки в Си...

	int m = a[0];

	for (int i = 1; i < len; ++i)
		if (a[i] < m)
			m = a[i];

	return m;
}

int min(int** a, int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
		return -1;
	
	int m = a[0][0];

	for (int i = 0; i < rows; ++i)
	{
		int m_r = min(a[i], cols);
		if (m_r < m)
			m = m_r;
	}

	return m;
}
