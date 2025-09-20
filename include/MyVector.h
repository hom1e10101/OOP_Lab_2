#pragma once
#include <iostream>

class MyVector
{
public:
    size_t size;
    size_t capacity;
    unsigned char* data;

    MyVector();
    MyVector(const size_t& n);
    MyVector(const std::initializer_list<unsigned char>& t);
    MyVector(const MyVector& other);

    void pop();
    void push_back(const unsigned int& n);
    virtual ~MyVector() noexcept;
    unsigned char get(size_t ind) const;
};
