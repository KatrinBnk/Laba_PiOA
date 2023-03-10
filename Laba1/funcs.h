#pragma once

bool readTAG();
bool constHread(float H);
float readH();
float computations(float h);
void computationsFILE(float* fileH, float* fileR, int countH);
void console(std::ostream& fout);
void txtREAD(std::istream& fin, std::ostream& fout);
