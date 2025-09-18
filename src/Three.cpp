#include "Three.h"
// #include <iostream>
// #include <string>
#include <new>
// #include <cmath>

void Three::pop()
{
    if (size > 0) size--;
}

void Three::push_back(const unsigned int& n)
{
    if (size >= capacity) {
        capacity *= 2;
        unsigned int* next = new unsigned int[capacity];
        std::copy(data, data + size, next);
        delete[] data;
        data = next;
        // data = (unsigned int*) realloc(data, sizeof(unsigned int) * capacity);
    }
    data[size] = n;
    size++;
}

Three::Three() : size(0), capacity(1), data(new unsigned int[1]) {}

Three::Three(int n)
    : size(0), capacity(1), data(new unsigned int[1])
{
    if (n <= 0) {
        push_back(0);
        return;
    }
    while (n > 0) {
        push_back(n % 3);
        n /= 3;
    }
}

Three::~Three() noexcept
{
    size = 0;
    capacity = 1;
    delete[] data;
    data = nullptr;
}


Three::Three(const Three& other)
    : size(other.size), capacity(other.capacity), data(new unsigned int[other.capacity])
{
    std::copy(other.data, other.data + other.size, data);
}


Three::Three(const std::initializer_list<unsigned int>& t) 
    : size(t.size()), capacity(t.size()), data(new unsigned int[t.size()])
{
    std::copy(t.begin(), t.end(), data);
}

std::ostream& operator<<(std::ostream& os, const Three& Tr)
{
    for (int i = (int)Tr.size - 1; i >= 0; --i) {
        os << Tr.data[i];
    }
    return os;
}

Three Three::operator+(const Three& other) const {
    Three result;
    size_t n = std::max(size, other.size);

    
    int added = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i < size && i < other.size) {
            if (data[i] + other.data[i] + added >= 3) {
                result.push_back(data[i] + other.data[i] + added - 3);
                added = 1;
            } else {
                result.push_back(data[i] + other.data[i] + added);
                added = 0;
            }
        } else if (i < size) {
            if (data[i] + added >= 3) {
                result.push_back(data[i] + added - 3);
                added = 1;
            } else {
                result.push_back(data[i] + added);
                added = 0;
            }
        } else if (i < other.size) {
            if (other.data[i] + added >= 3) {
                result.push_back(other.data[i] + added - 3);
                added = 1;
            } else {
                result.push_back(other.data[i] + added);
                added = 0;
            }
        }
    }
    if (added) {
        result.push_back(added);
        added = 0;
    }
    
    return result;
}


Three Three::operator-(const Three& other) const {
    Three result;
    size_t n = std::max(size, other.size);
    
    if (size < other.size) return Three(0);

    int added = 0;
    for (size_t i = 0; i < n; ++i) {
        
        if (i < size && i < other.size) {
            // std::cerr << "\tpipiska " << (long)data[i] - other.data[i] - added << "\n";
            if ((long)data[i] - other.data[i] - added < 0) {
                result.push_back(3 + (long)data[i] - other.data[i] - added);
                added = 1;
            } else {
                result.push_back((long)data[i] - other.data[i] - added);
                added = 0;
            }
        } else if (i < size) {
            if ((long)data[i] - added < 0) {
                result.push_back(3 + (long)data[i] - added);
                added = 1;
            } else {
                result.push_back(data[i] - added);
                added = 0;
            }
        } else if (i < other.size) {
            return Three(0);
        }
    }
    if (added) {
        return Three(0);
    }

    // std::cerr << "\tans is = " << result.data[0] << "\n";
    while (result.size > 0 && result.data[result.size - 1] == 0) {
        result.pop();
        // std::cerr << "\t" << result.size << "\n";
    }
    return result;
}

int Three::comp(const Three& other) const {
    if (size != other.size) {
        return (size > other.size) ? 1 : -1;
    }

    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return (data[i] > other.data[i]) ? 1 : -1;
        }
    }
    
    return 0;
}

bool Three::operator==(const Three& other) const {
    return (comp(other) == 0);
}

bool Three::operator!=(const Three& other) const {
    return (comp(other) != 0);
}

bool Three::operator<=(const Three& other) const {
    return (comp(other) <= 0);
}

bool Three::operator>=(const Three& other) const {
    return (comp(other) >= 0);
}

bool Three::operator<(const Three& other) const {
    return (comp(other) < 0);
}

bool Three::operator>(const Three& other) const {
    return (comp(other) > 0);
}
