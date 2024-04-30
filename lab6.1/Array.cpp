#include "Array.h"

Array::Array(const size_type& n) throw(bad_alloc, invalid_argument)
{
    First = 0;
    Count = Size = n;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = 0;
}
Array::Array(const iterator first, const iterator last) throw(bad_alloc, invalid_argument)
{
    First = 0;
    if (first <= last)
    {
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}
Array::Array(const size_type first, const size_type last) throw(bad_alloc, invalid_argument)
{
    if (first <= last)
    {
        First = first;
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}
Array::Array(const Array& t) throw(bad_alloc) : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
    for (UINT i = 0; i < Size; ++i)
        elems[i] = t.elems[i];
}
Array::~Array()
{
    delete[] elems;
    elems = 0;
}

Array::reference Array::operator[](size_type index) throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}
Array::const_reference Array::operator[](size_type index) const throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}
Array::size_type Array::capacity() const
{
    return Size;
}
Array::size_type Array::size() const
{
    return Count;
}

void Array::push_back(const value_type& v)
{
    if (Count == Size) // місця нема
        resize(Size * 2); // збільшили "місткість"
    elems[Count++] = v; // присвоїли
}
void Array::resize(size_type newsize) throw(bad_alloc)
{
    if (newsize > capacity())
    {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i)
            data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}
void Array::swap(Array& other)
{
    std::swap(elems, other.elems); // стандартна функція обміну
    std::swap(Size, other.Size);
}
bool Array::empty() const
{
    return Count == 0;
}

ostream& operator<<(ostream& out, const Array& tmp)
{
    out << "[ ";
    for (size_t j = 0; j < tmp.Count; j++)
        out << tmp[j] << " ";
    out << "]";
    return out;
}
istream& operator>>(istream& in, Array& tmp)
{
    // тут має бути введення елементів масиву!
    return in;
}

Array Array::dynamicArrayFromRegular(const int* regularArray, int size)
{
    Array dynamicArray(size);
    for (int i = 0; i < size; ++i)
    {
        dynamicArray[i] = regularArray[i];
    }
    return dynamicArray;
}
double Array::calculateSum() const
{
    double sum = 0;
    for (const_iterator it = begin(); it != end(); ++it)
    {
        sum += *it;
    }
    return sum;
}
double Array::calculateAbsoluteAverage() const
{
    double sum = 0;
    for (const_iterator it = begin(); it != end(); ++it)
    {
        sum += abs(*it);
    }
    return sum / size();
}
void Array::divideOddNumbersByAverage()
{
    double average = calculateAbsoluteAverage();
    for (iterator it = begin(); it != end(); ++it)
    {
        if (fmod(*it, 2) != 0) // перевіряємо, чи є число непарним
        {
            *it /= average;
        }
    }
}
