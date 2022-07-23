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
        switch (this->random(1, 5))
        {

        case 0: // +
        {
            reportData testDetails;

            std::string operationType = "addition";

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first + testPair.second);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first + referencePair.second);

            if (testResult != referenceResult)
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType(operationType);

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case 1: // -
        {
            reportData testDetails;

            std::string operationType = "subtraction";

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first - testPair.second);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first - referencePair.second);

            if (testResult != referenceResult)
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType(operationType);

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case 2: // *
        {
            reportData testDetails;

            std::string operationType = "multiplication";

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, true);

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first * testPair.second);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first * referencePair.second);

            if (testResult != referenceResult)
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType(operationType);

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case 3: // =
        {
            reportData testDetails;

            std::string operationType = "assignment";

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            testPair.first = testPair.second;
            referencePair.first = referencePair.second;

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first);

            if (testResult != referenceResult)
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType(operationType);

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case 4: // +=
        {
            reportData testDetails;

            std::string operationType = "assignment addition";

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            testPair.first += testPair.second;
            referencePair.first += referencePair.second;

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first);

            if (testResult != referenceResult)
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType(operationType);

                failReports.emplace(testID, testDetails);
            }
            else
            {
                this->successfulTests++;
            }

            break;
        }

        case 5: // -=
        {
            reportData testDetails;

            std::string operationType = "assignment subtraction";

            std::pair<matrix<double>, matrix<double>> testPair;
            std::pair<Eigen::MatrixXd, Eigen::MatrixXd> referencePair;

            this->prepareData(testPair, referencePair, false);

            testPair.first -= testPair.second;
            referencePair.first -= referencePair.second;

            // Casting results to the same type, so that it is possible to compare them

            std::vector<std::vector<double>> testResult = this->extractData(testPair.first);
            std::vector<std::vector<double>> referenceResult = this->extractData(referencePair.first);

            if (testResult != referenceResult)
            {
                testDetails.setTestPair(testPair);
                testDetails.setReferencePair(referencePair);
                testDetails.setTestResult(testResult);
                testDetails.setReferenceResult(referenceResult);

                testDetails.setOperationType(operationType);

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
 