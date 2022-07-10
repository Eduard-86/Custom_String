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

	char ffff1[20] = "dddddddd";
	
	const char* tttt1 = "ffffffff";
	
	memcpy(&ffff1[4], tttt1, 2);

	memcpy(ffff1, tttt1,20);

	
	//t odo переделать копирование и конкатанацию с помащью memcpy
	//t odo переделать сравнение через memcmp


	
	My_String g1("shs");
	My_String g2("fgf");

	My_String g3 = g1 + g2;

	My_String g4 = g3;

	
	bool A = g1 == g2;

	bool B = g4 == g3;



	vector<My_String> array;

	array.emplace_back(nullptr);
	
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
