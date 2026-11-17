#pragma once

int inc_by_value(int v);
void inc_by_pointer(int* pv);
void inc_by_reference(int& v);

void swap(int* xp, int* yp);
void swap(int& x, int& y);

int min(const int* a, int len);
int min(const int* const* a, int rows, int cols); // ƒл€ безопасного автоматического приведени€ типов

int my_str_cmp(const char* str1, const char* str2);
