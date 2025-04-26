#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<fstream>
using namespace std;

class candidate
{
private:
	string cnic,party_affiliation;
	int vote;
	string candidate_file;
protected:
	void incrementvotes(string ser);
	string get_candidate(string ser);
	int get_vote_count(string ser);
	void set_candidate(string cnic, string party_affiliation, int vote);
};
