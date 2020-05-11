#include<fstream>
#include<iostream>
#include "CRat.h"

using namespace std;
class CRatFactory {
public:
    virtual CRat* create_dat(int d)=0;
    virtual ~CRatFactory(){}
};

class CRatFactory0 : public CRatFactory{
public:
    CRat* create_dat(int d);
};
class CRatFactory1 : public CRatFactory{
public:
    CRat* create_dat(int d);
};
