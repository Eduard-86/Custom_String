#include "Custom_String.h"

#pragma region Constructors

My_String::My_String(const char* value)
{
	Construct_Array(value);
}

My_String::My_String(const My_String& value)
{
	Construct_Array(value);
}

My_String::My_String(My_String&& x) noexcept
{
	std::swap(string_ptr, x.string_ptr);
	std::swap(size, x.size);
}



My_String::~My_String()
{	
	delete[] string_ptr;
}

#pragma endregion 

#pragma region Operators

My_String& My_String::operator=(const char* value)
{
	delete[] string_ptr;

	Construct_Array(value);

	return *this;
}

My_String& My_String::operator=(const My_String& value)
{
	delete[] string_ptr;

	Construct_Array(value);

	return *this;
}

My_String& My_String::operator=(My_String&& x) noexcept
{
	std::swap(string_ptr, x.string_ptr);
	std::swap(size, x.size);

	return *this;
}

#pragma endregion 

void My_String::Construct_Array(const char* value)
{
	size = strlen(value);

	string_ptr = new char[size + 1];

	for (int i = 0; i <= size; ++i)
	{
		string_ptr[i] = value[i];
	}

	string_ptr[size] = '\0';
}

void My_String::Construct_Array(const My_String& value)
{
	size = value.size;

	string_ptr = new char[size + 1];

	for (int i = 0; i <= size; ++i)
	{
		string_ptr[i] = value.string_ptr[i];
	}

	string_ptr[size] = '\0';
}
