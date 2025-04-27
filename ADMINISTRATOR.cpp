#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include"LOCAL.h"
#include"PROVINCIAL.h"
#include"NATIONAL.h"
#include "ADMINISTRATOR.h"
#include <cstdlib>

using namespace std;

void ADMINISTRATOR::interface()
{
	cout << "\n\t----Adminstrator----\n\n";
	cout << "1. Add Candidate\n";
	cout << "2. View Results\n";
	cout << "3. Create Election\n";
	cout << "4. Exit\n";
	cout << "Enter Choice :";
	do {
		while (true) {
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter number between 1 and 3 :";
			}
			else if (choice > 4 || choice < 1)
				cout << "Enter number between 1 and 3 :";
			else
				break;
		}
		if (choice == 1)
		{
			add_candidate();
		}
		else if (choice == 2)
		{
			view_results();
		}
		else if (choice == 3)
		{
			create_election();
		}
		else
		{
			cout << "\n\tThanks for coming in E Voting Website";
			exit(0);
		}
	} while (true);
}

void ADMINISTRATOR::create_election()
{

}

void ADMINISTRATOR::add_candidate()
{
	cout << "\tAdd Candidate\n";
	cout << "1. Local Candidate\n";
	cout << "2. Provincial Candidate\n";
	cout << "3. National Candidate\n";
	cout << "4. Exit\n";
	cout << "Enter Choice :";
	while(true){
		cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter number between 1 and 3 :";
		}
		else if (choice > 4 || choice < 1)
			cout << "Enter number between 1 and 3 :";
		else
			break;
	}

	ELECTION* e;
	if (choice == 1)
	{
		LOCAL l;
		e = &l;
		e->add_condidate();
	}
	else if (choice == 2)
	{
		PROVINCIAL l;
		e = &l;
		e->add_condidate();
	}
	else if (choice == 3)
	{
		NATIONAL l;
		e = &l;
		e->add_condidate();
	}
	else
		return;
}

void ADMINISTRATOR::view_results()
{

}