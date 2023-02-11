#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class SetOfIntegers
{

public:

    SetOfIntegers();

    SetOfIntegers(const std::vector<int>& values);

    SetOfIntegers(const SetOfIntegers& other);

    ~SetOfIntegers();

    //проверка принадлежности к множеству
    bool contains(int value) const;

    //добавление элемента
    void insert(int value);

    //удаление элемента
    void remove(int value);

    friend SetOfIntegers operator+(const SetOfIntegers& temp1, const SetOfIntegers& temp2);

    friend SetOfIntegers operator-(const SetOfIntegers& temp1, const SetOfIntegers& temp2);

    SetOfIntegers operator*(const SetOfIntegers& other);

    SetOfIntegers& operator+=(const SetOfIntegers& other);

    SetOfIntegers& operator-=(const SetOfIntegers& other);

    SetOfIntegers& operator*=(const SetOfIntegers& other);

    SetOfIntegers& operator=(const SetOfIntegers& other);

    bool operator==(const SetOfIntegers& other) const;

    void print();

protected:

    std::vector<int>elements_;

};
