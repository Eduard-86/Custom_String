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

	x.string_ptr = nullptr;
	
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

	x.string_ptr = nullptr;

	return *this;
}

bool My_String::operator==(const My_String& value) const
{
	if (this->size != value.size)
	{
		return false;
	}
	
	int tempsize = this->size;

	for (int i = 0; i < tempsize; ++i)
	{
		if (this->string_ptr[i] != value.string_ptr[i])
		{
			return false;
		}
	}

	return true;
}

bool My_String::operator>(const My_String& value) const
{
	int tempsize = this->size < value.size ? value.size : this->size;

	for(int i = 0; i < tempsize; ++i)
	{
		if (this->string_ptr[i] == value.string_ptr[i])
		{
			continue;
		}
		
		else if(this->string_ptr[i] > value.string_ptr[i])
		{
			return true;
		}
		
		else if(this->string_ptr[i] < value.string_ptr[i])
		{
			return false;
		}
	}

	return false;
}

bool My_String::operator<(const My_String& value) const
{
	int tempsize = this->size < value.size ? value.size : this->size;
	
	for (int i = 0; i < tempsize; ++i)
	{
		if (this->string_ptr[i] == value.string_ptr[i])
		{
			continue;
		}

		else if (this->string_ptr[i] > value.string_ptr[i])
		{
			return false;
		}

		else if (this->string_ptr[i] < value.string_ptr[i])
		{
			return true;
		}
	}

	return false;
}

#pragma endregion 


const char* My_String::Get_String() const
{
	return string_ptr;
}

int My_String::Get_Size() const
{
	return size;
}

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
