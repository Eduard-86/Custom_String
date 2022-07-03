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
	
	memcpy(&ffff1[4], tttt1, 4);

	//todo переделать копирование и конкатанацию с помащью memcpy
	//todo переделать сравнение через memcmp
	
	My_String g1("sss");
	My_String g2("ssf");

	bool A = g1 == g2;

	bool B = g1 == g1;
	

	int gg = 5;
	int ss = 0;

	const char* ffff = "dddddddd";
	const char* tttt = "ffffffff";
	
	ss = memcmp("oopp", "ggg", gg);

	ss = memcmp("ggg", "ggg", gg);

	ss = memcmp("ggg", "oopp", gg);

	ss = memcmp(ffff, ffff, gg);


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
