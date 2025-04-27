#include "LOCAL.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include "ELECTION.h"
#include"candidate.h"

using namespace std;

void LOCAL::add_condidate() 
{
	cout << "Enter Cnic :";
	//check 13 digit cnic
	while (true)
	{
		cin >> cnic;
		if (cnic.length() != 13)
			cout << "Enter 13 digit Cnic :";
		else {
			ifstream in(candidate_file);
			while (getline(in, line))
			{
				stringstream s(line);
				string col1,col2;

				getline(s, col1, ',');
				getline(s, col2, ',');
				if (col2 == cnic)
				{
					cout << "You are already candidate.\n";found = true;break;
				}
			}
			in.close();

			if (found)
				break;
			if (!found)
			{
				ifstream in(Nadra_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3, col4, col5;

					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					getline(s, col4, ',');
					getline(s, col5, ',');

					name = col1;
					if (col5 == cnic)
					{
						found2 = true;break;
					}
				}
				in.close();
			}

			if (!found2)
				cout << "Enter Again Correct Cnic :";
			else
				break;
		}
	}

	if (found)
		return;
	
	if (check_pakistani(cnic))
	{
		if (check_age(cnic))//check age >=18
		{
			if (check_study(cnic))//check study is matric
			{
				//province
				int a;
				while (true) {
					while (true)
					{
						cout << "Province :" << endl
							<< "1.PUNJAB" << endl
							<< "2.SINDH" << endl
							<< "3.KHYBER PAKHTUNKHWA" << endl
							<< "4.BALOCHISTAN" << endl
							<< "5.GILGIT-BALTISTAN" << endl
							<< "6.AZAD JAMMU & KASHMIR" << endl
							<< "7.FEDERAL CAPITAL TERRITORY" << endl;
						cout << "Enter Province: ";
						cin >> a;
						if (cin.fail() || a > 7 || a < 1)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\nEnter again 1 to 7 !!!" << endl;
						}
						else
							break;
					}
					if (a == 1)
					{
						province = "PUNJAB";break;
					}
					else if (a == 2)
					{
						province = "SINDH";break;
					}
					else if (a == 3)
					{
						province = "KHYBER PAKHTUNKHWA";break;
					}
					else if (a == 4)
					{
						province = "BALOCHISTAN";break;
					}
					else if (a == 5)
					{
						province = "GILGIT-BALTISTAN";break;
					}
					else if (a == 6)
					{
						province = "AZAD JAMMU & KASHMIR";break;
					}
					else
					{
						province = "FEDERAL CAPITAL TERRITORY";break;
					}
					break;
				}

				//district
				bool validDistrict = false;
				while (!validDistrict) {
					cout << "\nProvince" << province << " of Districts :" << endl;
					if (province == "PUNJAB") {
						for (int i = 0;i < 38;i++)
						{
							cout << i + 1 << "." << punjabDistricts[i] << endl;
						}
					}
					else if (province == "SINDH") {
						for (int i = 0;i < 31;i++)
						{
							cout << i + 1 << "." << sindhDistricts[i] << endl;
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0;i < 26;i++)
						{
							cout << i + 1 << "." << kpkDistricts[i] << endl;
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0;i < 36;i++)
						{
							cout << i + 1 << "." << balochistanDistricts[i] << endl;
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0;i < 4;i++)
						{
							cout << i + 1 << "." << gilgitBaltistanDistricts[i] << endl;
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0;i < 8;i++)
						{
							cout << i + 1 << "." << ajkDistricts[i] << endl;
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						cout << "1.Islamabad" << endl;
					}
					cout << "Enter District: ";
					cin >> district;

					for (int i = 0; i < district.length(); ++i) {
						if (district[i] >= 'a' && district[i] <= 'z') {
							district[i] = district[i] - 'a' + 'A';
						}
					}

					if (province == "PUNJAB") {
						for (int i = 0; i < sizeof(punjabDistricts) / sizeof(punjabDistricts[0]); ++i) {
							if (district == punjabDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "SINDH") {
						for (int i = 0; i < sizeof(sindhDistricts) / sizeof(sindhDistricts[0]); ++i) {
							if (district == sindhDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0; i < sizeof(kpkDistricts) / sizeof(kpkDistricts[0]); ++i) {
							if (district == kpkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0; i < sizeof(balochistanDistricts) / sizeof(balochistanDistricts[0]); ++i) {
							if (district == balochistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0; i < sizeof(gilgitBaltistanDistricts) / sizeof(gilgitBaltistanDistricts[0]); ++i) {
							if (district == gilgitBaltistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0; i < sizeof(ajkDistricts) / sizeof(ajkDistricts[0]); ++i) {
							if (district == ajkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						for (int i = 0; i < sizeof(islamabadDistricts) / sizeof(islamabadDistricts[0]); ++i) {
							if (district == islamabadDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}

					if (validDistrict) {
						cout << "Valid district in " << province << "!" << endl;
					}
					else {
						cout << "Invalid district for the selected province. Please try again.\n";
					}
				}

				//union council
				int index = 1;
				cout << "\t!!! City of " << district << "!!!\n";
				if (province == "PUNJAB" || province == "SINDH" || province == "KHYBER PAKHTUNKHWA" || province == "BALOCHISTAN" || province == "FEDERAL CAPITAL TERRITORY")
				{
					ifstream in("F:\\project oop\\Data Base\\pakistan union council.txt");
					while (getline(in, line)) {
						stringstream ss(line);
						string col1, col2;

						getline(ss, col1, ',');
						getline(ss, col2, ',');

						if (col1 == district) {
							cout << index << ". " << col2 << endl;
							index++;
						}
					}
					in.close();
				}
				else if (province == "GILGIT-BALTISTAN") {
					ifstream i("F:\\project oop\\Data Base\\GILGIT.txt");
					while (getline(i, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');
						if (col1 == district)
							cout << index << col2 << endl;
					}
					i.close();
				}
				else {
					ifstream i("F:\\project oop\\Data Base\\AJK.txt");
					while (getline(i, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');
						if (col1 == district)
							cout << index << col2 << endl;
					}
					i.close();
				}
				do {
					if (province == "PUNJAB" || province == "SINDH" || province == "KHYBER PAKHTUNKHWA" || province == "BALOCHISTAN" || province == "FEDERAL CAPITAL TERRITORY")
					{
						cout << endl << "Enter City Name from the above list: ";
						cin >> union_council;

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\pakistan union council.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2, col3;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					else if (province == "GILGIT-BALTISTAN")
					{
						cout << endl << "Enter City Name from the above list: ";
						getline(cin, union_council);

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\GILGIT.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					else
					{
						cout << endl << "Enter City Name from the above list: ";
						getline(cin, union_council);

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\AJK.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2, col3, col4, col5, col6;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					if (!found) {
						cout << "\nUnion Council Not Found! Please try again.\n";
					}
				} while (!found);

				//Party of affiliation
				int i = 0;
				cout << "Parties of " << province << " !!!" << endl;
				ifstream in(party_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2;
					getline(s, col1, ',');
					getline(s, col2, ',');

					if (col1 == province)
					{
						cout << i + 1 <<". " << col2 << endl;i++;
					}
				}
				in.close();
				int b;
				while (true)
				{
					while(true){
						cout << "Enter Party Affiliation :";
						cin >> b;
						if (cin.fail() || (b < 1 || b > i))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Enter between 1 and " << i << endl;
						}
						else
							break;
					}
					i = 0;
					ifstream in(party_file);
					while (getline(in, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');

						if (col1 == province)
						{
							i++;
							if (i == b)
								party_affiliation = col2;
						}
					}
					in.close();
					break;
				}

				vote = 0;
				ofstream out(candidate_file, ios::app);
				out << name<<"," << cnic << "," << province << "," << district << "," << union_council
					<< "," << party_affiliation << "," << vote << endl;
				out.close();

				cout << "\n\tCandidate added successfully!" << endl;
			}
			else
				cout << "In Local Govt. Study is minimum is matric !!!" << endl;
		}
		else
			cout << "\tYour age is less than 18.!!!" << endl;
	}
	else
		cout << "You are not Pakistani so you are not applicable .\n";
}

void LOCAL::remove_condidate()
{
	do {
		cout << "Enter Cnic for Remove Candidate :";
		do {
			getline(cin, cnic);
			if (cnic.length() != 13)
				cout << "Enter 13 digit Cnic :";
		} while (cnic.length() != 13);

		ifstream in(candidate_file);
		ofstream out("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt",ios::app);
		while (getline(in, line))
		{
			stringstream s(line);
			string col1,col2;
			getline(s, col1, ',');
			getline(s, col2, ',');
			if (col2 == cnic) { found = true; break; }
			else
				out << line << endl;
		}
		in.close();
		out.close();
		if (found)
			break;
		else
			cout << "Enter Cnic for Candidate :";
	} while (true);
	remove(candidate_file.c_str());
	rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
	cout << "\nCandidate remove successfully !!!" << endl;
}

void LOCAL::modify_candidate()
{
	time_t currentTime = time(nullptr);
#ifdef _WIN32
	tm localTime;localtime_s(&localTime, &currentTime);
#else
	tm localTime;localtime_r(&currentTime, &localTime);
#endif

	int y = localTime.tm_year + 1900;
	int m = localTime.tm_mon + 1;
	int d = localTime.tm_mday;

	bool change = false;
	if (y >= start_year && y <= end_year)
	{
		if (m >= start_month && m <= end_month)
		{
			if (d >= start_day && d <= end_day)
				change = true;
		}
	}
	if (change)
		cout << "Not Modified because Election is Start.";
	else
	{
		int z;
		cout << "Enter Cnic to Modify :";
		while (true)
		{
			getline(cin, cnic);
			if (cnic.length() != 13)
				cout << "Enter 13 digit Cnic :";
			else {
				ifstream in(candidate_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					if (col2 == cnic)
					{
						province = col3;
						found = true;
						break;
					}
				}
				in.close();
			}
			if (found)
				break;
			else
			{
				cout << "\n\tCnic not Found !!!" << endl;
				cout << "Enter Correct Cnic :";
			}
		}
		if (found)
		{
			do {
				cout << " Modify " << endl;
				cout << " 1. Party Change " << endl;
				cout << " 2. Election Area Change " << endl;
				cin >> z;
				if (cin.fail() || (z != 1 && z != 2))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nInvalid number !!!" << endl;
				}
				else
					break;
			} while (true);
			if (z == 1)
			{
				int i = 0;
				cout << "Parties of " << province << " !!!" << endl;
				ifstream in(party_file);
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2;
					getline(s, col1, ',');
					getline(s, col2, ',');

					if (col1 == province)
					{
						cout << i + 1 << col2 << endl;i++;
					}
				}
				in.close();
				int b;
				while (true)
				{
					do {
						cout << "Enter Party Affiliation :";
						cin >> b;
						if (cin.fail() || b < 1 || b > i)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Enter between 1 and " << i << endl;
						}
					} while (cin.fail() || b < 1 || b > i);
					int j = 0;
					ifstream in(party_file);
					while (getline(in, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');

						if (col1 == province)
						{
							j++;
							if (j == b)
							{
								party_affiliation = col2;break;
						    }
						}
					}
					in.close();
				}

				ifstream in1(party_file);
				ofstream out("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt");
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3, col4, col5, col6, col7;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					getline(s, col4, ',');
					getline(s, col5, ',');
					getline(s, col6, ',');
					getline(s, col7, ',');
					if (col2 == cnic)
						out << col1 << "," << col2 << "," << col3 << ","
						<< col4 << "," << col5 << "," << party_affiliation << "," << col7 << endl;
					else
						out << line << endl;
				}
				out.close();
				in1.close();
				remove(candidate_file.c_str());
				rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
			}
			else
			{
				//province
				int a;
				while (true) {
					while (true)
					{
						cout << "Province :" << endl
							<< "1.PUNJAB" << endl
							<< "2.SINDH" << endl
							<< "3.KHYBER PAKHTUNKHWA" << endl
							<< "4.BALOCHISTAN" << endl
							<< "5.GILGIT-BALTISTAN" << endl
							<< "6.AZAD JAMMU & KASHMIR" << endl
							<< "7.FEDERAL CAPITAL TERRITORY" << endl;
						cout << "Enter Province: ";
						cin >> a;
						if (cin.fail() || a > 7 || a < 1)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\nEnter again 1 to 7 !!!" << endl;
						}
						else
							break;
					}
					if (a == 1)
					{
						province = "PUNJAB";break;
					}
					else if (a == 2)
					{
						province = "SINDH";break;
					}
					else if (a == 3)
					{
						province = "KHYBER PAKHTUNKHWA";break;
					}
					else if (a == 4)
					{
						province = "BALOCHISTAN";break;
					}
					else if (a == 5)
					{
						province = "GILGIT-BALTISTAN";break;
					}
					else if (a == 6)
					{
						province = "AZAD JAMMU & KASHMIR";break;
					}
					else
					{
						province = "FEDERAL CAPITAL TERRITORY";break;
					}
					break;
				}

				//district
				bool validDistrict = false;
				while (!validDistrict) {
					cout << "\nProvince" << province << " of Districts :" << endl;
					if (province == "PUNJAB") {
						for (int i = 0;i < 38;i++)
						{
							cout << i + 1 << "." << punjabDistricts[i] << endl;
						}
					}
					else if (province == "SINDH") {
						for (int i = 0;i < 31;i++)
						{
							cout << i + 1 << "." << sindhDistricts[i] << endl;
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0;i < 26;i++)
						{
							cout << i + 1 << "." << kpkDistricts[i] << endl;
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0;i < 36;i++)
						{
							cout << i + 1 << "." << balochistanDistricts[i] << endl;
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0;i < 4;i++)
						{
							cout << i + 1 << "." << gilgitBaltistanDistricts[i] << endl;
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0;i < 8;i++)
						{
							cout << i + 1 << "." << ajkDistricts[i] << endl;
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						cout << "1.Islamabad" << endl;
					}
					cout << "Enter District: ";
					getline(cin, district);

					for (int i = 0; i < district.length(); ++i) {
						if (district[i] >= 'a' && district[i] <= 'z') {
							district[i] = district[i] - 'a' + 'A';
						}
					}

					if (province == "PUNJAB") {
						for (int i = 0; i < sizeof(punjabDistricts) / sizeof(punjabDistricts[0]); ++i) {
							if (district == punjabDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "SINDH") {
						for (int i = 0; i < sizeof(sindhDistricts) / sizeof(sindhDistricts[0]); ++i) {
							if (district == sindhDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "KHYBER PAKHTUNKHWA") {
						for (int i = 0; i < sizeof(kpkDistricts) / sizeof(kpkDistricts[0]); ++i) {
							if (district == kpkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "BALOCHISTAN") {
						for (int i = 0; i < sizeof(balochistanDistricts) / sizeof(balochistanDistricts[0]); ++i) {
							if (district == balochistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "GILGIT-BALTISTAN") {
						for (int i = 0; i < sizeof(gilgitBaltistanDistricts) / sizeof(gilgitBaltistanDistricts[0]); ++i) {
							if (district == gilgitBaltistanDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "AZAD JAMMU & KASHMIR") {
						for (int i = 0; i < sizeof(ajkDistricts) / sizeof(ajkDistricts[0]); ++i) {
							if (district == ajkDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}
					else if (province == "FEDERAL CAPITAL TERRITORY") {
						for (int i = 0; i < sizeof(islamabadDistricts) / sizeof(islamabadDistricts[0]); ++i) {
							if (district == islamabadDistricts[i]) {
								validDistrict = true;
								break;
							}
						}
					}

					if (validDistrict) {
						cout << "Valid district in " << province << "!" << endl;
					}
					else {
						cout << "Invalid district for the selected province. Please try again.\n";
					}
				}

				//union council
				int index = 1;
				cout << "\t!!! City of " << district << "!!!\n";
				if (province == "PUNJAB" || province == "SINDH" || province == "KHYBER PAKHTUNKHWA" || province == "BALOCHISTAN" || province == "FEDERAL CAPITAL TERRITORY")
				{
					ifstream in("F:\\project oop\\Data Base\\pakistan union council.txt");
					while (getline(in, line)) {
						stringstream ss(line);
						string col1, col2;

						getline(ss, col1, ',');
						getline(ss, col2, ',');

						if (col1 == district) {
							cout << index << ". " << col2 << endl;
							index++;
						}
					}
					in.close();
				}
				else if (province == "GILGIT-BALTISTAN") {
					ifstream i("F:\\project oop\\Data Base\\GILGIT.txt");
					while (getline(i, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');
						if (col1 == district)
							cout << index << col2 << endl;
					}
					i.close();
				}
				else {
					ifstream i("F:\\project oop\\Data Base\\AJK.txt");
					while (getline(i, line))
					{
						stringstream s(line);
						string col1, col2;
						getline(s, col1, ',');
						getline(s, col2, ',');
						if (col1 == district)
							cout << index << col2 << endl;
					}
					i.close();
				}
				do {
					if (province == "PUNJAB" || province == "SINDH" || province == "KHYBER PAKHTUNKHWA" || province == "BALOCHISTAN" || province == "FEDERAL CAPITAL TERRITORY")
					{
						cout << endl << "Enter City Name from the above list: ";
						getline(cin, union_council);

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\pakistan union council.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2, col3;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					else if (province == "GILGIT-BALTISTAN")
					{
						cout << endl << "Enter City Name from the above list: ";
						getline(cin, union_council);

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\GILGIT.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					else
					{
						cout << endl << "Enter City Name from the above list: ";
						getline(cin, union_council);

						for (int i = 0; i < union_council.length(); ++i) {
							if (union_council[i] >= 'a' && union_council[i] <= 'z') {
								union_council[i] = union_council[i] - 'a' + 'A';
							}
						}
						found = false;

						ifstream in("F:\\project oop\\Data Base\\AJK.txt");
						while (getline(in, line)) {
							stringstream ss(line);
							string col1, col2, col3, col4, col5, col6;

							getline(ss, col1, ',');
							getline(ss, col2, ',');

							if (col2 == union_council) {
								found = true;
								break;
							}
						}
						in.close();
					}
					if (!found) {
						cout << "\nUnion Council Not Found! Please try again.\n";
					}
				} while (!found);

				ifstream in(party_file);
				ofstream out("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt");
				while (getline(in, line))
				{
					stringstream s(line);
					string col1, col2, col3, col4, col5, col6, col7;
					getline(s, col1, ',');
					getline(s, col2, ',');
					getline(s, col3, ',');
					getline(s, col4, ',');
					getline(s, col5, ',');
					getline(s, col6, ',');
					getline(s, col7, ',');
					if (col2 == cnic)
						out << col1 << "," << col2 << "," << province << ","
						<< district << "," << union_council << "," << col6 << "," << col7 << endl;
					else
						out << line << endl;
				}
				out.close();
				in.close();
				remove(candidate_file.c_str());
				rename("F:\\project oop\\Data Base\\CANDIDATE\\temp.txt", candidate_file.c_str());
			}
		}
	}
}

bool LOCAL::check_age(string a)
{
	ifstream in(Nadra_file);
	while (getline(in, line)) {
		stringstream ss(line);
		string col1, col2, col3, col4, col5;

		getline(ss, col1, ',');
		getline(ss, col2, ',');
		getline(ss, col3, ',');
		getline(ss, col4, ',');
		getline(ss, col5, ',');

		if (col5 == a) {
			time_t currentTime = time(nullptr);
#ifdef _WIN32
			tm localTime;
			localtime_s(&localTime, &currentTime);
#else
			tm localTime;
			localtime_r(&currentTime, &localTime);
#endif
			int d = (localTime.tm_year + 1900) - stoi(col2);
			if (d >= 18)
			{
				found = true;
			}
			break;
		}
	}
	in.close();
	return found;
}

bool LOCAL::check_study(string a)
{
	ifstream in(Nadra_file);

	while (getline(in,line))
	{
		stringstream s(line);
		string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, col13, col14, col15, col16;
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
		getline(s, col14, ',');
		getline(s, col15, ',');
		getline(s, col16, ',');
		if (col5 == a)
		{
			int d = stoi(col16);
			if (d >= 10)
			{
				found = true;
				break;
			}
		}
	}
	in.close();
	return found;
}