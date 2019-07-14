#include"String.h";
int String::get_size() const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}
void String::set_size(int size)
{
	if (size > 0)
	{
		this->size = size;
	}
	else
	{
		this->size = 80;
	}
}
String::String(int size)
{
	set_size(size);	//Задаем размер строки
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[])
{
	//cout << StrLen(str) << endl;
	this->size = StrLen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; other.str[i]; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	cout << "CopyAssignment:" << this << endl;
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; other.str[i]; i++)this->str[i] = other.str[i];
	return *this;
}

const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
String String::operator+=(const String& other)
{
	size += other.size;
	str += *other.str;
	return *this;
}
//			Methods:
int String::StrLen(char const* str) const
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void String::print()
{
	cout << "str:" << str << endl;
	cout << "size:" << size << endl;
}
bool String::is_bin()
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1')
		{
			return false;
		}
	}
	return true;
}
int String::bin_to_dec()
{
	if (!is_bin())
	{
		return 0;
	}
	int dec = 0;
	int weight = 1;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		dec += (str[i] - 48) * weight;
		weight *= 2;
	}
	return dec;
}
bool String::is_hex()
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'A' && str[i] <= 'F') && !(str[i] >= 'a' && str[i] <= 'f'))
		{
			return false;
		}
	}
	return true;
}
int String::hex_to_dec()
{
	if (!is_hex())
	{
		return false;
	}
	int dec = 0;
	int weight = 1;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			dec += (str[i] - '0') * weight;
		}
		if (str[i] >= 'A' && str[i] <= 'F')
		{
			dec += (str[i] - 'A' + 10) * weight;
		}
		if (str[i] >= 'a' && str[i] <= 'f')
		{
			dec += (str[i] - 'a' + 10) * weight;
		}
		weight *= 16;
	}
	return dec;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

istream& operator>>(istream& is, String& obj)
{
	return is >> obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String res = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size() - 1; i++)
	{
		res[i] = left[i];
	}
	for (int i = 0; i < right.get_size() - 1; i++)
	{
		res.get_str()[i + left.get_size() - 1] = right.operator[](i);
	}
	return res;
};

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}