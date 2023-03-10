
#ifndef FUNCS_H
#define FUNCS_H

bool readTAG();
int readNUM();
int lensNUMBER(int NUM);
void statARRAY(int NUM, int* ARRAYstat);
int deleteINT(int NUM, int* ARRAYstat);
void console(std::ostream& fout);
void txt(std::istream& fin, std::ostream& fout);
#endif