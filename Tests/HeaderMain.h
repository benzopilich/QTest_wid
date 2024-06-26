#pragma once
#include <vector>
class Prime
{
public:
    bool isPrime(unsigned n);
    std::vector<unsigned> Factorization(unsigned n);
};
class taylor
{
public:
    double series(double x, double eps);
};
class Roots
{
public:
    std::vector<double> Disc(double a,double b,double c);
};
