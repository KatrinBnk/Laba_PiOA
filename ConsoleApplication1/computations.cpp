
#include <iostream>
#include "costs.h"


// функция для основных вычислений задачи

float computations(float h)
{
    float r; // радиус основания цилиндра
    r = consts::v / (consts::pi * h);
    r = pow(r, 0.5); // возведение в степень 1/2
    return r;

}
