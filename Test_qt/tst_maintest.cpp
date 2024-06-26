#include <QtTest>
#include <vector>
#include "../Tests/HeaderMain.h"

// add necessary includes here

class mainTest : public QObject
{
    Q_OBJECT

public:
    mainTest();
    ~mainTest();

private slots:
    void test_prime();
    void test_taylor();
    void test_roots();
};

mainTest::mainTest() {}

mainTest::~mainTest() {}

void mainTest::test_prime()
{
    Prime pr;
    std::vector<unsigned> res;
    res=pr.Factorization(52);
    unsigned n=1;
    bool f=false;
    for(unsigned i=0;i<res.size();i++)
    {
        f=pr.isPrime(res[i]);
        QCOMPARE(f,true);
        f=false;
        n*=res[i];
    }
    QCOMPARE(n,52);
}
void mainTest::test_taylor()
{
    taylor t;
    QCOMPARE(t.series(0,0.001),0);
}
void mainTest::test_roots()
{
    Roots r;
    double a=1,b=-5,c=6;
    std::vector<double> res;
    res=r.Disc(a,b,c);
    double n=1.0;
    for(unsigned i=0;i<res.size();i++)
    {
        n*=res[i];
    }
    QCOMPARE(n,6);
}

QTEST_APPLESS_MAIN(mainTest)

#include "tst_maintest.moc"
