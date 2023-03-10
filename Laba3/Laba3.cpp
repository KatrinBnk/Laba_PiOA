// задача 371 (5 номер в списке)
#include <iostream>
#include <fstream> 
#include <string>
#include <random>
#include "funcsH.h"



int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Добро пожаловать. \n\
Данная программа преднозначена для вычислений задачи 371 из сбоника. \n\
Для начала вам необходимо ввести число 1, чтобы начать работу, или 0, если вы запустили программу по ошибке\n\
Ввод данных >> ";
    if (readTAG())
    {
        
        
        std::cout << "Для продолжение работы вам нееобходимо выбрать откуда будет происходить считывание данных. \n\
Введите 1, если хотите читывать данные с клавиатуры, и 0, если данные находятся в файле. \n\
Ввод данных >> ";
        std::ifstream fin("input.txt");
        if (!fin)
        {
            std::cerr << "Произошла ошибка при открытии файла для чтения.\n";
            return 1;
        }
        std::ofstream fout("output.txt");
        if (!fout)
        {
            std::cerr << "Произошла ошибка при открытии файла для записи.\n";
            return 1;
        }

        if (readTAG()) //чтение с клавиатуры
        {

            bool TAG{ 1 };
            do {
                int SIZE{};
                int i{ 0 }, j{ 0 };
                std::cout << "Введите размерность матрицы >> ";
                SIZE = readI(1);
                double** A = new double* [SIZE];
                double** B = new double* [SIZE];
                double** C = new double* [SIZE];
                for (int i{ 0 }; i < SIZE; i++)
                {
                    A[i] = new double[SIZE];
                    B[i] = new double[SIZE];
                    C[i] = new double[SIZE];
                }
                std::cout << "Вывод результатов в консоль (1) или вывод в файл(0) >> ";
                bool tag{ readTAG() };
                if (tag) workNOTtxt(A, B, C, SIZE, std::cout);
                else {
                    if (tag) {
                        workNOTtxt(A, B, C, SIZE, fout);
                        std::cout << "Результат работы записан в файл." << std::endl;
                    }
                    else {
                        std::cout << "Произошла ошибка при открытии файла для записи.\n";
                        std::cout << "Если вы хотиете повторно запустить программу, введите 1 иначе введите 0, чтобы завершить программу.\n\
Ввод данных >> ";
                    };
                }
                TAG = readTAG();
            } while (TAG);

        
        }
        else //чтение из файла
        {
            std::cout << "Выбрано чтение из файла\n";
            std::string str;
            std::getline(fin, str);
            if (fin.eof() && str.empty()) {
                std::cout << "Файл для чтения пуст" << std::endl;
                fout << "Файл для чтения пуст" << std::endl;
                return 1;
            }
            else {
                fin.seekg(0);
                int SIZE{ readSIZE(fin) };
                if (SIZE == 0) {
                    std::cout << "Размерность матрицы в файле указана неверно. Вычисления произведены не были. " << std::endl;
                    return 1;
                }
                
                int i{ 0 }, j{ 0 };

                std::cout << "Моемент не пофикшен. Что если размерость матрицы меньше или больше, чем заданная (в файле)" << std::endl;
                double** A = new double* [SIZE];
                double** B = new double* [SIZE];
                double** C = new double* [SIZE];
                for (int i{ 0 }; i < SIZE; i++)
                {
                    A[i] = new double[SIZE];
                    B[i] = new double[SIZE];
                    C[i] = new double[SIZE];
                }
                std::cout << "Вывод в консоль (1) или вывод в файл(0) >> ";
                bool tag{ readTAG() };
                if (tag) readTXT(A, B, C, SIZE, fin, std::cout);
                else {
                    readTXT(A, B, C, SIZE, fin, fout);
                    std::cout << "\nВычисления были произведены. Результат можно посмотреть в файле output.txt" << std::endl;
                }
            }
        }
        fin.close();
        fout.close();
    }
    std::cout << "Программа завершена.";
    return 0;
}