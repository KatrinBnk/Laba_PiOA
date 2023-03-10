//вариант 141 (5 в списке)
#include <fstream> 
#include <iostream>
#include <string>
#include <vector>
#include "funcs.h"

int globalTAGS{ 0 };

int main()
{
    setlocale(LC_ALL, "Russian");
    float h;
    short flag_prog, flag_read;
    float res;
    
    std :: cout << "Добро пожаловать. \n\
Данная программа преднозначена для вычисления радиуса основания цилиндра единичного объема с заданной высотой \n\
Для начала вам необходимо ввести число 1, чтобы начать работу, или 0, если вы запустили программу по ошибке\n\
Ввод данных >> ";
    flag_prog = tags(globalTAGS); //проверка дурака

    if (flag_prog == 1)
    {
        globalTAGS = 1;
        std::cout << "Для продолжение работы вам нееобходимо выбрать откуда будет происходить считывание данных. \n\
Введите 1, если хотите читывать данные с клавиатуры, и 0, если данные находятся в файле. \n\
Ввод данных >> ";
        flag_read = tags(globalTAGS); //проверка дурака
        if (flag_read == 1)
        {
            globalTAGS = 2;
            while (flag_prog != 0)
            {
                h = read_h(); //проверка дурака для высоты
                res = computations(h); //вычисления
                std::cout << "Радиус однования данного цилирдра равен " << res << " условных единиц. \n";
                std::cout << "Если вы хотиете сделать вычисления для цилиндра с дргой высотой, введите 1 иначе введите 0, чтобы завершить программу.\n\
Ввод данных >> ";
                flag_prog = tags(globalTAGS); //проверка дурака
            }
        }
        else
        {
            std::ifstream fin("input.txt");
            if (!fin)
            {
                // Распечатываем ошибку и завершаем прогу
                std::cerr << "Произошла ошибка при открытии файла для чтения.\n";
                return 0;
            }
            std::ofstream fout("output.txt");
            if (!fout)
            {
                // Распечатываем ошибку и завершаем прогу
                std::cerr << "Произошла ошибка при открытии файла для записи.\n";
                return 0;
            }
            int flag_read_mass;
            globalTAGS = 3;
            std::cout << "Выбрано считывание из файла. \n\
Если в ващем файле задано несколько значений для высоты цилиндра, введите 1, иначе — 0.\n\
Ввод данных >> ";
            flag_read_mass = tags(globalTAGS); //проверка дурака
            if (flag_read_mass == 0) {
                float h_txt;
                fin >> h_txt;
                if (h_txt)
                {
                    if (h_txt > 0 && h_txt <= 5)
                    {
                        res = computations(h_txt);
                        std::cout << "Радиус однования данного цилирдра равен " << res << " условных единиц " << std::endl;
                        fout << "Радиус однования данного цилирдра равен " << res << " условных единиц " << std::endl;
                        return 0;
                    }
                    else
                    {
                        std::cout << "Данные в файле записаны некорректно. Число записанное там, выходит за рамки [0;5]. Вычисления не были произведены";
                        fout << "Данные в файле записаны некорректно. Число записанное там, выходит за рамки [0;5]. Вычисления не были произведены";
                        return -1;
                    }
                }
                else
                {
                    std::cout << "Данные в файле записаны некорректно. Скорее всего там находится стррока. Вычисления не были произведены";
                    fout << "Данные в файле записаны некорректно. Скорее всего там находится стррока. Вычисления не были произведены";
                    return -1;
                }

            }
            else 
            {
                int count_H;
                std::cout << "Сколько радиусов записано в файле? \nВвод данных >> ";
                std::cin >> count_H;

                float* H_txt = new float[count_H];
                float* Res_txt = new float[count_H];
                float h_txt_h;

                for (int i = 0; i < count_H; i++) {
                    if (fin >> h_txt_h)
                    {
                        if (h_txt_h > 0 && h_txt_h <= 5)
                        {
                            H_txt[i] = h_txt_h;
                        }
                        else
                        {
                            H_txt[i] = 404;
                        }
                    }
                    else
                    {
                        H_txt[i] = 405;
                    }
                }
                /*for (int i{0}; i < count_H; i++) {
                    std::cout << H_txt[i]<< " ";
                }*/
                computationsFORtxt(H_txt, Res_txt, count_H);

                for (int i{ 0 }; i < count_H; i++) {
                    if (Res_txt[i]!= 404 && Res_txt[i] != 405){
                        std::cout << Res_txt[i] << "\n";
                        fout << Res_txt[i] << "\n";
                    }
                    else {
                        if (Res_txt[i] == 404) {
                            std::cout << "Некорректные данные. Неверный диапазон\n";
                            fout << "Некорректные данные. Неверный диапазон\n";
                        }
                        else {
                            std::cout << "Некорректные данные. Строка \n";
                            fout << "Некорректные данные. Строка \n";
                        }
                    }
                    
                }
                fin.close();
                fout.close();


            }
        }
    }

    
}



/*
                std::vector <float> H_mass;
                for (float h_txt_h; fin >> h_txt_h; ) {
                    if (h_txt_h)
                    {
                        if (h_txt_h > 0 && h_txt_h <= 5)
                        {
                            H_mass.push_back(h_txt_h);
                        }
                        else {
                            H_mass.push_back(INFINITY);
                        }
                    }
                    else
                    {
                        H_mass.push_back(INFINITY);

                    }
                }
                std::vector <float> res_mass{ read_v(H_mass) };

                for (int i = 0; i < res_mass.size(); i++)
                {
                    if (res_mass[i] != INFINITY) {
                        std::cout << res_mass.at(i) << std::endl;
                        fout << res_mass.at(i) << "\n";
                    }
                    else {
                        std::cout << "Некорректные данные." << std::endl;
                        fout << "Некорректные данные." << "\n";
                    }
                }*/

