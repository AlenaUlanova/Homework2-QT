#include "parsetext.h"

ParseText::ParseText(QString text)
{
    value = text;
}

const QString ParseText::GetValue() { return value; }

void ParseText::Parse(){
    while(1){
        qint32 find = value.indexOf("#", 0);
        qint32 r = value.indexOf("@", find);
        if(r == -1 || find == -1) return;
        QString raw = value.mid(find + 1, r-find-1);
        if(raw == "RUB"){
            raw = "₽";
        }
        else if(raw == "EUR")
        {
            raw = "€";
        }
        else if(raw == "PROM"){
            raw = "‰";
        }
        else if(raw == "COP"){
            raw = "©";
        }
        else{
            raw = "";
        }
        value = value.remove(find, r-find+1);
        value.insert(find, raw);
    }
}
