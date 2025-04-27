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
    bool pakistani;
    string district, province, union_council;

    string punjabDistricts[38] = { "ATTOCK", "RAWALPINDI", "CHAKWAL", "JEHLUM", "GUJRAT", "SIALKOT", "NAROWAL"
    , "WAZIRABAD", "GUJRANWALA", "MANDI_BAHAUDIN", "HAFIZABAD", "SARGODHA", "KHUSHAB", "BHAKKAR"
    , "FAISALABAD", "TOBA_TEK_SINGH", "JHANG", "LAHORE", "SHEIKHUPURA", "KASUR", "OKARA", "PAKPATTAN"
    , "SAHIWAL", "CHICHAWATNI", "MULTAN", "KHANEWAL", "LODHRAN", "VEHARI", "DUNYAPUR", "MIAN_CHANNU"
    , "BAHAWALNAGAR", "BAHAWALPUR", "RAHIM_YAR_KHAN", "MUZAFFARGARH", "LAYYAH", "D.G.KHAN", "D.G._KHAN"
    , "RAJANPUR" };
    string sindhDistricts[31] = {
        "JACOBABAD", "KASHMORE", "LARKANA", "QAMBAR_SHAHDADKOT", "SHIKARPUR",
        "GHOTKI", "SUKKUR", "KHAIRPUR", "SHAHEED_BENAZIRABAD", "NAUSHAHRO_FEROZE",
        "SANGHAR", "MIRPURKHAS", "UMERKOT", "THARPARKAR", "HYDERABAD",
        "TANDO_ALLAHYAR", "MATIARI", "TANDO_MUHAMMAD_KHAN", "THATTA", "SUJAWAL",
        "BADIN", "DADU", "JAMSHORO", "KARACHI_MALIR", "KARACHI_KORANGI",
        "KARACHI_SOUTH", "KARACHI_EAST", "KARACHI_CENTRAL", "KARACHI_WEST",
        "KARACHI_KEAMARI", "KARACHI_BIN_QASIM"
    };
    string kpkDistricts[26] = {
        "UPPER CHITRAL", "UPPER DIR", "CHITRAL UPPER", "CHITRAL LOWER",
        "SWAT", "LOWER DIR", "ABBOTTABAD", "MANSEHRA",
        "HARIPUR", "SWABI", "MARDAN", "CHARSADDA",
        "PESHAWAR", "NOWSHERA", "KOHAT", "HANGU",
        "MALAKAND", "MOHMAND", "BANNU", "LAKKI MARWAT",
        "KURRAM", "ORAKZAI", "NORTH WAZIRISTAN", "SOUTH WAZIRISTAN",
        "DERA ISMAIL KHAN", "TANK"
    };
    string balochistanDistricts[36] = {
        "SHERANI", "ZHOB", "KILLA SAIFULLAH", "MUSAKHEL", "BARKHAN",
        "LORALAI", "DUKKI", "ZIARAT", "HARNAI", "SIBI",
        "KOHLU", "DERA BUGTI", "JHAL MAGSI", "KACHHI", "NASIRABAD",
        "SOHBATPUR", "JAFFARABAD", "USTA MUHAMMAD", "KHUZDAR", "HUB",
        "LASBELA", "AWARAN", "GWAADAR", "KECH", "PANJGUR",
        "WASHUK", "CHAGAI", "KHARAN", "NUSHKI", "SURAB",
        "KALAT", "MASTUNG", "QUETTA", "PISHIN", "KILLA ABDULLAH", "CHAMAN"
    };
    string gilgitBaltistanDistricts[4] = {"GILGIT","Skardu","Hunza","Diamer"};
    string ajkDistricts[8] = {
        "MUZAFFARABAD","NEELUM","BAGH","POONCH","SUDHNATI",
        "KOTLI","MIRPUR","BHIMBER"
    };
    string islamabadDistricts[1] = {"ISLAMABAD"};

string file = "F:\\project oop\\Data Base\\nadra_database.txt";
bool isCnicUnique(const string& cnic);
public:
    void input();
    void update();
    void del();
    void search();
};