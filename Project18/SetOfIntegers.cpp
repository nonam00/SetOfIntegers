#include "SetOfIntegers.h"

SetOfIntegers::SetOfIntegers() {}

SetOfIntegers::SetOfIntegers(const std::vector<int>& values)
{
    for (int value : values)
        insert(value);
}

SetOfIntegers::SetOfIntegers(const SetOfIntegers& other)
{
    elements_ = other.elements_;
}

SetOfIntegers::~SetOfIntegers() {}

//проверка принадлежности к множеству
bool SetOfIntegers::contains(int value) const
{
    return std::find(elements_.begin(), elements_.end(), value) != elements_.end();
}

//добавление элемента
void SetOfIntegers::insert(int value)
{
    if (!contains(value))
        elements_.push_back(value);
}

//удаление элемента
void SetOfIntegers::remove(int value)
{
    elements_.erase(std::remove(elements_.begin(), elements_.end(), value), elements_.end());
}

SetOfIntegers operator+(const SetOfIntegers& temp1, const SetOfIntegers& temp2)
{
    SetOfIntegers result(temp1);
    for (int value : temp2.elements_)
        result.insert(value);
    return result;
}

SetOfIntegers operator-(const SetOfIntegers& temp1, const SetOfIntegers& temp2)
{
    SetOfIntegers result(temp1);
    for (int value : temp2.elements_)
        result.remove(value);
    return result;
}

SetOfIntegers SetOfIntegers::operator*(const SetOfIntegers& other)
{
    SetOfIntegers result;
    for (int value : elements_)
        if (other.contains(value))
            result.insert(value);
    return result;
}

SetOfIntegers& SetOfIntegers::operator+=(const SetOfIntegers& other)
{
    for (int value : other.elements_)
        insert(value);
    return *this;
}

SetOfIntegers& SetOfIntegers::operator-=(const SetOfIntegers& other)
{
    for (int value : other.elements_)
        remove(value);
    return *this;
}

SetOfIntegers& SetOfIntegers::operator*=(const SetOfIntegers& other)
{
    SetOfIntegers result;
    for (int value : elements_)
        if (other.contains(value))
            result.insert(value);
    elements_ = result.elements_;
    return *this;
}

SetOfIntegers& SetOfIntegers::operator=(const SetOfIntegers& other)
{
    elements_ = other.elements_;
    return *this;
}

bool SetOfIntegers::operator==(const SetOfIntegers& other) const
{
    return elements_ == other.elements_;
}

void SetOfIntegers::print()
{
    for (auto item : elements_)
        std::cout << item << " ";
    std::cout << std::endl;
}