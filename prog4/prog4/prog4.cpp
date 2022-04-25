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
    int count = 0;

    Buyer** buyers;
    
    initializationArray(buyers, count);

    // основная часть 

    string valueForSearch, temporary;
    int numb, b, item;
    Buyer newBuyer;
    bool exit = true;
    while (exit)
    {
        cout << "Что хотите сделать?" << endl
            << "1. Загрузить из файла" << endl
            << "2. Сохранить в файл" << endl
            << "3. Добавить элемент" << endl
            << "4. Удалить элемент" << endl
            << "5. Найти элемнт" << endl
            << "6. Вывести" << endl
            << "7. выход" << endl

            << "Введите число:" << endl;
        int a;
        cin >> a;
        system("cls");

        switch (a)
        {
        case 1:
            readFile(buyers, count);
            cout << "Загрузка завершена" << endl;
            break;
        case 2:
            writeFile(buyers, count);
            cout << "Сохранено" << endl;
            break;
        case 3:
            cout << "введите фамилию: ";
            cin >> newBuyer.LastName;
            cout << "введите год рождения: ";
            cin >> newBuyer.YearOfBirth;
            cout << "введите номер телефона: ";
            cin >> newBuyer.TelephoneNumber;
            cout << "введите адрес: ";
            cin >> newBuyer.Address;
            cout << "введите  номер счета:";
            cin >> newBuyer.AccountNumber;
            addItem(buyers, newBuyer, count);
            cout << "элемент добавлен" << endl;
            break;
        case 4:
            if (count > 0)
            {
                cout << "Введите номер элемента, который нужно удалить:";
                cin >> numb;
                deleteItem(buyers, numb, count);
                cout << "элемент удален" << endl;
            }
            else
            {
                cout << "Массив пустой, удалять нечего" << endl;
            }
            break;
        case 5:
            cout << "по какому полю искать" << endl;
            cout << "1. Фамилия" << endl;
            cout << "2. год рождения" << endl;
            cout << "3. Телефонный номер" << endl;
            cout << "4. Адресс" << endl;
            cout << "5. Номер счета" << endl;
            cout << "ваш выбор:" << endl;
            cin >> b;
            cout << "занчение поля:" << endl;
            cin >> valueForSearch;
            item = findElement(buyers, b , valueForSearch, count);
            if (item != -1)
            {
                cout << buyers[item]->LastName << endl
                    << buyers[item]->YearOfBirth << endl
                    << buyers[item]->TelephoneNumber << endl
                    << buyers[item]->Address << endl
                    << buyers[item]->AccountNumber << endl;
            }
            break;
        case 6:
            writeInConsole(buyers, count);
            break;
        case 7:
            exit = false;
            break;
        default:
            cout << "Число введено неверно, введите еще раз";
            break;
        }
        

    }
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

        long long convertValueL;

        try
        {
            convertValueL = stoll(findValue);
        }
        catch (const std::exception& e)
        {
            cout << e.what() << endl
                << "значение телефона не коректно" << endl;
        }

        for (int i = 0; i < count; i++)
            if (b[i]->TelephoneNumber == convertValueL)
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
    
}

