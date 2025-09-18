#pragma once
#include <iostream>
#include <string>

class Three
{
private:
    size_t size;
    size_t capacity;
    unsigned int* data;
    void pop();
    void push_back(const unsigned int& n);
    void resize(const unsigned int& n);

public:
    Three();
    Three(int n);
    Three(const Three& other);
    Three(const std::initializer_list<unsigned int>& t);
    int comp(const Three& other) const;
    Three operator+(const Three& other) const;
    Three operator-(const Three& other) const;
    bool operator==(const Three& other) const;
    bool operator!=(const Three& other) const;
    bool operator<=(const Three& other) const;
    bool operator>=(const Three& other) const;
    bool operator<(const Three& other) const;
    bool operator>(const Three& other) const;

    virtual ~Three() noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Three& Tr);
};
