#include<iostream>
using namespace std;

int StringLength(const char str[]);	
void Print(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
bool is_palindrome(const char str[]);
void shrink(char str[]);
bool is_int_number(const char str[]);
int  to_int_number(char str[]);
bool is_bin_number(const char str[]);
int  bin_to_dec(char str[]);
bool is_hex_number(const char str[]);
int hex_to_dec(char str[]);
void main()
{

	setlocale(LC_ALL, "");
	char str[] = "11A";
	cout << StringLength(str) << endl;

	/*to_upper(str);
	Print(str);
	to_lower(str);
	Print(str);
	Print(str);
	shrink(str);
	Print(str);*/
	cout << "���������� ����� " << to_int_number(str) << endl;
	cout << "�������� ����� � ���������� " << bin_to_dec(str) << endl;
	cout << "����������������� ����� � ���������� " << hex_to_dec(str) << endl;
	if (is_palindrome(str)==true)
	{
		cout << "������ �������� �����������" << endl;
	}
	else
	{
		cout << "������ �� �������� �����������" << endl;
	}
	if (is_int_number(str)==true)
	{
		cout << "������ �������� ���������� ������" << endl;
	}
	else
	{
		cout << "������ �� �������� ���������� ������" << endl;
	} 
	if (is_bin_number(str) == true)
	{
		cout << "������ �������� �������� ������" << endl;
	}
	else
	{
		cout << "������ �� �������� �������� ������" << endl;
	}
	if (is_hex_number(str) == true)
	{
		cout << "������ �������� ����������������� ������" << endl;
	}
	else
	{
		cout << "������ �� �������� ����������������� ������" << endl;
	}
}
void Print(char str[])
{
	for (int i = 0; i < StringLength(str); i++)
	{
		cout << str[i];
	}
	cout << endl;
}
int StringLength(const char str[])
{
	int i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return i;
}
void to_upper(char str[])
{

	for (int i = 0; i < StringLength(str); i++)
	{
		if (str[i] >= 97 and str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
		if (str[i] >= -32 and str[i] <= -1)
		{
			str[i] = str[i] - 32;
		}
		if (str[i] == -72)
		{
			str[i] = str[i] - 16;
		}
	}
}
void to_lower(char str[])
{
	for (int i = 0; i < StringLength(str); i++)
	{
		if (str[i] >= 65 and str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		if (str[i] >= -64 and str[i] <= -33)
		{
			str[i] = str[i] + 32;
		}
		if (str[i] == -88)
		{
			str[i] = str[i] + 16;
		}
	}
}
void shrink(char str[])
{
	int len = StringLength(str);
	for (int i = 0; i < StringLength(str); i++)
	{
		if (str[i] == str[i + 1] and str[i] == ' ')
		{
			for (int j = i; j < StringLength(str); j++)
			{
				str[j+1] = str[j + 2];
			}
			i--;
			len--;
		}
	}
	str[len] = 0;
}
bool is_palindrome(const char str[])
{
	int count = 0;
	int len = StringLength(str);
	for (int i = 0; i < (int)(len/2); i++)
	{
		if (str[i] != str[len - 1-i])
		{
			count++;
		}
	}
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool is_int_number(const char str[])
{
	int count = 0;
	int len = StringLength(str);
	for (int i = 0; i < len; i++)
	{
		if (!(str[i] >= 48 and str[i] <= 57))
		{
			count++;
		}
	}
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int  to_int_number(char str[])
{
	int value = 0;
	if (is_int_number(str) == true)
	{
		for (int i = 0; i < StringLength(str); i++)
		{
			value *= 10;
			value += (int)str[i] - 48;
		}
	}
	return value;
}
bool is_bin_number(const char str[])
{
	int count = 0;
	int len = StringLength(str);
	for (int i = 0; i < len; i++)
	{
		if (!(str[i] >= 48 and str[i] <= 49))
		{
			count++;
		}
	}
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int bin_to_dec(char str[])
{
	int value = 0;
	if (is_bin_number(str) == true)
	{
		for (int i = 0; i < StringLength(str); i++)
		{
			value += ((int)str[i] - 48) * pow(2, StringLength(str) - 1 - i);
		}
	}
	return value;
}
bool is_hex_number(const char str[])
{
	int count = 0;
	int len = StringLength(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 48 and str[i] <= 57) {}
		else if (str[i] >= 65 and str[i] <= 70){}
		else
		{
			count++;
		}
	}
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int hex_to_dec(char str[])
{
	int value = 0;
	int number;
	if (is_hex_number(str) == true)
	{
		for (int i = 0; i < StringLength(str); i++)
		{
			if (str[i] >= 48 and str[i] <= 57)
			{
				number = (int)str[i]-48;
			}
			else
			{
				number = (int)str[i] - 55;
			}
			value += number * pow(16, StringLength(str) - 1 - i);
		}
	}
	return value;
}