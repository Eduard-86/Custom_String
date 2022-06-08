#include <iostream>
#include "Custom_String.h"

using namespace std;

int main()
{

	setlocale(LC_ALL, "ru");
	using namespace std;


	My_String A("TTTT");

	My_String B("TEST");

	/*
		Лексикографический порядок, это побуквенное сравнение слов,
			Сравнение идёт до первой разжници в буквах, старше то слово у которого буква старше
				А < Б
			Если первое слово является подстрокой второго то второе слово старше 
	 
	 */

	
	return 0;
}
