#include <iostream>
#include "funcs.h";

float *f(float H[], int H_m)
{
	float* Res = new float[H_m];
	for (int i = 0; i < H_m;i++) {
		if (H[i] != INFINITY) {
			Res[i] = computations(H[i]);
		}
		else {
			Res[i] = INFINITY;
		}
	}
	return Res;
}