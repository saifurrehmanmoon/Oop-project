#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include"LOCAL.h"
#include"PROVINCIAL.h"
#include"NATIONAL.h"
#include"Candidate.h"

using namespace std;

class ADMINISTRATOR:public LOCAL,PROVINCIAL,NATIONAL
{
	int choice;
public:
	void create_election();
	void add_candidate();
	void view_results();
	void interface();
};


