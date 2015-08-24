#include "lbmc_utils.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>


template<typename T>
T convert_str (std::string &val)
{
    std::istringstream iss (val);
    T rez;
    iss >> rez;
    return rez;
}


LBMConfig::LBMConfig ()
{
    update_battery_info ();

    conf_refresh_sec = 30;
}

LBMConfig::~LBMConfig ()
{
    
}


bat_state LBMConfig::get_battery_state( ) 
{
    return battery_state;
}


float LBMConfig::get_battery_rate()
{
    return battery_rate;
}


long LBMConfig::get_conf_refresh_sec()
{
    return conf_refresh_sec;
}


void LBMConfig::update_battery_info ()
{
    std::ifstream f_charge_full, f_charge_now;

    f_charge_full.open("/sys/class/power_supply/BAT0/charge_full", std::ios::in);
    f_charge_now.open("/sys/class/power_supply/BAT0/charge_now", std::ios::in);

    if ( !f_charge_full.is_open() || !f_charge_now.is_open() )
    {
	std::cerr << "Erreur ouverture fichier" << std::endl;
	battery_rate = -100.0;
	
    }
    
    std::string bat_full_c;
    std::string bat_now_c;
    
    getline(f_charge_full, bat_full_c);
    getline(f_charge_now, bat_now_c);
    
    f_charge_full.close();
    f_charge_now.close();

    float bat_full (convert_str <float> (bat_full_c) );
    float bat_now  (convert_str <float> (bat_now_c) );

    battery_rate = bat_now / bat_full * 100.0;



    std::ifstream f_state;

    f_state.open("/sys/class/power_supply/BAT0/status", std::ios::in);
    
    if ( !f_state.is_open() )
    {
	std::cerr << "Erreur ouverture fichier" << std::endl;
	battery_state = UNKNOW;
    }

    std::string bat_status;

    getline(f_state, bat_status);
    
    switch (bat_status[0])
    {
    case 'F':
	battery_state = FULL;
	break;
	
    case 'D':
	battery_state = DISCHARGING;
	break;
	
    case 'C':
	battery_state = CHARGING;
	break;
	
    case 'U':
    default:
	battery_state = UNKNOW;
	break;
	
    }
    
}



QString utils::getIconPathByBattery (LBMConfig *config)
{
    QString rez ("/usr/share/icons/libamon/");

    //std::cout << config->get_battery_rate() << std::endl << config->get_battery_state() << std::endl;
    
    if (config->get_battery_rate() < 0)
	return rez.append("none.svg");
    
    if (config->get_battery_state() == CHARGING || config->get_battery_state() == FULL)
	rez.append("ac_");

    int bat ( (int) config->get_battery_rate() );

    bat /= 10;
    bat *= 10;
    
    
    rez.append(QString::number (bat) );
    
    
    rez.append(".svg");
    
    
    return rez;
    
}
