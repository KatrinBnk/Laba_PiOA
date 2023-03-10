
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
			std::cout << "Некорректный ввод. Однакомтесь с условием выше и повторите ввод.\n\
Ввод данных >>";
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
				std::cout << "Некорректный ввод. Однакомтесь с условием выше и повторите ввод.\n\
Ввод данных >> ";
			}

		}
		else {

			while (std::cin.get() != '\n') {
				if (std::cin.peek() == EOF)  std::cin.seekg(0, std::ios::end);
				std::cin.clear(); break;
			};
			std::cin.seekg(0, std::ios::end);
			std::cin.clear();
			std::cout << "Некорректный ввод. Однакомтесь с условием выше и повторите ввод.\n\
Ввод данных >> ";

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


//принимает на вход статистический массив и удаляет оттуда 0 и 5 
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
	std::cout << "Введите целое число, большее 0 >> ";
		long int consoleNUM{ readNUM() };
		int* ARRAYstat = new int[lensNUMBER(consoleNUM)];
		statARRAY(consoleNUM, ARRAYstat);
		fout << "Ответ для числа  "<< consoleNUM <<" — " << deleteINT(consoleNUM, ARRAYstat) << std::endl;
		std::cout << "Если вы хотиете изменить другое число, введите 1 иначе введите 0, чтобы завершить программу.\n\
Ввод данных >> ";
	
}

void txt(std::istream& fin, std::ostream& fout) {
	int countNUM;
	std::cout << "Сколько чисел записано в файле? \nВвод данных >> ";
	std::cin >> countNUM;
	int* fileS = new int[countNUM];
	int i = 0;
	for (int i{ 0 }; i < countNUM; i++) {
		if (fin >> fileS[i] && (fin.peek() == EOF || fin.peek() <= 32) && fin.peek() != ' ') {
			if (fileS[i] == 5 || fileS[i] <= 0) {
				fileS[i] = 0;
				fout << "Число выходит за пределы доступного диапазона (cостоить только из 5 или 0)" << std::endl;
			}
			else {
				int* ARRAYstat = new int[lensNUMBER(fileS[i])];
				statARRAY(fileS[i], ARRAYstat);
				fout << "Ответ для числа  " << fileS[i] << " — " << deleteINT(fileS[i], ARRAYstat) << std::endl;
			}

		}
		else {
			if (fin.eof() == true) {

				fout << "Строки закончились" << std::endl;
				break;
			}
			else {
				// пустые строки игнорим
				fout << "Запись содержит строку" << std::endl;
				fileS[i] = -1;
				fin.clear();
				while (fin.get() != '\n') { if (fin.peek() == EOF) break; };

			}


		}
		if (i == countNUM - 1 && fin.eof() != true) {
			fout << "Дальше есть записи, но они не были обработаны, так как вышли за объявленный вами диапазон записей" << std::endl;
		}

	}
}