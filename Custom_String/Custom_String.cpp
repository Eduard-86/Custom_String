#include "Custom_String.h"

#pragma region Constructors

My_String::My_String(const char* value)
{
	Construct_Array(value);
}

My_String::My_String(const My_String& value)
{
	Construct_Array(value.Get_C_Str());
}

My_String::My_String(My_String&& x) noexcept
{	
	Construct_Movement(std::move(x));
}

My_String::My_String(const My_String& left, const My_String& right)
{
	size = left.size + right.size;

	string_ptr = new char[size + 1];

	memcpy(string_ptr, left.Get_C_Str(), left.size);

	memcpy(&string_ptr[left.size], right.Get_C_Str(), right.size);

	string_ptr[size] = '\0';
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
	// todo
	if (&value == this)
	{
		return *this;
	}
	
	delete[] string_ptr;

	Construct_Array(value.Get_C_Str());

	return *this;
}

My_String& My_String::operator=(My_String&& x) noexcept
{
	//std::swap(string_ptr, x.string_ptr);
	//std::swap(size, x.size);

	//todo
	Construct_Movement(std::move(x));
	
	return *this;
}

bool My_String::operator==(const My_String& value) const
{
	if (&value == this)
	{
		return true;
	}
	
	if (this->size != value.size)
	{
		return false;
	}

	return (0 == memcmp(this->Get_C_Str(), value.Get_C_Str(), size));
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


const char* My_String::Get_C_Str() const
{
	return string_ptr;
}

int My_String::Get_Size() const
{
	return size;
}

void My_String::Construct_Array(const char* value)
{
	if(value == nullptr)
	{
		throw std::exception("Function Construct_Array() received nullptr");
		return;
	}
		
	size = strlen(value);

	if (size == 0)
	{
		string_ptr = nullptr;
		return;
	}

	string_ptr = new char[size + 1];

	memcpy(string_ptr, value, size);

	string_ptr[size] = '\0';
}

void My_String::Construct_Movement(My_String&& x)
{
	string_ptr = x.string_ptr;

	size = x.size;

	x.size = 0;

	x.string_ptr = nullptr;
}

/*
void My_String::Construct_Array(const My_String& value)
{
	size = value.size;

	if(size == 0)
	{
		string_ptr = nullptr;
		return ;
	}

	string_ptr = new char[size + 1];

	for (int i = 0; i <= size; ++i)
	{
		string_ptr[i] = value.string_ptr[i];
	}

	string_ptr[size] = '\0';
}
*/
