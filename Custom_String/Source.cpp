#include <iostream>
#include "Custom_String.h"
#include <vector>
#include <algorithm>


My_String operator+(const My_String& left, const My_String& right)
{
	return My_String (left, right);
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
		cout << array[i].Get_C_Str() << endl;
	}
	
	
	return 0;
}
