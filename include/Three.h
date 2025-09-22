#pragma once
#include <iostream>
#include <string>

#include "MyVector.h"

class Three
{    
public:
    MyVector data;
    Three();
    Three(int n);
    Three(const Three& other);
    Three(Three&& other);
    Three(const std::initializer_list<unsigned char>& t);
    int comp(const Three& other) const;

    virtual ~Three() noexcept;
    void print();
};


Three add(const Three& a, const Three& b);
Three sub(const Three& a, const Three& b);
bool eq(const Three& a, const Three& b);
bool noteq(const Three& a, const Three& b);
bool less_or_eq(const Three& a, const Three& b);
bool bigger_or_eq(const Three& a, const Three& b);
bool less(const Three& a, const Three& b);
bool bigger(const Three& a, const Three& b);
