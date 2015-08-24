#include "lbmw_tray.hpp"
#include "lbmc_utils.hpp"

#include <QMenu>
#include <QAction>
#include <QTimer>



W_Tray::W_Tray (QWidget *parent)
    : QSystemTrayIcon (parent)
{

    // Initializing the config
    config = new LBMConfig ();


    // Def the icon of the systray
    setIcon (QIcon (utils::getIconPathByBattery (config) ) );
    connect (this, SIGNAL (activated (QSystemTrayIcon::ActivationReason) ), this, SLOT (update_icon () ) );

    
    // Setting up the timer for update icon
    QTimer *timer = new QTimer (this);
    connect (timer, SIGNAL (timeout () ), this, SLOT (update_icon () ) );
    timer->start (1000*config->get_conf_refresh_sec ());
    

    // Setting up the menu
    tray_menu = new QMenu ( NULL );
    QAction *ac;

    switch (config->get_battery_state () )
    {
    case FULL:
	ac = new QAction ("Complet", NULL);
	
	break;	
    case CHARGING:
	ac = new QAction ("Charge", NULL);
	break;	
    case DISCHARGING:
	ac = new QAction ("Décharge", NULL);
	break;	
    case UNKNOW:
    default:
	ac = new QAction ("???", NULL);
	break;	
    }

    tray_menu->addAction (ac);

    setContextMenu (tray_menu);

}


W_Tray::~W_Tray ()
{
    delete config;    
}


void W_Tray::update_icon ()
{        
    config->update_battery_info();
    setIcon (QIcon (utils::getIconPathByBattery (config) ) );
    
}
