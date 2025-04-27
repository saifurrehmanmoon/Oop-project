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
public:
	ELECTION(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0):
		start_day(a),start_month(b),start_year(c),end_day(d),end_month(e),end_year(f){ }
	void start_election();
	void end_election();
    ~ELECTION() {}

	//define in derived class
	virtual void add_condidate() = 0;
	virtual void remove_condidate() = 0;
	virtual void modify_candidate() = 0;
};