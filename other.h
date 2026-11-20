#pragma once

int inc_by_value(int v);
void inc_by_pointer(int* pv);
void inc_by_reference(int& v);

void swap(int* xp, int* yp);
void swap(int& x, int& y);

int min(const int* a, int len);
int min(const int* const* a, int rows, int cols);

int my_str_cmp(const char* str1, const char* str2);

int day_of_year(int day, int month, int year, const int (*part)[2][12]);
void day_of_month(int num, int year, int& day, int& month, const int (*part)[2][12]);

void print_array(const int* a, int len);
int add_unique(int*& arr, int& len, int new_value);

int sumN(int n);
