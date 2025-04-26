#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<string>
using namespace std;

class NADRA {
private:
    string name, cnic, address,NA_NUMBER,PA_NUMBER,division;
    int number, year, month, day, inp;
    bool dual_nationality, religion;
    int study;
    char gender;
    //work
    bool pakistani;
    string district, province, union_council;

    //district size 
    int psize =36, ssize = 30,
        ksize=26, bsize=33,
        gsize=10, asize=10, isize=1;
    int work_size;

    string punjabDistricts[36] = {
        "ATTOCK", "BAHAWALNAGAR", "BAHAWALPUR", "BHAKKAR", "CHAKWAL", "CHINIOT",
        "DERA GHAZI KHAN", "FAISALABAD", "GUJRANWALA", "GUJRAT", "HAFIZABAD",
        "JHANG", "JHELUM", "KASUR", "KHANEWAL", "KHUSHAB", "LAHORE", "LAYYAH",
        "LODHRAN", "MANDI BAHAUDDIN", "MIANWALI", "MULTAN", "MUZAFFARGARH",
        "NAROWAL", "NANKANA SAHIB", "OKARA", "PAKPATTAN", "RAHIM YAR KHAN",
        "RAJANPUR", "RAWALPINDI", "SAHIWAL", "SARGODHA", "SHEIKHUPURA",
        "SIALKOT", "TOBA TEK SINGH", "VEHARI"
    };

    string sindhDistricts[29] = {
        "BADIN", "DADU", "GHOTKI", "HYDERABAD", "JACOBABAD", "JAMSHORO",
        "KARACHI CENTRAL", "KARACHI EAST", "KARACHI SOUTH", "KARACHI WEST",
        "KORANGI", "KEMARI", "KASHMORE", "KHAIRPUR", "LARKANA", "MATIARI",
        "MIRPURKHAS", "NAUSHAHRO FEROZE", "QAMBAR SHAHDADKOT", "SANGHAR",
        "SHAHEED BENAZIRABAD", "SHIKARPUR", "SUKKUR", "SUJAWAL",
        "TANDO ALLAHYAR", "TANDO MUHAMMAD KHAN", "THARPARKAR", "THATTA",
        "UMERKOT"
    };

    string kpkDistricts[35] = {
        "ABBOTTABAD", "BANNU", "BATTAGRAM", "BUNER", "CHARSADDA", "DERA ISMAIL KHAN",
        "HANGU", "HARIPUR", "KARAK", "KOHAT", "KOHISTAN", "LAKKI MARWAT", "LOWER DIR",
        "MALAKAND", "MANSEHRA", "MARDAN", "NOWSHERA", "PESHAWAR", "SHANGLA", "SWABI",
        "SWAT", "TANK", "TORGHAR", "UPPER DIR", "KURRAM", "NORTH WAZIRISTAN",
        "SOUTH WAZIRISTAN", "ORAKZAI"
    };

    string balochistanDistricts[30] = {
        "AWARAN", "BARKHAN", "CHAGAI", "DERA BUGTI", "GWADAR", "HARNAI",
        "JAFARABAD", "JHAL MAGSI", "KALAT", "KECH", "KHARAN", "KHUZDAR",
        "KILLA ABDULLAH", "KILLA SAIFULLAH", "KOHLU", "LASBELA", "LORALAI",
        "MASTUNG", "MUSAKHEL", "NASEERABAD", "NUSHKI", "PANJGUR", "PISHIN",
        "QUETTA", "SHERANI", "SIBI", "SOHBATPUR", "WASHUK", "ZHOB", "ZIARAT"
    };

    string gilgitBaltistanDistricts[10] = {
        "ASTORE", "DIAMER", "GHANCHE", "GHIZER", "GILGIT", "HUNZA", "KHARMANG",
        "NAGAR", "SHIGAR", "SKARDU"
    };

    string ajkDistricts[10] = {
        "BAGH", "BHIMBER", "HATTIAN BALA", "HAVELI", "KOTLI", "MIRPUR", "MUZAFFARABAD",
        "NEELUM", "POONCH", "SUDHNOTI"
    };

    string islamabadDistricts[1] = {
        "ISLAMABAD"
    };

string file = "F:\\project oop\\Data Base\\nadra_database.txt";
bool isCnicUnique(const string& cnic);


public:

    void input();
    void update();
    void del();
    void search();
    bool compare(string);
};