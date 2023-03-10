//лаба 2 (вариант 5 задача 207, если варианты по убыванию списка)
#include <iostream>
#include <fstream> 
#include <string>
#include "funccH.h"



int main() {
	setlocale(LC_ALL, "Russian");
    std::cout << "Добро пожаловать. \n\
Данная программа преднозначена для вычисления радиуса основания цилиндра единичного объема с заданной высотой \n\
Для начала вам необходимо ввести число 1, чтобы начать работу, или 0, если вы запустили программу по ошибке\n\
Ввод данных >> ";
    if (readTAG())
    {
        
        bool tagTXT{ 1 };
        std::ofstream fout("output.txt");
        if (!fout) tagTXT = 0;
        std::cout << "Для продолжение работы вам нееобходимо выбрать откуда будет происходить считывание данных. \n\
Введите 1, если хотите читывать данные с клавиатуры, и 0, если данные находятся в файле. \n\
Ввод данных >> ";

        if (readTAG()) //чтение с клавиатуры
        {
            bool TAG{1};
            do {
                std::cout << "Вывод результатов в консоль (1) или вывод в файл(0) >> ";
                bool tag{ readTAG() };
                if (tag) console(std::cout);
                else {
                    if (tagTXT) {
                        console(fout);
                        std::cout << "Измененное число записано в файл" << std::endl;
                    }
                    else std::cout << "Произошла ошибка при открытии файла для записи.\n";
                }
                TAG = readTAG();
            } while (TAG);
        }
        
        else //чтение из файла
        {
            std::cout << "Выбрано чтение из файла\n";
            std::ifstream fin("input.txt");
            if (!fin)
            {
                std::cout << "Произошла ошибка при открытии файла для чтения.\n";
                return 1;
            }
            else {

                std::string str;
                std::getline(fin, str);
                if (fin.eof() && str.empty()) {
                    std::cout << "Файл для чтения пуст" << std::endl;
                    fout << "Файл для чтения пуст" << std::endl;
                    return 1;
                }
                fin.seekg(0);
            }
            std::cout << "Вывод результатов в консоль (1) или вывод в файл(0) >> ";
            bool tag{ readTAG() };
            if (tag) txt(fin, std::cout);
            else {
                if (tagTXT) {
                    txt(fin, fout);
                    std::cout << "Вычисления были произведены. Результат можно посмотреть в файле output.txt" << std::endl;
                }
                else std::cout << "Произошла ошибка при открытии файла для записи.\n";
            }
           
            fin.close();
            fout.close();
        }
    }
    std::cout << "Программа завершена!";
	return 0;
}