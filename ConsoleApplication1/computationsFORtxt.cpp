#include <iostream>
#include "funcs.h";

void computationsFORtxt(float* H_txt, float* Res_txt, int count_H) {
	for (int i = 0; i < count_H; i++) 
	{
		if (H_txt[i] != 404 && H_txt[i] != 405) 
		{
			Res_txt[i] = computations(H_txt[i]);
		}
		else 
		{
			Res_txt[i] = H_txt[i];
		}
	}
}