// prog4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Buyer.h"
using namespace std;
void readFile(Buyer**&, int&);
void writeFile(Buyer**&, int);
void initializationArray(Buyer**&, int);
void addItem(Buyer**&, Buyer, int&);
void deleteItem(Buyer**&, int, int&);
void writeInConsole(Buyer**&, int);
int findElement(Buyer**&, int, string, int);

string path = "./data/data.txt";

int main()
{
    setlocale(LC_ALL, "Russian");
    // инициализация 
    int count = 2;

    Buyer** buyers;
    
    initializationArray(buyers, count);

    // основная часть 
    writeFile(buyers, count);
    Buyer newB("Лягушин", 2003, 89511656319, "улица", 1);

    addItem(buyers, newB, count);
    int item = findElement(buyers, buyers[0]->LastNameEnum, "Лягушин", count);
    if (item != -1) {
        cout << buyers[item]->LastName;
    }
    writeInConsole(buyers, count);



    // удаление 
    for (int i = 0; i < count; i++)
    {
        delete buyers[i];
    }
    delete buyers;


}

void readFile(Buyer**& b, int& count) {
    ifstream in(path);
    count = 0;
    in >> count;
    initializationArray(b, count);
    int i = 0;
    for (int i = 0; i < count; i++)
    {
        in  >> b[i]->LastName
            >> b[i]->YearOfBirth
            >> b[i]->TelephoneNumber
            >> b[i]->Address
            >> b[i]->AccountNumber;
    }

}

void writeFile(Buyer**& b, int count)
{
    ofstream out(path);
    out << count << '\n';
    for (int i = 0; i < count; i++)
    {
        out << b[i]->LastName << "\n"
            << b[i]->YearOfBirth << "\n"
            << b[i]->TelephoneNumber << "\n"
            << b[i]->Address << "\n"
            << b[i]->AccountNumber << "\n";
    }
}

void initializationArray(Buyer**& b, int count) {
    b = new Buyer * [count]();
    for (int i = 0; i < count; i++)
    {
        b[i] = new Buyer();
    }
}

void addItem(Buyer**& b, Buyer newBuyer, int& count) {
    Buyer** temporary;
    initializationArray(temporary, count + 1);
    for (int i = 0; i < count; i++)
    {
        temporary[i] = b[i];
    }
    *temporary[count] = newBuyer;
    b = temporary;
    count++;

}
void deleteItem(Buyer**& b, int deleteNumber, int& count) {
    Buyer** temporary;
    initializationArray(temporary, count - 1);
    delete b[deleteNumber];
    int t = 0;
    for (int i = 0; i < count; i++)
    {
        if (t == deleteNumber) {
            t++;
        }
        temporary[i] = b[t];
        t++;
    }

    b = temporary;
    count--;

}
void writeInConsole(Buyer**& b, int count) {
    for (int i = 0; i < count; i++)
    {
        cout << b[i]->LastName << "\n"
            << b[i]->YearOfBirth << "\n"
            << b[i]->TelephoneNumber << "\n"
            << b[i]->Address << "\n"
            << b[i]->AccountNumber << "\n";
    }
}
int findElement(Buyer**& b, int type, string findValue, int count ) {
    short convertValueS;
    int convertValueI;
    switch (type)
    {

    case b[0]->LastNameEnum:

        for (int i = 0; i < count; i++)
            if (b[i]->LastName == findValue)
                return i;
        return -1;
    break;

    case b[0]->YearOfBirthEnum:

        

        try
        {
            convertValueS = stoi(findValue);
        }
        catch (const std::exception& e )
        {
            cout << e.what() << endl
                << "значение года не коректно" << endl;
        }

        for (int i = 0; i < count; i++)
            if (b[i]->YearOfBirth == convertValueS)
                return i;
        return -1;
        break;

    case b[0]->TelephoneNumberEnum:

        

        try
        {
            convertValueI = stoi(findValue);
        }
        catch (const std::exception& e)
        {
            cout << e.what() << endl
                << "значение телефона не коректно" << endl;
        }

        for (int i = 0; i < count; i++)
            if (b[i]->TelephoneNumber == convertValueI)
                return i;
        return -1;
        break;

    case b[0]->AddressEnum:

        for (int i = 0; i < count; i++)
            if (b[i]->Address == findValue)
                return i;
        return -1;
        break;

    case b[0]->AccountNumberEnum:

    

        try
        {
            convertValueI = stoi(findValue);
        }
        catch (const std::exception& e)
        {
            cout << e.what() << endl
                << "значение телефона не коректно" << endl;
        }

        for (int i = 0; i < count; i++)
            if (b[i]->AccountNumber == convertValueI)
                return i;
        return -1;
        break;
    default:
        break;
    }
    /*LastNameEnum = 1,
        YearOfBirthEnum = 2,
        TelephoneNumberEnum = 3,
        AddressEnum = 4,
        AccountNumberEnum = 5*/
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
