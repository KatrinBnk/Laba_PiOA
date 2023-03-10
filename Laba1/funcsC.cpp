#include <iostream>
#include <fstream> 

#include "consts.h"

bool readTAG() {
    char TAG;
    bool tagFORtag{ false };
    while (not(tagFORtag)) {
        std::cin >> TAG;
        if ((TAG == '0' || TAG == '1') && std::cin.peek() == '\n')
        {
            std::cin.seekg(0, std::ios::end);
            std::cin.clear();
            tagFORtag = true;
        }
        else {
            std::cin.seekg(0, std::ios::end);
            std::cin.clear();
            std::cout << "������������ ����. ����������� � �������� ���� � ��������� ����.\n\
���� ������ >>";
        }
    }
    if (TAG == '1') return true;
    else return false;

}

bool constHread(float H) {
    for (int i = 0; i < 10; i++) {
        if (H == consts::H[i]) return true;
    }
    return false;
}

float readH() {
    float H;
    bool tagFORtag{ false };
    char s;
    while (not(tagFORtag)) {
        std::cin >> H;
        
        if (constHread(H) && std::cin.get() == '\n')

        { 
            if (constHread(H)) {
                return H;
                std::cin.seekg(0, std::ios::end);
                std::cin.clear();
                tagFORtag = true;
            }
            else{
                std::cin.seekg(0, std::ios::end);
                std::cin.clear();
                std::cout << "������������ ����. ����������� � �������� ���� � ��������� ����.\n\
���� ������ >> ";
            }
            
        }
        else {
            
            while (std::cin.get() != '\n') { if (std::cin.peek() == EOF)  std::cin.seekg(0, std::ios::end);
            std::cin.clear(); break; };
            std::cin.seekg(0, std::ios::end);
            std::cin.clear();
            std::cout << "������������ ����. ����������� � �������� ���� � ��������� ����.\n\
���� ������ >> ";
            
        }
    }
    

}


float computations(float h)
{
    float r; // ������ ��������� ��������
    r = consts::v / (consts::pi * h);
    r = pow(r, 0.5); // ���������� � ������� 1/2
    return r;

}

void computationsFILE(float* fileH, float* fileR, int countH) {
    for (int i{ 0 }; i < countH; i++) {
        if (fileH[i] != 404 and fileH[i] != 404 and fileH[i] != 400)
            fileR[i] = computations(fileH[i]);
        else fileR[i] = fileH[i];
    }
}

void console(std::ostream& fout) {
    std::cout << "���� ����������� ��������� ������ ������������ ����� ���������. \n\
������� 1, ���� �� ������ ��� �������, ��� 0, ���� ������ ������ ���� ������� �������. \n\
���� ������ >> ";
    if (not(readTAG())) {

        
            std::cout << "������� ������ �������� ([0.5,5] � ����� 0.5) >> ";
            float consoleH{ readH() };
            std::cout << "���������� �����������.";
            fout << "��� ������� � �������  " << consoleH << ". ������ ��������� ����� " << computations(consoleH) << std::endl;
            std::cout << "���� �� ������� ������� ���������� ��� �������� � ����� �������, ������� 1 ����� ������� 0, ����� ��������� ���������.\n\
���� ������ >> ";
       
    }
    else {
        float H{};
        for (int i{ 0 }; i < 10; i++) {
            H = consts::H[i];
            std::cout << "���������� �����������.";
            fout << "������ ��������� �������� � ������� " << H << " ����� " << computations(H) << " �������� ������. \n";
        }
        std::cout << "���� �� ������� ������� ���������� ��� �������� � ����� �������, ������� 1 ����� ������� 0, ����� ��������� ���������.\n\
���� ������ >> ";

    }
}

void txtREAD(std::istream& fin, std::ostream& fout) {
    int countH;
    std::cout << "������� ����� �������� � �����? \n���� ������ >> ";
    std::cin >> countH;
    float* fileH = new float[countH];
    float* fileR = new float[countH];
    int i = 0;
    while (true) {
        if (fin >> fileH[i] && (fin.peek() == EOF || fin.peek() <= 32)) {
            if (not(constHread(fileH[i])))
                fileH[i] = 404;
        }
        else {
            if (fin.eof() == true) {
                for (int h = i; h < countH; h++) fileH[h] = 400;
                break;
            }
            else {
                fileH[i] = 405;
                fin.clear();
                while (fin.get() != '\n') { if (fin.peek() == EOF) break; };
            }
        }
        ++i;
    }
    computationsFILE(fileH, fileR, countH);

    for (int i{ 0 }; i < countH; i++) {
        if (fileH[i] != 404 and fileH[i] != 405 and fileH[i] != 400) {
            fout << "��� ������� � �������  " << fileH[i] << ". ������ ��������� ����� " << fileR[i] << std::endl;
        }
        else {
            if (fileH[i] == 404) fout << "�������� �������� ������� ������. ���������� �� ���� �����������. " << std::endl;
            if (fileH[i] == 405) fout << "�������� ��� ������ (��������� ������). ���������� �� ���� �����������. " << std::endl;
            if (fileH[i] == 400) { fout << "������ �����������" << std::endl; break; }
        }
    }
}