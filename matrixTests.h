#pragma once

#include "reportData.h"
#include <chrono>
#include <random>
#include <map>

class matrixTests
{
public:

    matrixTests();

    ~matrixTests();

    void perform();

private:

    std::default_random_engine re;

    size_t nTests;

    unsigned successfulTests;

    std::map<unsigned, reportData> failReports;

    void showReport() const;

    void prepareData(std::pair<matrix<double>, matrix<double>> &_testPair, std::pair<Eigen::MatrixXd, Eigen::MatrixXd> &_referencePair, const bool _multiplicationFlag);

    void fillPair(matrix<double> &_matrixA, Eigen::MatrixXd &_matrixB);

    int random(const int _min, const int _max);

    double random(const double _min, const double _max);

    std::vector<std::vector<double>> extractData(const matrix<double> &_data) const;

    std::vector<std::vector<double>> extractData(const matrix<double> &&_data) const;

    std::vector<std::vector<double>> extractData(const Eigen::MatrixXd &_data) const;

    std::vector<std::vector<double>> extractData(const Eigen::MatrixXd &&_data) const;
};
 