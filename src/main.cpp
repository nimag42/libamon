#include "lbmw_setting.hpp"
#include "lbmw_tray.hpp"
#include "lbmc_utils.hpp"

#include <QApplication>
#include <QTextCodec>



int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    
    W_Tray t (NULL);
    t.show();
    
    return app.exec();
}

