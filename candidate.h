#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<fstream>
using namespace std;

class candidate
{
protected:
	string name,cnic, party_affiliation, candidate_file, party_file, line, province, union_council, district;
	int vote;
	bool found = false, found2 = false;
	string Nadra_file = "F:\\project oop\\Data Base\\nadra_database.txt";
public:
	virtual bool check_age(string a) = 0;
	bool check_pakistani(string a);
};
