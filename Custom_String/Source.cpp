#include <iostream>

#include "Custom_String.h"

#include <string>

#include <vector>

#include <algorithm>


My_String operator+(const My_String& left, const My_String& right)
{
	const char* leftdate = left.Get_String();

	const char* rightdate =  right.Get_String();


	int leftsize = left.Get_Size();

	int rightsize = right.Get_Size();
	

	int tempsize = rightsize + leftsize;
	

	char* tempstr = new char[tempsize + 1];
	

	int i = 0;
	
	for(; i < leftsize; ++i)
	{
		tempstr[i] = leftdate[i];
	}

	for(int j = 0; j < rightsize; ++i, ++j)
	{
		tempstr[i] = rightdate[j];
	}

	
	tempstr[tempsize] = '\0';

	
	My_String NewStr(tempstr);

	delete[] tempstr;
	
	return NewStr;
}




int main()
{
	using namespace std;


	vector<My_String> array;

	array.emplace_back("Red");
	
	array.emplace_back("Black");
	
	array.emplace_back("Yellow");
	
	array.emplace_back("Green");
	
	array.emplace_back("Brown");
	

	sort(array.begin(), array.end());

	
	for(int i = 0; i < array.size(); ++i)
	{
		cout << array[i].Get_String() << endl;
	}
	
	
	return 0;
}
