#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<string>
using namespace std;

class login
{
private:
    string username, password;
    bool vote;
    void signup();
    string file1 = "F:\\project oop\\Data Base\\nadra_database.txt";
    string file2 = "F:\\project oop\\Data Base\\login.txt";
public:
    void log();
};