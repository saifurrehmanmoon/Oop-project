#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

class ELECTION
{
protected:
	int start_month, start_year, start_day,end_year, end_month, end_day;
	string file,CNIC;
	virtual void add_condidate() = 0;
	virtual void remove_condidate() = 0;
	void start_election();
	void end_election();
	virtual void interface() = 0;
	virtual ~ELECTION() = 0;
};

