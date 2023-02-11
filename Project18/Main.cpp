//реализация на основе векторов

#include "SetOfIntegers.h"

int main()
{
    std::vector<int>v_values{ 1,2,3,4,5 };
    std::vector<int>v_values2{ 1,2,6,4,5 };

    SetOfIntegers values(v_values);
    SetOfIntegers values2(v_values2);

    values = values + values2;
    values.print();

    std::cout << (v_values == v_values2);
    return 0;
}