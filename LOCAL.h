#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include "ELECTION.h"
using namespace std;
class LOCAL:protected ELECTION
{
protected:
	void add_condidate () override;
	void remove_condidate() override;
	void interface() override;
};

