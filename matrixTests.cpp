#include "matrixTests.h"

matrixTests::matrixTests()
{
    unsigned randomSeed = std::chrono::steady_clock().now().time_since_epoch().count();

    this->re.seed(randomSeed);

    this->nTests = random(5, 20);

    this->successfulTests = 0;
}

matrixTests::~matrixTests()
{
}

void matrixTests::perform()
{
    for (size_t testID = 0; testID < nTests; testID++)
    {
        switch (this->randomOperation())
        {

        case operation::ADDITION:
        {
            reportData testDetails;

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first + testPair.second);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first + referencePair.second);

            if (!(this->comapreResults(testResult, referenceResult)))
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType("addition");

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case operation::SUBTRACTION:
        {
            reportData testDetails;

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first - testPair.second);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first - referencePair.second);

            if (!(this->comapreResults(testResult, referenceResult)))
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType("subtraction");

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case operation::MULTIPLICATION:
        {
            reportData testDetails;

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, true);

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first * testPair.second);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first * referencePair.second);

            if (!(this->comapreResults(testResult, referenceResult)))
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType("multiplication");

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case operation::ASSIGNMENT:
        {
            reportData testDetails;

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            testPair.first = testPair.second;
            referencePair.first = referencePair.second;

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first);

            if (!(this->comapreResults(testResult, referenceResult)))
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType("assignment");

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case operation::ASSIGNMENT_ADDITION:
        {
            reportData testDetails;

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            testPair.first += testPair.second;
            referencePair.first += referencePair.second;

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first);

            if (!(this->comapreResults(testResult, referenceResult)))
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType("assignment addition");

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case operation::ASSIGNMENT_SUBTRACTION:
        {
            reportData testDetails;

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            testPair.first -= testPair.second;
            referencePair.first -= referencePair.second;

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first);

            if (!(this->comapreResults(testResult, referenceResult)))
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType("assignment subtraction");

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case operation::ASSIGNMENT_MULTIPLICATION:
        {
            reportData testDetails;

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, true);

            testPair.first *= testPair.second;
            referencePair.first *= referencePair.second;

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first);

            if (!(this->comapreResults(testResult, referenceResult)))
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType("assignment multiplication");

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        default:

            break;
        }
    }

    showReport();
}

bool matrixTests::comapreResults(const std::vector<std::vector<double>> &_testResult, const std::vector<std::vector<double>> &_referenceResult) const
{
    if (_testResult.size() != _referenceResult.size())
    {
        return false;
    }
    else
    {
        for (size_t i = 0; i < _testResult.size(); i++)
        {
            if (_testResult[i].size() != _referenceResult[i].size())
            {
                return false;
            }
            else
            {
                for (size_t k = 0; k < _testResult[i].size(); k++)
                {
                    if (fabs(_testResult[i][k] - _referenceResult[i][k]) < .0001)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }                    
                }                
            }
        }        
    }

    // ? control reaches end of non-void function [-Wreturn-type]
}

void matrixTests::showReport() const
{
    // Basic output

    std::cout << "\nSuccesful tests: " << this->successfulTests << "/" << this->nTests << "\n\n";

    if (!(this->failReports.empty()))
    {
        std::cout << "Failed tests IDs: " << "\n\n";

        for (auto el : this->failReports)
        {
            std::cout << el.first << " (" << el.second.getOperationType() << ")\n";
        }

        // Show details dialogue

        while (true)
        {
            std::cout << "\nShow a detailed report on any of the tests? (y/n): ";

            std::string userInput;

            std::cin >> userInput;

            if (userInput == "n")
            {
                return;
            }
            else if (userInput == "y")
            {
                while (true)
                {
                    std::cout << "\nEnter test ID: ";

                    std::cin >> userInput;

                    unsigned userRequest;

                    try
                    {
                        userRequest = std::stoi(userInput);
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << "\nWrong input... Try again.\n";

                        continue;
                    }

                    auto failedTest = failReports.find(userRequest);

                    if (failedTest != failReports.end())
                    {
                        failedTest->second.details();

                        break;
                    }
                    else
                    {
                        bool wrongInput = false;

                        while (true)
                        {
                            if (wrongInput)
                            {
                                std::cout << "\nTry another one? (y/n): ";

                                wrongInput = false;
                            }
                            else
                            {
                                std::cout << "\nYour search was inconclusive. Try another one? (y/n): ";
                            }

                            std::cin >> userInput;

                            if (userInput == "n")
                            {
                                return;
                            }
                            else if (userInput == "y")
                            {
                                break;
                            }
                            else
                            {
                                std::cout << "\nWrong input... Try again.\n";

                                wrongInput = true;
                            }
                        }
                    }
                }
            }
            else
            {
                std::cout << "\nWrong input... Try again.\n";
            }
        }
    }
}

void matrixTests::prepareData(std::pair<matrix<double>, matrix<double>> &_testPair, std::pair<Eigen::MatrixXd, Eigen::MatrixXd> &_referencePair, const bool _multiplicationFlag)
{
    int m = this->random(1, 9);
    int n = this->random(1, 9);

    _testPair.first.resize(m, n);
    _referencePair.first.resize(m, n);

    if (_multiplicationFlag)
    {
        int k = random(1, 9);

        _testPair.second.resize(n, k);
        _referencePair.second.resize(n, k);
    }
    else
    {
        _testPair.second.resize(m, n);
        _referencePair.second.resize(m, n);
    }

    this->fillPair(_testPair.first, _referencePair.first);
    this->fillPair(_testPair.second, _referencePair.second);
}

void matrixTests::fillPair(matrix<double> &_matrixA, Eigen::MatrixXd &_matrixB)
{
    for (size_t i = 0; i < _matrixA.getRows(); i++)
    {
        for (size_t j = 0; j < _matrixA.getCols(); j++)
        {
            double element = this->random(0.0, 10000.0);

            _matrixA(i, j) = element;
            _matrixB(i, j) = element;
        }
    }
}

int matrixTests::random(const int _min, const int _max)
{
    std::uniform_int_distribution<int> distr(_min, _max);
    return distr(this->re);
}

double matrixTests::random(const double _min, const double _max)
{
    std::uniform_real_distribution<double> distr(_min, _max);
    return distr(this->re);
}

matrixTests::operation matrixTests::randomOperation()
{
    switch (this->random(1, 7))
    {
    case 1: return operation::ADDITION;
    case 2: return operation::SUBTRACTION;
    case 3: return operation::MULTIPLICATION;
    case 4: return operation::ASSIGNMENT;
    case 5: return operation::ASSIGNMENT_ADDITION;
    case 6: return operation::ASSIGNMENT_SUBTRACTION;
    case 7: return operation::ASSIGNMENT_MULTIPLICATION;
    }

    // ? control reaches end of non-void function [-Wreturn-type]
}

std::vector<std::vector<double>> matrixTests::extractData(const matrix<double> &_data) const
{
    std::vector<std::vector<double>> temp;

    temp.resize(_data.getRows());

    for (size_t i = 0; i < _data.getRows(); i++)
    {
        for (size_t j = 0; j < _data.getCols(); j++)
        {
            temp[i].resize(_data.getCols());

            temp[i][j] = _data(i, j);
        }
    }

    return temp;
}

std::vector<std::vector<double>> matrixTests::extractData(const matrix<double> &&_data) const
{
    std::vector<std::vector<double>> temp;

    temp.resize(_data.getRows());

    for (size_t i = 0; i < _data.getRows(); i++)
    {
        for (size_t j = 0; j < _data.getCols(); j++)
        {
            temp[i].resize(_data.getCols());

            temp[i][j] = _data(i, j);
        }
    }

    return temp;
}

std::vector<std::vector<double>> matrixTests::extractData(const Eigen::MatrixXd &_data) const
{
    std::vector<std::vector<double>> temp;

    temp.resize(_data.rows());

    for (size_t i = 0; i < _data.rows(); i++)
    {
        for (size_t j = 0; j < _data.cols(); j++)
        {
            temp[i].resize(_data.cols());

            temp[i][j] = _data(i, j);
        }
    }

    return temp;
}

std::vector<std::vector<double>> matrixTests::extractData(const Eigen::MatrixXd &&_data) const
{
    std::vector<std::vector<double>> temp;

    temp.resize(_data.rows());

    for (size_t i = 0; i < _data.rows(); i++)
    {
        for (size_t j = 0; j < _data.cols(); j++)
        {
            temp[i].resize(_data.cols());

            temp[i][j] = _data(i, j);
        }
    }

    return temp;
}
 