#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream f_charge_full, f_charge_now;
    f_charge_full.open("/sys/class/power_supply/BAT0/charge_full", ios::in);
    f_charge_now.open("/sys/class/power_supply/BAT0/charge_now", ios::in);
    if ( !f_charge_full.is_open() || !f_charge_now.is_open() )
    {
    	cout << "Erreur ouvertur fichier" << endl;
    	return 1;
    
    }
    string bat_full_c;
    string bat_now_c;
    
    
    getline(f_charge_full, bat_full_c);
    getline(f_charge_now, bat_now_c);
    
    cout << strtod (bat_now_c, NULL)/strtod (bat_full_c, NULL);
    
    f_charge_full.close();
    f_charge_now.close();

    return 0;
}
