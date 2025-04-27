#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<string>
#include<ctime>
#include <sstream>
#include "NADRA.h"
using namespace std;

bool NADRA::isCnicUnique(const string& cnic) {
    ifstream in(file);
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        string col1, col2, col3, col4, col5;

        getline(ss, col1, ',');
        getline(ss, col2, ',');
        getline(ss, col3, ',');
        getline(ss, col4, ',');
        getline(ss, col5, ',');

        if (col5 == cnic) {
            return false;
        }
    }
    in.close();
    return true; 
}

void NADRA::input() {
    cout << "Enter How Many Records to Input: ";
    cin >> inp;
    cin.ignore();

    bool f = false;
    ofstream out(file, ios::app);

    for (int i = 0; i < inp; i++)
    {
        cout << "\nEnter person " << i + 1 << " :\n";

        //name
        cout << "Enter Name: ";
        getline(cin, name);

        time_t currentTime = time(nullptr);

#ifdef _WIN32
        tm localTime;
        localtime_s(&localTime, &currentTime);
#else
        tm localTime;
        localtime_r(&currentTime, &localTime);
#endif

        // Birth Year
        int year;
        while (true) {
            cout << "Enter Year of Birth: ";
            cin >> year;
            if (cin.fail() || year < 1900 || year >(localTime.tm_year + 1900)) {
                cout << "Invalid input! Birth year must be between 1900 and the current year.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        cin.ignore(); 

        // Birth Month
        int month;
        while (true) {
            cout << "Enter Month of Birth (1-12): ";
            cin >> month;
            if (cin.fail() || month < 1 || month > 12) {
                cout << "Invalid input! Month must be between 1 and 12.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (year == localTime.tm_year + 1900 && month > localTime.tm_mon + 1) {
                cout << "Birth month cannot be greater than the current month for this year.\n";
            }
            else {
                break;
            }
        }
        cin.ignore();  

        // Birth Day
        int day;
        while (true) {
            cout << "Enter Day of Birth (1-31): ";
            cin >> day;
            if (cin.fail() || day < 1 || day > 31) {
                cout << "Invalid input! Day must be between 1 and 31.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if ((month == 2 && day > 29) || (month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
                cout << "Invalid day for the given month!\n";
            }
            else if (year == localTime.tm_year + 1900 && month == localTime.tm_mon + 1 && day > localTime.tm_mday) {
                cout << "Birth day cannot be greater than the current day for this year.\n";
            }
            else {
                break;
            }
        }
        cin.ignore();

        // CNIC 
        do {
            cout << "Enter CNIC (13 digits): ";
            getline(cin, cnic);
            if (cnic.length() == 13) {
                if (!isCnicUnique(cnic)) {
                    cout << "This CNIC is already registered. Please enter a unique CNIC.\n";
                }
                else {
                    break;
                }
            }
            else {
                cout << "Invalid CNIC! Enter exactly 13 digits." << endl;
            }
        } while (true);
        cin.ignore();

        // Number 
        do {
            cout << "Enter Number: ";
            if (!(cin >> number)) {
                cout << "Invalid number! Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);
        cin.ignore();

        // Province 
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
                if (cin.fail()||a>7 ||a<1)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nEnter again 1 to 7 !!!" << endl;
                }
                else
                    break;
            }
            if (a == 1)
            {province = "PUNJAB";break;}
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

        //dsitrict
        bool validDistrict = false;
        while (!validDistrict) {
            cout << "\nProvince" << province <<" of Districts :" << endl;
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
        bool found = false;
        string line;
        int index = 1;
        cout << "\t!!! City of " << district << "!!!\n";
        if (province == "PUNJAB" || province == "SINDH" || province == "KHYBER PAKHTUNKHWA" ||province == "BALOCHISTAN" || province == "FEDERAL CAPITAL TERRITORY")
        {
            ifstream in("F:\\project oop\\Data Base\\pakistan union council.txt");
            while (getline(in, line)) {
                stringstream ss(line);
                string col1, col2;

                getline(ss, col1, ',');
                getline(ss, col2, ',');

                if (col1 == district) {
                    cout << index << ". "<< col2 << endl;
                    index++;
                }
            }
            in.close();
        }
        else if(province == "GILGIT-BALTISTAN") {
            ifstream i("F:\\project oop\\Data Base\\GILGIT.txt");
            while (getline(i, line))
            {
                stringstream s(line);
                string col1, col2;
                getline(s, col1, ',');
                getline(s, col2, ',');
                if (col1 == district)
                    cout << index<<col2 << endl;
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
                    getline(ss, division, ',');
                    getline(ss, col3, ',');
                    getline(ss, NA_NUMBER, ',');
                    getline(ss, PA_NUMBER, ',');

                    if (col2 == union_council) {
                        found = true;
                        break;
                    }
                }
                in.close();
            }
            else if (province == "GILGIT-BALTISTAN")
            {
                cout <<endl<< "Enter City Name from the above list: ";
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
                    string col1, col2, col3;

                    getline(ss, col1, ',');
                    getline(ss, col2, ',');
                    getline(ss, division, ',');
                    getline(ss, col3, ',');
                    getline(ss, NA_NUMBER, ',');
                    getline(ss, PA_NUMBER, ',');

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
                    string col1, col2, col3;

                    getline(ss, col1, ',');
                    getline(ss, col2, ',');
                    getline(ss, division, ',');
                    getline(ss, col3, ',');
                    getline(ss, NA_NUMBER, ',');
                    getline(ss, PA_NUMBER, ',');

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

        //pakistani
        do {
            cout << "Enter Pakistani (1 for Yes, 0 for No): ";
            cin >> pakistani;
            if (cin.fail()) {
                cout << "Invalid input! Please enter 1 or 0." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);
        cin.ignore();

        // Dual Nationality
        do {
            cout << "Do you have Dual Nationality (1 for Yes, 0 for No): ";
            cin >> dual_nationality;
            if (cin.fail()) {
                cout << "Invalid input! Please enter 1 or 0." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);
        cin.ignore();

        // Religion 
        do {
            cout << "Enter Religion (1 for Muslim, 0 for Non-Muslim): ";
            cin >> religion;
            if (cin.fail()) {
                cout << "Invalid input! Please enter 1 or 0." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);
        cin.ignore();

        // Study 
        do {
            cout << "Enter Study Level (0 to 18): ";
            cin >> study;
            if (cin.fail() || study < 0 || study > 18) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid study level! Please enter a number between 1 and 18." << endl;
            }
            else {
                break;
            }
        } while (true);
        cin.ignore();

        //gender
        do {
            cout << "Enter Gender (M for Male, F for Female): ";
            cin >> gender;
            if (gender != 'M' && gender != 'F') {
                cout << "Invalid input! Please enter M or F." << endl;
            }
            else {
                break;
            }
        } while (true);
        cin.ignore();

        // Address 
        cout << "Enter Address: ";
        getline(cin, address);

        out << name << "," << year << "," << month << "," << day<< "," << cnic << "," << number << ","
            << province << "," << district << "," <<division<<","<<NA_NUMBER<<","<<PA_NUMBER<<","
            << union_council << ","<< pakistani << "," << dual_nationality << "," << religion << ","
            << study << "," << gender << "," << address << endl;
    }
    out.close();
}

void NADRA::update() {
    string ser, line;
    cout << "Enter record CNIC to update: ";
    getline(cin, ser);


    ofstream temp("temp.txt", ios::out);
    ifstream in(file);
    bool found = false;

    while (getline(in, line)) {
        stringstream ss(line);
        string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11,
            col12, col13, col14, col15,col16,col17,col18;

        getline(ss, col1, ','); // Name
        getline(ss, col2, ','); // Year
        getline(ss, col3, ','); // Month
        getline(ss, col4, ','); // Day
        getline(ss, col5, ','); // CNIC
        getline(ss, col6, ','); // Number
        getline(ss, col7, ','); // Province
        getline(ss, col16, ','); // Division
        getline(ss, col8, ','); // District
        getline(ss, col17, ','); // NA#
        getline(ss, col18, ','); // PA#
        getline(ss, col9, ','); // Union Council
        getline(ss, col10, ','); // Pakistani Citizenship
        getline(ss, col11, ','); // Dual Nationality
        getline(ss, col12, ','); // Religion
        getline(ss, col13, ','); // Study
        getline(ss, col14, ','); // Gender
        getline(ss, col15, ','); // Address

        if (col5 == ser) {
            found = true;
            int con;

            cout << "\n1. Change name\n";
            cout << "2. Change year\n";
            cout << "3. Change month\n";
            cout << "4. Change day\n";
            cout << "5. Change number\n";
            cout << "6. Change province\n";
            cout << "7. Change district\n";
            cout << "8. Change union council\n";
            cout << "9. Change Pakistani citizen\n";
            cout << "10. Change dual nationality\n";
            cout << "11. Change religion\n";
            cout << "12. Change study\n";
            cout << "13. Change gender\n";
            cout << "14. Change address\n";
            cout << "15. Change all\n";
            cout << "Enter your choice: ";
            cin >> con;
            cin.ignore(); 

            switch (con) {
            case 1:
                cout << "Enter new Name: ";
                getline(cin, col1);
                break;
            case 2:
                cout << "Enter new Year: ";
                while (true) {
                    cin >> col2;
                    int currentYear = 2025; 
                    if (cin.fail() || stoi(col2) > currentYear) {
                        cout << "Invalid year. Please enter a valid year: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else {
                        break;
                    }
                }
                cin.ignore();
                break;
            case 3:
                cout << "Enter new Month: ";
                cin >> col3;
                break;
            case 4:
                cout << "Enter new Day: ";
                cin >> col4;
                break;
            case 5:
                cout << "Enter new Number: ";
                cin >> col6;
                break;
            case 6:
                cout << "Enter new Province: ";
                getline(cin, col7);
                break;
            case 7:
                cout << "Enter new District: ";
                getline(cin, col8);
                break;
            case 8:
                cout << "Enter new Union Council: ";
                getline(cin, col9);
                break;
            case 9:
                cout << "Enter new Pakistani Citizenship (1 for Yes, 0 for No): ";
                cin >> col10;
                break;
            case 10:
                cout << "Enter new Dual Nationality (1 for Yes, 0 for No): ";
                cin >> col11;
                break;
            case 11:
                cout << "Enter new Religion (1 for Muslim, 0 for Non-Muslim): ";
                cin >> col12;
                break;
            case 12:
                cout << "Enter new Study Level (0 = No Education, 1 = Primary, 2 = Secondary, 3 = Higher Education): ";
                cin >> col13;
                break;
            case 13:
                cout << "Enter new Gender (M for Male, F for Female): ";
                cin >> col14;
                break;
            case 14:
                cout << "Enter new Address: ";
                cin.ignore();
                getline(cin, col15);
                break;
            case 15:
                cout << "Enter new Name: ";
                getline(cin, col1);
                cout << "Enter new Year: ";
                cin >> col2;
                cout << "Enter new Month: ";
                cin >> col3;
                cout << "Enter new Day: ";
                cin >> col4;
                cout << "Enter new Number: ";
                cin >> col6;
                cout << "Enter new Province: ";
                cin.ignore();
                getline(cin, col7);
                cout << "Enter new District: ";
                getline(cin, col8);
                cout << "Enter new Union Council: ";
                getline(cin, col9);
                cout << "Enter new Pakistani Citizenship (1 for Yes, 0 for No): ";
                cin >> col10;
                cout << "Enter new Dual Nationality (1 for Yes, 0 for No): ";
                cin >> col11;
                cout << "Enter new Religion (1 for Muslim, 0 for Non-Muslim): ";
                cin >> col12;
                cout << "Enter new Study Level (0 = No Education, 1 = Primary, 2 = Secondary, 3 = Higher Education): ";
                cin >> col13;
                cout << "Enter new Gender (M for Male, F for Female): ";
                cin >> col14;
                cout << "Enter new Address: ";
                getline(cin, address);
                break;
            default:
                cout << "Invalid option!\n";
                break;
            }

            temp << col1 << "," << col2 << "," << col3 << "," << col4
                << "," << col5 << "," << col6 << "," << col7 <<","<<col16 << "," << col8 << ","
                << col17 << "," << col18 <<"," << col9 << "," << col10 << "," << col11 << "," << col12 << ","
                << col13 << "," << col14 << "," << address << endl;
        }
        else {
            temp << line << endl;
        }
    }

    in.close();
    temp.close();
    remove(file.c_str());
    rename("temp.txt", file.c_str());
    if (!found) {
        cout << "Record not found!" << endl;
    }
    else {
        cout << "Record updated successfully!" << endl;
    }
}

void NADRA::del() {
    string ser, line;
    cout << "Enter record CNIC to delete: ";
    getline(cin, ser);

    ofstream temp("temp.txt", ios::app);
    ifstream in(file);
    bool found = false;

    while (getline(in, line)) {
        stringstream ss(line);
        string col1, col2, col3, col4, col5;

        getline(ss, col1, ',');
        getline(ss, col2, ',');
        getline(ss, col3, ',');
        getline(ss, col4, ',');
        getline(ss, col5, ',');

        if (col5 == ser) {
            found = true;
            cout << "RECORD DELETED !!!" << endl;
        }
        else {
            temp << line << endl;
        }
    }

    in.close();
    temp.close();

    remove(file.c_str());
    rename("temp.txt", file.c_str());

    if (!found) {
        cout << "Record not found!" << endl;
    }
}

void NADRA::search() {
    string ser, line;
    cout << "Enter CNIC to search: ";
    getline(cin, ser);

    ifstream in(file);
    bool found = false;

    while (getline(in, line)) {
        stringstream ss(line);
        string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11,
            col12, col13, col14, col15,col16,col17,col18;

        getline(ss, col1, ','); // Name
        getline(ss, col2, ','); // Year
        getline(ss, col3, ','); // Month
        getline(ss, col4, ','); // Day
        getline(ss, col5, ','); // CNIC
        getline(ss, col6, ','); // Number
        getline(ss, col7, ','); // Province
        getline(ss, col16, ','); // Division
        getline(ss, col8, ','); // District
        getline(ss, col17, ','); // NA #
        getline(ss, col18, ','); // PA #
        getline(ss, col9, ','); // Union Council
        getline(ss, col10, ','); // Pakistani Citizenship
        getline(ss, col11, ','); // Dual Nationality
        getline(ss, col12, ','); // Religion
        getline(ss, col13, ','); // Study
        getline(ss, col14, ','); // Gender
        getline(ss, col15, ','); // Address

        if (col5 == ser) {
            found = true;
            cout << endl
                << "\tName :" << col1 << endl
                << "\tYear of Birth :" << col2 << endl
                << "\tMonth :" << col3 << endl
                << "\tDay :" << col4 << endl
                << "\tCNIC :" << col5 << endl
                << "\tNumber :" << col6 << endl
                << "\tProvince :" << col7 << endl
                << "\tDivision :"<<col16<<endl
                << "\tDistrict :" << col8 << endl
                << "\tNA# :"<<col17 << endl
                << "\tPA# :" << col18 << endl
                << "\tUnion Council :" << col9 << endl
                << "\tPakistani :" << col10 << endl
                << "\tDual Nationality :" << col11 << endl
                << "\tReligion :" << col12 << endl
                << "\tStudy :" << col13 << endl
                << "\tGender :" << col14 << endl
                << "\tAddress :" << col15 << endl;
            break; 
        }
    }

    in.close(); 

    if (!found) {
        cout << "Record not found!" << endl;
    }
}