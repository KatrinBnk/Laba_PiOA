
#ifndef FUNCS_H
#define FUNCS_H

bool readTAG();
int readI(bool tag);
int readSIZE(std::istream& fin);

void DELETEmass(double** mass, int SIZE);
float readA();
void READmass(int SIZE, double** A);
void RANDOMmass(int SIZE, double** A);
void work(double** A, double** B, double** C, int SIZE);
void outPUT(double** mass, int SIZE, std::ostream& f);
void readTXT(double** A, double** B, double** C, int SIZE, std::istream& f, std::ostream& fout);
void workNOTtxt(double** A, double** B, double** C, int SIZE, std::ostream& f);
void outPUTres(double** A, double** B, double** C, int SIZE, std::ostream& f);

#endif
