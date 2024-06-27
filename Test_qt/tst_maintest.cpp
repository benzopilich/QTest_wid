#include <QtTest>
#include <vector>
#include <cmath>
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
    res=pr.Factorization(2000000000);
    unsigned n=1;
    for(unsigned i=0;i<res.size();i++)
    {
        n*=res[i];
    }
    QCOMPARE(n,2000000000);
}
void mainTest::test_taylor()
{
    taylor t;
    double d=t.series(-1000,0.001);
    double d1=sin(-1000);
    QVERIFY(fabs(d-d1)<0.001);
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
    QVERIFY(fabs(n-6)<0.001);
}

QTEST_APPLESS_MAIN(mainTest)

#include "tst_maintest.moc"
