#include "ConsoleOutput.h"

ConsoleOutput::ConsoleOutput(QList<QPair<QString, QString>> jsonInfo)
{
    std::cout << " Name " << "Latitude " << std::endl;
    for (QList<QPair<QString, QString>>::iterator i = jsonInfo.begin(); i != jsonInfo.end(); ++i){
        std::cout << (*i).first.toUtf8().constData() << "  ";
        if ((*i).second == "Red") {
            SetColor(15, Red);
            std::cout << "  ";
            SetColor(15, Black);
        } else {
            SetColor(15, Green);
            std::cout << "  ";
            SetColor(15, Black);
        }
        std::cout << "   " << std::endl  << std::endl;
    }
}

void ConsoleOutput::SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void ConsoleOutput::SetColor(int text, ConsoleColor/*int*/ background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

