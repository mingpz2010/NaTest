#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_       1

#include <cstdlib>
#include <cstring>

template<typename T>
class Vector
{
    T *_v;
    size_t N;

public:
    Vector()
    {
        _v = nullptr;
        N = 0;
    }

    Vector(size_t n)
    {
        if (n <= 0) {
            N = 0;
            _v = nullptr;
        } else {
            N = n;
            _v = new T[n];
            memset(_v, 0, n * sizeof(T));
        }
    }

    Vector(const Vector& other)
    {
        N = other.N;
        if (N <= 0){
            N = 0;
            _v = nullptr;
        }else{
            _v = new T[N];
            for (size_t i = 0; i < N; ++i) {
                _v[i] = other._v[i];
            }
        }
    }

    ~Vector()
    {
        if (_v != nullptr)  delete[] _v;
    }

    Vector<T>& operator=(const Vector<T>& rhs)
    {
        // Check if it is a self assignment
        if (&rhs == this)
            return *this;
        // Check if they don't have the same size
        if (N != rhs.N){
            if (_v != nullptr)
                delete[] _v;
            if (rhs.N > 0) {
                N = rhs.N;
                _v = new T[N];
            } else {
                N = 0;
                _v = nullptr;
            }
        }

        for (size_t i = 0; i < N; ++i) {
            _v[i] = rhs._v[i];
        }
        return *this;
    }

    const T& operator[](size_t index) const { return _v[index]; }

    T& operator[](size_t index) { return _v[index]; }

    bool operator==(const Vector<T>& rhs) const
    {
        if (N != rhs.N)  return false;
        for (size_t i = 0; i < N; ++i) {
            if (_v[i] != rhs._v[i])  return false;
        }
        return true;
    }

    bool operator!=(const Vector<T>& rhs) const { return !(*this == rhs); }

    Vector<T> operator+(const Vector<T>& rhs) const
    {
        if (N != rhs.N)
            return Vector<T>();
        Vector<T> ret(N);
        for (size_t i = 0; i < N; ++i) {
            ret._v[i] = _v[i] + rhs._v[i];
        }
        return ret;
    }

    Vector<T> operator-(const Vector<T>& rhs) const
    {
        if (N != rhs.N)
            return Vector<T>();
        Vector<T> ret(N);
        for (size_t i = 0; i < N; ++i) {
            ret._v[i] = _v[i] - rhs._v[i];
        }
        return ret;
    }

    size_t dim() const { return N; }

    bool is_valid() const { return (N!=0); }

    void set_zero()
    {
        memset(_v, 0, N*sizeof(T));
    }

    inline void zero()
    {
        set_zero();
    }

    void set_all(T val)
    {
        Vector<T> &p = *this;

        for (size_t i = 0; i < N; i++) {
            _v[i] = val;
        }
    }

    inline void set_one()
    {
        set_all(1);
    }
};

#endif
