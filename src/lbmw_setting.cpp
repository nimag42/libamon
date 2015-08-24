#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "lbmw_setting.hpp"
#include "lbmw_tray.hpp"



W_Setting::W_Setting( QWidget *parent ) : QWidget (parent)
{

    QVBoxLayout *lyt_main = new QVBoxLayout();

    QLabel *text = new QLabel("Hello !", this);

    lyt_main->addWidget(text);
    
    setLayout(lyt_main);
}

W_Setting::~W_Setting ()
{
    
}
