#include"String.h";
void main()
{
	setlocale(LC_ALL, "Russian");
	String str;
	cout << "������� ����������������� �����: ";
	cin >> str;
	cout << str.is_hex() << endl;
	cout << str.hex_to_dec() << endl;
}