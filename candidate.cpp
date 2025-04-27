#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<fstream>
#include"candidate.h"
using namespace std;

bool candidate::check_pakistani(string a)
{
	ifstream in(Nadra_file);

	while (getline(in, line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13;
		getline(s, col1, ',');
		getline(s, col2, ',');
		getline(s, col3, ',');
		getline(s, col4, ',');
		getline(s, col5, ',');
		getline(s, col6, ',');
		getline(s, col7, ',');
		getline(s, col8, ',');
		getline(s, col9, ',');
		getline(s, col10, ',');
		getline(s, col11, ',');
		getline(s, col12, ',');
		getline(s, col13, ',');
		if (col5 == a)
		{
			int d = stoi(col13);
			if (d == 1)
			{
				found = true;
				break;
			}
		}
	}
	in.close();
	return found;
}