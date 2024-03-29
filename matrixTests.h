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

    enum operation
    {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        ASSIGNMENT,
        ASSIGNMENT_ADDITION,
        ASSIGNMENT_SUBTRACTION,
        ASSIGNMENT_MULTIPLICATION
    };

    size_t nTests;

    unsigned successfulTests;

    std::map<unsigned, reportData> failReports;

    bool comapreResults(const std::vector<std::vector<double>> &_testResult, const std::vector<std::vector<double>> &_referenceResult) const;

    void showReport() const;

    void prepareData(std::pair<matrix<double>, matrix<double>> &_testPair, std::pair<Eigen::MatrixXd, Eigen::MatrixXd> &_referencePair, const bool _multiplicationFlag);

    void fillPair(matrix<double> &_matrixA, Eigen::MatrixXd &_matrixB);

    int random(const int _min, const int _max);

    double random(const double _min, const double _max);

    operation randomOperation();

    std::vector<std::vector<double>> extractData(const matrix<double> &_data) const;

    std::vector<std::vector<double>> extractData(const matrix<double> &&_data) const;

    std::vector<std::vector<double>> extractData(const Eigen::MatrixXd &_data) const;

    std::vector<std::vector<double>> extractData(const Eigen::MatrixXd &&_data) const;
};
 