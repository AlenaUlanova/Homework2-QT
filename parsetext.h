#ifndef PARSETEXT_H
#define PARSETEXT_H
#include <QString>

class ParseText
{
    QString value;
public:
    const QString GetValue();
    void Parse();
    ParseText(QString text);
};

#endif // PARSETEXT_H
