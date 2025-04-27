#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include "ELECTION.h"
#include"candidate.h"

using namespace std;

class NATIONAL :public ELECTION, public candidate
{
public:
    NATIONAL()
    {
        candidate_file = "F:\\project oop\\Data Base\\CANDIDATE\\national candidate database.txt";
        party_file = "F:\\project oop\\Data Base\\PARTY\\NATIONAL PARTIES.txt";
    }
protected:

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
    string gilgitBaltistanDistricts[4] = { "GILGIT","Skardu","Hunza","Diamer" };
    string ajkDistricts[8] = {
        "MUZAFFARABAD","NEELUM","BAGH","POONCH","SUDHNATI",
        "KOTLI","MIRPUR","BHIMBER"
    };
    string islamabadDistricts[1] = { "ISLAMABAD" };
public:
    void add_condidate() override;
    void remove_condidate() override;
    void modify_candidate() override;
    bool check_age(string a)override;
    bool check_dual_nationality(string a);
};

