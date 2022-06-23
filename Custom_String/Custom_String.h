#pragma once
#include <cstring>
#include <iostream>

class My_String
{
public:

	My_String() : string_ptr(nullptr), size(0) {}

	My_String(const char* value);

	My_String(const My_String& value);

	My_String(My_String&& x) noexcept;

	// concatenate constructor 
	My_String(const My_String& left, const My_String& right);

	~My_String();
	

	My_String& operator=(const char* value);

	My_String& operator=(const My_String& value);

	My_String& operator=(My_String&& x) noexcept;

	bool operator==(const My_String& value) const;

	bool operator>(const My_String& value) const;

	bool operator<(const My_String& value) const;


	const char* Get_C_Str() const;

	int Get_Size() const;

protected:

	char* string_ptr;
	int size;

private:

	void Construct_Array(const char* value);

	void Construct_Array(const My_String& value);
};



