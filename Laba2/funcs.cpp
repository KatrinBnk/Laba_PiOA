
#include <iostream>
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



int readNUM() {
	int NUM;
	bool tagFORtag{ false };
	while (not(tagFORtag)) {
		std::cin >> NUM;

		if (std::cin.get() == '\n')

		{
			if (NUM > 0) {
				tagFORtag = true;
				return NUM;
			}
			else {
				std::cin.seekg(0, std::ios::end);
				std::cin.clear();
				std::cout << "������������ ����. ����������� � �������� ���� � ��������� ����.\n\
���� ������ >> ";
			}

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







int lensNUMBER(int NUM) {
	int count{ 0 };
	while (NUM) {
		NUM /= 10;
		count++;
	}
	return count;
}

void statARRAY(int NUM, int* ARRAYstat) {
	
	int i{ lensNUMBER(NUM) - 1 };
	do {

		ARRAYstat[i] = NUM % 10;
		NUM /= 10;
		i--;
	} while (NUM);

}


//��������� �� ���� �������������� ������ � ������� ������ 0 � 5 
int deleteINT(int NUM, int* ARRAYstat) {
	int RES{ 0 };
	int I{ 0 };
	for (int i{ lensNUMBER(NUM) - 1 }; i >= 0; i--) {
		if (ARRAYstat[i] != 5 && ARRAYstat[i] != 0) {
			RES += ARRAYstat[i] * pow(10, I);
			I++;
		}
	}
	return RES;
}

void console(std::ostream& fout) {
	std::cout << "������� ����� �����, ������� 0 >> ";
		long int consoleNUM{ readNUM() };
		int* ARRAYstat = new int[lensNUMBER(consoleNUM)];
		statARRAY(consoleNUM, ARRAYstat);
		fout << "����� ��� �����  "<< consoleNUM <<" � " << deleteINT(consoleNUM, ARRAYstat) << std::endl;
		std::cout << "���� �� ������� �������� ������ �����, ������� 1 ����� ������� 0, ����� ��������� ���������.\n\
���� ������ >> ";
	
}

void txt(std::istream& fin, std::ostream& fout) {
	int countNUM;
	std::cout << "������� ����� �������� � �����? \n���� ������ >> ";
	std::cin >> countNUM;
	int* fileS = new int[countNUM];
	int i = 0;
	for (int i{ 0 }; i < countNUM; i++) {
		if (fin >> fileS[i] && (fin.peek() == EOF || fin.peek() <= 32) && fin.peek() != ' ') {
			if (fileS[i] == 5 || fileS[i] <= 0) {
				fileS[i] = 0;
				fout << "����� ������� �� ������� ���������� ��������� (c������� ������ �� 5 ��� 0)" << std::endl;
			}
			else {
				int* ARRAYstat = new int[lensNUMBER(fileS[i])];
				statARRAY(fileS[i], ARRAYstat);
				fout << "����� ��� �����  " << fileS[i] << " � " << deleteINT(fileS[i], ARRAYstat) << std::endl;
			}

		}
		else {
			if (fin.eof() == true) {

				fout << "������ �����������" << std::endl;
				break;
			}
			else {
				// ������ ������ �������
				fout << "������ �������� ������" << std::endl;
				fileS[i] = -1;
				fin.clear();
				while (fin.get() != '\n') { if (fin.peek() == EOF) break; };

			}


		}
		if (i == countNUM - 1 && fin.eof() != true) {
			fout << "������ ���� ������, �� ��� �� ���� ����������, ��� ��� ����� �� ����������� ���� �������� �������" << std::endl;
		}

	}
}