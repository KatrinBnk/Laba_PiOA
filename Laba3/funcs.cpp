#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include <iomanip>
#include "funcsH.h"


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

int readI(bool tag) {
	int I;
	bool tagFORtag{ true };
	while (tagFORtag) {
		std::cin >> I;
		
			if (((I > 0 && tag) or not (tag)) && std::cin.get() == '\n') return I;
			else
			{
				while (std::cin.get() != '\n') {
					if (std::cin.peek() == EOF)  std::cin.seekg(0, std::ios::end);
						std::cin.clear(); break;
				};
					std::cin.seekg(0, std::ios::end);
						std::cin.clear();
						std::cout << "������������ ����. ����������� � �������� ���� � ��������� ����.\n\
���� ������ >> ";
			}
		
	}
}

void readTXT(double** A, double** B, double** C, int SIZE, std::istream& fin, std::ostream&fout) {
	int N, M;
	std::cout << "����� ����\n";
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			fin >> A[i][j];
			
			if (fin.fail() && (fin.peek() == EOF || fin.peek() <= 32)) {
				break;
			}
			else{
				N = i;
				M = j;
			}
			
		}
	if (N == M && M == SIZE - 1 && fin.peek() == EOF) {
		outPUTres(A, B, C, SIZE, fout);
	}
	else {
		if (not(fin.peek() == EOF) || not(N == M && M == SIZE - 1))
			fout << "����������� ������ �� ����� ������� \n";
		else 
			fout << "�������� � ������� �������� �������. ��������� ������ ������. \n";
		
	}
}

void DELETEmass(double** mass, int SIZE) {
	for (int i{ 0 }; i < SIZE; i++)
		delete[] mass[i];
	delete[] mass;
}


void READmass(int SIZE, double** A) { //������������ ���������� � ���������� 
	for (int i{ 0 }; i < SIZE; i++) {
		for (int j{ 0 }; j < SIZE; j++) {
			std::cout << "A[" << i << "][" << j << "] = ";
			A[i][j] = readA();
		}
	}
}

int TAB{ 0 };

void RANDOMmass(int SIZE, double** A)
{
	srand(time(NULL));//����� ������ ������ ������������������ ��������� ����
	int minVALUE, maxVALUE, precision{ 0 };
	bool tag{1};
	while (tag) {
		std::cout << "������� ������ �������� ����� >> ";
		minVALUE = readI(0);
		std::cout << "������� ������� �������� ����� >> ";
		maxVALUE = readI(0);
		if (minVALUE >= maxVALUE) std::cout << "������������ ����. ��������� ���.\n";
		else tag = 0;
	}
	std::cout << "������� ������� ������ �� ����� �����? ������� 1 � ���� ��, 0 � ���� ��� >>";
	bool TYPE{ readTAG() };
	if (TYPE) {
		
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
			{
				A[i][j] = minVALUE + rand() % (maxVALUE - minVALUE + 1);
			}
	}
	else {
		
		std::cout << "������� ������ ����� ������� ������ ����������� � �����? >>";
		precision = readI(1);
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
			{
				A[i][j] = minVALUE + (rand() % (int)pow(10, precision+1) / pow(10, precision+1)) * (maxVALUE - minVALUE);
			}
	}
	if (std::abs(maxVALUE) > std::abs(minVALUE)) 
		TAB =  std::to_string(maxVALUE).length() + 1 + 1 + precision;
	else TAB = std::to_string(minVALUE).length() + 1 + 1 + precision;
	

}

void work(double** A, double** B, double** C, int SIZE) {
	for (int i = 0; i < SIZE; i++) 
		for (int j = 0; j < SIZE; j++)
		{
			if (j >= i) {
				B[i][j] = A[i][j];
				if (A[i][j] == 0) C[i][j] = A[i][j];
				else C[i][j] = (-1)* A[i][j];
			}
			else {
				B[i][j] = A[j][i];
				C[i][j] = A[i][j];
			}
		}
}

void outPUT(double** mass, int SIZE, std::ostream& f) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) 
			f << std::setw(TAB) <<mass[i][j] << " ";
		f << std::endl;
	}
	DELETEmass(mass, SIZE);
}

void outPUTres(double** A, double** B, double** C, int SIZE, std::ostream& f) {
	work(A, B, C, SIZE);
	f << "�������� ������� � ����� ���:" << std::endl;
	outPUT(A, SIZE, f);
	f << "��� �������� ������� �, ������� � ����� ���:" << std::endl;
	outPUT(B, SIZE, f);
	f << "��� �������� ������� �, ������� � ����� ���:" << std::endl;
	outPUT(C, SIZE, f);

}


float readA() {
	float H;
	bool tagFORtag{ false };
	char s;
	while (not(tagFORtag)) {
		std::cin >> H;
		if ( std::cin.get() == '\n')
		{
			std::cin.seekg(0, std::ios::end);
			std::cin.clear();
			tagFORtag = true;
			return H;
		}
		else {
			while (std::cin.get() != '\n') {
				if (std::cin.peek() == EOF)  std::cin.seekg(0, std::ios::end);
				std::cin.clear(); break;
			};
			std::cin.seekg(0, std::ios::end);
			std::cin.clear();
			std::cout << "������������ ����. ����������� � �������� ���� � ��������� ����.\n\
���� ������ >> ";

		}
	}


}

void workNOTtxt(double** A, double** B, double** C, int SIZE, std::ostream& f) {
	
		std::cout << "�� ������ ������ ������� �������? ������� 1 � ���� ��, 0 � ���� ��� >> ";
		if (readTAG()) {
			READmass(SIZE, A);
			outPUTres(A, B, C, SIZE, f);
		}
		else
		{
			RANDOMmass(SIZE, A);
			outPUTres(A, B, C, SIZE, f);
		}
		std::cout << "���� �� ������� �������� ��������� ���������, ������� 1 ����� ������� 0, ����� ��������� ���������.\n\
���� ������ >> ";
	
}
 






int readSIZE(std::istream& fin) {
	int SIZE;
	if (fin >> SIZE && (fin.peek() == EOF || fin.peek() <= 32) && fin.peek() != ' ' && SIZE >= 0) {
		return SIZE;
	}
	else return 0;
}