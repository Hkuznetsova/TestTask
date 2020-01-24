#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <Windows.h>
#include <iostream>
#include <QQmlContext>
#include <QtCore/QDebug>

enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};

class ConsoleOutput
{
public:
    ConsoleOutput(QList<QPair<QString, QString>> JSONInfo);
private:
    void SetColor(int text, int background);
    void SetColor(int text, ConsoleColor/*int*/ background);
};

#endif // CONSOLEOUTPUT_H
