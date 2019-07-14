#pragma once
#include<iostream>
#include<Windows.h>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

const char tab = '\t';

class String
{
	int size;
	char* str;
public:
	int get_size() const;
	const char* get_str() const;
	char* get_str();
	void set_size(int size);
	String(int size = 80);
	String(const char str[]);
	String(const String& other);
	~String();

	//			Operators:
	String& operator=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);
	String operator+=(const String& other);
	//			Methods:
	int StrLen(char const* str) const;
	void print();
	bool is_bin();
	int bin_to_dec();
	bool is_hex();
	int hex_to_dec();
};
ostream& operator<<(ostream& os, const String& obj);
istream& operator>>(istream& is, String& obj);
String operator+(const String& left, const String& right);