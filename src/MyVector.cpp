#include "MyVector.h"
#include <new>

void MyVector::pop()
{
    if (size > 0) size--;
}

void MyVector::push_back(const unsigned char& n)
{
    if (size >= capacity) {
        capacity *= 2;
        unsigned char* next = new unsigned char[capacity];
        std::copy(data, data + size, next);
        delete[] data;
        data = next;
    }
    data[size] = n;
    size++;
}

MyVector::MyVector() 
    : size(0), capacity(1), data(new unsigned char){};

MyVector::MyVector(const size_t& n) 
    : size(n), capacity(n * 2), data(new unsigned char[n * 2])
{
    for (size_t i = 0; i < n; ++i) {
        data[i] = 0;
    }
};

MyVector::MyVector(const std::initializer_list<unsigned char>& t)
    : size(t.size()), capacity(t.size() * 2), data(new unsigned char[t.size() * 2])
{
    std::copy(t.begin(), t.end(), data);
    for (size_t i = 0; i < t.size() / 2; ++i) {
        std::swap(data[i], data[size - i - 1]);
    }
}

MyVector::MyVector(const MyVector& other)
    : size(other.size), capacity(other.capacity), data(new unsigned char[other.capacity])
{
    std::copy(other.data, other.data + other.size, data);
}

MyVector::MyVector(MyVector&& other) noexcept
    : size(other.size), capacity(other.capacity), data(new unsigned char[other.capacity])
{
    std::copy(other.data, other.data + other.size, data);
    other.~MyVector();
}

MyVector::~MyVector() noexcept
{
    size = 0;
    capacity = 1;
    delete[] data;
    data = nullptr;
}

unsigned char MyVector::get(size_t ind) const {
    return data[ind];
}


