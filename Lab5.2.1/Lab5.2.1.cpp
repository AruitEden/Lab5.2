#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Data.h"
#include "Dictionary.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char opera;
    Dictionary lst;


    cout << "Что вы хотите сделать?" << endl;
    cout << "\nСоставить список с данными из файла - S \nНайти страницы на которых находиться слово - F \nУдалить слово из списка - D";
    cout << "\nЕсли хотите добавить элемент списка в ручную - A";
    cout << "\nЕсли хотите завершить работу - E";
    cout << endl;
    cout << endl;


    while (true)
    {
        cout << "Введите операцию: ";
        cin >> opera;
        cout << endl;

        switch (opera)
        {

        case('S'):
        {
            string path;
            ifstream fout;

            cout << "Введите путь к файлу из которого вы хотите взять данные (без кавычек)" << endl;
            cin.ignore(1);
            getline(cin, path);

            fout.open(path);

            //Проверка на открытие файла
            if (!fout.is_open())
            {
                cout << "Ошибка" << endl;
                return -1;
            }

            cout << "Файл открыт!" << endl;

            //Игнорирование первой строчки с заголовком
            while (fout.peek() != '\n')
            {
                fout.ignore(1);
            }

            //Заполнение списка
            while (!fout.eof())
            {
                Data* a = new Data();
                fout >> *a;
                lst.push_back(*a);
            }

            cout << "\t\t\t\t   ***Полученый список***" << endl;
            lst.Print();

            cout << endl;

            fout.close();
        }
        break;

        case('F'):
        {
            if (lst.getSize() == 0)
            {
                cout << "Вы не создали список. Для начала сделайте это.\n";
                cout << endl;
                break;
            }

            //Поиск страниц
            string finde;

            cout << "\t\t\t\t   ***Поиск в спсике***" << endl;
            cout << "(Если вам болтше не нужно искать слово введите '/no')" << endl;

            cin.ignore();

            while (true)
            {
                cout << "\nВведите слово что бы узнать на каких оно страницах встречаеться: ";

                getline(cin, finde);
                cout << endl;

                if (finde == "/no")
                {
                    break;
                }

                int f = lst.FindSlovo(finde);

                if (f < 0)
                {
                    cout << "Такого слова нет, вы ошиблись" << endl;
                }
                else
                {
                    cout << "Страницы на которых есть это слово: ";
                    for (int i = 0; i < lst[f].dat.getNumber(); i++)
                    {
                        cout << lst[f].dat.getPage()[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
        break;

        case('D'):
        {
            if (lst.getSize() == 0)
            {
                cout << "Вы не создали список. Для начала сделайте это.\n";
                cout << endl;
                break;
            }

            //Удаление элемента
            int num;
            cout << "\t\t\t\t   ***Удаление элемента из списка***" << endl;
            cout << "Вам нужно ввести номер элемента который вы хотите удалть. Номер указан рядом со словом в списке" << endl;
            cout << "Если вам больше не надо удалять элементы из списка введите отрицательное значение" << endl;
            cout << endl;

            while (true)
            {
                if (lst.getSize() == 0)
                {
                    cout << "Вы удалли все элементы" << endl;
                    break;
                }

                cout << "Номер: ";
                cin >> num;

                if (num > lst.getSize())
                {
                    cout << "Такого номера нет в списке" << endl;
                }

                if (num < 0)
                {
                    break;
                }

                if (num > 0 && num < lst.getSize() + 1)
                {
                    lst.DeletElment(num);
                    lst.Print();
                    cout << endl;
                }
            }
        }
        break;

        case('E'):
        {
            cout << "Хорошего дня";
            exit(0);
        }

        case('A'):
        {
            cout << "\t\t\t\t   ***Добавление элемента в список***" << endl;
            cout << "Введите слово и количество страниц где оно встречаеться через пробел, а сами страницы через запятую" << endl;
            cout << "Будьте внимательны, количество страниц где встречаються и фактическое значение должны быть равны\n" << endl;
            Data d1;
            cout << "Ваш элемент списка: ";
            cin >> d1;
            cout << endl;
            lst.push_back(d1);
            lst.Print();
            cout << endl;
        }
        break;

        default:

            cout << "Вы ввели незвестную команду. Попробуйте ещё раз\n";
            cout << endl;
            break;
        }
    }
}