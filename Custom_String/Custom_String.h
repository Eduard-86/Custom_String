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

	~My_String();
	

	My_String& operator=(const char* value);

	My_String& operator=(const My_String& value);

	My_String& operator=(My_String&& x) noexcept;

	bool operator==(const My_String& value) const;

	bool operator>(const My_String& value) const;

	bool operator<(const My_String& value) const;


	const char* Get_String() const;

	int Get_Size() const;

protected:

	char* string_ptr;
	int size;

private:

	void Construct_Array(const char* value);

	void Construct_Array(const My_String& value);
};



