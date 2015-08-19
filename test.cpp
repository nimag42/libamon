#include <fstream>
#include <iostream>
#include <string>
#include <QApplication>
#include <QPushButton>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QTextCodec>
//#include <libnotify/notify.h>

using namespace std;

int main(int argc, char **argv)
{   

    ifstream f_charge_full, f_charge_now;
    f_charge_full.open("/sys/class/power_supply/BAT0/charge_full", ios::in);
    f_charge_now.open("/sys/class/power_supply/BAT0/charge_now", ios::in);
    if ( !f_charge_full.is_open() || !f_charge_now.is_open() )
    {
    	cout << "Erreur ouverture fichier" << endl;
    	return 1;
    
    }
    string bat_full_c;

    getline(f_charge_full, bat_full_c);
    cout << bat_full_c;
    f_charge_full.close();
    f_charge_now.close();

    float batt_low = 18;
    float batt_critic = 10.5;

    QApplication app (argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

    QPushButton button("Hello !");
    
    QSystemTrayIcon trayicon(QIcon("icons/ac_100.svg"),&button);
    trayicon.show();

    QString mess ("Charge ");
    
    trayicon.showMessage("Batterie Faible !", mess,QSystemTrayIcon::Critical,5000);
    return app.exec();
}







