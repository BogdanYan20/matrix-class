#pragma once

#include <iostream>
#include <vector>

template <typename T>
class matrix
{

public:

    matrix();

    matrix(const unsigned _rows, const unsigned _cols, const T &_initial);

    matrix(const matrix<T> &_rhs);

    ~matrix();

    T &operator()(const unsigned _row, const unsigned _col);

    T operator()(const unsigned _row, const unsigned _col) const;

    matrix<T> &operator=(const matrix<T> &_rhs);

    matrix<T> &operator+=(const matrix<T> &_rhs);

    matrix<T> &operator-=(const matrix<T> &_rhs);

    matrix<T> operator+(const matrix<T> &_rhs) const;

    matrix<T> operator-(const matrix<T> &_rhs) const;

    matrix<T> operator*(const matrix<T> &_rhs) const;

    bool operator==(const matrix<T> &_rhs) const;

    bool operator!=(const matrix<T> &_rhs) const;

    unsigned getRows() const;

    unsigned getCols() const;

    void resize(const unsigned m, const unsigned n);

    void print() const;

private:

    std::vector<std::vector<T>> mat;

    unsigned rows;
    unsigned cols;
};

template <typename T>
matrix<T>::matrix()
{
    this->mat.resize(1);

    for (size_t i = 0; i < 1; i++)
    {
        this->mat[i].resize(1);
    }

    this->rows = 1;
    this->cols = 1;
}

template <typename T>
matrix<T>::matrix(const unsigned _rows, const unsigned _cols, const T &_initial)
{
    this->mat.resize(_rows);

    for (size_t i = 0; i < _rows; i++)
    {
        this->mat[i].resize(_cols, _initial);
    }

    this->rows = _rows;
    this->cols = _cols;
}

template <typename T>
matrix<T>::matrix(const matrix<T> &_rhs)
{
    this->mat = _rhs.mat;
    this->rows = _rhs.rows;
    this->cols = _rhs.cols;
}

template <typename T>
matrix<T>::~matrix()
{
}

template <typename T>
T &matrix<T>::operator()(const unsigned _row, const unsigned _col)
{
    if (_row > this->rows || _col > this->cols)
    {
        throw std::runtime_error("Out of range");
    }

    else
    {
        return this->mat[_row][_col];
    }    
}

template <typename T>
T matrix<T>::operator()(const unsigned _row, const unsigned _col) const
{
    if (_row > this->rows || _col > this->cols)
    {
        throw std::runtime_error("Out of range");
    }

    else
    {
        return this->mat[_row][_col];
    }    
}

template <typename T>
matrix<T> &matrix<T>::operator=(const matrix<T> &_rhs)
{
    if (&_rhs == this)
    {
        return *this;
    }

    this->rows = _rhs.rows;
    this->cols = _rhs.cols;

    this->mat.resize(this->rows);

    for (size_t i = 0; i < this->rows; i++)
    {
        this->mat[i].resize(this->cols);
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            this->mat[i][j] = _rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
matrix<T> &matrix<T>::operator+=(const matrix<T> &_rhs)
{
    if (this->rows != _rhs.rows || this->cols != _rhs.cols)
    {
        throw std::runtime_error("Matrices are incompatible");
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            this->mat[i][j] += _rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
matrix<T> &matrix<T>::operator-=(const matrix<T> &_rhs)
{
    if (this->rows != _rhs.rows || this->cols != _rhs.cols)
    {
        throw std::runtime_error("Matrices are incompatible");
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            this->mat[i][j] -= _rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T> &_rhs) const
{
    if (this->rows != _rhs.rows || this->cols != _rhs.cols)
    {
        throw std::runtime_error("Matrices are incompatible");
    }

    matrix temp(this->rows, this->cols, 0);

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            temp.mat[i][j] = this->mat[i][j] + _rhs.mat[i][j];
        }
    }

    return temp;
}

template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T> &_rhs) const
{
    if (this->rows != _rhs.rows || this->cols != _rhs.cols)
    {
        throw std::runtime_error("Matrices are incompatible");
    }

    matrix temp(this->rows, this->cols, 0);

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            temp.mat[i][j] = this->mat[i][j] - _rhs.mat[i][j];
        }
    }

    return temp;
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T> &_rhs) const
{
    if (this->cols != _rhs.rows)
    {
        throw std::runtime_error("Matrices are incompatible");
    }

    matrix temp(this->rows, _rhs.cols, 0);

    for (size_t i = 0; i < temp.rows; i++)
    {
        for (size_t j = 0; j < _rhs.cols; j++)
        {
            for (size_t k = 0; k < _rhs.rows; k++)
            {
                temp.mat[i][j] += this->mat[i][k] * _rhs.mat[k][j];
            }
        }
    }

    return temp;
}

template <typename T>
bool matrix<T>::operator==(const matrix<T> &_rhs) const
{
    if (this->rows != _rhs.rows || this->cols != _rhs.cols)
    {
        return false;
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (this->mat[i][j] != _rhs.mat[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

template <typename T>
bool matrix<T>::operator!=(const matrix<T> &_rhs) const
{
    return !(this->operator==(_rhs));
}

template <typename T>
unsigned matrix<T>::getRows() const
{
    return this->rows;
}

template <typename T>
unsigned matrix<T>::getCols() const
{
    return this->cols;
}

template <typename T>
void matrix<T>::resize(const unsigned m, const unsigned n)
{
    this->rows = m;
    this->cols = n;

    this->mat.resize(this->rows);

    for (size_t i = 0; i < this->rows; i++)
    {
        this->mat[i].resize(this->cols);
    }
}

template <typename T>
void matrix<T>::print() const
{
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            std::cout << this->mat[i][j] << " ";
        }

        std::cout << "\n";
    }
}
 