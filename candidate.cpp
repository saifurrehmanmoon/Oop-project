#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<fstream>
#include "candidate.h"

using namespace std;

//vote increase
void candidate::incrementvotes(string ser)
{
	string line;
	ofstream temp("F:\\project oop\\Data Base\\temp_database.txt");
	ifstream in(candidate_file);
	if (!in)
	{
		ofstream out(candidate_file);
		out.close();
	}
	while (getline(in, line))
	{
		string a, b, c;
		stringstream s(line);
		getline(s, a, ',');
		getline(s, b, ',');
		getline(s, c, ',');
		if (a == ser)
		{
			vote = stoi(c);
			vote++;
			temp << a << "," << b << "," << vote<<endl;
		}
		else
			temp << line << endl;
	}
	in.close();
	temp.close();

	remove(candidate_file.c_str());
	rename("F:\\project oop\\Data Base\\candidate\\temp_database.txt", candidate_file.c_str());
}

//return candidate 
string candidate::get_candidate(string ser)
{
	string line="";
	ifstream in(candidate_file);
	if (!in)
	{
		ofstream out(candidate_file);
		out.close();
	}
	while (getline(in, line))
	{
		string a, b, c;
		stringstream s(line);
		getline(s, a, ',');
		getline(s, b, ',');
		getline(s, c, ',');
		if (a == ser)
		{
			return line;
		}
	}
	in.close();
	return "";
}

//vote
int candidate::get_vote_count(string ser)
{
	string line = "";
	ifstream in(candidate_file);
	if (!in)
	{
		ofstream out(candidate_file);
		out.close();
	}
	while (getline(in, line))
	{
		string a, b, c;
		stringstream s(line);
		getline(s, a, ',');
		getline(s, b, ',');
		getline(s, c, ',');
		if (a == ser)
		{
			int vote = stoi(c);
			return vote;
		}
	}
	in.close();
}

//add condidate & update condidate
void candidate::set_candidate(string a, string b, int c)
{
	string line;
	ifstream in(candidate_file);
	ofstream temp("F:\\project oop\\Data Base\\temp_database.txt");
	if (!in)
	{
		ofstream out(candidate_file);
		out.close();
	}
	while (getline(in, line))
	{
		string aa, bb, cc;
		stringstream s(line);
		getline(s, aa, ',');
		getline(s, bb, ',');
		getline(s, cc, ',');
		if (aa == a)
		{
			temp << a << "," << b << "," << c << endl;
		}
		else
			temp << line << endl;
	}
	in.close();
	temp.close();

	remove(candidate_file.c_str());
	rename("F:\\project oop\\Data Base\\temp_database.txt", candidate_file.c_str());
}