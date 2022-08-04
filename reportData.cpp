#include "reportData.h"

reportData::reportData()
{
}

reportData::~reportData()
{
}

void reportData::details() const
{
    std::cout << "\n---------------\n\nTEST PAIR\n\nMatrix A:\n\n";

    this->testData.first.print();

    std::cout << "\n\nOperation type: [" << this->operationType << "]\n";

    std::cout << "\n\nMarix B:\n\n";

    this->testData.second.print();

    std::cout << "\n\nResult:\n\n\n";

    this->printResult(testResult);

    std::cout << "\n---------------\n\nREFERENCE PAIR\n\nMatrix A:\n\n" << this->referenceData.first << "\n";

    std::cout << "\n\nOperation type: [" << this->operationType << "]\n";

    std::cout << "\n\nMarix B:\n\n"<< this->referenceData.second;

    std::cout << "\n\n\nResult:\n\n";

    this->printResult(referenceResult);
}

void reportData::setTestPair(const std::pair<matrix<double>, matrix<double>> &_testPair)
{
    this->testData = _testPair;
}

void reportData::setReferencePair(const std::pair<Eigen::MatrixXd, Eigen::MatrixXd> &_referencePair)
{
    this->referenceData = _referencePair;
}

void reportData::setTestResult(const std::vector<std::vector<double>> &_testResult)
{
    this->testResult = _testResult;
}

void reportData::setReferenceResult(const std::vector<std::vector<double>> &_referenceResult)
{
    this->referenceResult = _referenceResult;
}

void reportData::setOperationType(const char *_operationType)
{
    this->operationType = _operationType;
}

std::pair<matrix<double>, matrix<double>> reportData::getTestData() const
{
    return testData;
}

std::pair<Eigen::MatrixXd, Eigen::MatrixXd> reportData::getReferenceData() const
{
    return referenceData;
}

std::vector<std::vector<double>> reportData::getTestResult () const
{
    return testResult;
}

std::vector<std::vector<double>> reportData::getReferenceResult() const
{
    return referenceResult;
}

std::string reportData::getOperationType() const
{
    return operationType;
}

void reportData::printResult(const std::vector<std::vector<double>> &_data) const
{
    for (size_t i = 0; i < _data.size(); i++)
    {
        for (size_t j = 0; j < _data[i].size(); j++)
        {
            std::cout << _data[i][j] << " ";
        }

        std::cout << "\n";        
    }
}
 