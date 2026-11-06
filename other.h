#pragma once

int inc_by_value(int v);
void inc_by_pointer(int* pv);
void inc_by_reference(int& v);

void swap(int* xp, int* yp);
void swap(int& x, int& y);

int min(int* a, int len);
int min(int** a, int rows, int cols);
