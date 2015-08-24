#ifndef LBMC_UTILS_HPP
#define LBMC_UTILS_HPP

#include <QString>



enum bat_state {CHARGING, DISCHARGING, UNKNOW, FULL};



class LBMConfig
{
public:
    LBMConfig ();
    ~LBMConfig ();

    float get_battery_rate ();
    bat_state get_battery_state ();

    long get_conf_refresh_sec();
    
    void  update_battery_info ();
    
    
private:
    float battery_rate;
    bat_state battery_state;
    
    
    float battery_low;
    float battery_critical;

    long conf_refresh_sec;
    
};



class utils
{
public:
    static QString getIconPathByBattery(LBMConfig *config);

};



#endif /* LBMC_UTILS_HPP */
