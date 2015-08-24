#ifndef LBMW_TRAY_HPP
#define LBMW_TRAY_HPP

#include <QSystemTrayIcon>


class QMenu;
class LBMConfig;



class W_Tray
    : public QSystemTrayIcon
{
    Q_OBJECT

public:
    
    W_Tray (QWidget *parent);
    W_Tray (QWidget *parent, LBMConfig *config);
    
    ~W_Tray ();

private:
    QMenu *tray_menu;

    LBMConfig *config;

private slots:
    void update_icon ();
    
};

#endif /* LBMW_TRAY_HPP */
