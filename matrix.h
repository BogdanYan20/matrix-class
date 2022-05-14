#pragma once

#include <iostream>
#include <vector>

template <typename T>
class matrix
{

public:
    matrix(unsigned _rows, unsigned _cols, const T &_initial);

    matrix(const matrix<T> &rhs);

    ~matrix();

    matrix<T> &operator=(const matrix<T> &rhs);

    matrix<T> &operator+=(const matrix<T> &rhs);

    matrix<T> &operator-=(const matrix<T> &rhs);

    matrix<T> operator+(const matrix<T> &rhs);

    matrix<T> operator-(const matrix<T> &rhs);

    matrix<T> operator*(const matrix<T> &rhs);

    bool operator==(const matrix<T> &rhs);

    bool operator!=(const matrix<T> &rhs);

    void print();

private:
    std::vector<std::vector<T> > mat;

    unsigned rows;
    unsigned cols;
};

template <typename T>
matrix<T>::matrix(unsigned _rows, unsigned _cols, const T &_initial)
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
matrix<T>::matrix(const matrix<T> &rhs)
{
    this->mat = rhs.mat;
    this->rows = rhs.rows;
    this->cols = rhs.cols;
}

template <typename T>
matrix<T>::~matrix()
{
}

template <typename T>
matrix<T> &matrix<T>::operator=(const matrix<T> &rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    this->rows = rhs.rows;
    this->cols = rhs.cols;

    mat.resize(this->rows);

    for (size_t i = 0; i < this->rows; i++)
    {
        mat[i].resize(this->cols);
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            mat[i][j] = rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
matrix<T> &matrix<T>::operator+=(const matrix<T> &rhs)
{
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            this->mat[i][j] += rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
matrix<T> &matrix<T>::operator-=(const matrix<T> &rhs)
{
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            this->mat[i][j] -= rhs.mat[i][j];
        }
    }

    return *this;
}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T> &rhs)
{
    matrix temp(rows, cols, 0);

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            temp.mat[i][j] = mat[i][j] + rhs.mat[i][j];
        }
    }

    return temp;
}

template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T> &rhs)
{
    matrix temp(rows, cols, 0);

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            temp.mat[i][j] = mat[i][j] - rhs.mat[i][j];
        }
    }

    return temp;
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T> &rhs)
{
    matrix temp(this->rows, rhs.cols, 0);

    for (size_t i = 0; i < temp.rows; i++)
    {
        for (size_t j = 0; j < rhs.cols; j++)
        {
            for (size_t k = 0; k < rhs.rows; k++)
            {
                temp.mat[i][j] += this->mat[i][k] * rhs.mat[k][j];
            }
        }
    }

    return temp;
}

template <typename T>
bool matrix<T>::operator==(const matrix<T> &rhs)
{
    if (this->rows != rhs.rows || this->cols != rhs.cols)
    {
        return false;
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (this->mat[i][j] != rhs.mat[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

template <typename T>
bool matrix<T>::operator!=(const matrix<T> &rhs)
{
    return !(this->operator==(rhs));
}

template <typename T>
void matrix<T>::print()
{
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            std::cout << mat[i][j] << " ";
        }

        std::cout << std::endl;
    }
}
 