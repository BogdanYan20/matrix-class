#pragma once

#include "matrix.h"
#include <Eigen/Dense>
#include <string>

class reportData
{
    
public:

    reportData();

    ~reportData();

    void details() const;

    void setTestPair(const std::pair<matrix<double>, matrix<double>> &_testPair);

    void setReferencePair(const std::pair<Eigen::MatrixXd, Eigen::MatrixXd> &_referencePair);

    void setTestResult(const std::vector<std::vector<double>> &_testResult);

    void setReferenceResult(const std::vector<std::vector<double>> &_referenceResult);

    void setOperationType(const std::string &_operationType);

    std::pair<matrix<double>, matrix<double>> getTestData() const;

    std::pair<Eigen::MatrixXd, Eigen::MatrixXd> getReferenceData() const;

    std::vector<std::vector<double>> getTestResult () const;

    std::vector<std::vector<double>> getReferenceResult() const;

    std::string getOperationType() const;

private:

    std::pair<matrix<double>, matrix<double>> testData;
    std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referenceData;

    std::vector<std::vector<double>> testResult;
    std::vector<std::vector<double>> referenceResult;

    std::string operationType;

    void printResult(const std::vector<std::vector<double>> &_data) const;
};
 