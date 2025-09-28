#include <new>

#include "Three.h"
#include "MyVector.h"

Three::Three() : data() {}

Three::Three(int n)
    : data()
{
    if (n <= 0) {
        data.push_back(0);
        return;
    }
    while (n > 0) {
        data.push_back(n % 3);
        n /= 3;
    }
}

Three::~Three() noexcept {}

Three::Three(const Three& other) : data(other.data) {}

Three::Three(Three&& other)
    : data(other.data)
{
    other.~Three();
}

Three::Three(const std::initializer_list<unsigned char>& t)
    : data(t) {}

Three add(const Three& a, const Three& b) {
    Three result;
    size_t n = std::max(a.data.size, b.data.size);

    unsigned char added = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i < a.data.size && i < b.data.size) {
            if (a.data.get(i) + b.data.get(i) + added >= 3) {
                result.data.push_back(a.data.get(i) + b.data.get(i) + added - 3);
                added = 1;
            } else {
                result.data.push_back(a.data.get(i) + b.data.get(i) + added);
                added = 0;
            }
        } else if (i < a.data.size) {
            if (a.data.get(i) + added >= 3) {
                result.data.push_back(a.data.get(i) + added - 3);
                added = 1;
            } else {
                result.data.push_back(a.data.get(i) + added);
                added = 0;
            }
        } else if (i < b.data.size) {
            if (b.data.get(i) + added >= 3) {
                result.data.push_back(b.data.get(i) + added - 3);
                added = 1;
            } else {
                result.data.push_back(b.data.get(i) + added);
                added = 0;
            }
        }
    }
    if (added) {
        result.data.push_back(added);
        added = 0;
    }
    
    return result;
}

Three sub(const Three& a, const Three& b) {
    Three result;
    size_t n = std::max(a.data.size, b.data.size);
    
    if (a.data.size < b.data.size) return Three(0);

    long long added = 0;
    for (size_t i = 0; i < n; ++i) {
        
        if (i < a.data.size && i < b.data.size) {
            // std::cerr << "\tpipiska " << (long)data[i] - other.data[i] - added << "\n";
            if (a.data.get(i) - b.data.get(i) - added < 0) {
                result.data.push_back(3 + a.data.get(i) - b.data.get(i) - added);
                added = 1;
            } else {
                result.data.push_back(a.data.get(i) - b.data.get(i) - added);
                added = 0;
            }
        } else if (i < a.data.size) {
            if (a.data.get(i) - added < 0) {
                result.data.push_back(3 + a.data.get(i) - added);
                added = 1;
            } else {
                result.data.push_back(a.data.get(i) - added);
                added = 0;
            }
        } else if (i < b.data.size) {
            return Three(0);
        }
    }
    if (added) {
        return Three(0);
    }

    while (result.data.size > 0 && result.data.get(result.data.size - 1) == 0) {
        result.data.pop();
    }
    return result;
}

int Three::comp(const Three& other) const
{
    if (data.size != other.data.size) {
        return (data.size > other.data.size) ? 1 : -1;
    }

    for (size_t i = 0; i < data.size; ++i) {
        if (data.get(i) != other.data.get(i)) {
            return (data.get(i) > other.data.get(i)) ? 1 : -1;
        }
    }

    return 0;
}


bool eq(const Three& a, const Three& b) {
    return (a.comp(b) == 0);
}

bool noteq(const Three& a, const Three& b) {
    return (a.comp(b) != 0);
}

bool less_or_eq(const Three& a, const Three& b) {
    return (a.comp(b) <= 0);
}

bool bigger_or_eq(const Three& a, const Three& b) {
    return (a.comp(b) >= 0);
}

bool less(const Three& a, const Three& b) {
    return (a.comp(b) < 0);
}

bool bigger(const Three& a, const Three& b) {
    return (a.comp(b) > 0);
}

void Three::print() {
    for (size_t i = 0; i < data.size; ++i) {
        std::cout << (unsigned int)data.get(i);
    }
}
