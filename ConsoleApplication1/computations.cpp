
#include <iostream>
#include "costs.h"


// ������� ��� �������� ���������� ������

float computations(float h)
{
    float r; // ������ ��������� ��������
    r = consts::v / (consts::pi * h);
    r = pow(r, 0.5); // ���������� � ������� 1/2
    return r;

}
